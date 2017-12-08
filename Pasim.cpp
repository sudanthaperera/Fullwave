#include "Pasim.h"


Pasim::Pasim()
{
	initializeProblemSpace();
	defineGeometry();
	defineSources();
	defineWaveform();
	defineOutput();
	initMaterialGrid();
	defineOutput();
	initMaterialGrid();
	initFDTDparams();
	initFDTDarrays();
	initSource();
	initWaveForm();
	genCoefficients();
	initParam();
}


Pasim::~Pasim()
{
}

void Pasim::initializeProblemSpace(){
	std::cout<<"Defining the problem space parameters..."<<std::endl;
	timeSteps = 100;
	courantFactor = 0.9;
	VoltageSource::voltageSourceCount = 1;
	CurrentSource::currentSourceCount = 0;
	c = *(new Cell(0.525e-3, 0.525e-3, 0.525e-3));
	b = *(new Boundary());
	b.setAirBuffer(10, 10, 10, 10, 10, 10);
	b.setBoundaryType(true, true, true, true, true, true);
	b.setCpmlCellNumber(8, 8, 8, 8, 8, 8);
	b.setCpmlParam(3, 1.3, 7.0, 0.0, 0.05);

	m = gen1DArray<Material>(5, *(new Material(0, 0.0, 0.0, 0, 0)));
	m[0] = *(new Material(0, 1.0, 1.0, 0, 0)); // Vac
	m[1] = *(new Material(1, 1.0, 1.0, 0, 0)); // air
	m[2] = *(new Material(2, 1.0, 1.0, 1.0e10, 0)); // PEC
	m[3] = *(new Material(3, 1.0, 1.0, 0, 1.0e10)); // PMC
	m[4] = *(new Material(4, 2.2, 1.0, 0, 0)); // Dielectric
}

void Pasim::defineGeometry(){
	std::cout << "Defining the problem geometry..."<<std::endl;
	brickCount = 4;
	bricks = gen1DArray<Brick>(brickCount,*(new Brick(0.0,0.0,0.0,0.0,0.0,0.0,new Material(0,0.0,0.0,0.0,0.0))));
	double gap = 10e-3;

	bricks[0] = *(new Brick(-39.375e-3 - gap, -39.375e-3 - gap, -1.575e-3 - gap, 39.375e-3 + gap, 39.375e-3 + gap, 0 + gap, &(this->m[1]))); //Air
	bricks[1] = *(new Brick(-39.375e-3, -39.375e-3, -1.575e-3, 39.375e-3, 39.375e-3, 0, &(this->m[4]))); //Dielectric
	bricks[2] = *(new Brick(-39.375e-3, -39.375e-3, -1.575e-3, 39.375e-3, 39.375e-3, -1.575e-3, &(this->m[2]))); //Ground
	bricks[3] = *(new Brick(-17.775e-3, -17.775e-3, 0, 17.775e-3, 17.775e-3, 0, &(this->m[2]))); //Patch
}

void Pasim::defineSources(){
	std::cout << "Defining sources and lumped element components..."<<std::endl;
	if (VoltageSource::voltageSourceCount > 0){
		vs = gen1DArray<VoltageSource>(VoltageSource::voltageSourceCount,*(new VoltageSource()));
		for (int i = 0; i<VoltageSource::voltageSourceCount; i++){
			//vs[i] = new VoltageSource(40e-3, 44.5e-3, 0, 40e-3, 45.5e-3, 1.5e-3, c);
			vs[i] = *(new VoltageSource(0, 5.25e-3, -1.575e-3, 0, 5.25e-3, 0, c));
			vs[i].setDirection(ZP);
			vs[i].setResistance(50.0);
			vs[i].setMagnitude(1.0);
		}
	}

	if (CurrentSource::currentSourceCount > 0){
		cs = gen1DArray<CurrentSource>(CurrentSource::currentSourceCount,*(new CurrentSource()));
	}
}

