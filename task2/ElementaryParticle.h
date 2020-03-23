#pragma once
#include <string>
using namespace std;

class ElementaryParticle
{
public:
	long double get_weight();
	long double get_charge();
	virtual string get_name() = 0;
	virtual ~ElementaryParticle() {};
protected:
	long double charge;
	long double weight;
	string name;
};

