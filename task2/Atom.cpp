#include "stdafx.h"
#include "Atom.h"

using namespace std;

Atom::Atom() {}
Atom::Atom(const Atom &to_copy)
{
	this->name = to_copy.name;
	this->prt_count = to_copy.prt_count;
	this->elc_count = to_copy.elc_count;
	this->neutr_count = to_copy.neutr_count;
	for (int i = 0; i < to_copy.particles.size(); i++)
	{
		Particle *cur;
		if (to_copy.particles[i]->get_name() == "ELECTRON")
		{
			cur = new Electron();
		}
		else if (to_copy.particles[i]->get_name() == "PROTON")
		{
			cur = new Proton();
		}
		else if (to_copy.particles[i]->get_name() == "NEUTRONS") 
		{
			cur = new Neutrons();
		}
		else
		{
			throw 4;
		}
		this->add_particle(cur);
	}
}
Atom::Atom(string name, Electron *electrons, Proton *protons, Neutrons *neutrons, int elc_count, int prt_count, int neutr_count)
{
	this->name = name;
	this->elc_count = elc_count;
	this->prt_count = prt_count;
	this->neutr_count = neutr_count;
	Electron *p_elc = electrons;
	for(int i = 0; i < elc_count; i++)
	{
		this->add_particle(p_elc);
		p_elc++;
	}
	Proton *p_prt = protons;
	for (int i = 0; i < prt_count; i++)
	{
		this->add_particle(p_prt);
		p_prt++;
	}
	Neutrons *p_ntr = neutrons;
	for (int i = 0; i < neutr_count; i++)
	{
		this->add_particle(p_ntr);
		p_ntr;
	}
}
Atom::Atom(string name, int elc_count, int prt_count, int neutr_count)
{
	this->name = name;
	this->elc_count = elc_count;
	this->prt_count = prt_count;
	this->neutr_count = neutr_count;
	for (int i = 0; i < elc_count; i++)
	{
		Electron *electron = new Electron();
		this->add_particle(electron);
	}
	for (int i = 0; i < prt_count; i++)
	{
		Proton *proton = new Proton();
		this->add_particle(proton);
	}
	for (int i = 0; i < neutr_count; i++)
	{
		Neutrons *neutron = new Neutrons();
		this->add_particle(neutron);
	}
}

long double Atom::get_weight()
{
	long double sum_weight = 0;
	for (int i = 0; i < particles.size(); i++)
	{
		sum_weight += particles[i]->get_weight();
	}
	return sum_weight;
}

void Atom::set_name(string name)
{
	this->name = name;
}

void Atom::add_particle(Particle *new_particle)
{
	if (!new_particle)
	{
		return;
	}
	this->particles.push_back(new_particle);
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
	for (auto it = this->particles.begin(); it != this->particles.end(); ++it)
	{
		delete *it;
	}
}

