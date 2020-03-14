#pragma once

#include "Nucleon.h"

class Proton: public Nucleon
{
public:
	Proton();
	~Proton();
private:
	const long double PROTON_WEIGHT = 1.672e-27;
};

