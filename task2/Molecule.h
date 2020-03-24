#pragma once
#include "Atom.h"
#include <string>
#include <map>
#include <memory>
#include <algorithm>

class Molecule: public Particle
{
public:
	Molecule();
	Molecule(string name, vector<Atom *> atoms, int atoms_count);
	Molecule(string name, vector<Atom *> atoms, map<string, int> composition, int atoms_count);
	~Molecule();
	long double get_weight();
	void set_atoms(vector<Atom *> atoms);
	vector<Atom *> get_atoms();
	void set_name(string name);
	void set_atoms_count(int atoms_count);
	int get_atoms_count();
	void set_composition();
	void get_info();
private:
	vector<Atom *> atoms;
	map<string, int> composition;
	int atoms_count;
};

