#include "Test.h"
#include <iostream>
#include <cassert>
using namespace std;

Test::Test()
{}

void Test::testAng()
//teste pt entitatea "Angajat"
{
	Angajat a1(20, "Dana", "dana@gmail.com", 5);
	Angajat a2(21, "Marius", "marius123@gmail.com", 3);

	assert(a1.getGrad() == 5);
	//assert(a1.getMail == "dana@gmail.com");
	assert(a2.getId() == 21);
	string numea2 = "Marius";
	assert(a2.getNume()== numea2);
	//assert((a1 == a2) != 0);

	a2.setNume("Edi");
	assert(a2.getNume() != numea2);

}

void Test::testMed()
//teste pt entitatea "Medicament"
{
	Medicament m1(30, "algocalmin", 0, 100, "zentiva");
	Medicament m2 = m1;
	Medicament m3 = m2;

	string nume3 = "alprazolam";
	m3.setNume("alprazolam");

	assert(m2.getId() == 30);
	assert(m3.getNume() == nume3);
	assert(m3.getReteta() == 0);
}

void Test::testUser()
//teste pt entitatea "Utilizator"
{
	Utilizator u1("Raluca", "parola123");
	assert(u1.getParola() == "parola123");
	u1.setParola("parola45");
	assert(u1.getParola() != "parola123");
}

void Test::testCsv()
//teste pt repository-ul ce foloseste fisiere de tip "*.csv"
{
	const char* fileName = "Medicamente.csv";
	
	RepositoryFile<Medicament>* repo = new RepositoryFileCSV<Medicament>(fileName);
	((RepositoryFileCSV<Medicament>*)repo)->loadFromFile();
	assert(repo->size() == 4);

	Medicament m(47, "plasture", 1, 39, "abc");
	Medicament m1(47, "plasture", 0, 45, "abc");
	repo->add(m);
	assert(repo->size() == 5);

	repo->update(m, m1);
	assert(m.getStoc() == 39);

	repo->remove(47);
	assert(repo->size() == 4);
}

void Test::testTxt()
//teste pt repository-ul ce foloseste fisiere de tip "*.txt"
{
	const char* fileName = "Angajati.txt";
	RepositoryFile<Angajat>* repo=new RepositoryFileTXT<Angajat>(fileName);
	((RepositoryFile<Angajat>*)repo)->loadFromFile();
	assert(repo->size() == 4);
}

void Test::testLive()
{
	Repository<Medicament>* repo = new RepositoryFileTXT<Medicament>();
	Medicament m1 = Medicament(100, "parasinus", false, 10, "p1");
	Medicament m2 = Medicament(200, "ketonal", false, 90, "p2");
	Medicament m3 = Medicament(300, "antibiotic", true, 70, "p3");

	repo->add(m1);
	repo->add(m2);
	assert(repo->getAll().size() == 2);
	assert(repo->getAll()[0] == m1);
	assert(repo->getAll()[1] == m2);
	repo->add(m3);
	assert(repo->getAll()[2] == m3);

	//Medicament m1_new(100, "paracetamol", false, 50, "p1");
	//repo->update(m1, m1_new);
	//assert(repo->getAll()[0] != m1);
	//assert(repo->getAll()[0] == m1_new);

	repo->remove(200);
	assert(repo->getAll().size() == 2);
}

void Test::runTests()
{
	testAng();
	testMed();
	testUser();
	testCsv();
	testTxt();
	
}

Test::~Test()
{}