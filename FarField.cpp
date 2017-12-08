#include "FarField.h"


FarField::FarField()
{
}


FarField::~FarField()
{
}

FarField::FarField(double start, double stop, int count){
	double step = (stop - start) / (count - 1);
	frequencies = new double[count];

	for (int i = 0; i < count; i++){
		frequencies[i] = start + i*step;
	}

	angleStepsCount = 360;
	theta = gen1DArray<double>(angleStepsCount, 0.0);
	phi = gen1DArray<double>(angleStepsCount, 0.0);

	for (int i = 0; i<angleStepsCount; i++){
		theta[i] = i*PI / angleStepsCount;
		phi[i] = i*(2 * PI / angleStepsCount) - 2 * PI;
	}
}

void FarField::setupFarFieldOutPut(double *theta, double *phi){
	this->angleStepsCount = sizeof1DArray<double>(theta);
	this->theta = theta;
	this->phi = phi;
}

void FarField::saveFarFieldThetaPhiPattern(){
	save2DArray<double>(farfield_dataPhi, "FarFieldPhiPattern");
	save2DArray<double>(farfield_dataTheta, "FarFieldThetaPattern");
	save1DArray<double>(phi, "FarFIeldPhi");
	save1DArray<double>(theta, "FarFieldTheta");
}

