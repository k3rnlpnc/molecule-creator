#include "stdafx.h"
#include "Neutrons.h"

#include <iostream>
using namespace std;

Neutrons::Neutrons()
{
	this->weight = NEUTRONS_WEIGHT;
	this->name = NAME;
}

long double Neutrons::get_weight()
{
	return this->weight;
}
