#include "Prob.h"

Prob::Prob(){

}

Prob::Prob(Position probPos)
{
	this->x = probPos.x;
	this->y = probPos.y;
	this->z = probPos.z;

	this->Xmin = this->x;
	this->Ymin = this->y;
	this->Zmin = this->z;

	this->Xmax = this->x;
	this->Ymax = this->y;
	this->Zmax = this->z;
}


Prob::~Prob()
{
}