void FarField::calFarField(){
	std::complex<double> *initVal = new std::complex<double>(0.0, 0.0);
	std::complex<double>* exp_jk_rpr = gen1DArray<std::complex<double>>(angleStepsCount, *initVal);
	double *dx_sinth_cosphi = gen1DArray<double>(angleStepsCount, 0.0);
	double *dy_sinth_sinphi = gen1DArray<double>(angleStepsCount, 0.0);
	double *dz_costh = gen1DArray<double>(angleStepsCount, 0.0);
	double *dy_dz_costh_sinphi = gen1DArray<double>(angleStepsCount, 0.0);
	double *dy_dz_sinth = gen1DArray<double>(angleStepsCount, 0.0);
	double *dy_dz_cosphi = gen1DArray<double>(angleStepsCount, 0.0);
	double *dx_dz_costh_cosphi = gen1DArray<double>(angleStepsCount, 0.0);
	double *dx_dz_sinth = gen1DArray<double>(angleStepsCount, 0.0);
	double *dx_dz_sinphi = gen1DArray<double>(angleStepsCount, 0.0);
	double *dx_dy_costh_cosphi = gen1DArray<double>(angleStepsCount, 0.0);
	double *dx_dy_costh_sinphi = gen1DArray<double>(angleStepsCount, 0.0);
	double *dx_dy_sinphi = gen1DArray<double>(angleStepsCount, 0.0);
	double *dx_dy_cosphi = gen1DArray<double>(angleStepsCount, 0.0);

	//double[][] farfield_dirTheta = Common.genDouble2DArray(freqCount,angleStepsCount,0.0);
	//double[][] farfield_dir = Common.genDouble2DArray(freqCount,angleStepsCount,0.0);
	//double[][] farfield_dirPhi = Common.genDouble2DArray(freqCount,angleStepsCount,0.0);

	farfield_dataTheta = gen2DArray<double>(sizeof1DArray<double>(frequencies), angleStepsCount, 0.0);
	farfield_dataPhi = gen2DArray<double>(sizeof1DArray<double>(frequencies), angleStepsCount, 0.0);

	for (int i = 0; i<angleStepsCount; i++){
		dx_sinth_cosphi[i] = c.getDeltaX()*sin(theta[i])*cos(phi[i]);
		dy_sinth_sinphi[i] = c.getDeltaY()*sin(theta[i])*sin(phi[i]);
		dz_costh[i] = c.getDeltaZ()*cos(theta[i]);
		dy_dz_costh_sinphi[i] = c.getDeltaY()*c.getDeltaZ()*cos(theta[i])*sin(phi[i]);
		dy_dz_sinth[i] = c.getDeltaY()*c.getDeltaZ()*sin(theta[i]);
		dy_dz_cosphi[i] = c.getDeltaY()*c.getDeltaZ()*cos(phi[i]);
		dx_dz_costh_cosphi[i] = c.getDeltaX()*c.getDeltaZ()*cos(theta[i])*cos(phi[i]);
		dx_dz_sinth[i] = c.getDeltaX()*c.getDeltaZ()*sin(theta[i]);
		dx_dz_sinphi[i] = c.getDeltaX()*c.getDeltaZ()*sin(phi[i]);
		dx_dy_costh_cosphi[i] = c.getDeltaX()*c.getDeltaY()*cos(theta[i])*cos(phi[i]);
		dx_dy_costh_sinphi[i] = c.getDeltaX()*c.getDeltaY()*cos(theta[i])*sin(phi[i]);
		dx_dy_sinphi[i] = c.getDeltaX()*c.getDeltaY()*sin(phi[i]);
		dx_dy_cosphi[i] = c.getDeltaX()*c.getDeltaY()*cos(phi[i]);
	}

	double ci = 0.5*(ui + li);
	double cj = 0.5*(uj + lj);
	double ck = 0.5*(uk + lk);

	std::complex<double>* Ntheta = gen1DArray<std::complex<double>>(angleStepsCount, *initVal);
	std::complex<double>* Ltheta = gen1DArray<std::complex<double>>(angleStepsCount, *initVal);
	std::complex<double>* Nphi = gen1DArray<std::complex<double>>(angleStepsCount, *initVal);
	std::complex<double>* Lphi = gen1DArray<std::complex<double>>(angleStepsCount, *initVal);
	double *rpr = gen1DArray<double>(angleStepsCount, 1.0);

	double k;
	std::complex<double> unitImag{ 0.0, 1.0 };

	for (int mi = 0; mi<sizeof1DArray<double>(frequencies); mi++){
		std::cout<<"Calculating directivity for "<<this->frequencies[mi]<<" Hz"<<std::endl;
		k = 2 * PI*frequencies[mi] * sqrt(MU0*EPS0);
		for (int nj = lj; nj<uj; nj++){
			for (int nk = lk; nk<uk; nk++){
				for (int i = 0; i<angleStepsCount; i++){
					//for +ax direction
					rpr[i] = (ui - ci)*dx_sinth_cosphi[i] + (nj - cj + 0.5)*dy_sinth_sinphi[i] + (nk - ck + 0.5)*dz_costh[i];
					exp_jk_rpr[i] = expComplex(-unitImag*k*rpr[i]);
					Ntheta[i] = Ntheta[i] + (cjyxp[0][nj - lj][nk - lk][mi] * dy_dz_costh_sinphi[i] - cjzxp[0][nj - lj][nk - lk][mi] * dy_dz_sinth[i])*exp_jk_rpr[i];
					Ltheta[i] = Ltheta[i] + (cmyxp[0][nj - lj][nk - lk][mi] * dy_dz_costh_sinphi[i] - cmzxp[0][nj - lj][nk - lk][mi] * dy_dz_sinth[i])*exp_jk_rpr[i];
					Nphi[i] = Nphi[i] + cjyxp[0][nj - lj][nk - lk][mi] * dy_dz_cosphi[i] * exp_jk_rpr[i];
					Lphi[i] = Lphi[i] + cmyxp[0][nj - lj][nk - lk][mi] * dy_dz_cosphi[i] * exp_jk_rpr[i];

					//for -ax direction
					rpr[i] = (li - ci)*dx_sinth_cosphi[i] + (nj - cj + 0.5)*dy_sinth_sinphi[i] + (nk - ck + 0.5)*dz_costh[i];
					exp_jk_rpr[i] = expComplex(-unitImag*k*rpr[i]);
					Ntheta[i] = Ntheta[i] + (cjyxn[0][nj - lj][nk - lk][mi] * dy_dz_costh_sinphi[i] - cjzxn[0][nj - lj][nk - lk][mi] * dy_dz_sinth[i])*exp_jk_rpr[i];
					Ltheta[i] = Ltheta[i] + (cmyxn[0][nj - lj][nk - lk][mi] * dy_dz_costh_sinphi[i] - cmzxn[0][nj - lj][nk - lk][mi] * dy_dz_sinth[i])*exp_jk_rpr[i];
					Nphi[i] = Nphi[i] + cjyxn[0][nj - lj][nk - lk][mi] * dy_dz_cosphi[i] * exp_jk_rpr[i];
					Lphi[i] = Lphi[i] + cmyxn[0][nj - lj][nk - lk][mi] * dy_dz_cosphi[i] * exp_jk_rpr[i];
				}
			}
		}

		for (int ni = li; ni<ui; ni++){
			for (int nk = lk; nk<uk; nk++){
				for (int i = 0; i<angleStepsCount; i++){
					//for +ay direction
					rpr[i] = (ni - ci + 0.5)*dx_sinth_cosphi[i] + (uj - cj)*dy_sinth_sinphi[i] + (nk - ck + 0.5)*dz_costh[i];
					exp_jk_rpr[i] = expComplex(-unitImag*k*rpr[i]);
					Ntheta[i] = Ntheta[i] + (cjxyp[ni - li][0][nk - lk][mi] * dx_dz_costh_cosphi[i] - cjzyp[ni - li][0][nk - lk][mi] * dx_dz_sinth[i])*exp_jk_rpr[i];
					Ltheta[i] = Ltheta[i] + (cmxyp[ni - li][0][nk - lk][mi] * dx_dz_costh_cosphi[i] - cmzyp[ni - li][0][nk - lk][mi] * dx_dz_sinth[i])*exp_jk_rpr[i];
					Nphi[i] = Nphi[i] + cjxyp[ni - li][0][nk - lk][mi] * (-1.0)*dx_dz_sinphi[i] * exp_jk_rpr[i];
					Lphi[i] = Lphi[i] + cmxyp[ni - li][0][nk - lk][mi] * (-1.0)*dx_dz_sinphi[i] * exp_jk_rpr[i];

					//for -ay direction
					rpr[i] = (ni - ci + 0.5)*dx_sinth_cosphi[i] + (lj - cj)*dy_sinth_sinphi[i] + (nk - ck + 0.5)*dz_costh[i];
					exp_jk_rpr[i] = expComplex(-unitImag*k*rpr[i]);
					Ntheta[i] = Ntheta[i] + (cjxyn[ni - li][0][nk - lk][mi] * dx_dz_costh_cosphi[i] - cjzyn[ni - li][0][nk - lk][mi] * dx_dz_sinth[i])*exp_jk_rpr[i];
					Ltheta[i] = Ltheta[i] + (cmxyn[ni - li][0][nk - lk][mi] * dx_dz_costh_cosphi[i] - cmzyn[ni - li][0][nk - lk][mi] * dx_dz_sinth[i])*exp_jk_rpr[i];
					Nphi[i] = Nphi[i] + cjxyn[ni - li][0][nk - lk][mi] * (-1.0)*dx_dz_sinphi[i] * exp_jk_rpr[i];
					Lphi[i] = Lphi[i] + cmxyn[ni - li][0][nk - lk][mi] * (-1.0)*dx_dz_sinphi[i] * exp_jk_rpr[i];
				}
			}
		}

		for (int ni = li; ni<ui; ni++){
			for (int nj = lj; nj<uj; nj++){
				for (int i = 0; i<angleStepsCount; i++){
					//for +az direction

					rpr[i] = (ni - ci + 0.5)*dx_sinth_cosphi[i] + (nj - cj + 0.5)*dy_sinth_sinphi[i] + (uk - ck)*dz_costh[i];
					exp_jk_rpr[i] = expComplex((-unitImag)*k*rpr[i]);
					Ntheta[i] = Ntheta[i] + (cjxzp[ni - li][nj - lj][0][mi] * dx_dy_costh_cosphi[i] + cjyzp[ni - li][nj - lj][0][mi] * dx_dy_costh_sinphi[i])*exp_jk_rpr[i];
					Ltheta[i] = Ltheta[i] + (cmxzp[ni - li][nj - lj][0][mi] * dx_dy_costh_cosphi[i] + cmyzp[ni - li][nj - lj][0][mi] * dx_dy_costh_sinphi[i])*exp_jk_rpr[i];
					Nphi[i] = Nphi[i] + (cjxzp[ni - li][nj - lj][0][mi] * (-1.0)*dx_dy_sinphi[i] + cjyzp[ni - li][nj - lj][0][mi] * dx_dy_cosphi[i])*exp_jk_rpr[i];
					Lphi[i] = Lphi[i] + (cmxzp[ni - li][nj - lj][0][mi] * (-1.0)*dx_dy_sinphi[i] + cmyzp[ni - li][nj - lj][0][mi] * dx_dy_cosphi[i])*exp_jk_rpr[i];

					//for -az direction
					rpr[i] = (ni - ci + 0.5)*dx_sinth_cosphi[i] + (nj - cj + 0.5)*dy_sinth_sinphi[i] + (lk - ck)*dz_costh[i];
					exp_jk_rpr[i] = expComplex((-unitImag)*k*rpr[i]);
					Ntheta[i] = Ntheta[i] + (cjxzn[ni - li][nj - lj][0][mi] * dx_dy_costh_cosphi[i] + cjyzn[ni - li][nj - lj][0][mi] * dx_dy_costh_sinphi[i])*exp_jk_rpr[i];
					Ltheta[i] = Ltheta[i] + (cmxzn[ni - li][nj - lj][0][mi] * dx_dy_costh_cosphi[i] + cmyzn[ni - li][nj - lj][0][mi] * dx_dy_costh_sinphi[i])*exp_jk_rpr[i];
					Nphi[i] = Nphi[i] + (cjxzn[ni - li][nj - lj][0][mi] * (-1.0)*dx_dy_sinphi[i] + cjyzn[ni - li][nj - lj][0][mi] * dx_dy_cosphi[i])*exp_jk_rpr[i];
					Lphi[i] = Lphi[i] + (cmxzn[ni - li][nj - lj][0][mi] * (-1.0)*dx_dy_sinphi[i] + cmyzn[ni - li][nj - lj][0][mi] * dx_dy_cosphi[i])*exp_jk_rpr[i];
				}
			}
		}

		for (int i = 0; i<angleStepsCount; i++){
			farfield_dataTheta[mi][i] = pow(k, 2) / (8 * PI*ETA0*radiatedPower[mi] * pow(abs(Lphi[i] + Ntheta[i] * ETA0), 2));
			farfield_dataPhi[mi][i] = pow(k, 2) / (8 * PI*ETA0*radiatedPower[mi] * pow(abs(Ltheta[i] - Nphi[i] * ETA0), 2));
		}
	}
}


