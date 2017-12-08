#include "VoltageProb.h"


VoltageProb::VoltageProb()
{
}


VoltageProb::~VoltageProb()
{
}

VoltageProb::VoltageProb(Position probPos, int direction, double d){
	Prob::Prob(probPos);
	this->direction = direction;
	switch (direction){
	case XP: this->Xmin = d; break;
	case XN: this->Xmax = d; break;
	case YP: this->Ymin = d; break;
	case YN: this->Ymax = d; break;
	case ZP: this->Zmin = d; break;
	case ZN: this->Zmax = d; break;
	}
}

void VoltageProb::initVoltageProb(ProblemSpace ps, Cell c, int timeSteps){
	is = (int)round((Xmin - ps.getXmin()) / c.getDeltaX()) + 1;
	js = (int)round((Ymin - ps.getYmin()) / c.getDeltaY()) + 1;
	ks = (int)round((Zmin - ps.getZmin()) / c.getDeltaZ()) + 1;
	ie = (int)round((Xmax - ps.getXmin()) / c.getDeltaX()) + 1;
	je = (int)round((Ymax - ps.getYmin()) / c.getDeltaY()) + 1;
	ke = (int)round((Zmax - ps.getZmin()) / c.getDeltaZ()) + 1;
	timeDomainValue = gen1DArray<double>(timeSteps, 0.0);
	time = gen1DArray<double>(timeSteps, 0.0);

	if (direction == XN || direction == XP){
		Csvf = -c.getDeltaX() / ((je - js + 1)*(ke - ks + 1));
	}

	if (direction == YN || direction == YP){
		Csvf = -c.getDeltaY() / ((ke - ks + 1)*(ie - is + 1));
	}

	if (direction == ZN || direction == ZP){
		Csvf = -c.getDeltaZ() / ((ie - is + 1)*(je - js + 1));
	}

	if (direction == XN || direction == YN || direction == ZN){
		Csvf = -1 * Csvf;
	}

	for (int i = 0; i < timeSteps; i++){
		time[i] = (i + 1)*c.getDeltaT();
	}
}

void VoltageProb::CaptureVoltage(EField E, int timeIndex){
	double sample = 0.0;

	if (direction == XN || direction == XP){
		for (int i = is; i <= ie; i++){
			for (int j = js; j <= je; j++){
				for (int k = ks; k<ke; k++){
					sample = sample + Csvf*E.getEx(i, j, k);
				}
			}
		}
	}
	if (direction == YN || direction == YP){
		for (int i = is; i <= ie; i++){
			for (int j = js; j <= je; j++){
				for (int k = ks; k<ke; k++){
					sample = sample + Csvf*E.getEy(i, j, k);
				}
			}
		}
	}
	if (direction == ZN || direction == ZP){
		for (int i = is; i <= ie; i++){
			for (int j = js; j <= je; j++){
				for (int k = ks; k<ke; k++){
					sample = sample + Csvf*E.getEz(i, j, k);
				}
			}
		}
	}

	timeDomainValue[timeIndex] = sample;
}

void VoltageProb::saveTimeDomainValue(){
	save1DArray<double>(timeDomainValue, "VProbTimeDomainValue");
}

void VoltageProb::saveFreqDomainValue(){
	save1DArray<std::complex<double>>(frequencyDomainValue, "VProbFrequencyDomainValue");
}

void VoltageProb::time2freq(double *freqArray){
	frequencies = freqArray;
	frequencyDomainValue = timeDomain2frequencyDomain(timeDomainValue, time, frequencies, 0.0);
}

void VoltageProb::saveTime(){
	save1DArray<double>(time, "VProbTime");
}

void VoltageProb::saveFreq(){
	save1DArray<double>(frequencies, "VProbFrequencies");
}

std::complex<double> VoltageProb::getFreqDomainValue(int index){
	return this->frequencyDomainValue[index];
}
