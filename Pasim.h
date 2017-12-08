#pragma once
#include <ctime>
#include "HField.h"
#include "EField.h"
#include "PMLmedia.h"
#include "VoltageSource.h"
#include "CurrentSource.h"
#include "VoltageProb.h"
#include "CurrentProb.h"
#include "Gaussian.h"
#include "HFieldProb.h"
#include "EFieldProb.h"
#include "Port.h"
#include "FarField.h"
#include "FrequencyDomain.h"

class Pasim
{
private:
	int timeSteps;
	double courantFactor;
	int brickCount, eFieldProbCount, hFieldProbCount, voltageProbCount, currentProbCount, portCount, gaussianWaveformCount;
	double speed;
	double eta0;
	double *time;

	HField H;
	EField E;
	ProblemSpace ps;
	PMLmedia pml;
	Cell c;
	Boundary b;
	Material *m;
	Brick *bricks;
	VoltageSource *vs;
	CurrentSource *cs;
	Gaussian *w;
	Position *currentProbPos, *voltageProbPos, *eFieldProbPos, *hFieldProbPos;
	VoltageProb *voltageProbObject;
	CurrentProb *currentProbObject;
	HFieldProb *hProbObject;
	EFieldProb *eProbObject;
	Port *ports;
	FarField ff;
	FrequencyDomain freqDomain;
public:
	Pasim();
	~Pasim();
	void initializeProblemSpace();
	void defineGeometry();
	void defineSources();
	void defineWaveform();
	void defineOutput();

	void initMaterialGrid();
	void initFDTDparams();
	void initFDTDarrays();
	void initSource();
	void initWaveForm();
	void genCoefficients();
	void initParam();
	void run();
	void postProcessing();
	void saveData();
};

