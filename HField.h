#pragma once
#include "Field.h"

class HField :
	public Field
{
public:
	HField();
	HField(int nx, int ny, int nz, Cell c);
	~HField();
	void updatingCoefficients(ProblemSpace ps);
	double getHx(int i, int j, int k);
	double getHy(int i, int j, int k);
	double getHz(int i, int j, int k);
	void setAllX(double val);
	void setAllY(double val);
	void setAllZ(double val);
	void updateHField();
};

