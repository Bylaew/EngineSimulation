#include "Engine.h"

Engine::Engine()
{
	tEnv = 0;
	tEngine = 0;
}

Engine::Engine(double tEnv) {
	this->tEnv = tEnv;
	this->tEngine = tEnv;
}

Engine::Engine(double tEnv, double tMax, double C )
{
	this->tEnv = tEnv;
	this->tEngine = tEnv;
	this->tMax = tMax;
	this->cVCool = C;
}

void Engine::setEnvT(double &envT)
{
	this->tEnv = envT;
	this->tEngine = envT;
}

short Engine::getCode()
{
	return code;
}

void Engine::setCode(short code)
{
	this->code = code;
}

bool Engine::isStarted()
{
	return isWorking;
}

double Engine::interpolation(std::vector<double>& x, std::vector<double>& y, short n, double _x)
{
	double result = 0.0;
	for (short i = 0; i < n; i++)
	{
		double P = 1.0;
		for (short j = 0; j < n; j++)
			if (j != i)
				P *= (_x - x[j]) / (x[i] - x[j]);
		result += P * y[i];
	}

	return result;
}
