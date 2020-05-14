#include "MedicineService.h"

MedicineService::MedicineService()
{}

MedicineService::MedicineService(Repository<Medicament>* repo)
{
	this->repoMed = repo;
}

void MedicineService::add(Medicament)
{
	
	Medicament m;
	repoMed->add(m);
	
}

void MedicineService::remove(int i)
{
	//Medicament m = repoMed->getById(i);
	repoMed->remove(i);
}

void MedicineService::update(Medicament vechi, Medicament& nou)
{
	
	repoMed->update(vechi, nou);
	
}

Medicament MedicineService::getById(int id)
{
	return repoMed->getById(id);
}

vector<Medicament> MedicineService::search(string s)
//gaseste toate medicamentele care au in nume un subsir dat
{
	vector<Medicament> found;
	vector<Medicament> allMed = repoMed->getAll();
	for (Medicament m : allMed)
		if (m.getNume().find(s) != string::npos)
			found.push_back(m);
	return found;
}

vector<Medicament> MedicineService::getAll()
{
	return repoMed->getAll();
}

MedicineService::~MedicineService(){}