#pragma once
#include <string>
#include "Electron.h"
#include "Nucleon.h"
#include "Neutrons.h"
#include "Proton.h"

using namespace std;


class Atom
{
public:
	Atom();
	Atom(string name, long double atomic_mass, Electron *electrons, Proton *protons, Neutrons *neutrons, int elc_count, int prt_count, int neutr_count);
	Atom(string name, long double atomic_mass, Electron *electrons, Proton *protons, int elc_count, int prt_count);
	~Atom();
	void set_atomic_mass(double amu);
	long double get_atomic_mass();
	void set_name(string name);
	string get_name();
	void set_protons(Proton *protons);
	Proton *get_protons();
	void set_neutrons(Neutrons *neutrons);
	Neutrons *get_neutrons();
	void set_electrons(Electron *electrons);
	Electron *get_electrons();
	void set_prt_count(int prt_count);
	int get_prt_count();
	void set_neutr_count(int neutr_count);
	int get_neutr_count();
	void set_electrons_count(int el_count);
	int get_electrons_count();
	long double el_particles_weight();
private:
	const long double ATOMIC_MASS_UNIT = 1.6605e-27;
	long double atomic_mass;
	string name;
	Electron *electrons;
	Proton *protons;
	Neutrons *neutrons;
	int elc_count;
	int prt_count;
	int neutr_count;
};

