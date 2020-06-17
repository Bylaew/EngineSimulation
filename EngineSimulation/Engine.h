#pragma once
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
class Engine
{
private:
	short code;
protected:
	enum Code {
		NOTHING = 0,
		OK,
		INFINITY_CYCLE
	};
	std::vector<double> aV = { 0.f,75.f,150.f,200.f,250.f,300.f };
	std::vector<double> aM = { 20.f,75.f,100.f,105.f,75.f,0.f };
	double engineInertia = 10;
	double tEnv;
	double tEngine;
	double tMax = 110;
	double cVCool = 0.1;
	bool isWorking = false;
	double interpolation(std::vector<double>& x, std::vector<double>& y, short n, double _x);
	void setCode(short code);
	virtual void work() = 0;
public:
	Engine();
	Engine(double);
	Engine(double, double, double);
	virtual void start() = 0;
	virtual void stop() = 0;
	void setEnvT(double &envT);
	short getCode();
	bool isStarted();
};

