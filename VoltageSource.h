#pragma once
#include "Source.h"
#include "ProblemSpace.h"

class VoltageSource :
	public Source
{
private:
	double resistance;
	double magnitude;
	int waveformType;
	int waveformIndex;
	double resistancePerComponent = 1e-20;
	double *voltagePerEfield;
	double *waveform;
	double ***Cezs;
	double ***Ceys;
	double ***Cexs;
	std::complex<double> *freqDomainValue;
	double *frequencies;
public:
	static int voltageSourceCount;
	VoltageSource();
	~VoltageSource();
	VoltageSource(double Xmin, double Ymin, double Zmin, double Xmax, double Ymax, double Zmax, Cell c);
	void updateVoltageSourceEfiled(int timeIndex);
	void initVoltagePerEfield(int timeSteps);
	void initWaveform(int timeSteps);
	void setVoltagePerEfield(int index, double value);
	void setWaveform(int index, double value);
	void setIS(int is);
	void setJS(int js);
	void setKS(int ks);
	void setIE(int ie);
	void setJE(int je);
	void setKE(int ke);
	void setDirection(int direction);
	int getDirection();
	double getMagnitude();
	double getXmax();
	double getXmin();
	double getYmax();
	double getYmin();
	double getZmax();
	double getZmin();
	double getResistancePerComponent();
	void setResistancePerComponent(double resistance_per_component);
	void setResistance(double resistance);
	void setMagnitude(double magnitude);
	double getResistance();
	void updatingCoefficients(ProblemSpace ps);
};

