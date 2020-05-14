#pragma once
#include "Service.h"
class MedicineService: public Service
{
public:
	MedicineService();
	MedicineService(Repository<Medicament>*);
	void add(Medicament);
	void remove(int);
	void update(Medicament, Medicament&);
	vector<Medicament> search(string);
	vector<Medicament> getAll();
	Medicament getById(int);
	~MedicineService();
};
