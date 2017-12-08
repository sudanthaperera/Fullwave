#include "MaterialGrid.h"

MaterialGrid::MaterialGrid(){

}

MaterialGrid::MaterialGrid(int nx, int ny, int nz, Cell c, Material* m, int*** index)
{
	EMobject::EMobject(nx, ny, nz, c);
	this->index = index;
	this->m = m;
	this->epsrX = gen3DArray<double>(nx, ny + 1, nz + 1, 0.0);
	this->epsrY = gen3DArray<double>(nx + 1, ny, nz + 1, 0.0);
	this->epsrZ = gen3DArray<double>(nx + 1, ny + 1, nz, 0.0);
	this->murX = gen3DArray<double>(nx + 1, ny, nz, 0.0);
	this->murY = gen3DArray<double>(nx, ny + 1, nz, 0.0);
	this->murZ = gen3DArray<double>(nx, ny, nz + 1, 0.0);
	this->sigmaeX = gen3DArray<double>(nx, ny + 1, nz + 1, 0.0);
	this->sigmaeY = gen3DArray<double>(nx + 1, ny, nz + 1, 0.0);
	this->sigmaeZ = gen3DArray<double>(nx + 1, ny + 1, nz, 0.0);
	this->sigmamX = gen3DArray<double>(nx + 1, ny, nz, 0.0);
	this->sigmamY = gen3DArray<double>(nx, ny + 1, nz, 0.0);
	this->sigmamZ = gen3DArray<double>(nx, ny, nz + 1, 0.0);
}


MaterialGrid::~MaterialGrid()
{
}

void MaterialGrid::averageAll(){
	averageEpsX();
	averageEpsY();
	averageEpsZ();

	averageMuX();
	averageMuY();
	averageMuZ();

	averageSigmaEX();
	averageSigmaEY();
	averageSigmaEZ();

	averageSigmaMX();
	averageSigmaMY();
	averageSigmaMZ();
}

void MaterialGrid::setAll(){
	setAllEpsRX(1.0);
	setAllEpsRY(1.0);
	setAllEpsRZ(1.0);

	setAllMuRX(1.0);
	setAllMuRY(1.0);
	setAllMuRZ(1.0);

	setAllSigmaEX(0.0);
	setAllSigmaEY(0.0);
	setAllSigmaEZ(0.0);

	setAllSigmaMX(0.0);
	setAllSigmaMY(0.0);
	setAllSigmaMZ(0.0);
}

void MaterialGrid::setAllEpsRX(double val){
	for (int i = 0; i<nx; i++){
		for (int j = 0; j<ny + 1; j++){
			for (int k = 0; k<nz + 1; k++){
				epsrX[i][j][k] = val;
			}
		}
	}
}

void MaterialGrid::setAllEpsRY(double val){
	for (int i = 0; i<nx + 1; i++){
		for (int j = 0; j<ny; j++){
			for (int k = 0; k<nz + 1; k++){
				epsrY[i][j][k] = val;
			}
		}
	}
}

void MaterialGrid::setAllEpsRZ(double val){
	for (int i = 0; i<nx + 1; i++){
		for (int j = 0; j<ny + 1; j++){
			for (int k = 0; k<nz; k++){
				epsrZ[i][j][k] = val;
			}
		}
	}
}

void MaterialGrid::setAllMuRX(double val){
	for (int i = 0; i<nx + 1; i++){
		for (int j = 0; j<ny; j++){
			for (int k = 0; k<nz; k++){
				murX[i][j][k] = val;
			}
		}
	}
}

void MaterialGrid::setAllMuRY(double val){
	for (int i = 0; i<nx; i++){
		for (int j = 0; j<ny + 1; j++){
			for (int k = 0; k<nz; k++){
				murY[i][j][k] = val;
			}
		}
	}
}

void MaterialGrid::setAllMuRZ(double val){
	for (int i = 0; i<nx; i++){
		for (int j = 0; j<ny; j++){
			for (int k = 0; k<nz + 1; k++){
				murZ[i][j][k] = val;
			}
		}
	}
}

