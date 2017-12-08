#include "HFieldProb.h"


HFieldProb::HFieldProb()
{
}


HFieldProb::~HFieldProb()
{
}

HFieldProb::HFieldProb(Position probPos, ProblemSpace ps, Cell c, int timeSteps){
	Prob::Prob(probPos);
	is = (int)((x - ps.getXmin()) / c.getDeltaX()) + 1;
	js = (int)((y - ps.getYmin()) / c.getDeltaY()) + 1;
	ks = (int)((z - ps.getZmin()) / c.getDeltaZ()) + 1;
	timeDomainSamples = gen1DArray<double>(timeSteps, 0.0);
	time = gen1DArray<double>(timeSteps, 0.0);

	for (int sample_time_ind = 0; sample_time_ind < timeSteps; sample_time_ind++){
		time[sample_time_ind] = (sample_time_ind + 0.5)*c.getDeltaT();
	}
}

void HFieldProb::CaptureHField(int timeIndex){
	//to be use
}
