#include "ICEngine.h"

ICEngine::ICEngine()
{
	tEnv = 0;
}

ICEngine::ICEngine(double tEnv) : Engine(tEnv)
{
}

ICEngine::ICEngine(double tEnv, double tMax, double C) : Engine(tEnv, tMax, C)
{
}

ICEngine::ICEngine(double tEnv, double tMax, double C, double cdrm, double cdrk) : Engine(tEnv, tMax, C)
{
	this->cDRM = cdrm;
	this->cDRK = cdrk;
}

void ICEngine::work()
{
	double m, vh, vc;
	double v = 0.f;
	int i = 0;
	double infinityTracker = *std::max_element(aV.begin(), aV.end()) - cDRM;
	while (isWorking) {
		if (tEngine >= tMax) {
			std::cout << "\n\tTIME FROM START TO OVERHEATING EQUALS " << i << " SECONDS\n" << std::endl; //in case to display
			stop();
			setCode(OK);
			break;
		}

		if (v >= infinityTracker) {
			stop();
			setCode(INFINITY_CYCLE);
			break;
		}
		
		m = interpolation(aV, aM, aV.size(), v);
		vh = m * cDRM + (v * v) * cDRK;
		vc = cVCool * (tEnv - tEngine);
		tEngine += (vh + vc);
		v = v + (m  / engineInertia);
		i++;
	}
}

void ICEngine::start() {
	isWorking = true;
	work();
}

void ICEngine::stop() {
	isWorking = false;
}

