#pragma once
class Boundary
{
 private:
  bool cpmlXn, cpmlXp, cpmlYn, cpmlYp, cpmlZn, cpmlZp;
  int airBufferXn, airBufferXp, airBufferYn, airBufferYp, airBufferZn, airBufferZp;
  int cpmlCellsXn, cpmlCellsXp, cpmlCellsYn, cpmlCellsYp, cpmlCellsZn, cpmlCellsZp;
  int order;
  double sigmaFactor;
  double kappaMax;
  double alphaMin;
  double alphaMax;
 public:
  Boundary();
  ~Boundary();
  void setAirBuffer(int airBufferXn, int airBufferXp, int airBufferYn, int airBufferYp, int airBufferZn, int airBufferZp);
  void setCpmlCellNumber(int cpmlCellsXn, int cpmlCellsXp, int cpmlCellsYn, int cpmlCellsYp, int cpmlCellsZn, int cpmlCellsZp);
  void setCpmlParam(int order, double sigmaFactor, double kappaMax, double alphaMin, double alphaMax);
  void setBoundaryType(bool cpmlXn, bool cpmlXp, bool cpmlYn, bool cpmlYp, bool cpmlZn, bool cpmlZp);
  int getAirBufferCellCountXn();
  int getAirBufferCellCountXp();
  int getAirBufferCellCountYn();
  int getAirBufferCellCountYp();
  int getAirBufferCellCountZn();
  int getAirBufferCellCountZp();
  bool getCPMLxn();
  bool getCPMLxp();
  bool getCPMLyn();
  bool getCPMLyp();
  bool getCPMLzn();
  bool getCPMLzp();
  bool isAnySideCPML();
  int getCellCountXn();
  int getCellCountXp();
  int getCellCountYn();
  int getCellCountYp();
  int getCellCountZn();
  int getCellCountZp();
  int getOrder();
  double getSigmaFactor();
  double getKappaMax();
  double getKappaMin();
  double getAlphaMax();
};

