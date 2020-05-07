#include "Angajat.h"
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

Angajat::Angajat()
//constructor implicit
{
	this->id = 0;
	this->nume = "";
	this->mail = "";
	this->grad = 0;
}

Angajat::Angajat(int i, string n, string m, int g)
//constructor cu parametrii
{
	this->id = i;
	this->nume = n;
	this->mail = m;
	this->grad = g;
}

vector<string> Angajat::splitLine(string linie, char delim)
/*creaza un vector cu obiecte de tip string(atributele unui
obiect in urma citirii din fisier*/
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

Angajat::Angajat(string linie, char delimitator)
/*creaza un obiect de tip angajat prin delimitarea parametrilor
obiectului, atunci cand este citit dintr-o linie dintr-un fisier
input: linie: string, linia pe care se afla atributele obiectului
       delim: char, delimitatorul specific fiecarui tip de fisier*/
{
	vector<string> tokens = splitLine(linie, delimitator);
	id = stoi(tokens[0]);

	nume = tokens[1];

	mail = tokens[2];

	grad = stoi(tokens[3]);
}

Angajat::Angajat(const Angajat&a)
//constructor de copiere
{
	id = a.id;
	nume = a.nume;
	mail = a.mail;
	grad = a.grad;
}

void Angajat::setId(int i)
//seteaza id-ul
{
	id = i;
}

void Angajat::setNume(string n)
{
	nume = n;
}

void Angajat::setMail(string m)
{
	mail = m;
}

void Angajat::setGrad(int g)
{
	grad = g;
}

int Angajat::getId()
//gaseste id-ul
{
	return id;
}

string Angajat::getNume()
{
	return nume;
}

string Angajat::getMail()
{
	return mail;
}

int Angajat::getGrad()
{
	return grad;
}

bool Angajat::operator ==(const Angajat&a)
//operator de egalitate
{
	return(id == a.id);
}

string Angajat::toString()
//converteste in string atributele entitatii
{
	return to_string(id) + " " + nume + " " + mail + " " + to_string(grad);
}

string Angajat::toStringDelimiter(char d)
/*converteste in string atributele entitatii tinand cont de
delimitatorul acceptat de tipul de fisier folosit*/
{
	return to_string(id) + d + nume + d + mail + d + to_string(grad);
}

Angajat::~Angajat(){}