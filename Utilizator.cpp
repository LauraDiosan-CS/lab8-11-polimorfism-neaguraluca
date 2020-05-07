#include "Utilizator.h"

Utilizator::Utilizator()
{}

Utilizator::Utilizator(string n, string p):nume(n), parola(p)
{}

void Utilizator::setNume(string n)
{
	nume = n;
}
void Utilizator::setParola(string p)
{
	parola = p;
}

string Utilizator::getNume()
{
	return nume;
}

string Utilizator::getParola()
{
	return parola;
}

bool Utilizator::operator==(const Utilizator& u)
{
	return(nume == u.nume && parola == u.parola);
}

string Utilizator::toString()
{
	return nume + " " + parola;
}

string Utilizator::toStringDelimiter(char delimiter)
{
	return nume + delimiter + parola;
}

Utilizator::~Utilizator(){}