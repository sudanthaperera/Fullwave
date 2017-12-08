#pragma once
#include <cmath>

class Cell
{
 private:
  double deltaX;
  double deltaY;
  double deltaZ;
  double deltaT;
 public:
  Cell();
  Cell(double deltaX, double deltaY, double deltaZ);
  ~Cell();
  double getDeltaX();
  double getDeltaY();
  double getDeltaZ();
  double getDeltaT();
  void setDeltaT(double courantFactor, double speed);
  void setDeltaX(double Value);
  void setDeltaY(double Value);
  void setDeltaZ(double Value);
  double getMax();
};