void MaterialGrid::setAllSigmaEX(double val){
	for (int i = 0; i<nx; i++){
		for (int j = 0; j<ny + 1; j++){
			for (int k = 0; k<nz + 1; k++){
				sigmaeX[i][j][k] = val;
			}
		}
	}
}

void MaterialGrid::setAllSigmaEY(double val){
	for (int i = 0; i<nx + 1; i++){
		for (int j = 0; j<ny; j++){
			for (int k = 0; k<nz + 1; k++){
				sigmaeY[i][j][k] = val;
			}
		}
	}
}

void MaterialGrid::setAllSigmaEZ(double val){
	for (int i = 0; i<nx + 1; i++){
		for (int j = 0; j<ny + 1; j++){
			for (int k = 0; k<nz; k++){
				sigmaeZ[i][j][k] = val;
			}
		}
	}
}

void MaterialGrid::setAllSigmaMX(double val){
	for (int i = 0; i<nx + 1; i++){
		for (int j = 0; j<ny; j++){
			for (int k = 0; k<nz; k++){
				sigmamX[i][j][k] = val;
			}
		}
	}
}

void MaterialGrid::setAllSigmaMY(double val){
	for (int i = 0; i<nx; i++){
		for (int j = 0; j<ny + 1; j++){
			for (int k = 0; k<nz; k++){
				sigmamY[i][j][k] = val;
			}
		}
	}
}

void MaterialGrid::setAllSigmaMZ(double val){
	for (int i = 0; i<nx; i++){
		for (int j = 0; j<ny; j++){
			for (int k = 0; k<nz + 1; k++){
				sigmamZ[i][j][k] = val;
			}
		}
	}
}

double MaterialGrid::getEpsRX(int x, int y, int z){
	return epsrX[x][y][z];
}

double MaterialGrid::getEpsRY(int x, int y, int z){
	return epsrY[x][y][z];
}

double MaterialGrid::getEpsRZ(int x, int y, int z){
	return epsrZ[x][y][z];
}

double MaterialGrid::getMuRX(int x, int y, int z){
	return murX[x][y][z];
}

double MaterialGrid::getMuRY(int x, int y, int z){
	return murY[x][y][z];
}

double MaterialGrid::getMuRZ(int x, int y, int z){
	return murZ[x][y][z];
}

double MaterialGrid::getSigmaEX(int x, int y, int z){
	return sigmaeX[x][y][z];
}

double MaterialGrid::getSigmaEY(int x, int y, int z){
	return sigmaeY[x][y][z];
}

double MaterialGrid::getSigmaEZ(int x, int y, int z){
	return sigmaeZ[x][y][z];
}

double MaterialGrid::getSigmaMX(int x, int y, int z){
	return sigmamX[x][y][z];
}

double MaterialGrid::getSigmaMY(int x, int y, int z){
	return sigmamY[x][y][z];
}

double MaterialGrid::getSigmaMZ(int x, int y, int z){
	return sigmamZ[x][y][z];
}

void MaterialGrid::setEpsRX(int x, int y, int z, double val){
	epsrX[x][y][z] = val;
}

void MaterialGrid::setEpsRY(int x, int y, int z, double val){
	epsrY[x][y][z] = val;
}

void MaterialGrid::setEpsRZ(int x, int y, int z, double val){
	epsrZ[x][y][z] = val;
}

void MaterialGrid::setMuRX(int x, int y, int z, double val){
	murX[x][y][z] = val;
}

void MaterialGrid::setMuRY(int x, int y, int z, double val){
	murY[x][y][z] = val;
}

void MaterialGrid::setMuRZ(int x, int y, int z, double val){
	murZ[x][y][z] = val;
}

void MaterialGrid::setSigmaEX(int x, int y, int z, double val){
	sigmaeX[x][y][z] = val;
}

void MaterialGrid::setSigmaEY(int x, int y, int z, double val){
	sigmaeY[x][y][z] = val;
}

