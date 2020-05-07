#pragma once
#include "IRepo.h"
#include "RepoFile.h"
#include "RepoTXT.h"
#include "RepoCSV.h"
#include "Angajat.h"
#include "Medicament.h"
#include "Utilizator.h"

class Test
{
private:
	void testMed();
	void testAng();
	void testUser();
	void testCsv();
	void testTxt();
	void testLive();
public:
	Test();
	void runTests();
	~Test();
};