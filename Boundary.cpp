#include "Boundary.h"


Boundary::Boundary()
{
  this->setAirBuffer(10, 10, 10, 10, 10, 10);
  this->setBoundaryType(true, true, true, true, true, true);
  this->setCpmlCellNumber(8, 8, 8, 8, 8, 8);
  this->setCpmlParam(3, 1.3, 7.0, 0.0, 0.05);
}

Boundary::~Boundary()
{
}

void Boundary::setAirBuffer(int airBufferXn, int airBufferXp, int airBufferYn, int airBufferYp, int airBufferZn, int airBufferZp){
  this->airBufferXn = airBufferXn;
  this->airBufferXp = airBufferXp;
  this->airBufferYn = airBufferYn;
  this->airBufferYp = airBufferYp;
  this->airBufferZn = airBufferZn;
  this->airBufferZp = airBufferZp;
}

void Boundary::setCpmlCellNumber(int cpmlCellsXn, int cpmlCellsXp, int cpmlCellsYn, int cpmlCellsYp, int cpmlCellsZn, int cpmlCellsZp){
  this->cpmlCellsXn = cpmlCellsXn;
  this->cpmlCellsXp = cpmlCellsXp;
  this->cpmlCellsYn = cpmlCellsYn;
  this->cpmlCellsYp = cpmlCellsYp;
  this->cpmlCellsZn = cpmlCellsZn;
  this->cpmlCellsZp = cpmlCellsZp;
}

void Boundary::setCpmlParam(int order, double sigmaFactor, double kappaMax, double alphaMin, double alphaMax){
  this->order = order;
  this->sigmaFactor = sigmaFactor;
  this->kappaMax = kappaMax;
  this->alphaMin = alphaMin;
  this->alphaMax = alphaMax;
}

void Boundary::setBoundaryType(bool cpmlXn, bool cpmlXp, bool cpmlYn, bool cpmlYp, bool cpmlZn, bool cpmlZp){
  this->cpmlXn = cpmlXn;
  this->cpmlXp = cpmlXp;
  this->cpmlYn = cpmlYn;
  this->cpmlYp = cpmlYp;
  this->cpmlZn = cpmlZn;
  this->cpmlZp = cpmlZp;
}

int Boundary::getAirBufferCellCountXn(){
  return this->airBufferXn;
}

int Boundary::getAirBufferCellCountYn(){
  return this->airBufferYn;
}

int Boundary::getAirBufferCellCountZn(){
  return this->airBufferZn;
}

int Boundary::getAirBufferCellCountXp(){
  return this->airBufferXp;
}

int Boundary::getAirBufferCellCountYp(){
  return this->airBufferYp;
}

int Boundary::getAirBufferCellCountZp(){
  return this->airBufferZp;
}

bool Boundary::getCPMLxn(){
  return this->cpmlXn;
}

bool Boundary::getCPMLxp(){
  return this->cpmlXp;
}

bool Boundary::getCPMLyn(){
  return this->cpmlYn;
}

bool Boundary::getCPMLyp(){
  return this->cpmlYp;
}

bool Boundary::getCPMLzn(){
  return this->cpmlZn;
}

bool Boundary::getCPMLzp(){
  return this->cpmlZn;
}

bool Boundary::isAnySideCPML(){
  return cpmlXn | cpmlXp | cpmlYn | cpmlYp | cpmlZn | cpmlZp;
}

int Boundary::getCellCountXn(){
  return this->cpmlCellsXn;
}

int Boundary::getCellCountXp(){
  return this->cpmlCellsXp;
}

int Boundary::getCellCountYn(){
  return this->cpmlCellsYn;
}

int Boundary::getCellCountYp(){
  return this->cpmlCellsYp;
}

int Boundary::getCellCountZn(){
  return this->cpmlCellsZn;
}

int Boundary::getCellCountZp(){
  return this->cpmlCellsZp;
}

int Boundary::getOrder(){
  return order;
}

double Boundary::getSigmaFactor(){
  return sigmaFactor;
}

double Boundary::getKappaMax(){
  return kappaMax;
}

double Boundary::getKappaMin(){
  return alphaMin;
}

double Boundary::getAlphaMax(){
  return alphaMax;
}
