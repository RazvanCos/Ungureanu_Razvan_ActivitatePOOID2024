#include<iostream>

using namespace std;

class Angajat {
public:
	string nume;
	const int id;
	static int numarAngajati;
	float* salariu;

	// Constructori
	Angajat() :id(++numarAngajati) {
		this->nume = "Necunoscut";
		this->salariu = nullptr; // salariu default
	};

	Angajat(string numeAngajat) :id(++numarAngajati) {
		this->nume = numeAngajat;
		this->salariu = new float(1500);
	}

	Angajat(string numeAngajat, float salariuAngajat) : id(++numarAngajati){
		this->nume = numeAngajat;
		this->salariu = new float(salariuAngajat);
	}

	static int getTotalAngajati() { // functie statica
		return numarAngajati;
	};

	// destructor

	~Angajat() {
		delete salariu;
	}
};

int Angajat::numarAngajati = 0;


class Manager {
public:
	string nume;
	static int numarManageri;
	const int idManager;
	int* echipa;

	// constructori

	Manager(): idManager(++numarManageri) {
		this->nume = "Necunoscut";
		this->echipa = new int(5);
	}

	Manager(string numeManager): idManager(++numarManageri){
		this->nume = numeManager;
		this->echipa = new int(3);
	}

	Manager(string numeManager, int numarEchipa) : idManager(++numarManageri) {
		this->nume = numeManager;
		this->echipa = new int(numarEchipa);
	}

	static int getTotalManageri() {
		return numarManageri;
	}

	// destructor
	~Manager() {
		delete echipa;
	}

};

int Manager::numarManageri = 0;

class Proiect {
public:
	string titlu;
	static int numarProiecte;
	const int idProiect;
	int* durata;

	Proiect() : idProiect(++numarProiecte) {
		this->titlu = "Necunoscut";
		this->durata = new int(6);
	};

	Proiect(string titluProiect) :idProiect(++numarProiecte) {
		this->titlu = titluProiect;
		this->durata = new int(12);
	}

	Proiect(string titluProiect, int durataProiect) : idProiect(++numarProiecte) {
		this->titlu = titluProiect;
		this->durata = new int(durataProiect);
	}

	static int getTotalProiecte() {
		return numarProiecte;
	}

	~Proiect() {
		delete durata;
	}
};

int Proiect::numarProiecte = 0;


int main() {

	Angajat a1;
	Angajat a2("Gigel");
	Angajat a3("Popescu Maria", 16);
	cout << "Numarul total de angajati este: " << a1.getTotalAngajati() << endl;

}