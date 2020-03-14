#include "stdafx.h"
#include "Molecule.h"


Molecule::Molecule()
{
}

Molecule::Molecule(string name, Atom *atoms, int atoms_count)
{
	this->name = name;
	this->atoms = atoms;
	this->atoms_count = atoms_count;
}

map<string, int> Molecule::molecule_info()
{
	map<string, int> types_counter;
	Atom *cur_atom = this->atoms;
	for (int i = 0; i < atoms_count; i++)
	{
		int is_el = types_counter.count((*cur_atom).get_name());
		if (is_el)
		{
			types_counter.at((*cur_atom).get_name()) = ++types_counter.find((*cur_atom).get_name())->second;
		}
		else
		{
			types_counter.insert(pair<string, int>((*cur_atom).get_name(), 1));
		}
		cur_atom++;
	}
	
	return types_counter;
}

long double Molecule::el_particles_mass()
{
	long double sum_weight = 0;
	Atom *cur_atom = this->atoms;
	for (int i = 0; i < atoms_count; i++)
	{
		sum_weight += (*cur_atom).el_particles_weight();
		cur_atom++;
	}
	return sum_weight;
}

long double Molecule::molecule_mass()
{
	long double sum_mass = 0;
	Atom *cur_atom = this->atoms;
	for (int i = 0; i < atoms_count; i++)
	{
		sum_mass += (*cur_atom).get_atomic_mass();
		cur_atom++;
	}
	return sum_mass;
}

void Molecule::set_atoms_count(int atoms_count)
{
	this->atoms_count = atoms_count;
}

int Molecule::get_atoms_count()
{
	return this->atoms_count;
}

void Molecule::set_atoms(Atom *atoms)
{
	this->atoms = atoms;
}

Atom *Molecule::get_atoms()
{
	return this->atoms;
}

void Molecule::set_name(string name)
{
	this->name = name;
}

string Molecule::get_name()
{
	return this->name;
}

Molecule::~Molecule()
{
}
