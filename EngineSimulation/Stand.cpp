#include "Stand.h"

Stand::Stand()
{
	std::cout << "Please, enter ambient temperatue: ";
	std::cin >> this->ambientT;
}

Stand::Stand(double at)
{
	ambientT = at;
}

void Stand::setAT(double nAT)
{
	ambientT = nAT;
}

double Stand::getAT()
{
	return ambientT;
}

void Stand::run(Engine* engine)
{
	engine->setEnvT(ambientT);
	engine->start();
	if (engine->getCode() == 2) {
		std::cout << "It is impossible to overheating!" << std::endl;
	}
	else if (engine->getCode() == 1) {
		std::cout << "Everything's ok!" << std::endl;
	}
}
