#include "Common.h"

template<typename T>
T* gen1DArray(int nx, T initValue){
  nx = std::abs(nx);
  
  T *array = new T[nx];
  
  for (int i = 0; i<nx; i++){
    array[i] = initValue;
  }
  return array;
}

template<typename T>
T** gen2DArray(int nx, int ny, T initValue){
  nx = std::abs(nx);
  ny = std::abs(ny);
  
  T **array = new T*[nx];
  
  for (int i = 0; i<nx; i++){
    array[i] = new T[ny];
    for (int j = 0; j<ny; j++){
      array[i][j] = initValue;
    }
  }
  return array;
}

template<typename T>
T*** gen3DArray(int nx, int ny, int nz, T initValue){
  nx = std::abs(nx);
  ny = std::abs(ny);
  nz = std::abs(nz);
  
  T ***array = new T**[nx];
  
  for (int i = 0; i<nx; i++){
    array[i] = new T*[ny];
    for (int j = 0; j<ny; j++){
      array[i][j] = new T[nz];
      for (int k = 0; k<nz; k++){
	array[i][j][k] = initValue;
      }
    }
  }
  return array;
}

template<typename T>
T**** gen4DArray(int nx, int ny, int nz, int nw, T initValue){
  nx = std::abs(nx);
  ny = std::abs(ny);
  nz = std::abs(nz);
  nw = std::abs(nw);
  
  T ****array = new T***[nx];
  
  for (int i = 0; i<nx; i++){
    array[i] = new T**[ny];
    for (int j = 0; j<ny; j++){
      array[i][j] = new T*[nz];
      for (int k = 0; k<nz; k++){
	array[i][j][k] = new T[nw];
	for (int l = 0; l < nw; l++){
	  array[i][j][k][l] = initValue;
	}
      }
    }
  }
  return array;
}

template<typename T>
void save1DArray(T* a, std::string fileName){
  
}

template<typename T>
void save2DArray(T** a, std::string fileName){
  
}

template<typename T>
void save3DArray(T*** a, std::string fileName){
  
}

template<typename T>
void save4DArray(T**** a, std::string fileName){
  
}

template<typename T>
int sizeof1DArray(T* a){
  int size = (sizeof(a) / sizeof(*a));
  return size;
}

std::complex<double>* timeDomain2frequencyDomain(double* x, double* time, double* frequencies, double timeShift){
  int lengthFreq = sizeof1DArray<double>(frequencies);
  int lengthTime = sizeof1DArray<double>(time);
  std::complex<double> init{ 0.0, 0.0 };
  std::complex<double>* array = gen1DArray<std::complex<double>>(lengthFreq, init);
  std::complex<double> temp{ 0.0, 0.0 };
  double freqTemp = 0.0;
  double dt = time[1] - time[0];
  double angleTemp = 0.0;
  
  for (int freqIndex = 0; freqIndex < lengthFreq; freqIndex++){
    freqTemp = frequencies[freqIndex];
    for (int timeIndex = 0; timeIndex < lengthTime; timeIndex++){
      angleTemp = -(2 * PI*freqTemp)*(time[timeIndex] + timeShift);
      temp = { cos(angleTemp), sin(angleTemp) };
      array[freqIndex] = temp*x[timeIndex] + array[freqIndex];
    }
    array[freqIndex] = array[freqIndex]*dt;
  }
  return array;
}

std::complex<double> expComplex(std::complex<double> number){
  double r = number.real();
  double i = number.imag();
  std::complex<double> temp{ cos(i), sin(i) };
  return temp*exp(r);
}
