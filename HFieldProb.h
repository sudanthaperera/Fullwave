#pragma once
#include "Prob.h"
#include "ProblemSpace.h"
#include "Common.h"

class HFieldProb :
	public Prob
{
private:
	int is;
	int js;
	int ks;
	double *timeDomainSamples;
	int component;
	double *time;
	std::complex<double> *freqDomainSamples;
	double *frequency;
public:
	HFieldProb();
	HFieldProb(Position probPos, ProblemSpace ps, Cell c, int timeSteps);
	~HFieldProb();
	void CaptureHField(int timeIndex);
};