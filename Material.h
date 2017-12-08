#pragma once
class Material
{
private:
	int ind;
	double eps_R, mu_R, sigma_E, sigma_M;
public:
	Material();
	Material(int index, double epsR, double muR, double sigmaE, double sigmaM);
	~Material();
	int index();
	double epsR();
	double muR();
	double sigmaE();
	double sigmaM();
};