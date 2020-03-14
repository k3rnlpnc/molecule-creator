#pragma once

#include "Nucleon.h"

class Neutrons: public Nucleon
{
public:
	Neutrons();
	~Neutrons();
private:
	const long double NEUTRONS_WEIGHT = 1.674e-27;
};

