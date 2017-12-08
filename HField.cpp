#include "HField.h"


HField::HField()
{
}


HField::~HField()
{
}

HField::HField(int nx, int ny, int nz, Cell c){
	Field::Field(nx, ny, nz, c);
	Hx = gen3DArray<double>(nx + 1, ny, nz, 0.0);
	Hy = gen3DArray<double>(nx, ny + 1, nz, 0.0);
	Hz = gen3DArray<double>(nx, ny, nz + 1, 0.0);

	Chxh = gen3DArray<double>(nx + 1, ny, nz, 0.0);
	Chxez = gen3DArray<double>(nx + 1, ny, nz, 0.0);
	Chxey = gen3DArray<double>(nx + 1, ny, nz, 0.0);
	Chyh = gen3DArray<double>(nx, ny + 1, nz, 0.0);
	Chyex = gen3DArray<double>(nx, ny + 1, nz, 0.0);
	Chyez = gen3DArray<double>(nx, ny + 1, nz, 0.0);
	Chzh = gen3DArray<double>(nx, ny, nz + 1, 0.0);
	Chzey = gen3DArray<double>(nx, ny, nz + 1, 0.0);
	Chzex = gen3DArray<double>(nx, ny, nz + 1, 0.0);
}

void HField::updatingCoefficients(ProblemSpace ps){
	std::cout<<"General magnetic field updating coefficients...."<<std::endl;
	MaterialGrid mg = ps.getMaterialGrid();
	for (int i = 0; i<nx + 1; i++){
		for (int j = 0; j<ny; j++){
			for (int k = 0; k<nz; k++){
				//Coeffiecients updating Hx
				Chxh[i][j][k] = (2 * mg.getMuRX(i, j, k)*MU0 - dt*mg.getSigmaMX(i, j, k)) / (2 * mg.getMuRX(i, j, k)*MU0 + dt*mg.getSigmaMX(i, j, k));
				Chxez[i][j][k] = -(2 * dt / c.getDeltaY()) / (2 * mg.getMuRX(i, j, k)*MU0 + dt*mg.getSigmaMX(i, j, k));
				Chxey[i][j][k] = (2 * dt / c.getDeltaZ()) / (2 * mg.getMuRX(i, j, k)*MU0 + dt*mg.getSigmaMX(i, j, k));
			}
		}
	}

	for (int i = 0; i<nx; i++){
		for (int j = 0; j<ny + 1; j++){
			for (int k = 0; k<nz; k++){
				//Coeffiecients updating Hy
				Chyh[i][j][k] = (2 * mg.getMuRY(i, j, k)*MU0 - dt*mg.getSigmaMY(i, j, k)) / (2 * mg.getMuRY(i, j, k)*MU0 + dt*mg.getSigmaMY(i, j, k));
				Chyex[i][j][k] = -(2 * dt / c.getDeltaZ()) / (2 * mg.getMuRY(i, j, k)*MU0 + dt*mg.getSigmaMY(i, j, k));
				Chyez[i][j][k] = (2 * dt / c.getDeltaX()) / (2 * mg.getMuRY(i, j, k)*MU0 + dt*mg.getSigmaMY(i, j, k));
			}
		}
	}

	for (int i = 0; i<nx; i++){
		for (int j = 0; j<ny; j++){
			for (int k = 0; k<nz + 1; k++){
				//Coeffiecients updating Hz
				Chzh[i][j][k] = (2 * mg.getMuRZ(i, j, k)*MU0 - dt*mg.getSigmaMZ(i, j, k)) / (2 * mg.getMuRZ(i, j, k)*MU0 + dt*mg.getSigmaMZ(i, j, k));
				Chzey[i][j][k] = -(2 * dt / c.getDeltaX()) / (2 * mg.getMuRZ(i, j, k)*MU0 + dt*mg.getSigmaMZ(i, j, k));
				Chzex[i][j][k] = (2 * dt / c.getDeltaY()) / (2 * mg.getMuRZ(i, j, k)*MU0 + dt*mg.getSigmaMZ(i, j, k));
			}
		}
	}
}

double HField::getHx(int i, int j, int k){
	return Hx[i][j][k];
}

double HField::getHy(int i, int j, int k){
	return Hy[i][j][k];
}

double HField::getHz(int i, int j, int k){
	return Hz[i][j][k];
}

void HField::setAllX(double val){
	for (int i = 0; i<nx + 1; i++){
		for (int j = 0; j<ny; j++){
			for (int k = 0; k<nz; k++){
				Hx[i][j][k] = val;
			}
		}
	}
}

void HField::setAllY(double val){
	for (int i = 0; i<nx; i++){
		for (int j = 0; j<ny + 1; j++){
			for (int k = 0; k<nz; k++){
				Hy[i][j][k] = val;
			}
		}
	}
}

void HField::setAllZ(double val){
	for (int i = 0; i<nx; i++){
		for (int j = 0; j<ny; j++){
			for (int k = 0; k<nz + 1; k++){
				Hz[i][j][k] = val;
			}
		}
	}
}

void HField::updateHField(){
	for (int i = 0; i<nx + 1; i++){
		for (int j = 0; j<ny; j++){
			for (int k = 0; k<nz; k++){
				Hx[i][j][k] = Chxh[i][j][k] * Hx[i][j][k] + Chxey[i][j][k] * (Ey[i][j][k + 1] - Ey[i][j][k]) + Chxez[i][j][k] * (Ez[i][j + 1][k] - Ez[i][j][k]);
			}
		}
	}
	for (int i = 0; i<nx; i++){
		for (int j = 0; j<ny + 1; j++){
			for (int k = 0; k<nz; k++){
				Hy[i][j][k] = Chyh[i][j][k] * Hy[i][j][k] + Chyez[i][j][k] * (Ez[i + 1][j][k] - Ez[i][j][k]) + Chyex[i][j][k] * (Ex[i][j][k + 1] - Ex[i][j][k]);
			}
		}
	}
	for (int i = 0; i<nx; i++){
		for (int j = 0; j<ny; j++){
			for (int k = 0; k<nz + 1; k++){
				Hz[i][j][k] = Chzh[i][j][k] * Hz[i][j][k] + Chzex[i][j][k] * (Ex[i][j + 1][k] - Ex[i][j][k]) + Chzey[i][j][k] * (Ey[i + 1][j][k] - Ey[i][j][k]);
			}
		}
	}
}