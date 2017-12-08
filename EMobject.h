#pragma once
#include "Cell.h"
#include "Common.h"
#include <complex>
#include <cmath>

class EMobject
{
protected:
	static int nx, ny, nz;
	static double*** Hx, ***Hy, ***Hz;
	static double ***Ex, ***Ey, ***Ez;
	static double ***Cexe, ***Cexhz, ***Cexhy, ***Ceye, ***Ceyhx, ***Ceyhz, ***Ceze, ***Cezhy, ***Cezhx;
	static double ***Chxh, ***Chxez, ***Chxey, ***Chyh, ***Chyex, ***Chyez, ***Chzh, ***Chzey, ***Chzex;
	static Cell c;
public:
	EMobject();
	EMobject(int nx, int ny, int nz, Cell c);
	double getCexe(int x, int y, int z);
	double getCexhz(int x, int y, int z);
	double getCexhy(int x, int y, int z);
	double getCeye(int x, int y, int z);
	double getCeyhx(int x, int y, int z);
	double getCeyhz(int x, int y, int z);
	double getCeze(int x, int y, int z);
	double getCezhy(int x, int y, int z);
	double getCezhx(int x, int y, int z);
	double getChxh(int x, int y, int z);
	double getChxez(int x, int y, int z);
	double getChxey(int x, int y, int z);
	double getChyh(int x, int y, int z);
	double getChyex(int x, int y, int z);
	double getChyez(int x, int y, int z);
	double getChzh(int x, int y, int z);
	double getChzey(int x, int y, int z);
	double getChzex(int x, int y, int z);
	void setCexe(int x, int y, int z, double value);
	void setCexhz(int x, int y, int z, double value);
	void setCexhy(int x, int y, int z, double value);
	void setCeye(int x, int y, int z, double value);
	void setCeyhx(int x, int y, int z, double value);
	void setCeyhz(int x, int y, int z, double value);
	void setCeze(int x, int y, int z, double value);
	void setCezhy(int x, int y, int z, double value);
	void setCezhx(int x, int y, int z, double value);
	void setChxh(int x, int y, int z, double value);
	void setChxez(int x, int y, int z, double value);
	void setChxey(int x, int y, int z, double value);
	void setChyh(int x, int y, int z, double value);
	void setChyex(int x, int y, int z, double value);
	void setChyez(int x, int y, int z, double value);
	void setChzh(int x, int y, int z, double value);
	void setChzey(int x, int y, int z, double value);
	void setChzex(int x, int y, int z, double value);
	~EMobject();
};