void Pasim::defineWaveform(){
	std::cout << "Defining source waveform types and parameters..." << std::endl;
	gaussianWaveformCount = 2;
	w = new Gaussian[gaussianWaveformCount];

	w[0] = *(new Gaussian(20, 1.0, 0.0, timeSteps));
	w[1] = *(new Gaussian(20, 1.0, 0.0, timeSteps));
}

void Pasim::defineOutput(){
	std::cout << "Defining output parameters..." << std::endl;

	eFieldProbCount = 1;
	hFieldProbCount = 0;
	voltageProbCount = 1;
	currentProbCount = 1;
	portCount = 1;

	currentProbPos = gen1DArray<Position>(1,Position());
	voltageProbPos = new Position[1];
	eFieldProbPos = new Position[1];
	hFieldProbPos = new Position[1];

	currentProbPos[0] = *(new Position(0, 5.25e-3, -1e-3));
	voltageProbPos[0] = *(new Position(0, 5.25e-3, 0));
	eFieldProbPos[0] = *(new Position(38.375e-3, 38.375e-3, 9e-3));
	hFieldProbPos[0] = *(new Position(0, 5.25e-3, 0));

	voltageProbObject = new VoltageProb[voltageProbCount];
	currentProbObject = new CurrentProb[currentProbCount];
	ports = new Port[portCount];
	freqDomain = *(new FrequencyDomain(1e8, 5e9, 40001));
	ff = *(new FarField(2.5e9, 3.1e9, 7));
	ff.setCellCountOuterBoundary(13);

	if (voltageProbCount > 0){
		for (int i = 0; i<voltageProbCount; i++){
			voltageProbObject[i] = *(new VoltageProb(voltageProbPos[i], ZP, -1.575e-3));
		}
	}

	if (currentProbCount > 0){
		for (int i = 0; i<currentProbCount; i++){
			currentProbObject[i] = *(new CurrentProb(currentProbPos[i], ZP));
		}
	}

	if (portCount > 0){
		for (int i = 0; i<portCount; i++){
			ports[i] = *(new Port(50, true));
		}
	}
}

////////////////////////
void Pasim::initMaterialGrid(){
  ps = *(new ProblemSpace(this->brickCount, this->bricks, this->c, this->b, this->m));
  std::cout<<"Number of cells in X direction = "<<ps.getNX()<<std::endl;
  std::cout << "Number of cells in Y direction = "<<ps.getNY()<<std::endl;
  std::cout << "Number of cells in Z direction = " << ps.getNZ() << std::endl;
  std::cout << "Number of cells = " << ps.getNX()*ps.getNY()*ps.getNZ() << std::endl;
  
  std::cout << "Initializing FDTD material grid..." << std::endl;
  ps.initMaterialGrid();
}

void Pasim::initFDTDparams(){
  speed = 1 / sqrt(MU0*EPS0);
  eta0 = sqrt(MU0 / EPS0);
  c.setDeltaT(courantFactor, speed);
  time = new double[this->timeSteps];
  
  for (int index = 0; index < this->timeSteps; index++){
    time[index] = (0.5 + index)*c.getDeltaT();
  }
}

void Pasim::initFDTDarrays(){
  H = *(new HField(this->ps.getNX(), this->ps.getNY(), this->ps.getNZ(), c));
  E = *(new EField(this->ps.getNX(), this->ps.getNY(), this->ps.getNZ(), c));
  
  H.setAllX(0.0);
  H.setAllY(0.0);
  H.setAllZ(0.0);
  
  E.setAllX(0.0);
  E.setAllY(0.0);
  E.setAllZ(0.0);
}

void Pasim::initSource(){
  double insValue;
  for (int ind = 0; ind < this->gaussianWaveformCount; ind++){
    if (w[ind].getCellsPerWavelength() == 0){
      w[ind].setCellsPerWavelength(CELLS_PER_WAVELENGTH);
    }
    
    w[ind].setMaxFreq(speed / (w[ind].getCellsPerWavelength()*c.getMax()));
    w[ind].setTau((w[ind].getCellsPerWavelength()*c.getMax() / (2 * speed)));
    w[ind].setT0(4.5*w[ind].getTau());
    
    for (int time_ind = 0; time_ind < this->timeSteps; time_ind++){
      insValue = exp(-((time[time_ind] - w[ind].getT0()) / w[ind].getTau())* ((time[time_ind] - w[ind].getT0()) / w[ind].getTau()));
      w[ind].set(insValue, time_ind);
    }
  }
}

