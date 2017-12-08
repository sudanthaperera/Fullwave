#pragma once
#include "Prob.h"
#include "ProblemSpace.h"
#include "EField.h"
#include "Constants.h"

class VoltageProb :
	public Prob
{
private:
	int direction;
	int is;
	int js;
	int ks;
	int ie;
	int je;
	int ke;
	double *timeDomainValue;
	double Csvf;
	double *time;
	std::complex<double> *frequencyDomainValue;
	double *frequencies;
public:
	VoltageProb();
	VoltageProb(Position probPos, int direction, double d);
	~VoltageProb();
	void initVoltageProb(ProblemSpace ps, Cell c, int timeSteps);
	void CaptureVoltage(EField E, int timeIndex);
	void saveTimeDomainValue();
	void saveFreqDomainValue();
	void time2freq(double *freqArray);
	void saveTime();
	void saveFreq();
	std::complex<double> getFreqDomainValue(int index);
};

