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
#include <vector>
#include <memory>

#define ELEMENTS_TABLE "elements.txt"

Atom* create_new_atom(string element_name)
{
	string element_string;
	fstream file(ELEMENTS_TABLE);
	if (!file)
	{
		throw 1;
	}
	Atom *atom = nullptr;
	while (getline(file, element_string))
	{
		strstream element;
		element << element_string;
		string name;
		element >> name;
		if (name == element_name)
		{
			int elc_count, prt_count, neutr_count;
			element >> elc_count;
			prt_count = elc_count;
			element >> neutr_count;
			atom = new Atom(name, elc_count, prt_count, neutr_count);
			file.close();
			return atom;
		}
	}
	throw 2;
}

map<string, int> parse_the_formula(string formula, int *total_count)
{
	map<string, int> elements;
	int i = 0;
	int count = 1;
	string element_name = "";
	while (formula[i])
	{
		if (isalpha(formula[i]))
		{
			if (isupper(formula[i]))
			{
				if (element_name != "")
				{
					if (!elements.count(element_name))
					{
						elements.insert(pair<string, int>(element_name, count));
					}
					else
					{
						elements.at(element_name) += count;
					}
					*total_count += count;
					element_name = "";
					count = 1;
				}
			}
			element_name += formula[i];
			i++;
		}
		else if (isdigit(formula[i]))
		{
			count = formula[i] - '0';
			i++;
		}
		else
		{
			throw 3;
		}
	}
	if (!elements.count(element_name))
	{
		elements.insert(pair<string, int>(element_name, count));
	}
	else
	{
		elements.at(element_name) += count;
	}
	*total_count += count;
	return elements;
}

int main()
{
	try {
		string formula;

		while (true)
		{
			cout << "Input the formula or '0' to exit: " << endl;
			cin >> formula;
			if (formula == "0")
			{
				return 0;
			}
			else
			{
				map<string, int> elements;
				int count = 0; int *pcount = &count;
				elements = parse_the_formula(formula, pcount);
				vector<Atom *> atoms;
				for (auto current = elements.begin(); current != elements.end(); current++)
				{
					Atom *cur = create_new_atom(current->first);
					for (int j = 0; j < current->second; j++)
					{
						Atom *a = new Atom(*cur);
						atoms.push_back(a);
					}
					delete cur;
				}
				Molecule molecule(formula, atoms, elements, count);
				molecule.get_info();
			}
			cout << endl;
		}
		return 0;
	}
	catch (int exc_code)
	{
		switch (exc_code)
		{
			case 1:
				cout << "Opening file error." << endl;
				break;
			case 2:
				cout << "Element doesn't exist." << endl;
				break;
			case 3:
				cout << "Parsing formula error." << endl;
				break;
			case 4:
				cout << "Object type error." << endl;
				break;
			default:
				cout << "Executing error." << endl;
				break;
		}

	}
	
}




