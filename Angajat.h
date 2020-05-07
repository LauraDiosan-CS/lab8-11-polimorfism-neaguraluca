#pragma once
#include <string>
#include <vector>
using namespace std;

class Angajat
{
private:
	int id;
	string nume;
	string mail;
	int grad;
public:
	Angajat();
	Angajat(int, string, string, int);
	vector<string> splitLine(string, char);
	Angajat(string, char);
	Angajat(const Angajat&);
	void setId(int);
	void setNume(string);
	void setMail(string);
	void setGrad(int);
	int getId();
	string getNume();
	string getMail();
	int getGrad();
	bool operator ==(const Angajat&);
	string toString();
	string toStringDelimiter(char);
	~Angajat();
};
