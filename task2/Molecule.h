#pragma once
#include "Atom.h"
#include <string>
#include <map>
#include <memory>
#include <algorithm>

class Molecule
{
public:
	Molecule();
	Molecule(string name, vector<Atom *> atoms, int atoms_count);
	Molecule(string name, vector<Atom *> atoms, map<string, int> composition, int atoms_count);
	~Molecule();
	void set_atoms(vector<Atom *> atoms);
	vector<Atom *> get_atoms();
	void set_name(string name);
	string get_name();
	void set_atoms_count(int atoms_count);
	int get_atoms_count();
	void set_composition();
	long double el_particles_mass();
	long double molecule_mass();
	void get_info();
private:
	string name;
	vector<Atom *> atoms;
	map<string, int> composition;
	int atoms_count;
};

