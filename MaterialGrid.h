#pragma once
#include "EMobject.h"
#include "Material.h"
#include "Common.h"
#include "Cell.h"

class MaterialGrid :
	public EMobject
{
private:
	Material* m;
	int*** index;
	double ***epsrX, ***epsrY, ***epsrZ, ***murX, ***murY, ***murZ, ***sigmaeX, ***sigmaeY, ***sigmaeZ, ***sigmamX, ***sigmamY, ***sigmamZ;
public:
	MaterialGrid();
	MaterialGrid(int nx, int ny, int nz, Cell c, Material* m, int*** index);
	~MaterialGrid();
	void averageAll();
	void setAll();
	void setAllEpsRX(double val);
	void setAllEpsRY(double val);
	void setAllEpsRZ(double val);
	void setAllMuRX(double val);
	void setAllMuRY(double val);
	void setAllMuRZ(double val);
	void setAllSigmaEX(double val);
	void setAllSigmaEY(double val);
	void setAllSigmaEZ(double val);
	void setAllSigmaMX(double val);
	void setAllSigmaMY(double val);
	void setAllSigmaMZ(double val);
	double getEpsRX(int x, int y, int z);
	double getEpsRY(int x, int y, int z);
	double getEpsRZ(int x, int y, int z);
	double getMuRX(int x, int y, int z);
	double getMuRY(int x, int y, int z);
	double getMuRZ(int x, int y, int z);
	double getSigmaEX(int x, int y, int z);
	double getSigmaEY(int x, int y, int z);
	double getSigmaEZ(int x, int y, int z);
	double getSigmaMX(int x, int y, int z);
	double getSigmaMY(int x, int y, int z);
	double getSigmaMZ(int x, int y, int z);
	void setEpsRX(int x, int y, int z, double val);
	void setEpsRY(int x, int y, int z, double val);
	void setEpsRZ(int x, int y, int z, double val);
	void setMuRX(int x, int y, int z, double val);
	void setMuRY(int x, int y, int z, double val);
	void setMuRZ(int x, int y, int z, double val);
	void setSigmaEX(int x, int y, int z, double val);
	void setSigmaEY(int x, int y, int z, double val);
	void setSigmaEZ(int x, int y, int z, double val);
	void setSigmaMX(int x, int y, int z, double val);
	void setSigmaMY(int x, int y, int z, double val);
	void setSigmaMZ(int x, int y, int z, double val);
	void averageMuX();
	void averageMuY();
	void averageMuZ();
	void averageSigmaMX();
	void averageSigmaMY();
	void averageSigmaMZ();
	void averageEpsX();
	void averageEpsY();
	void averageEpsZ();
	void averageSigmaEX();
	void averageSigmaEY();
	void averageSigmaEZ();
};

