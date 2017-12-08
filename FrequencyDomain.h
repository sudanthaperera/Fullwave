#pragma once
#include "Common.h"

class FrequencyDomain
{
private:
	double* frequencies;
	double start;
	double step;
	double end;
	int freqCount;
public:
	FrequencyDomain();
	FrequencyDomain(double start, double end, int freqCount);
	~FrequencyDomain();
	void setMonotone(double frequency);
	void resetFrequency(double start, double end, int freqCount);
	double* getFreqArray();
	int getFreqCount();
};

