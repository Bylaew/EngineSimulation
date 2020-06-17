#pragma once
#include "Engine.h"
class ICEngine :
    public Engine
{
private:
    double cDRM = 0.01, cDRK = 0.0001;
public:
    ICEngine();
    ICEngine(double);
    ICEngine(double,double,double);
    ICEngine(double,double,double,double,double);
    void work();
    void start();
    void stop();
};

