#pragma once
#include "EMobject.h"
#include "ProblemSpace.h"

class FarField :
	public EMobject
{
private: 
	double *frequencies, *omegas;;
	int outerBoundaryCellCount, angleStepsCount;
	double *radiatedPower;
	int li, lj, lk, ui, uj, uk;
	double *theta, *phi;
	double **farfield_dataTheta;
	double **farfield_dataPhi;

	double ****tjxyp, ****tjxzp, ****tjyxp, ****tjyzp, ****tjzxp, ****tjzyp;
	double ****tjxyn, ****tjxzn, ****tjyxn, ****tjyzn, ****tjzxn, ****tjzyn;
	double ****tmxyp, ****tmxzp, ****tmyxp, ****tmyzp, ****tmzxp, ****tmzyp;
	double ****tmxyn, ****tmxzn, ****tmyxn, ****tmyzn, ****tmzxn, ****tmzyn;
	std::complex<double> ****cjxyp, ****cjxzp, ****cjyxp, ****cjyzp, ****cjzxp, ****cjzyp;
	std::complex<double> ****cjxyn, ****cjxzn, ****cjyxn, ****cjyzn, ****cjzxn, ****cjzyn;
	std::complex<double> ****cmxyp, ****cmxzp, ****cmyxp, ****cmyzp, ****cmzxp, ****cmzyp;
	std::complex<double> ****cmxyn, ****cmxzn, ****cmyxn, ****cmyzn, ****cmzxn, ****cmzyn;

public:
	FarField();
	FarField(double start, double stop, int count);
	~FarField();
	void setupFarFieldOutPut(double *theta, double *phi);
	void saveFarFieldThetaPhiPattern();
	void calFarField();
	void saveTotalRadiatedPower();
	void calTotalRadiatedPower();
	void CalculateJandM(int timeIndex);
	double* getFreqArray();
	double getFreq(int index);
	int getFreqCount();
	void setCellCountOuterBoundary(int count);
	void initFarFieldArrays(ProblemSpace* ps);
};

