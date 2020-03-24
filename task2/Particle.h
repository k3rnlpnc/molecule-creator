#pragma once
#include <string>
using namespace std;

class Particle
{
public:
	Particle() {};
	virtual ~Particle() = 0 {};
	virtual long double get_weight() = 0;
	string get_name();
protected:
	long double weight;
	string name;
};

