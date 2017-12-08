#include "Gaussian.h"


Gaussian::Gaussian()
{
}


Gaussian::~Gaussian()
{
}

Gaussian::Gaussian(int cellsPerWavelength, double amplitude, double phaseShift, int timeSteps){
	WaveForm::WaveForm(cellsPerWavelength, amplitude, phaseShift, timeSteps);
}

void Gaussian::buildWave(int timeSteps){
	WaveForm::buildWave(timeSteps);
}

double Gaussian::getMaxFreq(){
	return this->maximumFrequency;
}

void Gaussian::setMaxFreq(double val){
	this->maximumFrequency = val;
}

void Gaussian::setTau(double val){
	this->tau = val;
}

void Gaussian::setT0(double val){
	this->t0 = val;
}

double Gaussian::getT0(){
	return this->t0;
}

double Gaussian::getTau(){
	return this->tau;
}