void FarField::saveTotalRadiatedPower(){
	save1DArray<double>(radiatedPower, "RadiatedPower");
}

void FarField::calTotalRadiatedPower(){
	int freqCount = getFreqCount();
	std::complex<double> initVal{ 0.0, 0.0 };
	radiatedPower = gen1DArray<double>(freqCount, 0.0);

	std::complex<double>* sum_of_cxn = gen1DArray<std::complex<double>>(freqCount, initVal);
	std::complex<double>* sum_of_cxp = gen1DArray<std::complex<double>>(freqCount, initVal);
	std::complex<double>* sum_of_cyn = gen1DArray<std::complex<double>>(freqCount, initVal);
	std::complex<double>* sum_of_cyp = gen1DArray<std::complex<double>>(freqCount, initVal);
	std::complex<double>* sum_of_czn = gen1DArray<std::complex<double>>(freqCount, initVal);
	std::complex<double>* sum_of_czp = gen1DArray<std::complex<double>>(freqCount, initVal);

	std::complex<double> temp1, temp2, temp3, temp4, temp5, temp6;

	for (int ind = 1; ind < freqCount; ind++){
		for (int i = 0; i<ui - li; i++){
			for (int j = 0; j<uj - lj; j++){
				sum_of_czp[ind] = sum_of_czp[ind] + (cmyzp[i][j][0][ind] * std::conj<double>(cjxzp[i][j][0][ind]) - cmxzp[i][j][0][ind] * std::conj<double>(cjyzp[i][j][0][ind]));
				sum_of_czn[ind] = sum_of_czn[ind] + (cmyzn[i][j][0][ind] * std::conj<double>(cjxzn[i][j][0][ind]) - cmxzn[i][j][0][ind] * std::conj<double>(cjyzn[i][j][0][ind]));
			}
		}

		for (int i = 0; i<ui - li; i++){
			for (int k = 0; k<uk - lk; k++){
				sum_of_cyp[ind] = sum_of_cyp[ind] + (cmxyp[i][0][k][ind] * std::conj<double>(cjzyp[i][0][k][ind]) - cmzyp[i][0][k][ind] * std::conj<double>(cjxyp[i][0][k][ind]));
				sum_of_cyn[ind] = sum_of_cyn[ind] + (cmxyn[i][0][k][ind] * std::conj<double>(cjzyn[i][0][k][ind]) - cmzyn[i][0][k][ind] * std::conj<double>(cjxyn[i][0][k][ind]));
			}
		}

		for (int j = 0; j<uj - lj; j++){
			for (int k = 0; k<uk - lk; k++){
				sum_of_cxp[ind] = sum_of_cxp[ind] + (cmzxp[0][j][k][ind] * std::conj<double>(cjyxp[0][j][k][ind]) - cmyxp[0][j][k][ind] * std::conj<double>(cjzxp[0][j][k][ind]));
				sum_of_cxn[ind] = sum_of_cxn[ind] + (cmzxn[0][j][k][ind] * std::conj<double>(cjyxn[0][j][k][ind]) - cmyxn[0][j][k][ind] * std::conj<double>(cjzxn[0][j][k][ind]));
			}
		}
		temp1 = sum_of_czp[ind]*c.getDeltaX()*c.getDeltaY();
		temp2 = sum_of_czn[ind]*c.getDeltaX()*c.getDeltaY();
		temp3 = sum_of_cyp[ind]*c.getDeltaX()*c.getDeltaZ();
		temp4 = sum_of_cyn[ind]*c.getDeltaX()*c.getDeltaZ();
		temp5 = sum_of_cxp[ind]*c.getDeltaY()*c.getDeltaZ();
		temp6 = sum_of_cxn[ind]*c.getDeltaY()*c.getDeltaZ();
		radiatedPower[ind] = 0.5*(temp1 - temp2 + temp3 - temp4 + temp5 - temp6).real();
	}
}

