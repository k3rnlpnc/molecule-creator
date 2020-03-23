#pragma once
#include "ElementaryParticle.h"
#include <iostream>
using namespace std;

class Electron: public ElementaryParticle
{
public:
	Electron();
	virtual string get_name();
	~Electron() override {};

private:
	const long double ELECTRON_WEIGHT = 9.1093e-31;
	const long double ELECTRON_CHARGE = -1.602e-19;
	string NAME = "ELECTRON";
};

