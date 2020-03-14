#pragma once
#include "Atom.h"
#include <string>
#include <map>

class Molecule
{
public:
	Molecule();
	Molecule(string name, Atom *atoms, int atoms_count);
	~Molecule();
	void set_atoms(Atom *atoms);
	Atom *get_atoms();
	void set_name(string name);
	string get_name();
	void set_atoms_count(int atoms_count);
	int get_atoms_count();
	long double el_particles_mass();
	long double molecule_mass();
	map<string, int> molecule_info();
private:
	string name;
	Atom *atoms;
	int atoms_count;
};

