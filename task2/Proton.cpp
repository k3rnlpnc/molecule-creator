#include "stdafx.h"
#include "Proton.h"

#include <iostream>
using namespace std;

Proton::Proton()
{
	this->weight = PROTON_WEIGHT;
	this->charge = PROTON_CHARGE;
	this->name = NAME;
}

string Proton::get_name()
{
	return this->name;
}
