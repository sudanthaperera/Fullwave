#include "FrequencyDomain.h"


FrequencyDomain::FrequencyDomain()
{
}


FrequencyDomain::~FrequencyDomain()
{
}

FrequencyDomain::FrequencyDomain(double start, double end, int freqCount){
	this->start = start;
	this->end = end;
	this->freqCount = freqCount;
	this->step = (end - start) / (freqCount - 1);
	this->frequencies = gen1DArray<double>(freqCount, 0.0);
	for (int i = 0; i<freqCount; i++){
		this->frequencies[i] = this->start + i*this->step;
	}
}

 void FrequencyDomain::setMonotone(double frequency){
	this->start = frequency;
	this->end = frequency;
	this->freqCount = 1;
	this->step = 0;
	this->frequencies = new double[1];
}

 void FrequencyDomain::resetFrequency(double start, double end, int freqCount){
	this->start = start;
	this->end = end;
	this->freqCount = freqCount;
	this->step = (end - start) / (freqCount - 1);
	this->frequencies = new double[freqCount];
}

 double* FrequencyDomain::getFreqArray(){
	return this->frequencies;
}

 int FrequencyDomain::getFreqCount(){
	return this->freqCount;
}
