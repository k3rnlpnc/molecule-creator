#pragma once
#include "Particle.h"
#include <iostream>
using namespace std;

class Electron: public Particle
{
public:
	Electron();
	~Electron() {};
	long double get_weight();

private:
	const long double ELECTRON_WEIGHT = 9.1093e-31;
	string NAME = "ELECTRON";
};

