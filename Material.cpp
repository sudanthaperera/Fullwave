#include "Material.h"


Material::Material()
{
}


Material::~Material()
{
}

Material::Material(int index, double epsR, double muR, double sigmaE, double sigmaM){
	this->ind = index;

	if (epsR == 0)
		this->eps_R = 1.0;
	else
		this->eps_R = epsR;

	if (muR == 0)
		this->mu_R = 1.0;
	else
		this->mu_R = muR;

	if (sigmaE == 0)
		this->sigma_E = 1.0e-40;
	else
		this->sigma_E = sigmaE;

	if (sigmaM == 0)
		this->sigma_M = 1.0e-40;
	else
		this->sigma_M = sigmaM;
}

int Material::index(){
	return this->ind;
}

double Material::epsR(){
	return this->eps_R;
}

double Material::muR(){
	return this->mu_R;
}

double Material::sigmaE(){
	return this->sigma_E;
}

double Material::sigmaM(){
	return this->sigma_M;
}