void Pasim::initWaveForm(){
  int is, js, ks, ie, je, ke;
  for (int i = 0; i < sizeof1DArray<VoltageSource>(vs); i++){
    is = (int)round((this->vs[i].getXmin() - ps.getYmin()) / c.getDeltaX());
    js = (int)round((this->vs[i].getYmin() - ps.getYmin()) / c.getDeltaY());
    ks = (int)round((this->vs[i].getZmin() - ps.getZmin()) / c.getDeltaZ());
    ie = (int)round((this->vs[i].getXmax() - ps.getXmin()) / c.getDeltaX());
    je = (int)round((this->vs[i].getYmax() - ps.getYmin()) / c.getDeltaY());
    ke = (int)round((this->vs[i].getZmax() - ps.getZmin()) / c.getDeltaZ());
    
    this->vs[i].setIS(is);
    this->vs[i].setJS(js);
    this->vs[i].setKS(ks);
    this->vs[i].setIE(ie);
    this->vs[i].setJE(je);
    this->vs[i].setKE(ke);
    
    int n_fields = 0;
    double r_magnitude_factor = 0.0;
    double v_magnitude_factor = 0.0;
    
    if (this->vs[i].getDirection() == XN){
      n_fields = ie - is;
      r_magnitude_factor = (double)((1 + je - js) * (1 + ke - ks)) / (ie - is);
      v_magnitude_factor = (-1 * vs[i].getMagnitude()) / n_fields;
    }
    else if (vs[i].getDirection() == XP){
      n_fields = ie - is;
      r_magnitude_factor = (double)((1 + je - js) * (1 + ke - ks)) / (ie - is);
      v_magnitude_factor = (1 * vs[i].getMagnitude()) / n_fields;
    }
    else if (vs[i].getDirection() == YN){
      n_fields = je - js;
      r_magnitude_factor = (double)((1 + ie - is) * (1 + ke - ks)) / (je - js);
      v_magnitude_factor = (-1 * vs[i].getMagnitude()) / n_fields;
    }
    else if (vs[i].getDirection() == YP){
      n_fields = je - js;
      r_magnitude_factor = (double)((1 + ie - is) * (1 + ke - ks)) / (je - js);
      v_magnitude_factor = (1 * vs[i].getMagnitude()) / n_fields;
    }
    else if (vs[i].getDirection() == ZN){
      n_fields = ke - ks;
      r_magnitude_factor = (double)((1 + ie - is) * (1 + je - js)) / (ke - ks);
      v_magnitude_factor = (-1 * vs[i].getMagnitude()) / n_fields;
    }
    else if (vs[i].getDirection() == ZP){
      n_fields = ke - ks;
      r_magnitude_factor = (double)((1 + ie - is) * (1 + je - js)) / (ke - ks);
      v_magnitude_factor = (1 * vs[i].getMagnitude()) / n_fields;
    }
    
    vs[i].setResistancePerComponent(r_magnitude_factor * vs[i].getResistance());
    vs[i].initVoltagePerEfield(timeSteps);
    vs[i].initWaveform(timeSteps);
    
    for (int j = 0; j<this->timeSteps; j++){
      vs[i].setVoltagePerEfield(j, (v_magnitude_factor)*(w[0].get(j)));
      vs[i].setWaveform(j, (v_magnitude_factor)*(w[0].get(j)*(n_fields)));
    }
  }
}

void Pasim::genCoefficients(){
  E.updatingCoefficients(ps);
  H.updatingCoefficients(ps);
  vs[0].updatingCoefficients(ps);
}

