#include "Field.h"


Field::Field()
{
}

Field::Field(int nx, int ny, int nz, Cell c){
	EMobject::EMobject(nx, ny, nz, c);
	this->dt = c.getDeltaT();
}


Field::~Field()
{
}

void Field::setHX(int xIndex, int yIndex, int zIndex, double val){
	Hx[xIndex][yIndex][zIndex] = val;
}

void Field::setHY(int xIndex, int yIndex, int zIndex, double val){
	Hy[xIndex][yIndex][zIndex] = val;
}

void Field::setHZ(int xIndex, int yIndex, int zIndex, double val){
	Hz[xIndex][yIndex][zIndex] = val;
}

double Field::getHX(int xIndex, int yIndex, int zIndex){
	return Hx[xIndex][yIndex][zIndex];
}

double Field::getHY(int xIndex, int yIndex, int zIndex){
	return Hy[xIndex][yIndex][zIndex];
}

double Field::getHZ(int xIndex, int yIndex, int zIndex){
	return Hz[xIndex][yIndex][zIndex];
}


void Field::setEX(int xIndex, int yIndex, int zIndex, double val){
	Ex[xIndex][yIndex][zIndex] = val;
}

void Field::setEY(int xIndex, int yIndex, int zIndex, double val){
	Ey[xIndex][yIndex][zIndex] = val;
}

void Field::setEZ(int xIndex, int yIndex, int zIndex, double val){
	Ez[xIndex][yIndex][zIndex] = val;
}

double Field::getEX(int xIndex, int yIndex, int zIndex){
	return Ex[xIndex][yIndex][zIndex];
}

double Field::getEY(int xIndex, int yIndex, int zIndex){
	return Ey[xIndex][yIndex][zIndex];
}

double Field::getEZ(int xIndex, int yIndex, int zIndex){
	return Ez[xIndex][yIndex][zIndex];
}