void MaterialGrid::setSigmaEZ(int x, int y, int z, double val){
	sigmaeZ[x][y][z] = val;
}

void MaterialGrid::setSigmaMX(int x, int y, int z, double val){
	sigmamX[x][y][z] = val;
}

void MaterialGrid::setSigmaMY(int x, int y, int z, double val){
	sigmamY[x][y][z] = val;
}

void MaterialGrid::setSigmaMZ(int x, int y, int z, double val){
	sigmamZ[x][y][z] = val;
}

void MaterialGrid::averageMuX(){
	int xStart = 1, xEnd = nx;
	int yStart = 0, yEnd = ny;
	int zStart = 0, zEnd = nz;

	for (int i = xStart; i<xEnd; i++){
		for (int j = yStart; j<yEnd; j++){
			for (int k = zStart; k<zEnd; k++){
				murX[i][j][k] = (2.0*(m[index[i][j][k]].muR())*(m[index[i - 1][j][k]].muR())) / (m[index[i][j][k]].muR() + m[index[i - 1][j][k]].muR());
			}
		}
	}
}

void MaterialGrid::averageMuY(){
	int xStart = 0, xEnd = nx;
	int yStart = 1, yEnd = ny;
	int zStart = 0, zEnd = nz;

	for (int i = xStart; i<xEnd; i++){
		for (int j = yStart; j<yEnd; j++){
			for (int k = zStart; k<zEnd; k++){
				murY[i][j][k] = (2.0*(m[index[i][j][k]].muR())*(m[index[i][j - 1][k]].muR())) / (m[index[i][j][k]].muR() + m[index[i][j - 1][k]].muR());
			}
		}
	}
}

void MaterialGrid::averageMuZ(){
	int xStart = 0, xEnd = nx;
	int yStart = 0, yEnd = ny;
	int zStart = 1, zEnd = nz;

	for (int i = xStart; i<xEnd; i++){
		for (int j = yStart; j<yEnd; j++){
			for (int k = zStart; k<zEnd; k++){
				murZ[i][j][k] = (2.0*(m[index[i][j][k]].muR())*(m[index[i][j][k - 1]].muR())) / (m[index[i][j][k]].muR() + m[index[i][j][k - 1]].muR());
			}
		}
	}
}

void MaterialGrid::averageSigmaMX(){
	int xStart = 1, xEnd = nx;
	int yStart = 0, yEnd = ny;
	int zStart = 0, zEnd = nz;

	for (int i = xStart; i<xEnd; i++){
		for (int j = yStart; j<yEnd; j++){
			for (int k = zStart; k<zEnd; k++){
				sigmamX[i][j][k] = (2.0*(m[index[i][j][k]].sigmaM())*(m[index[i - 1][j][k]].sigmaM())) / (m[index[i][j][k]].sigmaM() + m[index[i - 1][j][k]].sigmaM());
			}
		}
	}
}

void MaterialGrid::averageSigmaMY(){
	int xStart = 0, xEnd = nx;
	int yStart = 1, yEnd = ny;
	int zStart = 0, zEnd = nz;

	for (int i = xStart; i<xEnd; i++){
		for (int j = yStart; j<yEnd; j++){
			for (int k = zStart; k<zEnd; k++){
				sigmamY[i][j][k] = (2.0*(m[index[i][j][k]].sigmaM())*(m[index[i][j - 1][k]].sigmaM())) / (m[index[i][j][k]].sigmaM() + m[index[i][j - 1][k]].sigmaM());
			}
		}
	}
}

void MaterialGrid::averageSigmaMZ(){
	int xStart = 0, xEnd = nx;
	int yStart = 0, yEnd = ny;
	int zStart = 1, zEnd = nz;

	for (int i = xStart; i<xEnd; i++){
		for (int j = yStart; j<yEnd; j++){
			for (int k = zStart; k<zEnd; k++){
				sigmamZ[i][j][k] = (2.0*(m[index[i][j][k]].sigmaM())*(m[index[i][j][k - 1]].sigmaM())) / (m[index[i][j][k]].sigmaM() + m[index[i][j][k - 1]].sigmaM());
			}
		}
	}
}

