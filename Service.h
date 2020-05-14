#pragma once
#include "IRepo.h"
#include "RepoCSV.h"
#include "RepoFile.h"
#include "RepoTXT.h"
#include "Angajat.h"
#include "Medicament.h"
#include "Utilizator.h"


class Service
{
protected:
	Repository<Medicament>* repoMed;
	Repository<Angajat>* repoAng;
	Repository<Utilizator>* repoUtil;
public:
	Service();
	Service(Repository<Medicament>*, Repository<Angajat>*, Repository<Utilizator>*);
	bool login(string, string);
	void logout(string, string);
	
	void updateGrad(int, int);
	
	vector<Angajat> allAng();
	vector<Utilizator> allUtil();
	~Service();

};