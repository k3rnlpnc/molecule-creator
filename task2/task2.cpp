// task2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Molecule.h"
#include "Atom.h";
#include "Proton.h"
#include "Neutrons.h"
#include "Electron.h"
#include <iostream>
#include <ctype.h>
#include <map>
#include <fstream>
#include <strstream>
#include <math.h>

int create_new_atom(string element_name, Atom *atom)
{
	string element_string;
	fstream file("elements.txt");
	if (!file)
	{
		cout << "Opening file error" << endl;
		return -1;
	}
	while (getline(file, element_string))
	{
		strstream element;
		element << element_string;
		string name;
		element >> name;
		if (name == element_name)
		{
			int elc_count, prt_count;
			long double atomic_mass;
			int neutr_count;
			element >> elc_count >> atomic_mass;
			prt_count = elc_count;
			neutr_count = round(atomic_mass) - prt_count;
			file.close();
			Electron *electrons = new Electron[elc_count];
			Proton *protons = new Proton[prt_count];
			Neutrons *neutrons = new Neutrons[neutr_count];
			atom = new Atom(name, atomic_mass, electrons, protons, neutrons, elc_count, prt_count, neutr_count);
			return 0;
		}
	}
	cout << "Element doesn't exist" << endl;
	return -1;
}

int atoms_count(map<string, int> elements)
{
	int count = 0;
	for (auto current = elements.begin(); current != elements.end(); current++)
	{
		count += current->second;
	}
	return count;
}

map<string, int> parse_the_formula(char *formula)
{
	map<string, int> elements;
	int i = 0;
	int count = 1;
	string element_name = "";
	while (formula[i])
	{
		if (isupper(formula[i]))
		{
			if (element_name.length() >= 1) 
			{
				if (elements.count(element_name))
				{
					elements.at(element_name) += count;
				}
				else
				{
					elements.insert(pair<string, int>(element_name, count));
				}
				count = 1;
				element_name = "";
				continue;
			}
			else
			{
				element_name += formula[i];
			}
			if (!formula[i + 1])
			{
				if (elements.count(element_name))
				{
					elements.at(element_name) += count;
				}
				else
				{
					elements.insert(pair<string, int>(element_name, count));
				}
			}
			i++;
			continue;
		}
		else if (isdigit(formula[i]))
		{
			count = formula[i] - '0';
			if (elements.count(element_name))
			{
				elements.at(element_name) += count;
			}
			else
			{
				elements.insert(pair<string, int>(element_name, count));
			}
			i++;
			continue;
		}
		else
		{
			element_name += formula[i];
			i++;
		}
	}
	return elements;
}

int main()
{
	char *formula = new char;

	while (true)
	{
		cout << "Input the formula or '0' to exit: " << endl;
		cin >> formula;
		if (*formula == '0')
		{
			return 0;
		}
		else
		{
			map<string, int> elements;
			elements = parse_the_formula(formula);
			int count = atoms_count(elements);
			Atom *atoms = new Atom[count];
			int i = 0;
			for (auto cur = elements.begin(); cur != elements.end(); cur++)
			{
				create_new_atom(cur->first, &atoms[i]);
				for (int j = 1; j <= cur->second; j++)
				{
					atoms[i + j] = Atom(atoms[i]);
				}
				cout << cur->first << " was created..." << endl;
				i+=cur->second+1;
			}
			Molecule molecule(formula, atoms, elements.size());
		}
	}
	delete formula;
	return 0;
}




