#pragma once

#include "Nucleon.h"

class Neutrons: public Nucleon
{
public:
	Neutrons();
	virtual string get_name();
	~Neutrons() override {};
private:
	const long double NEUTRONS_WEIGHT = 1.674e-27;
	const long double NEUTRONS_CHARGE = 0;
	string NAME = "NEUTRONS";
};

