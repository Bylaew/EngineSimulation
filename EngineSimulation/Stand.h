#pragma once
#include "ICEngine.h"
class Stand
{
private:
	double ambientT;
public:
	Stand();
	Stand(double);
	void setAT(double nAT);
	double getAT();
	void run(Engine*);
};

