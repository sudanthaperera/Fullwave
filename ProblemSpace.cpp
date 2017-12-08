#include "ProblemSpace.h"

ProblemSpace::ProblemSpace(){

}

ProblemSpace::ProblemSpace(int brickCount, Brick* bricks, Cell c, Boundary b, Material* m)
{
	this->brickCount = brickCount;
	this->bricks = bricks;
	this->c = c;
	this->b = b;
	this->m = m;

	for (int i = 0; i < brickCount; i++)
	{
		if (this->Xmin > bricks[i].getXmin())
			this->Xmin = bricks[i].getXmin();
		if (this->Ymin > bricks[i].getYmin())
			this->Ymin = bricks[i].getYmin();
		if (this->Zmin > bricks[i].getZmin())
			this->Zmin = bricks[i].getZmin();
		if (this->Xmax < bricks[i].getXmax())
			this->Xmax = bricks[i].getXmax();
		if (this->Ymax < bricks[i].getYmax())
			this->Ymax = bricks[i].getYmax();
		if (this->Zmax < bricks[i].getZmax())
			this->Zmax = bricks[i].getZmax();
	}

	this->Xmin = this->Xmin - c.getDeltaX() * b.getAirBufferCellCountXn();
	this->Ymin = this->Ymin - c.getDeltaY() * b.getAirBufferCellCountYn();
	this->Zmin = this->Zmin - c.getDeltaZ() * b.getAirBufferCellCountZn();
	this->Xmax = this->Xmax + c.getDeltaX() * b.getAirBufferCellCountXp();
	this->Ymax = this->Ymax + c.getDeltaY() * b.getAirBufferCellCountYp();
	this->Zmax = this->Zmax + c.getDeltaZ() * b.getAirBufferCellCountZp();

	sizeX = this->Xmax - this->Xmin;
	sizeY = this->Ymax - this->Ymin;
	sizeZ = this->Zmax - this->Zmin;

	this->nx = (int)std::round(sizeX / c.getDeltaX());
	this->ny = (int)std::round(sizeY / c.getDeltaY());
	this->nz = (int)std::round(sizeZ / c.getDeltaZ());

	sizeX = nx*c.getDeltaX();
	sizeY = ny*c.getDeltaY();
	sizeZ = nz*c.getDeltaZ();

	this->Xmax = this->Xmin + sizeX;
	this->Ymax = this->Ymin + sizeY;
	this->Zmax = this->Zmin + sizeZ;
}

ProblemSpace::~ProblemSpace()
{
}

MaterialGrid ProblemSpace::getMaterialGrid(){
	return this->mg;
}

double ProblemSpace::getXmax(){
	return this->Xmax;
}

double ProblemSpace::getYmax(){
	return this->Ymax;
}

double ProblemSpace::getZmax(){
	return this->Zmax;
}

double ProblemSpace::getXmin(){
	return this->Xmin;
}

double ProblemSpace::getYmin(){
	return this->Ymin;
}

double ProblemSpace::getZmin(){
	return this->Zmin;
}

int ProblemSpace::getNX(){
	return this->nx;
}

int ProblemSpace::getNY(){
	return this->ny;
}

int ProblemSpace::getNZ(){
	return this->nz;
}

void ProblemSpace::initMaterialGrid(){
	this->ms = gen3DArray<int>(nx, ny, nz, 1);
	double sigmaPEC;
	std::cout<<"assign material type of the brick to the cells..."<<std::endl;
	for (int index = 0; index < this->brickCount; index++){
		//convert brick end coordinates to node indices 
		blx = (int)std::round((this->bricks[index].getXmin() - this->Xmin) / c.getDeltaX());
		bly = (int)std::round((this->bricks[index].getYmin() - this->Ymin) / c.getDeltaY());
		blz = (int)std::round((this->bricks[index].getZmin() - this->Zmin) / c.getDeltaZ());

		bux = (int)std::round((this->bricks[index].getXmax() - this->Xmin) / c.getDeltaX());
		buy = (int)std::round((this->bricks[index].getYmax() - this->Ymin) / c.getDeltaY());
		buz = (int)std::round((this->bricks[index].getZmax() - this->Zmin) / c.getDeltaZ());

		for (int i = blx; i < bux; i++){
			for (int j = bly; j < buy; j++){
				for (int k = blz; k < buz; k++){
					this->ms[i][j][k] = this->bricks[index].getMaterialType();
				}
			}
		}
	}

	mg = *(new MaterialGrid(this->nx, this->ny, this->nz, c, m, this->ms));
	mg.setAll();
	mg.averageAll();

	std::cout<<"find the zero thickness bricks..."<<std::endl;
	for (int index = 0; index < this->brickCount; index++){
		sigmaPEC = this->m[this->bricks[index].getMaterialType()].sigmaE();

		//convert brick end coordinates to node indices 
		blx = (int)std::round((this->bricks[index].getXmin() - this->Xmin) / c.getDeltaX());
		bly = (int)std::round((this->bricks[index].getYmin() - this->Ymin) / c.getDeltaY());
		blz = (int)std::round((this->bricks[index].getZmin() - this->Zmin) / c.getDeltaZ());

		bux = (int)std::round((this->bricks[index].getXmax() - this->Xmin) / c.getDeltaX());
		buy = (int)std::round((this->bricks[index].getYmax() - this->Ymin) / c.getDeltaY());
		buz = (int)std::round((this->bricks[index].getZmax() - this->Zmin) / c.getDeltaZ());

		if (blx == bux){
			for (int indexBy = bly; indexBy <= buy; indexBy++){
				for (int indexBz = blz; indexBz <= buz; indexBz++){
					if (indexBy < buy){
						mg.setSigmaEY(blx, indexBy, indexBz, sigmaPEC);
					}
					if (indexBz < buz){
						mg.setSigmaEZ(blx, indexBy, indexBz, sigmaPEC);
					}
				}
			}
		}

		if (bly == buy){
			for (int indexBx = blx; indexBx <= bux; indexBx++){
				for (int indexBz = blz; indexBz <= buz; indexBz++){
					if (indexBz < buz){
						mg.setSigmaEZ(indexBx, bly, indexBz, sigmaPEC);
					}
					if (indexBx < bux){
						mg.setSigmaEX(indexBx, bly, indexBz, sigmaPEC);
					}
				}
			}
		}

		if (blz == buz){
			for (int indexBx = blx; indexBx <= bux; indexBx++){
				for (int indexBy = bly; indexBy <= buy; indexBy++){
					if (indexBx < bux){
						mg.setSigmaEX(indexBx, indexBy, blz, sigmaPEC);
					}
					if (indexBy < buy){
						mg.setSigmaEY(indexBx, indexBy, blz, sigmaPEC);
					}
				}
			}
		}
	}
}
