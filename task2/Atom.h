#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "Electron.h"
#include "Nucleon.h"
#include "Neutrons.h"
#include "Proton.h"

using namespace std;


class Atom
{
public:
	Atom();
	~Atom();
	Atom(const Atom &to_copy);
	Atom(string name, long double atomic_mass, Electron *electrons, Proton *protons, Neutrons *neutrons, int elc_count, int prt_count);
	Atom(string name, long double atomic_mass, int elc_count, int prt_count);
	void set_atomic_mass(double amu);
	long double get_atomic_mass();
	void set_name(string name);
	string get_name();
	void add_particle(ElementaryParticle *new_particle);
	void set_prt_count(int prt_count);
	int get_prt_count();
	void set_neutr_count(int neutr_count);
	int get_neutr_count();
	void set_electrons_count(int el_count);
	int get_electrons_count();
	long double el_particles_mass();
private:
	const long double ATOMIC_MASS_UNIT = 1.6605e-27;

	long double atomic_mass;
	string name;
	vector<ElementaryParticle *> particles;
	int elc_count;
	int prt_count;
	int neutr_count;
};

