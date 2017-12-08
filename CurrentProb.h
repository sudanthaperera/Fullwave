#pragma once
#include "Prob.h"
#include "Cell.h"
#include "Position.h"
#include "Common.h"
#include "ProblemSpace.h"
#include "Common.h"
#include "Constants.h"
#include "HField.h"
#include <complex>
#include <cmath>

class CurrentProb :
	public Prob
{
private:
	double Xmin, Ymin, Zmin, Xmax, Ymax, Zmax;
	int direction;
	int is, js, ks, ie, je, ke;
	double* timeDomainValue;
	double* time;
	std::complex<double>* frequencyDomainValue;
	double* frequencies;
	Cell c;
public:
	CurrentProb();
	CurrentProb(Position probPos, int direction);
	void initCurrentProb(ProblemSpace ps, Cell c, int timeSteps);
	void CaptureCurrent(HField H, int timeIndex);
	void saveTimeDomainValue();
	void saveFreqDomainValue();
	void time2freq(double* freqArray);
	void saveTime();
	void saveFreq();
	std::complex<double> getFreqDomainValue(int index);
	~CurrentProb();
};

