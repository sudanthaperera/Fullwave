#include "Pasim.h"


void main() {
	std::clock_t start = std::clock();
	Pasim *pas = new Pasim();
	pas->run();
	pas->postProcessing();
	pas->saveData();
	std::cout<<"Done!!"<<std::endl;
	std::clock_t totalTime = std::clock() - start;
	std::cout << "The time taken : " << (long)totalTime /(double)CLOCKS_PER_SEC << "ms" << std::endl;
}