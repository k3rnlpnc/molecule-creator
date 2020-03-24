#include "stdafx.h"
#include "Electron.h"


Electron::Electron()
{
	this->weight = ELECTRON_WEIGHT;
	this->name = NAME;
}

long double Electron::get_weight()
{
	return this->weight;
}
