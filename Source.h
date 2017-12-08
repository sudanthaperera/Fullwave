#pragma once

#include "Cell.h"
#include "EMobject.h"

class Source : 
	public EMobject
{
protected:
	double Xmin, Ymin, Zmin, Xmax, Ymax, Zmax;
	int is, js, ks, ie, je, ke;
	int direction;

public:
	Source::Source();
	Source(double Xmax, double Ymax, double Zmax, double Xmin, double Ymin, double Zmin, Cell c);
	~Source();
};

