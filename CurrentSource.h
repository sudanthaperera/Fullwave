#pragma once
#include "Source.h"
#include "ProblemSpace.h"

class CurrentSource :
	public Source
{
public:
	CurrentSource();
	CurrentSource(double Xmax, double Ymax, double Zmax, double Xmin, double Ymin, double Zmin, Cell c);
	~CurrentSource();
	void SetDirection(int direction);
	void updateCurrentSourceHfiled(int timeIndex);
	static int currentSourceCount;
private:
	std::complex<double>* freqDomainValue;
	double* frequencies;
	double* waveform;
	double resistance, magnitude;
};

