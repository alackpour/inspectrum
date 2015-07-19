#include "spectrogramcontrols.h"
#include <QLabel>

SpectrogramControls::SpectrogramControls(const QString & title, QWidget * parent)
	: QDockWidget::QDockWidget(title, parent)
{
	widget = new QWidget(this);
	layout = new QFormLayout(widget);

	fftSizeSlider = new QSlider(Qt::Horizontal, widget);
	fftSizeSlider->setRange(7, 13);
	fftSizeSlider->setValue(10);
	layout->addRow(new QLabel(tr("FFT size:")), fftSizeSlider);

	powerMaxSlider = new QSlider(Qt::Horizontal, widget);
	powerMaxSlider->setRange(-60, 20);
	powerMaxSlider->setValue(0);
	layout->addRow(new QLabel(tr("Power max:")), powerMaxSlider);

	powerRangeSlider = new QSlider(Qt::Horizontal, widget);
	powerRangeSlider->setRange(0, 80);
	powerRangeSlider->setValue(40);
	layout->addRow(new QLabel(tr("Power range:")), powerRangeSlider);

	widget->setLayout(layout);
	setWidget(widget);

	connect(fftSizeSlider, SIGNAL(valueChanged(int)), this, SLOT(fftSizeSliderChanged(int)));
}

void SpectrogramControls::fftSizeSliderChanged(int size)
{
	emit fftSizeChanged((int)pow(2, size));
}