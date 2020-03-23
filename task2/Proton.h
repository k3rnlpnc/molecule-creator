#pragma once

#include "Nucleon.h"

class Proton: public Nucleon
{
public:
	Proton();
	~Proton() override {};
	virtual string get_name();
private:
	const long double PROTON_WEIGHT = 1.672e-27;
	const long double PROTON_CHARGE = 1.602e-19;
	string NAME = "PROTON";
};