void FarField::CalculateJandM(int timeIndex){
	std::complex<double> zi{ 0.0, 1.0 };
	std::complex<double> initVal{ 0.0, 0.0 };
	int freqCount = getFreqCount();
	std::complex<double>* exp_h = gen1DArray<std::complex<double>>(freqCount, initVal);
	std::complex<double>* exp_e = gen1DArray<std::complex<double>>(freqCount, initVal);

	std::complex<double> hTemp, eTemp;

	for (int mi = 0; mi < freqCount; mi++){
		hTemp = { 0.0, -omegas[mi] * (timeIndex - 0.5)*c.getDeltaT() };
		eTemp = { 0.0, -omegas[mi] * timeIndex*c.getDeltaT() };
		exp_h[mi] = expComplex(hTemp)*c.getDeltaT();
		exp_e[mi] = expComplex(eTemp)*c.getDeltaT();
	}

	if (freqCount > 0){
		for (int i = li; i < ui; i++){
			for (int j = lj; j < uj; j++){
				for (int k = lk; k < uk; k++){
					if (i == ui - 1){
						tmyxp[0][0][j - lj][k - lk] = 0.5*(Ez[ui][j][k] + Ez[ui][j + 1][k]);
						tmzxp[0][0][j-lj][k-lk] = -0.5*(Ey[ui][j][k] + Ey[ui][j][k + 1]);

						tjyxp[0][0][j-lj][k-lk] = -0.25*(Hz[ui][j][k] + Hz[ui][j][k + 1] + Hz[ui - 1][j][k] + Hz[ui - 1][j][k + 1]);
						tjzxp[0][0][j-lj][k-lk] = 0.25*(Hy[ui][j][k] + Hy[ui][j + 1][k] + Hy[ui - 1][j][k] + Hy[ui - 1][j + 1][k]);

						tmyxn[0][0][j-lj][k-lk] = -0.5*(Ez[li][j][k] + Ez[li][j + 1][k]);
						tmzxn[0][0][j-lj][k-lk] = 0.5*(Ey[li][j][k] + Ey[li][j][k + 1]);

						tjyxn[0][0][j-lj][k-lk] = 0.25*(Hz[li][j][k] + Hz[li][j][k + 1] + Hz[li - 1][j][k] + Hz[li - 1][j][k + 1]);
						tjzxn[0][0][j-lj][k-lk] = -0.25*(Hy[li][j][k] + Hy[li][j + 1][k] + Hy[li - 1][j][k] + Hy[li - 1][j + 1][k]);

						//fourier transform
						for (int mi = 0; mi<freqCount; mi++){
							cjyxp[0][j - lj][k - lk][mi] = cjyxp[0][j - lj][k - lk][mi] + exp_h[mi] * tjyxp[0][0][j - lj][k - lk];
							cjzxp[0][j - lj][k - lk][mi] = cjzxp[0][j - lj][k - lk][mi] + exp_h[mi] * tjzxp[0][0][j - lj][k - lk];

							cjyxn[0][j - lj][k - lk][mi] = cjyxn[0][j - lj][k - lk][mi] + exp_h[mi] * tjyxn[0][0][j - lj][k - lk];
							cjzxn[0][j - lj][k - lk][mi] = cjzxn[0][j - lj][k - lk][mi] + exp_h[mi] * tjzxn[0][0][j - lj][k - lk];

							cmyxp[0][j - lj][k - lk][mi] = cmyxp[0][j - lj][k - lk][mi] + exp_e[mi] * tmyxp[0][0][j - lj][k - lk];
							cmzxp[0][j - lj][k - lk][mi] = cmzxp[0][j - lj][k - lk][mi] + exp_e[mi] * tmzxp[0][0][j - lj][k - lk];

							cmyxn[0][j - lj][k - lk][mi] = cmyxn[0][j - lj][k - lk][mi] + exp_e[mi] * tmyxn[0][0][j - lj][k - lk];
							cmzxn[0][j - lj][k - lk][mi] = cmzxn[0][j - lj][k - lk][mi] + exp_e[mi] * tmzxn[0][0][j - lj][k - lk];
						}
					}

					if (j == uj - 1){
						tmxyp[0][i - li][0][k - lk] = -0.5*(Ez[i][uj][k] + Ez[i + 1][uj][k]);
						tmzyp[0][i - li][0][k - lk] = 0.5*(Ex[i][uj][k] + Ex[i][uj][k + 1]);

						tjzyp[0][i - li][0][k - lk] = -0.25*(Hx[i][uj][k] + Hx[i + 1][uj][k] + Hx[i][uj - 1][k] + Hx[i + 1][uj - 1][k]);
						tjxyp[0][i - li][0][k - lk] = 0.25*(Hz[i][uj][k] + Hz[i][uj][k + 1] + Hz[i][uj - 1][k] + Hz[i][uj - 1][k + 1]);

						tmxyn[0][i - li][0][k - lk] = 0.5*(Ez[i][lj][k] + Ez[i + 1][lj][k]);
						tmzyn[0][i - li][0][k - lk] = -0.5*(Ex[i][lj][k] + Ex[i][lj][k + 1]);

						tjzyn[0][i - li][0][k - lk] = 0.25*(Hx[i][lj][k] + Hx[i + 1][lj][k] + Hx[i][lj - 1][k] + Hx[i + 1][lj - 1][k]);
						tjxyn[0][i - li][0][k - lk] = -0.25*(Hz[i][lj][k] + Hz[i][lj][k + 1] + Hz[i][lj - 1][k] + Hz[i][lj - 1][k + 1]);

						//fourier transform
						for (int mi = 0; mi<freqCount; mi++){
							cjxyp[i - li][0][k - lk][mi] = cjxyp[i - li][0][k - lk][mi] + exp_h[mi] * tjxyp[0][i - li][0][k - lk];
							cjzyp[i - li][0][k - lk][mi] = cjzyp[i - li][0][k - lk][mi] + exp_h[mi] * tjzyp[0][i - li][0][k - lk];

							cjxyn[i - li][0][k - lk][mi] = cjxyn[i - li][0][k - lk][mi] + exp_h[mi] * tjxyn[0][i - li][0][k - lk];
							cjzyn[i - li][0][k - lk][mi] = cjzyn[i - li][0][k - lk][mi] + exp_h[mi] * tjzyn[0][i - li][0][k - lk];

							cmxyp[i - li][0][k - lk][mi] = cmxyp[i - li][0][k - lk][mi] + exp_e[mi] * tmxyp[0][i - li][0][k - lk];
							cmzyp[i - li][0][k - lk][mi] = cmzyp[i - li][0][k - lk][mi] + exp_e[mi] * tmzyp[0][i - li][0][k - lk];

							cmxyn[i - li][0][k - lk][mi] = cmxyn[i - li][0][k - lk][mi] + exp_e[mi] * tmxyn[0][i - li][0][k - lk];
							cmzyn[i - li][0][k - lk][mi] = cmzyn[i - li][0][k - lk][mi] + exp_e[mi] * tmzyn[0][i - li][0][k - lk];
						}
					}

					if (k == uk - 1){
						tmxzp[0][i - li][j - lj][0] = 0.5*(Ey[i][j][uk] + Ey[i + 1][j][uk]);
						tmyzp[0][i - li][j - lj][0] = -0.5*(Ex[i][j][uk] + Ex[i][j + 1][uk]);

						tjyzp[0][i - li][j - lj][0] = 0.25*(Hx[i][j][uk] + Hx[i + 1][j][uk] + Hx[i][j][uk - 1] + Hx[i + 1][j][uk - 1]);
						tjxzp[0][i - li][j - lj][0] = -0.25*(Hy[i][j][uk] + Hy[i][j + 1][uk] + Hy[i][j][uk - 1] + Hy[i][j + 1][uk - 1]);

						tmxzn[0][i - li][j - lj][0] = -0.5*(Ey[i][j][lk] + Ey[i + 1][j][lk]);
						tmyzn[0][i - li][j - lj][0] = 0.5*(Ex[i][j][lk] + Ex[i][j + 1][lk]);

						tjyzn[0][i - li][j - lj][0] = -0.25*(Hx[i][j][lk] + Hx[i + 1][j][lk] + Hx[i][j][lk - 1] + Hx[i + 1][j][lk - 1]);
						tjxzn[0][i - li][j - lj][0] = 0.25*(Hy[i][j][lk] + Hy[i][j + 1][lk] + Hy[i][j][lk - 1] + Hy[i][j + 1][lk - 1]);

						//fourier transform
						for (int mi = 0; mi<freqCount; mi++){
							cjxzp[i - li][j - lj][0][mi] = cjxzp[i - li][j - lj][0][mi] + exp_h[mi] * tjxzp[0][i - li][j - lj][0];
							cjyzp[i - li][j - lj][0][mi] = cjyzp[i - li][j - lj][0][mi] + exp_h[mi] * tjyzp[0][i - li][j - lj][0];

							cjxzn[i - li][j - lj][0][mi] = cjxzn[i - li][j - lj][0][mi] + exp_h[mi] * tjxzn[0][i - li][j - lj][0];
							cjyzn[i - li][j - lj][0][mi] = cjyzn[i - li][j - lj][0][mi] + exp_h[mi] * tjyzn[0][i - li][j - lj][0];

							cmxzp[i - li][j - lj][0][mi] = cmxzp[i - li][j - lj][0][mi] + exp_e[mi] * tmxzp[0][i - li][j - lj][0];
							cmyzp[i - li][j - lj][0][mi] = cmyzp[i - li][j - lj][0][mi] + exp_e[mi] * tmyzp[0][i - li][j - lj][0];

							cmxzn[i - li][j - lj][0][mi] = cmxzn[i - li][j - lj][0][mi] + exp_e[mi] * tmxzn[0][i - li][j - lj][0];
							cmyzn[i - li][j - lj][0][mi] = cmyzn[i - li][j - lj][0][mi] + exp_e[mi] * tmyzn[0][i - li][j - lj][0];
						}
					}
				}
			}
		}
	}
}

