#include "VoltageSource.h"


VoltageSource::VoltageSource()
{
	this->voltageSourceCount = 0;
	this->resistance = 50.0;
	this->magnitude = 1.0;
}


VoltageSource::~VoltageSource()
{

}

VoltageSource::VoltageSource(double Xmin, double Ymin, double Zmin, double Xmax, double Ymax, double Zmax, Cell c){
	Source::Source(Xmax, Ymax, Zmax, Xmin, Ymin, Zmin, c);
	this->resistance = 50.0;
	this->magnitude = 1.0;
}

void VoltageSource::updateVoltageSourceEfiled(int timeIndex){
	if (direction == XN || direction == XP){
		for (int i = is; i < ie; i++){
			for (int j = js; j < je; j++){
				for (int k = ks; k < ke; k++){
					Ex[i][j][k] = Ex[i][j][k] + Cexs[i][j][k] * voltagePerEfield[timeIndex];
				}
			}
		}
	}
	if (direction == YN || direction == YP){
		for (int i = is; i < ie; i++){
			for (int j = js; j < je; j++){
				for (int k = ks; k < ke; k++){
					Ey[i][j][k] = Ey[i][j][k] + Ceys[i][j][k] * voltagePerEfield[timeIndex];
				}
			}
		}
	}
	if (direction == ZN || direction == ZP){
		for (int i = is; i <= ie; i++){
			for (int j = js; j <= je; j++){
				for (int k = ks; k < ke; k++){
					Ez[i][j][k] = Ez[i][j][k] + Cezs[i - is][j - js][k - ks] * voltagePerEfield[timeIndex];
				}
			}
		}
	}
}


void VoltageSource::initVoltagePerEfield(int timeSteps){
	this->voltagePerEfield = new double[timeSteps];
	for (int i = 0; i<timeSteps; i++){
		this->voltagePerEfield[i] = 0.0;
	}
}

void VoltageSource::initWaveform(int timeSteps){
	this->waveform = new double[timeSteps];
	for (int i = 0; i<timeSteps; i++){
		this->waveform[i] = 0.0;
	}
}

void VoltageSource::setVoltagePerEfield(int index, double value){
	this->voltagePerEfield[index] = value;
}

void VoltageSource::setWaveform(int index, double value){
	this->waveform[index] = value;
}

void VoltageSource::setIS(int is){
	this->is = is;
}

void VoltageSource::setJS(int js){
	this->js = js;
}

void VoltageSource::setKS(int ks){
	this->ks = ks;
}

void VoltageSource::setIE(int ie){
	this->ie = ie;
}

void VoltageSource::setJE(int je){
	this->je = je;
}

void VoltageSource::setKE(int ke){
	this->ke = ke;
}

void VoltageSource::setDirection(int direction){
	this->direction = direction;
}

int VoltageSource::getDirection(){
	return this->direction;
}

double VoltageSource::getMagnitude(){
	return this->magnitude;
}

double VoltageSource::getXmax(){
	return this->Xmax;
}

double VoltageSource::getXmin(){
	return this->Xmin;
}

double VoltageSource::getYmax(){
	return this->Ymax;
}

double VoltageSource::getYmin(){
	return this->Ymin;
}

double VoltageSource::getZmax(){
	return this->Zmax;
}

double VoltageSource::getZmin(){
	return this->Zmin;
}

double VoltageSource::getResistancePerComponent(){
	return this->resistancePerComponent;
}

void VoltageSource::setResistancePerComponent(double resistance_per_component){
	this->resistancePerComponent = resistance_per_component;
}

void VoltageSource::setResistance(double resistance){
	this->resistance = resistance;
}

void VoltageSource::setMagnitude(double magnitude){
	this->magnitude = magnitude;
}

double VoltageSource::getResistance(){
	return this->resistance;
}

