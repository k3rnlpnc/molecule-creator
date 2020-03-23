#include "stdafx.h"
#include "Electron.h"


Electron::Electron()
{
	this->weight = ELECTRON_WEIGHT;
	this->charge = ELECTRON_CHARGE;
	this->name = NAME;
}

string Electron::get_name()
{
	return this->name;
}
