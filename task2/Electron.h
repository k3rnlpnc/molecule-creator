#pragma once
#include "ElementaryParticle.h"

class Electron: public ElementaryParticle
{
public:
	Electron();
	~Electron();

private:
	const long double ELECTRON_WEIGHT = 9.1093e-31;
};

