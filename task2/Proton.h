#pragma once

#include "Nucleon.h"

class Proton: public Nucleon
{
public:
	Proton();
	~Proton() {};
	long double get_weight();
private:
	const long double PROTON_WEIGHT = 1.672e-27;
	string NAME = "PROTON";
};

