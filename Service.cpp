#include "Service.h"

Service::Service()
{}


Service::Service(Repository<Medicament>* repoMed, Repository<Angajat>* repoAng, Repository<Utilizator>* repoUtil)
{
	this->repoMed = repoMed;
	this->repoAng = repoAng;
	this->repoUtil = repoUtil;
}



bool Service::login(string n, string p)
{
	Utilizator user(n, p);
	return repoUtil->find(user) != -1;
}

void Service::logout(string n, string p)
{
	Utilizator user(n, p);
	//repoUtil->remove(user);
}



void Service::updateGrad(int id_angajat, int introdus)
{
	if (introdus < id_angajat)
		cout << "Actulaizare nepermisa";
	else
	{
		Angajat found = repoAng->getById(id_angajat);
		string foundName = found.getNume();
		string foundMail = found.getMail();
		Angajat updated(id_angajat, foundName, foundMail, introdus);
		repoAng->update(found, updated);
	}
}


vector<Angajat> Service::allAng()
{
	return repoAng->getAll();
}

vector<Utilizator> Service::allUtil()
{
	return repoUtil->getAll();
}

Service::~Service(){}