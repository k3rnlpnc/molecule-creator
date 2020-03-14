#include "stdafx.h"
#include "ElementaryParticle.h"


ElementaryParticle::ElementaryParticle()
{
}

void ElementaryParticle::set_weight(long double weight)
{
	this->weight = weight;
}

long double ElementaryParticle::get_weight()
{
	return this->weight;
}

ElementaryParticle::~ElementaryParticle()
{
}
