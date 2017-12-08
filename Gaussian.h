#pragma once
#include "WaveForm.h"

class Gaussian :
	public WaveForm
{
private:
	double maximumFrequency;
	double tau;
	double t0;
public:
	Gaussian();
	~Gaussian();
	Gaussian(int cellsPerWavelength, double amplitude, double phaseShift, int timeSteps);
	void buildWave(int timeSteps);
	double getMaxFreq();
	void setMaxFreq(double val);
	void setTau(double val);
	void setT0(double val);
	double getT0();
	double getTau();
};

