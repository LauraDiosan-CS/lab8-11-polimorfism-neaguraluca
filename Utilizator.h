#pragma once
#include <string>
using namespace std;

class Utilizator
{
private:
	string nume;
	string parola;
public:
	Utilizator();
	Utilizator(string, string);
	void setNume(string);
	void setParola(string);
	string getNume();
	string getParola();
	bool operator==(const Utilizator& u);
	string toString();
	string toStringDelimiter(char delimiter);
	~Utilizator();
};