double* FarField::getFreqArray(){
	return this->frequencies;
}

double FarField::getFreq(int index){
	return frequencies[index];
}

int FarField::getFreqCount(){
	return sizeof1DArray<double>(frequencies);
}

void FarField::setCellCountOuterBoundary(int count){
	this->outerBoundaryCellCount = count;
}

void FarField::initFarFieldArrays(ProblemSpace *ps){
	std::complex<double> *initVal = new std::complex<double>(0.0, 0.0);
	int freqCount = sizeof1DArray<double>(frequencies);
	li = this->outerBoundaryCellCount + 1;
	lj = this->outerBoundaryCellCount + 1;
	lk = this->outerBoundaryCellCount + 1;
	ui = ps->getNX() - this->outerBoundaryCellCount + 1;
	uj = ps->getNY() - this->outerBoundaryCellCount + 1;
	uk = ps->getNZ() - this->outerBoundaryCellCount + 1;

	this->omegas = gen1DArray<double>(freqCount, 0.0);

	for (int i = 0; i < freqCount; i++){
		omegas[i] = 2 * PI*frequencies[i];
	}

	tjxyp = gen4DArray<double>(1, ui - li, 1, uk - lk, 0.0);
	tjxzp = gen4DArray<double>(1, ui - li, uj - lj, 1, 0.0);
	tjyxp = gen4DArray<double>(1, 1, uj - lj, uk - lk, 0.0);
	tjyzp = gen4DArray<double>(1, ui - li, uj - lj, 1, 0.0);
	tjzxp = gen4DArray<double>(1, 1, uj - lj, uk - lk, 0.0);
	tjzyp = gen4DArray<double>(1, ui - li, 1, uk - lk, 0.0);
	tjxyn = gen4DArray<double>(1, ui - li, 1, uk - lk, 0.0);
	tjxzn = gen4DArray<double>(1, ui - li, uj - lj, 1, 0.0);
	tjyxn = gen4DArray<double>(1, 1, uj - lj, uk - lk, 0.0);
	tjyzn = gen4DArray<double>(1, ui - li, uj - lj, 1, 0.0);
	tjzxn = gen4DArray<double>(1, 1, uj - lj, uk - lk, 0.0);
	tjzyn = gen4DArray<double>(1, ui - li, 1, uk - lk, 0.0);
	tmxyp = gen4DArray<double>(1, ui - li, 1, uk - lk, 0.0);
	tmxzp = gen4DArray<double>(1, ui - li, uj - lj, 1, 0.0);
	tmyxp = gen4DArray<double>(1, 1, uj - lj, uk - lk, 0.0);
	tmyzp = gen4DArray<double>(1, ui - li, uj - lj, 1, 0.0);
	tmzxp = gen4DArray<double>(1, 1, uj - lj, uk - lk, 0.0);
	tmzyp = gen4DArray<double>(1, ui - li, 1, uk - lk, 0.0);
	tmxyn = gen4DArray<double>(1, ui - li, 1, uk - lk, 0.0);
	tmxzn = gen4DArray<double>(1, ui - li, uj - lj, 1, 0.0);
	tmyxn = gen4DArray<double>(1, 1, uj - lj, uk - lk, 0.0);
	tmyzn = gen4DArray<double>(1, ui - li, uj - lj, 1, 0.0);
	tmzxn = gen4DArray<double>(1, 1, uj - lj, uk - lk, 0.0);
	tmzyn = gen4DArray<double>(1, ui - li, 1, uk - lk, 0.0);

	cjxyp = gen4DArray<std::complex<double>>(ui - li, 1, uk - lk, freqCount, *initVal);
	cjxzp = gen4DArray<std::complex<double>>(ui - li, uj - lj, 1, freqCount, *initVal);
	cjyxp = gen4DArray<std::complex<double>>(1, uj - lj, uk - lk, freqCount, *initVal);
	cjyzp = gen4DArray<std::complex<double>>(ui - li, uj - lj, 1, freqCount, *initVal);
	cjzxp = gen4DArray<std::complex<double>>(1, uj - lj, uk - lk, freqCount, *initVal);
	cjzyp = gen4DArray<std::complex<double>>(ui - li, 1, uk - lk, freqCount, *initVal);
	cjxyn = gen4DArray<std::complex<double>>(ui - li, 1, uk - lk, freqCount, *initVal);
	cjxzn = gen4DArray<std::complex<double>>(ui - li, uj - lj, 1, freqCount, *initVal);
	cjyxn = gen4DArray<std::complex<double>>(1, uj - lj, uk - lk, freqCount, *initVal);
	cjyzn = gen4DArray<std::complex<double>>(ui - li, uj - lj, 1, freqCount, *initVal);
	cjzxn = gen4DArray<std::complex<double>>(1, uj - lj, uk - lk, freqCount, *initVal);
	cjzyn = gen4DArray<std::complex<double>>(ui - li, 1, uk - lk, freqCount, *initVal);
	cmxyp = gen4DArray<std::complex<double>>(ui - li, 1, uk - lk, freqCount, *initVal);
	cmxzp = gen4DArray<std::complex<double>>(ui - li, uj - lj, 1, freqCount, *initVal);
	cmyxp = gen4DArray<std::complex<double>>(1, uj - lj, uk - lk, freqCount, *initVal);
	cmyzp = gen4DArray<std::complex<double>>(ui - li, uj - lj, 1, freqCount, *initVal);
	cmzxp = gen4DArray<std::complex<double>>(1, uj - lj, uk - lk, freqCount, *initVal);
	cmzyp = gen4DArray<std::complex<double>>(ui - li, 1, uk - lk, freqCount, *initVal);
	cmxyn = gen4DArray<std::complex<double>>(ui - li, 1, uk - lk, freqCount, *initVal);
	cmxzn = gen4DArray<std::complex<double>>(ui - li, uj - lj, 1, freqCount, *initVal);
	cmyxn = gen4DArray<std::complex<double>>(1, uj - lj, uk - lk, freqCount, *initVal);
	cmyzn = gen4DArray<std::complex<double>>(ui - li, uj - lj, 1, freqCount, *initVal);
	cmzxn = gen4DArray<std::complex<double>>(1, uj - lj, uk - lk, freqCount, *initVal);
	cmzyn = gen4DArray<std::complex<double>>(ui - li, 1, uk - lk, freqCount, *initVal);
}
