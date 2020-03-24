#include "stdafx.h"
#include "Proton.h"

#include <iostream>
using namespace std;

Proton::Proton()
{
	this->weight = PROTON_WEIGHT;
	this->name = NAME;
}

long double Proton::get_weight()
{
	return this->weight;
}
