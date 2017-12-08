#include "EFieldProb.h"


EFieldProb::EFieldProb()
{

}


EFieldProb::~EFieldProb()
{
}

EFieldProb::EFieldProb(Position probPos, ProblemSpace ps, Cell c, int timeSteps){
	Prob::Prob(probPos);
	is = (int)round((x - ps.getXmin()) / c.getDeltaX()) + 1;
	js = (int)round((y - ps.getYmin()) / c.getDeltaY()) + 1;
	ks = (int)round((z - ps.getZmin()) / c.getDeltaZ()) + 1;
	timeDomainSamplesX = gen1DArray<double>(timeSteps, 0.0);
	timeDomainSamplesY = gen1DArray<double>(timeSteps, 0.0);
	timeDomainSamplesZ = gen1DArray<double>(timeSteps, 0.0);
	time = gen1DArray<double>(timeSteps, 0.0);

	for (int sample_time_ind = 0; sample_time_ind < timeSteps; sample_time_ind++){
		time[sample_time_ind] = (sample_time_ind + 1)*c.getDeltaT();
	}
}

void EFieldProb::CaptureEField(int timeIndex){
	timeDomainSamplesX[timeIndex] = Ex[is][js][ks];
	timeDomainSamplesY[timeIndex] = Ey[is][js][ks];
	timeDomainSamplesZ[timeIndex] = Ez[is][js][ks];
}

void EFieldProb::saveEfiled(){
	save1DArray<double>(timeDomainSamplesX, "EX");
	save1DArray<double>(timeDomainSamplesY, "EY");
	save1DArray<double>(timeDomainSamplesZ, "EZ");
}