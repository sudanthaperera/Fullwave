#pragma once
#include "EMobject.h"
#include "Position.h"

class Prob :
	public EMobject
{
protected:
	double x, y, z, Xmin, Ymin, Zmin, Xmax, Ymax, Zmax;
public:
	Prob();
	Prob(Position probPos);
	~Prob();
};

