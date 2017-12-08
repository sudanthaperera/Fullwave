#pragma once
class WaveForm
{
private:
	int cellsPerWavelength;
	double amplitude;
	double phaseShift;
	double* waveform;
public:
	WaveForm();
	WaveForm(int cellsPerWavelength, double amplitude, double phaseShift, int timeSteps);
	~WaveForm();
	void buildWave(int timeSteps);
	int getCellsPerWavelength();
	void setCellsPerWavelength(int cellsPerWavelength);
	void set(double value, int index);
	double get(int index);
};

