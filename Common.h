#pragma once
#include <cmath>
#include <complex>
#include <string>
#include "Constants.h"

template<typename T>
T* gen1DArray(int nx, T initValue);

template<typename T>
T** gen2DArray(int nx, int ny, T initValue);

template<typename T>
T*** gen3DArray(int nx, int ny, int nz, T initValue);

template<typename T>
T**** gen4DArray(int nx, int ny, int nz, int nw, T initValue);

template<typename T>
void save1DArray(T* a, std::string fileName);

template<typename T>
void save2DArray(T** a, std::string fileName);

template<typename T>
void save3DArray(T*** a, std::string fileName);

template<typename T>
void save4DArray(T**** a, std::string fileName);

template<typename T>
int sizeof1DArray(T* a);

std::complex<double>* timeDomain2frequencyDomain(double* x, double* time, double* frequencies, double timeShift);

std::complex<double> expComplex(std::complex<double> number);

double* gen1DArrayDouble(int nx, double initValue);

double** gen2DArrayDouble(int nx, int ny, double initValue);

double*** gen3DArrayDouble(int nx, int ny, int nz, double initValue);

double**** gen4DArrayDouble(int nx, int ny, int nz, int nw, double initValue);

void save1DArrayDouble(double* a, std::string fileName);

void save2DArrayDouble(double** a, std::string fileName);

void save3DArrayDouble(double*** a, std::string fileName);

void save4DArrayDouble(double**** a, std::string fileName);

int sizeof1DArrayDouble(double* a);