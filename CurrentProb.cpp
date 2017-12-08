#include "CurrentProb.h"

CurrentProb::CurrentProb(){
  
}

CurrentProb::CurrentProb(Position probPos, int direction)
{
  Prob::Prob(probPos);
  this->direction = direction;
}


CurrentProb::~CurrentProb()
{
  
}

void CurrentProb::initCurrentProb(ProblemSpace ps, Cell c, int timeSteps){
  this->c = c;
  is = (int)std::round((Xmin - ps.getXmin()) / c.getDeltaX()) + 1;
  js = (int)std::round((Ymin - ps.getYmin()) / c.getDeltaY()) + 1;
  ks = (int)std::round((Zmin - ps.getZmin()) / c.getDeltaZ()) + 1;
  ie = (int)std::round((Xmax - ps.getXmin()) / c.getDeltaX()) + 1;
  je = (int)std::round((Ymax - ps.getYmin()) / c.getDeltaY()) + 1;
  ke = (int)std::round((Zmax - ps.getZmin()) / c.getDeltaZ()) + 1;
  timeDomainValue = gen1DArray<double>(timeSteps, 0.0);
  time = gen1DArray<double>(timeSteps, 0.0);
  
  for (int i = 0; i < timeSteps; i++){
    time[i] = (i + 1)*c.getDeltaT();
  }
}

void CurrentProb::CaptureCurrent(HField H, int timeIndex){
  double sample = 0.0;
  double sample1 = 0.0;
  double sample2 = 0.0;
  double sample3 = 0.0;
  double sample4 = 0.0;
  
  if (direction == XN || direction == XP){
    for (int j = js; j <= je; j++){
      sample1 = sample1 + c.getDeltaY()*H.getHy(ie - 1, j, ks - 1);
      sample3 = sample3 + c.getDeltaY()*H.getHy(ie - 1, j, ke);
    }
    for (int k = ks; k <= ke; k++){
      sample2 = sample2 + c.getDeltaZ()*H.getHz(ie - 1, je, k);
      sample4 = sample4 + c.getDeltaZ()*H.getHz(ie - 1, js - 1, k);
    }
  }
  
  else if (direction == YN || direction == YP){
    for (int i = is; i <= ie; i++){
      sample1 = sample1 + c.getDeltaX()*H.getHx(i, je - 1, ke);
      sample3 = sample3 + c.getDeltaX()*H.getHx(i, je - 1, ks - 1);
    }
    for (int k = ks; k <= ke; k++){
      sample2 = sample2 + c.getDeltaZ()*H.getHz(is - 1, je - 1, k);
      sample4 = sample4 + c.getDeltaZ()*H.getHz(ie, je - 1, k);
    }
  }
  
  else if (direction == ZN || direction == ZP){
    for (int i = is; i <= ie; i++){
      sample1 = sample1 + c.getDeltaX()*H.getHx(i, js - 1, ke - 1);
      sample3 = sample3 + c.getDeltaX()*H.getHx(i, je, ke - 1);
    }
    for (int j = js; j <= je; j++){
      sample2 = sample2 + c.getDeltaY()*H.getHy(ie, j, ke - 1);
      sample4 = sample4 + c.getDeltaY()*H.getHy(is - 1, j, ke - 1);
    }
  }
  
  sample = sample + sample1 + sample2 - sample3 - sample4;
  
  if (direction == XN || direction == YN || direction == ZP){
    sample = -1 * sample;
  }
  this->timeDomainValue[timeIndex] = sample;
}

void CurrentProb::saveTimeDomainValue(){
  save1DArray<double>(timeDomainValue, "IProbTimeDomainValue");
}

void CurrentProb::saveFreqDomainValue(){
  save1DArray<std::complex<double>>(frequencyDomainValue, "IProbFrequencyDomainValue");
}

void CurrentProb::time2freq(double *freqArray){
  frequencies = freqArray;
  frequencyDomainValue = timeDomain2frequencyDomain(timeDomainValue, time, frequencies, 0.0);
}

void CurrentProb::saveTime(){
  save1DArray<double>(time, "IProbTime");
}

void CurrentProb::saveFreq(){
  save1DArray<double>(frequencies, "IProbFrequencies");
}

std::complex<double> CurrentProb::getFreqDomainValue(int index){
  return this->frequencyDomainValue[index];
}
