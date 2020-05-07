#pragma once
#include <string>
#include <vector>
using namespace std;

class Medicament
{
private:
	int id;
	string nume;
	bool reteta;
	int stoc;
	string producator;
public:
	Medicament();
	Medicament(int, string, bool, int, string);
	vector<string> splitLine(string linie, char delim);
	Medicament(string, char);
	Medicament(const Medicament&);
	int getId();
	string getNume();
	bool getReteta();
	int getStoc();
	string getProducator();
	void setId(int);
	void setNume(string);
	void setReteta(bool);
	void setStoc(int);
	void setProducator(string);
	bool operator==(const Medicament&);
	string toString();
	string toStringDelimiter(char);
	~Medicament();
};
