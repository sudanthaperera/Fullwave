#include "Source.h"

Source::Source(){

}

Source::Source(double Xmax, double Ymax, double Zmax, double Xmin, double Ymin, double Zmin, Cell c)
{
	EMobject::EMobject(1, 1, 1, c);
	this->Xmax = Xmax;
	this->Ymax = Ymax;
	this->Zmax = Zmax;
	this->Xmin = Xmin;
	this->Ymin = Ymin;
	this->Zmin = Zmin;
}


Source::~Source()
{
}