void MaterialGrid::averageEpsX(){
	int xStart = 0, xEnd = nx;
	int yStart = 1, yEnd = ny;
	int zStart = 1, zEnd = nz;

	for (int i = xStart; i<xEnd; i++){
		for (int j = yStart; j<yEnd; j++){
			for (int k = zStart; k<zEnd; k++){
				epsrX[i][j][k] = 0.25*(m[index[i][j][k]].epsR() + m[index[i][j - 1][k]].epsR() + m[index[i][j][k - 1]].epsR() + m[index[i][j - 1][k - 1]].epsR());
			}
		}
	}
}

void MaterialGrid::averageEpsY(){
	int xStart = 1, xEnd = nx;
	int yStart = 0, yEnd = ny;
	int zStart = 1, zEnd = nz;

	for (int i = xStart; i<xEnd; i++){
		for (int j = yStart; j<yEnd; j++){
			for (int k = zStart; k<zEnd; k++){
				epsrY[i][j][k] = 0.25*(m[index[i][j][k]].epsR() + m[index[i - 1][j][k]].epsR() + m[index[i][j][k - 1]].epsR() + m[index[i - 1][j][k - 1]].epsR());
			}
		}
	}
}

void MaterialGrid::averageEpsZ(){
	int xStart = 1, xEnd = nx;
	int yStart = 1, yEnd = ny;
	int zStart = 0, zEnd = nz;

	for (int i = xStart; i<xEnd; i++){
		for (int j = yStart; j<yEnd; j++){
			for (int k = zStart; k<zEnd; k++){
				epsrZ[i][j][k] = 0.25*(m[index[i][j][k]].epsR() + m[index[i - 1][j][k]].epsR() + m[index[i][j - 1][k]].epsR() + m[index[i - 1][j - 1][k]].epsR());
			}
		}
	}
}

void MaterialGrid::averageSigmaEX(){
	int xStart = 0, xEnd = nx;
	int yStart = 1, yEnd = ny;
	int zStart = 1, zEnd = nz;

	for (int i = xStart; i<xEnd; i++){
		for (int j = yStart; j<yEnd; j++){
			for (int k = zStart; k<zEnd; k++){
				sigmaeX[i][j][k] = 0.25*(m[index[i][j][k]].sigmaE() + m[index[i][j - 1][k]].sigmaE() + m[index[i][j][k - 1]].sigmaE() + m[index[i][j - 1][k - 1]].sigmaE());
			}
		}
	}
}

void MaterialGrid::averageSigmaEY(){
	int xStart = 1, xEnd = nx;
	int yStart = 0, yEnd = ny;
	int zStart = 1, zEnd = nz;

	for (int i = xStart; i<xEnd; i++){
		for (int j = yStart; j<yEnd; j++){
			for (int k = zStart; k<zEnd; k++){
				sigmaeY[i][j][k] = 0.25*(m[index[i][j][k]].sigmaE() + m[index[i - 1][j][k]].sigmaE() + m[index[i][j][k - 1]].sigmaE() + m[index[i - 1][j][k - 1]].sigmaE());
			}
		}
	}
}

void MaterialGrid::averageSigmaEZ(){
	int xStart = 1, xEnd = nx;
	int yStart = 1, yEnd = ny;
	int zStart = 0, zEnd = nz;

	for (int i = xStart; i<xEnd; i++){
		for (int j = yStart; j<yEnd; j++){
			for (int k = zStart; k<zEnd; k++){
				sigmaeZ[i][j][k] = 0.25*(m[index[i][j][k]].sigmaE() + m[index[i - 1][j][k]].sigmaE() + m[index[i][j - 1][k]].sigmaE() + m[index[i - 1][j - 1][k]].sigmaE());
			}
		}
	}
}
