#pragma once
#include "Shape3D.h"
#include "Material.h"

class Brick :
public Shape3D
{
 private: 
  double Xmin, Ymin, Zmin, Xmax, Ymax, Zmax;
 public:
  Brick(double Xmin, double Ymin, double Zmin, double Xmax, double Ymax, double Zmax, Material* material);
  ~Brick();
  double getXmin();
  double getYmin();
  double getZmin();
  double getXmax();
  double getYmax();
  double getZmax();
  int getMaterialType();
  void setXmin(double value);
  void setYmin(double value);
  void setZmin(double value);
  void setXmax(double value);
  void setYmax(double value);
  void setZmax(double value);
  Material* getMaterial();
};

