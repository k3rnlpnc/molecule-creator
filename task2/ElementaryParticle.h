#pragma once
class ElementaryParticle
{
public:
	ElementaryParticle();
	~ElementaryParticle();
	void set_weight(long double weight);
	long double get_weight();

protected:
	long double weight;
};