void Pasim::initParam(){
  std::cout<<"initializing the CPML parameters..."<<std::endl;
  pml = *(new PMLmedia(ps, b, c));
  pml.initAllCPMLboundary();
  
  std::cout<<"initializing the output parameters..."<<std::endl;
  
  if (eFieldProbCount > 0){
    eProbObject = new EFieldProb[eFieldProbCount];
    
    for (int ind = 0; ind < eFieldProbCount; ind++){
      this->eProbObject[ind] = *(new EFieldProb(eFieldProbPos[ind], ps, c, timeSteps));
    }
  }
  
  if (hFieldProbCount > 0){
    hProbObject = new HFieldProb[hFieldProbCount];
    
    for (int ind = 0; ind < hFieldProbCount; ind++){
      this->hProbObject[ind] = *(new HFieldProb(hFieldProbPos[ind], ps, c, timeSteps));
    }
  }
  
  if (voltageProbCount > 0){
    for (int i = 0; i < voltageProbCount; i++){
      this->voltageProbObject[i].initVoltageProb(ps, c, timeSteps);
    }
  }
  
  if (currentProbCount > 0){
    for (int i = 0; i < currentProbCount; i++){
      this->currentProbObject[i].initCurrentProb(ps, c, timeSteps);
    }
  }
  ff.initFarFieldArrays(&ps);
}

void Pasim::run(){
  std::cout<<"Starting the time marching loop..."<<std::endl;
  std::clock_t startTimeMs = std::clock();
  std::clock_t taskTimeMs;
  
  for (int timeIndex = 0; timeIndex < timeSteps; timeIndex++){
    startTimeMs = std::clock();
    
    H.updateHField();
    
    pml.applyCPML2Hfield();
    
    for (int i = 0; i<CurrentSource::currentSourceCount; i++){
      this->cs[i].updateCurrentSourceHfiled(timeIndex);
    }
    
    for (int i = 0; i<hFieldProbCount; i++){
      this->hProbObject[i].CaptureHField(timeIndex);
    }
    
    for (int i = 0; i<currentProbCount; i++){
      this->currentProbObject[i].CaptureCurrent(H, timeIndex);
    }
    
    E.updateEField();
    
    pml.applyCPML2Efield();
    
    for (int i = 0; i<sizeof1DArray<VoltageSource>(this->vs); i++){
      this->vs[i].updateVoltageSourceEfiled(timeIndex);
    }
    
    for (int i = 0; i<eFieldProbCount; i++){
      this->eProbObject[i].CaptureEField(timeIndex);
    }
    
    for (int i = 0; i<voltageProbCount; i++){
      this->voltageProbObject[i].CaptureVoltage(E, timeIndex);
    }
    
    ff.CalculateJandM(timeIndex);
    
    if (timeIndex % (timeSteps / 10) == 0){
      taskTimeMs = std::clock() - startTimeMs;
      std::cout << "**** " << (100 * timeIndex / timeSteps) << "% Done! ****  " << taskTimeMs*(timeSteps - timeIndex) / 1000 << " Seconds Remaining\n" <<std::endl;
    }
  }
}

void Pasim::postProcessing(){
  voltageProbObject[0].time2freq(freqDomain.getFreqArray());
  currentProbObject[0].time2freq(freqDomain.getFreqArray());
  ports[0].setIProb(this->currentProbObject[0]);
  ports[0].setVProb(this->voltageProbObject[0]);
  ports[0].calAB(freqDomain.getFreqArray());
  ports[0].calSparam(ports);
  //Complex S[][][] = calSparam(ports);
  ff.calTotalRadiatedPower();
  ff.calFarField();
}

void Pasim::saveData(){
  eProbObject[0].saveEfiled();
  
  voltageProbObject[0].saveTimeDomainValue();
  voltageProbObject[0].saveFreqDomainValue();
  voltageProbObject[0].saveTime();
  voltageProbObject[0].saveFreq();
  
  currentProbObject[0].saveTimeDomainValue();
  currentProbObject[0].saveFreqDomainValue();
  currentProbObject[0].saveTime();
  currentProbObject[0].saveFreq();
  
  ports[0].saveSParam();
  ff.saveTotalRadiatedPower();
  ff.saveFarFieldThetaPhiPattern();
}
