#include "WaveForm.h"


WaveForm::WaveForm()
{
}


WaveForm::~WaveForm()
{
}

WaveForm::WaveForm(int cellsPerWavelength, double amplitude, double phaseShift, int timeSteps){
	this->cellsPerWavelength = cellsPerWavelength;
	this->amplitude = amplitude;
	this->phaseShift = phaseShift;
	this->waveform = new double[timeSteps];
}

void WaveForm::buildWave(int timeSteps){
	this->waveform = new double[timeSteps];
}

int WaveForm::getCellsPerWavelength(){
	return this->cellsPerWavelength;
}

void WaveForm::setCellsPerWavelength(int cellsPerWavelength){
	this->cellsPerWavelength = cellsPerWavelength;
}

void WaveForm::set(double value, int index){
	this->waveform[index] = value;
}

double WaveForm::get(int index){
	return this->waveform[index];
}
