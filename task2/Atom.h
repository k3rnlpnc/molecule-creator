#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "Electron.h"
#include "Nucleon.h"
#include "Neutrons.h"
#include "Proton.h"
#include "Particle.h"

using namespace std;


class Atom: public Particle
{
public:
	Atom();
	Atom(const Atom &to_copy);
	Atom(string name, Electron *electrons, Proton *protons, Neutrons *neutrons, int elc_count, int prt_count, int neutr_count);
	Atom(string name, int elc_count, int prt_count, int neutr_count);
	~Atom();
	long double get_weight();
	void set_name(string name);
	void set_prt_count(int prt_count);
	int get_prt_count();
	void set_neutr_count(int neutr_count);
	int get_neutr_count();
	void set_electrons_count(int el_count);
	int get_electrons_count();
	void add_particle(Particle *new_particle);
private:
	vector<Particle *> particles;
	int elc_count;
	int prt_count;
	int neutr_count;
};

