#include "stdafx.h"
#include "Neutrons.h"

#include <iostream>
using namespace std;

Neutrons::Neutrons()
{
	this->weight = NEUTRONS_WEIGHT;
	this->charge = NEUTRONS_CHARGE;
	this->name = NAME;
}

string Neutrons::get_name()
{
	return this->name;
}
