#pragma once
#include "VoltageProb.h"
#include "CurrentProb.h"

class Port
{
private:
	VoltageProb probV;
	CurrentProb probI;
	std::complex<double> impedance;
	bool srcPort;
	std::complex<double> **S;
	std::complex<double> *a, *b;
	double *frequencies;
public:
	Port();
	Port(double impedance, bool isSourcePort);
	Port(std::complex<double> impedance, bool isSourcePort);
	~Port();
	void setVProb(VoltageProb probV);
	bool isSourcePort();
	void setIProb(CurrentProb probI);
	void saveSParam();
	void calAB(double *frequencies);
	void calSparam(Port *ports);
};

