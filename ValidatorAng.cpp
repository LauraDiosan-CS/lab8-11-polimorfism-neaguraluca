/*#include "ValidatorAng.h"

ValidatorAng::ValidatorAng()
{
	err = 0;
}


int ValidatorAng::validate(Angajat a)

{
	err = 0;

	if (a.getId() < 1)
	{
		err++;
		mesaj += "Id-ul trebuie sa fie pozitiv";
	}

	for(int i=0; i<(a.getNume().length); i++)
		if (!isalpha(a.getNume()[i]) and a.getNume()[i] != ' ')
		{
			err++;
			mesaj += "Numele poate contine doar litere si spatii";
		}

	if (a.getGrad() < 1)
	{
		err++;
		mesaj += "Gradul trebuie sa fie pozitiv";
	}

	return err;
}

string ValidatorAng::errorMessage()
//mesajul de eroare, in caz ca acesta exista
{
	return mesaj;
}

ValidatorAng::~ValidatorAng()
{}*/