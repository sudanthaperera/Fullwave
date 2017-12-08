#pragma once
#include "Field.h"
#include <iostream>

class EField :
	public Field
{
public:
	EField();
	EField(int nx, int ny, int nz, Cell c);
	~EField();
	void updatingCoefficients(ProblemSpace ps);

	void setAllX(double val);
	void setAllY(double val);
	void setAllZ(double val);
	void updateEField();
	double getEx(int i, int j, int k);
	double getEy(int i, int j, int k);
	double getEz(int i, int j, int k);
};