void VoltageSource::updatingCoefficients(ProblemSpace ps){
	MaterialGrid mg = ps.getMaterialGrid();
	double temp;
	double rpc;
	rpc = resistancePerComponent;

	if (direction == XP || direction == XN){
		temp = (c.getDeltaT()*c.getDeltaX()) / (rpc*c.getDeltaY()*c.getDeltaZ());
		Cexs = gen3DArray<double>(ie - is, je + 1 - js, ke + 1 - ks, 0.0);
		for (int i = is; i <= ie - 1; i++){
			for (int j = js; j <= je; j++){
				for (int k = ks; k <= ke; k++){
					Cexe[i][j][k] = (2 * EPS0*mg.getEpsRX(i, j, k) - c.getDeltaT()*mg.getSigmaEX(i, j, k) - temp) / (2 * EPS0*mg.getEpsRX(i, j, k) + c.getDeltaT()*mg.getSigmaEX(i, j, k) + temp);
					Cexhz[i][j][k] = (2 * c.getDeltaT() / c.getDeltaY()) / (2 * mg.getEpsRX(i, j, k)*EPS0 + c.getDeltaT()*mg.getSigmaEX(i, j, k) + temp);
					Cexhy[i][j][k] = -(2 * c.getDeltaT() / c.getDeltaZ()) / (2 * mg.getEpsRX(i, j, k)*EPS0 + c.getDeltaT()*mg.getSigmaEX(i, j, k) + temp);
					Cexs[i - is][j - js][k - ks] = -(2 * c.getDeltaT() / (rpc*c.getDeltaZ()*c.getDeltaZ())) / (2 * mg.getEpsRX(i, j, k)*EPS0 + c.getDeltaT()*mg.getSigmaEX(i, j, k) + temp);
				}
			}
		}
	}

	if (direction == YP || direction == YN){
		temp = (c.getDeltaT()*c.getDeltaY()) / (rpc*c.getDeltaZ()*c.getDeltaX());
		Ceys = gen3DArray<double>(ie + 1 - is, je - js, ke + 1 - ks, 0.0);
		for (int i = is; i <= ie; i++){
			for (int j = js; j <= je - 1; j++){
				for (int k = ks; k <= ke; k++){
					Ceye[i][j][k] = (2 * EPS0*mg.getEpsRY(i, j, k) - c.getDeltaT()*mg.getSigmaEY(i, j, k) - temp) / (2 * EPS0*mg.getEpsRY(i, j, k) + c.getDeltaT()*mg.getSigmaEY(i, j, k) + temp);
					Ceyhx[i][j][k] = (2 * c.getDeltaT() / c.getDeltaZ()) / (2 * mg.getEpsRY(i, j, k)*EPS0 + c.getDeltaT()*mg.getSigmaEY(i, j, k) + temp);
					Ceyhz[i][j][k] = -(2 * c.getDeltaT() / c.getDeltaX()) / (2 * mg.getEpsRY(i, j, k)*EPS0 + c.getDeltaT()*mg.getSigmaEY(i, j, k) + temp);
					Ceys[i - is][j - js][k - ks] = -(2 * c.getDeltaT() / (rpc*c.getDeltaZ()*c.getDeltaX())) / (2 * mg.getEpsRY(i, j, k)*EPS0 + c.getDeltaT()*mg.getSigmaEY(i, j, k) + temp);
				}
			}
		}
	}

	if (direction == ZP || direction == ZN){
		temp = (c.getDeltaT()*c.getDeltaZ()) / (rpc*c.getDeltaX()*c.getDeltaY());
		Cezs = gen3DArray<double>(ie + 1 - is, je + 1 - js, ke - ks, 0.0);
		for (int i = is; i <= ie; i++){
			for (int j = js; j <= je; j++){
				for (int k = ks; k <= ke - 1; k++){
					Ceze[i][j][k] = (2 * EPS0*mg.getEpsRZ(i, j, k) - c.getDeltaT()*mg.getSigmaEZ(i, j, k) - temp) / (2 * EPS0*mg.getEpsRZ(i, j, k) + c.getDeltaT()*mg.getSigmaEZ(i, j, k) + temp);
					Cezhy[i][j][k] = (2 * c.getDeltaT() / c.getDeltaX()) / (2 * mg.getEpsRZ(i, j, k)*EPS0 + c.getDeltaT()*mg.getSigmaEZ(i, j, k) + temp);
					Cezhx[i][j][k] = -(2 * c.getDeltaT() / c.getDeltaY()) / (2 * mg.getEpsRZ(i, j, k)*EPS0 + c.getDeltaT()*mg.getSigmaEZ(i, j, k) + temp);
					Cezs[i - is][j - js][k - ks] = -(2 * c.getDeltaT() / (rpc*c.getDeltaX()*c.getDeltaY())) / (2 * mg.getEpsRZ(i, j, k)*EPS0 + c.getDeltaT()*mg.getSigmaEZ(i, j, k) + temp);
				}
			}
		}
	}
}