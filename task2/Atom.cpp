#include "stdafx.h"
#include "Atom.h"

using namespace std;

Atom::Atom() {}
Atom::Atom(string name, long double atomic_mass, Electron *electrons, Proton *protons, Neutrons *neutrons, int elc_count, int prt_count, int neutr_count)
{
	this->name = name;
	this->atomic_mass = atomic_mass;
	this->electrons = electrons;
	this->protons = protons;
	this->neutrons = neutrons;
	this->elc_count = elc_count;
	this->prt_count = prt_count;
	this->neutr_count = neutr_count;
}
Atom::Atom(string name, long double atomic_mass, Electron *electrons, Proton *protons, int elc_count, int prt_count)
{
	this->name = name;
	this->atomic_mass = atomic_mass;
	this->electrons = electrons;
	this->protons = protons;
	this->elc_count = elc_count;
	this->prt_count = prt_count;
}

long double Atom::el_particles_weight()
{
	long double sum_weight = 0;
	Proton *cur_prt = protons;
	Neutrons *cur_neutr = neutrons;
	Electron *cur_electron = electrons;
	for (int i = 0; i < prt_count; i++)
	{
		sum_weight += (*cur_prt).get_weight();
		cur_prt++;
	}
	for (int i = 0; i < neutr_count; i++)
	{
		sum_weight += (*cur_neutr).get_weight();
		cur_neutr++;
	}
	for (int i = 0; i < elc_count; i++)
	{
		sum_weight += (*cur_electron).get_weight();
		cur_electron++;
	}
	return sum_weight;
}

void Atom::set_atomic_mass(double amu)
{
	this->atomic_mass = amu * ATOMIC_MASS_UNIT;
}

long double Atom::get_atomic_mass()
{
	return this->atomic_mass;
}

void Atom::set_name(string name)
{
	this->name = name;
}

string Atom::get_name()
{
	return this->name;
}

void Atom::set_protons(Proton *protons) 
{
	this->protons = protons;
}

Proton *Atom::get_protons()
{
	return this->protons;
}

void Atom::set_neutrons(Neutrons *neutrons)
{
	this->neutrons = neutrons;
}

Neutrons *Atom::get_neutrons()
{
	return this->neutrons;
}

void Atom::set_electrons(Electron *electrons)
{
	this->electrons = electrons;
}

Electron *Atom::get_electrons()
{
	return this->electrons;
}

void Atom::set_prt_count(int prt_count)
{
	this->prt_count = prt_count;
}

int Atom::get_prt_count()
{
	return this->prt_count;
}

void Atom::set_neutr_count(int neutr_count)
{
	this->neutr_count = neutr_count;
}

int Atom::get_neutr_count()
{
	return this->neutr_count;
}

void Atom::set_electrons_count(int elc_count)
{
	this->elc_count = elc_count;
}

int Atom::get_electrons_count()
{
	return this->elc_count;
}

Atom::~Atom() 
{
}

