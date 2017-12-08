#include "Port.h"


Port::Port()
{

}


Port::~Port()
{

}

void Port::setVProb(VoltageProb probV){
	this->probV = probV;
}

bool Port::isSourcePort(){
	return this->srcPort;
}

void Port::setIProb(CurrentProb probI){
	this->probI = probI;
}

Port::Port(double impedance, bool isSourcePort){
	this->impedance = *(new std::complex<double>(impedance, 0));
	this->srcPort = isSourcePort;
}

Port::Port(std::complex<double> impedance, bool isSourcePort){
	this->impedance = impedance;
	this->srcPort = isSourcePort;
}

void Port::saveSParam(){
	save2DArray<std::complex<double>>(S, "SParam");
}

void Port::calAB(double* frequencies){
	this->frequencies = frequencies;
	std::complex<double> initVal{ 0.0, 0.0 };
	a = gen1DArray<std::complex<double>>(sizeof1DArray<double>(frequencies), initVal);
	b = gen1DArray<std::complex<double>>(sizeof1DArray<double>(frequencies), initVal);
	std::complex<double> tempV{ 0.0, 0.0 };
	std::complex<double> tempI{ 0.0, 0.0 };

	for (int ind = 0; ind < sizeof1DArray<double>(frequencies); ind++){
		tempV = probV.getFreqDomainValue(ind);
		tempI = probI.getFreqDomainValue(ind);
		a[ind] = 0.5*(tempV + impedance*tempI) / sqrt(impedance.real());
		b[ind] = 0.5*(tempV - std::conj(impedance)*tempI) / sqrt(impedance.real());
	}
}

void Port::calSparam(Port *ports){
	if (this->isSourcePort()){
		S = gen2DArray<std::complex<double>>(sizeof1DArray<Port>(ports), sizeof1DArray<double>(frequencies), *(new std::complex<double>()));
		for (int portIndex = 0; portIndex < sizeof1DArray<Port>(ports); portIndex++){
			for (int ind = 0; ind < sizeof1DArray<double>(frequencies); ind++){
				if (a[ind] == *(new std::complex<double>())){
					S[portIndex][ind] = *(new std::complex<double>());
					std::cout<<"WARNING!! S parramater is not Calculated Correctly"<<std::endl;
				}
				else{
					S[portIndex][ind] = ports[portIndex].b[ind]/this->a[ind];
				}
			}
		}
	}
}