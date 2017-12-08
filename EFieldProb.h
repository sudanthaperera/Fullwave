#pragma once
#include "Prob.h"
#include "ProblemSpace.h"

class EFieldProb :
	public Prob
{
private:
	int is;
	int js;
	int ks;
	double *timeDomainSamplesX, *timeDomainSamplesY, *timeDomainSamplesZ;
	int component;
	double *time;
	std::complex<double> *freqDomainSamples;
	double *frequency;
public:
	EFieldProb();
	~EFieldProb();
	EFieldProb(Position probPos, ProblemSpace ps, Cell c, int timeSteps);
	void CaptureEField(int timeIndex);
	void saveEfiled();
};

