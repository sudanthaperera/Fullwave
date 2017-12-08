#include "Cell.h"


Cell::Cell()
{
  this->deltaX = 1e-3;
  this->deltaY = 1e-3;
  this->deltaZ = 1e-3;
}

Cell::Cell(double deltaX, double deltaY, double deltaZ)
{
  this->deltaX = deltaX;
  this->deltaY = deltaY;
  this->deltaZ = deltaZ;
  this->deltaT = 1.0e-12;
}

Cell::~Cell()
{
}

double Cell::getDeltaT(){
  return this->deltaT;
}

void Cell::setDeltaT(double courantFactor, double speed){
  this->deltaT = courantFactor / (speed*std::sqrt((1 / (std::pow(deltaX, 2))) + (1 / (std::pow(deltaY, 2))) + (1 / (std::pow(deltaZ, 2)))));
}

double Cell::getDeltaX(){
  return this->deltaX;
}

double Cell::getDeltaY(){
  return this->deltaY;
}

double Cell::getDeltaZ(){
  return this->deltaZ;
}

void Cell::setDeltaX(double Value){
  this->deltaX = Value;
}

void Cell::setDeltaY(double Value){
  this->deltaY = Value;
}

void Cell::setDeltaZ(double Value){
  this->deltaZ = Value;
}

double Cell::getMax(){
  return std::fmax(deltaX, std::fmax(deltaY, deltaZ));
}
