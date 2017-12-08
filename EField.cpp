#include "EField.h"


EField::EField()
{
}

EField::EField(int nx, int ny, int nz, Cell c){
	Field::Field(nx, ny, nz, c);
	this->Ex = gen3DArray<double>(nx, ny + 1, nz + 1, 0.0);
	this->Ey = gen3DArray<double>(nx + 1, ny, nz + 1, 0.0);
	this->Ez = gen3DArray<double>(nx + 1, ny + 1, nz, 0.0);

	Cexe = gen3DArray<double>(nx, ny + 1, nz + 1, 0.0);
	Cexhz = gen3DArray<double>(nx, ny + 1, nz + 1, 0.0);
	Cexhy = gen3DArray<double>(nx, ny + 1, nz + 1, 0.0);
	Ceye = gen3DArray<double>(nx + 1, ny, nz + 1, 0.0);
	Ceyhx = gen3DArray<double>(nx + 1, ny, nz + 1, 0.0);
	Ceyhz = gen3DArray<double>(nx + 1, ny, nz + 1, 0.0);
	Ceze = gen3DArray<double>(nx + 1, ny + 1, nz, 0.0);
	Cezhy = gen3DArray<double>(nx + 1, ny + 1, nz, 0.0);
	Cezhx = gen3DArray<double>(nx + 1, ny + 1, nz, 0.0);
}

EField::~EField()
{
}

void EField::updatingCoefficients(ProblemSpace ps){
	std::cout<<"General electric field updating coefficients..."<<std::endl;
	MaterialGrid mg = ps.getMaterialGrid();
	for (int i = 0; i<nx; i++){
		for (int j = 0; j<ny + 1; j++){
			for (int k = 0; k<nz + 1; k++){
				Cexe[i][j][k] = (2 * mg.getEpsRX(i, j, k)*EPS0 - dt*mg.getSigmaEX(i, j, k)) / (2 * mg.getEpsRX(i, j, k)*EPS0 + dt*mg.getSigmaEX(i, j, k));
				Cexhz[i][j][k] = (2 * dt / c.getDeltaY()) / (2 * mg.getEpsRX(i, j, k)*EPS0 + dt*mg.getSigmaEX(i, j, k));
				Cexhy[i][j][k] = -(2 * dt / c.getDeltaZ()) / (2 * mg.getEpsRX(i, j, k)*EPS0 + dt*mg.getSigmaEX(i, j, k));
			}
		}
	}

	for (int i = 0; i<nx + 1; i++){
		for (int j = 0; j<ny; j++){
			for (int k = 0; k<nz + 1; k++){
				Ceye[i][j][k] = (2 * mg.getEpsRY(i, j, k)*EPS0 - dt*mg.getSigmaEY(i, j, k)) / (2 * mg.getEpsRY(i, j, k)*EPS0 + dt*mg.getSigmaEY(i, j, k));
				Ceyhx[i][j][k] = (2 * dt / c.getDeltaZ()) / (2 * mg.getEpsRY(i, j, k)*EPS0 + dt*mg.getSigmaEY(i, j, k));
				Ceyhz[i][j][k] = -(2 * dt / c.getDeltaX()) / (2 * mg.getEpsRY(i, j, k)*EPS0 + dt*mg.getSigmaEY(i, j, k));
			}
		}
	}

	for (int i = 0; i<nx + 1; i++){
		for (int j = 0; j<ny + 1; j++){
			for (int k = 0; k<nz; k++){
				Ceze[i][j][k] = (2 * mg.getEpsRZ(i, j, k)*EPS0 - dt*mg.getSigmaEZ(i, j, k)) / (2 * mg.getEpsRZ(i, j, k)*EPS0 + dt*mg.getSigmaEZ(i, j, k));
				Cezhy[i][j][k] = (2 * dt / c.getDeltaX()) / (2 * mg.getEpsRZ(i, j, k)*EPS0 + dt*mg.getSigmaEZ(i, j, k));
				Cezhx[i][j][k] = -(2 * dt / c.getDeltaY()) / (2 * mg.getEpsRZ(i, j, k)*EPS0 + dt*mg.getSigmaEZ(i, j, k));
			}
		}
	}
}


void EField::setAllX(double val){
	for (int i = 0; i<nx; i++){
		for (int j = 0; j<ny + 1; j++){
			for (int k = 0; k<nz + 1; k++){
				Ex[i][j][k] = val;
			}
		}
	}
}

void EField::setAllY(double val){
	for (int i = 0; i<nx + 1; i++){
		for (int j = 0; j<ny; j++){
			for (int k = 0; k<nz + 1; k++){
				Ey[i][j][k] = val;
			}
		}
	}
}

void EField::setAllZ(double val){
	for (int i = 0; i<nx + 1; i++){
		for (int j = 0; j<ny + 1; j++){
			for (int k = 0; k<nz; k++){
				Ez[i][j][k] = val;
			}
		}
	}
}

void EField::updateEField(){
	for (int i = 0; i<nx; i++){
		for (int j = 1; j<ny; j++){
			for (int k = 1; k<nz; k++){
				Ex[i][j][k] = Cexe[i][j][k] * Ex[i][j][k] + Cexhz[i][j][k] * (Hz[i][j][k] - Hz[i][j - 1][k]) + Cexhy[i][j][k] * (Hy[i][j][k] - Hy[i][j][k - 1]);
			}
		}
	}
	for (int i = 1; i<nx; i++){
		for (int j = 0; j<ny; j++){
			for (int k = 1; k<nz; k++){
				Ey[i][j][k] = Ceye[i][j][k] * Ey[i][j][k] + Ceyhx[i][j][k] * (Hx[i][j][k] - Hx[i][j][k - 1]) + Ceyhz[i][j][k] * (Hz[i][j][k] - Hz[i - 1][j][k]);
			}
		}
	}
	for (int i = 1; i<nx; i++){
		for (int j = 1; j<ny; j++){
			for (int k = 0; k<nz; k++){
				Ez[i][j][k] = Ceze[i][j][k] * Ez[i][j][k] + Cezhy[i][j][k] * (Hy[i][j][k] - Hy[i - 1][j][k]) + Cezhx[i][j][k] * (Hx[i][j][k] - Hx[i][j - 1][k]);
			}
		}
	}
}

double EField::getEx(int i, int j, int k){
	return Ex[i][j][k];
}

double EField::getEy(int i, int j, int k){
	return Ey[i][j][k];
}

double EField::getEz(int i, int j, int k){
	return Ez[i][j][k];
}