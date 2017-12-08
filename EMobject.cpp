#include "EMobject.h"

EMobject::EMobject(){
	this->nx = 1;
	this->ny = 1;
	this->nz = 1;
}

EMobject::EMobject(int nx, int ny, int nz, Cell c)
{
	this->nx = nx;
	this->ny = ny;
	this->nz = nz;
	this->c = c;
}


EMobject::~EMobject()
{
}

double EMobject::getCexe(int x, int y, int z){
	return this->Cexe[x][y][z];
}

double EMobject::getCexhz(int x, int y, int z){
	return this->Cexhz[x][y][z];
}

double EMobject::getCexhy(int x, int y, int z){
	return this->Cexhy[x][y][z];
}

double EMobject::getCeye(int x, int y, int z){
	return this->Ceye[x][y][z];
}

double EMobject::getCeyhx(int x, int y, int z){
	return this->Ceyhx[x][y][z];
}

double EMobject::getCeyhz(int x, int y, int z){
	return this->Ceyhz[x][y][z];
}

double EMobject::getCeze(int x, int y, int z){
	return this->Ceze[x][y][z];
}

double EMobject::getCezhy(int x, int y, int z){
	return this->Cezhy[x][y][z];
}

double EMobject::getCezhx(int x, int y, int z){
	return this->Cezhx[x][y][z];
}

double EMobject::getChxh(int x, int y, int z){
	return this->Chxh[x][y][z];
}

double EMobject::getChxez(int x, int y, int z){
	return this->Chxez[x][y][z];
}

double EMobject::getChxey(int x, int y, int z){
	return this->Chxey[x][y][z];
}

double EMobject::getChyh(int x, int y, int z){
	return this->Chyh[x][y][z];
}

double EMobject::getChyex(int x, int y, int z){
	return this->Chyex[x][y][z];
}

double EMobject::getChyez(int x, int y, int z){
	return this->Chyez[x][y][z];
}

double EMobject::getChzh(int x, int y, int z){
	return this->Chzh[x][y][z];
}

double EMobject::getChzey(int x, int y, int z){
	return this->Chzey[x][y][z];
}

double EMobject::getChzex(int x, int y, int z){
	return this->Chzex[x][y][z];
}

/////

void EMobject::setCexe(int x, int y, int z, double value){
	this->Cexe[x][y][z] = value;
}

void EMobject::setCexhz(int x, int y, int z, double value){
	this->Cexhz[x][y][z] = value;
}

void EMobject::setCexhy(int x, int y, int z, double value){
	this->Cexhy[x][y][z] = value;
}

void EMobject::setCeye(int x, int y, int z, double value){
	this->Ceye[x][y][z] = value;
}

void EMobject::setCeyhx(int x, int y, int z, double value){
	this->Ceyhx[x][y][z] = value;
}

void EMobject::setCeyhz(int x, int y, int z, double value){
	this->Ceyhz[x][y][z] = value;
}

void EMobject::setCeze(int x, int y, int z, double value){
	this->Ceze[x][y][z] = value;
}

void EMobject::setCezhy(int x, int y, int z, double value){
	this->Cezhy[x][y][z] = value;
}

void EMobject::setCezhx(int x, int y, int z, double value){
	this->Cezhx[x][y][z] = value;
}

void EMobject::setChxh(int x, int y, int z, double value){
	this->Chxh[x][y][z] = value;
}

void EMobject::setChxez(int x, int y, int z, double value){
	this->Chxez[x][y][z] = value;
}

void EMobject::setChxey(int x, int y, int z, double value){
	this->Chxey[x][y][z] = value;
}

void EMobject::setChyh(int x, int y, int z, double value){
	this->Chyh[x][y][z] = value;
}

void EMobject::setChyex(int x, int y, int z, double value){
	this->Chyex[x][y][z] = value;
}

void EMobject::setChyez(int x, int y, int z, double value){
	this->Chyez[x][y][z] = value;
}

void EMobject::setChzh(int x, int y, int z, double value){
	this->Chzh[x][y][z] = value;
}

void EMobject::setChzey(int x, int y, int z, double value){
	this->Chzey[x][y][z] = value;
}

void EMobject::setChzex(int x, int y, int z, double value){
	this->Chzex[x][y][z] = value;
}