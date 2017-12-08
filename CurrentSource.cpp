#include "CurrentSource.h"



CurrentSource::CurrentSource(double Xmax, double Ymax, double Zmax, double Xmin, double Ymin, double Zmin, Cell c){
	Source::Source(Xmax, Ymax, Zmax, Xmin, Ymin, Zmin, c);
	this->resistance = 50.0;
	this->magnitude = 1.0;
}

CurrentSource::~CurrentSource(){

}

void CurrentSource::SetDirection(int direction){
	this->direction = direction;
}

void CurrentSource::updateCurrentSourceHfiled(int timeIndex){
	//to be use
}
