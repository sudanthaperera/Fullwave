#include "Brick.h"


Brick::Brick(double Xmin, double Ymin, double Zmin, double Xmax, double Ymax, double Zmax, Material *material)
{
  Shape3D::Shape3D(material);
  this->Xmin = Xmin;
  this->Ymin = Ymin;
  this->Zmin = Zmin;
  this->Xmax = Xmax;
  this->Ymax = Ymax;
  this->Zmax = Zmax;
}


Brick::~Brick()
{
}

double Brick::getXmin(){
  return Xmin;
}

double Brick::getYmin(){
  return Ymin;
}

double Brick::getZmin(){
  return Zmin;
}

double Brick::getXmax(){
  return Xmax;
}

double Brick::getYmax(){
  return Ymax;
}

double Brick::getZmax(){
  return Zmax;
}

int Brick::getMaterialType(){
  return this->material->index();
}

void Brick::setXmin(double value){
  Xmin = value;
}

void Brick::setYmin(double value){
  Ymin = value;
}

void Brick::setZmin(double value){
  Zmin = value;
}

void Brick::setXmax(double value){
  Xmax = value;
}

void Brick::setYmax(double value){
  Ymax = value;
}

void Brick::setZmax(double value){
  Zmax = value;
}

Material* Brick::getMaterial(){
  return this->material;
}
