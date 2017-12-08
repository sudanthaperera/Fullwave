#pragma once
#include "EMobject.h"
#include "ProblemSpace.h"

class Field :
	public EMobject
{
protected:
	double dt;
public:
	Field();
	Field(int nx, int ny, int nz, Cell c);
	~Field();

	static void setHX(int xIndex, int yIndex, int zIndex, double val);
	static void setHY(int xIndex, int yIndex, int zIndex, double val);
	static void setHZ(int xIndex, int yIndex, int zIndex, double val);
	static double getHX(int xIndex, int yIndex, int zIndex);
	static double getHY(int xIndex, int yIndex, int zIndex);
	static double getHZ(int xIndex, int yIndex, int zIndex);
	static void setEX(int xIndex, int yIndex, int zIndex, double val);
	static void setEY(int xIndex, int yIndex, int zIndex, double val);
	static void setEZ(int xIndex, int yIndex, int zIndex, double val);
	static double getEX(int xIndex, int yIndex, int zIndex);
	static double getEY(int xIndex, int yIndex, int zIndex);
	static double getEZ(int xIndex, int yIndex, int zIndex);
};

