#pragma once
#include "Brick.h"
#include "Boundary.h"
#include "MaterialGrid.h"
#include "Cell.h"
#include "Common.h"
#include <cmath>
#include <iostream>

class ProblemSpace
{
private:
	double Xmin = 10000;
	double Ymin = 10000;
	double Zmin = 10000;
	double Xmax = -10000;
	double Ymax = -10000;
	double Zmax = -10000;
	double sizeX;
	double sizeY;
	double sizeZ;
	int nx, ny, nz;
	int*** ms;
	Brick* bricks;
	int brickCount;
	Cell c;
	Boundary b;
	MaterialGrid mg;
	Material* m;
	int blx, bly, blz, bux, buy, buz;
public:
	ProblemSpace(int brickCount, Brick* bricks, Cell c, Boundary b, Material* m);
	ProblemSpace();
	~ProblemSpace();
	MaterialGrid getMaterialGrid();
	double getXmax();
	double getYmax();
	double getZmax();
	double getXmin();
	double getYmin();
	double getZmin();
	int getNX();
	int getNY();
	int getNZ();
	void initMaterialGrid();
};

