#include "Medicament.h"
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

Medicament::Medicament()
//constructor implicit
{
	this->id = 0;
	this->nume = ""; 
	this->reteta = false;
	this->stoc = 0;
	this->producator = "";
}


Medicament::Medicament(int i, string n, bool r, int s, string p)
//constructor cu parametrii
{
	this->id = i;
	this->nume = n;
	this->reteta = r;
	this->stoc = s;
	this->producator = p;
}

vector<string> Medicament::splitLine(string linie, char delim)
/*creaza un vector cu obiecte de tip string(atributele unui
obiect)in urma citirii din fisier*/
{
	stringstream ss(linie);
	string item;
	vector<string> elems;
	while (getline(ss, item, delim))
	{
		elems.push_back(item);
	}
	return elems;
}

Medicament::Medicament(string linie, char delimitator)
/*creaza un obiect de tip medicament prin delimitarea parametrilor
obiectului, atunci cand este citit dintr-o linie dintr-un fisier
input: linie: string, linia pe care se afla atributele obiectului
	   delim: char, delimitatorul specific fiecarui tip de fisier*/

{
	vector<string> tokens = splitLine(linie, delimitator);
	id = stoi(tokens[0]);

	nume = tokens[1];

	reteta = (tokens[2] == "1");
	stoc = stoi(tokens[3]);

	producator = tokens[4];
	
}

Medicament::Medicament(const Medicament& m)
//constructor ded copierer
{
	id = m.id;
	nume = m.nume;
	reteta = m.reteta;
	stoc = m.stoc;
	producator = m.producator;
}

int Medicament::getId()
{
	return id;
}

string Medicament::getNume()
{
	return nume;
}

bool Medicament::getReteta()
{
	return reteta;
}

int Medicament::getStoc()
{
	return stoc;
}

string Medicament::getProducator()
{
	return producator;
}

void Medicament::setId(int i)
{
	id = i;
}

void Medicament::setNume(string n)
{
	nume = n;
}

void Medicament::setReteta(bool r)
{
	reteta = r;
}

void Medicament::setStoc(int s)
{
	stoc = s;
}

void Medicament::setProducator(string p)
{
	producator = p;
}

bool Medicament::operator==(const Medicament& m)
{
	return (id == m.id);
}

string Medicament::toString()
//converteste in string atributele entitatii
{
	return to_string(id) + " " + nume + " " + to_string(reteta) + " " + to_string(stoc) + " " + producator;
}

string Medicament::toStringDelimiter(char d)
/*converteste in string atributele entitatii tinand cont de
delimitatorul acceptat de tipul de fisier folosit*/
{
	return to_string(id) + d + nume + d+ to_string(reteta) +d+ to_string(stoc) + d + producator;
}

Medicament::~Medicament()
{}//destructor