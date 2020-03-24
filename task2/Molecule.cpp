#include "stdafx.h"
#include "Molecule.h"


Molecule::Molecule()
{
}

Molecule::Molecule(string name, vector<Atom *> atoms, int atoms_count)
{
	this->name = name;
	this->atoms = atoms;
	this->atoms_count = atoms_count;
	set_composition();
}
Molecule::Molecule(string name, vector<Atom *> atoms, map<string, int> composition, int atoms_count)
{
	this->name = name;
	this->atoms = atoms;
	this->atoms_count = atoms_count;
	this->composition = composition;
}

void Molecule::get_info()
{
	cout << "Molecule name: " << this->get_name() << endl;
	cout << "Molecule's mass: " << this->get_weight() << endl;
	for (auto item = this->composition.begin(); item != this->composition.end(); ++item)
	{
		cout << "Count of " << item->first << " : " << item->second << endl;
	}
}

void Molecule::set_composition()
{
	for (int i = 0; i < this->atoms_count; i++)
	{
		if (!this->composition.count(this->atoms[i]->get_name()))
		{
			this->composition.insert(pair<string, int>(this->atoms[i]->get_name(), 1));
		}
		else
		{
			this->composition.at(this->atoms[i]->get_name()) += 1;
		}
	}
}

long double Molecule::get_weight()
{
	long double sum_weight = 0;
	for (int i = 0; i < atoms_count; i++)
	{
		sum_weight += this->atoms[i]->get_weight();
	}
	return sum_weight;
}

void Molecule::set_atoms_count(int atoms_count)
{
	this->atoms_count = atoms_count;
}

int Molecule::get_atoms_count()
{
	return this->atoms_count;
}

void Molecule::set_atoms(vector<Atom *> atoms)
{
	this->atoms = atoms;
}

vector<Atom *> Molecule::get_atoms()
{
	return this->atoms;
}

void Molecule::set_name(string name)
{
	this->name = name;
}

Molecule::~Molecule()
{
	for (auto it = this->atoms.begin(); it != this->atoms.end(); ++it)
	{
		delete *it;
	}
}
