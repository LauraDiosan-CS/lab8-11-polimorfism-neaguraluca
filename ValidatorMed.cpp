/*#include "ValidatorMed.h"

ValidatorMed::ValidatorMed()
{
	err = 0;
}


int ValidatorMed::validate(Medicament a)
se asigura ca datele introduse sunt corecte:
	id:int, pozitiv
	nume:string, format din litere si eventual spatii
	stoc: int, pozitiv
	producator: string, format din litere si eventual spatii

{
	err = 0;

	if (a.getId() < 1)
	{
		err++;
		mesaj += "Id-ul trebuie sa fie pozitiv";
	}

	for (int i = 0; i < (a.getNume().length); i++)
		if (!isalpha(a.getNume()[i]) and a.getNume()[i] != ' ')
		{
			err++;
			mesaj += "Numele poate contine doar litere si spatii";
		}

	if (a.getStoc() < 0)
	{
		err++;
		mesaj += "Numarul de medicamente din stoc trebuie sa fie cel putin 0";
	}

	for (int i = 0; i < (a.getProducator().length); i++)
		if (!isalpha(a.getProducator()[i]) and a.getProducator()[i] != ' ')
		{
			err++;
			mesaj += "Numele producatorului poate contine doar litere si spatii";
		}

	return err;
}

string ValidatorMed::errorMessage()
//mesajul de eroare, in caz ca acesta exista
{
	return mesaj;
}

ValidatorMed::~ValidatorMed()
{}*/