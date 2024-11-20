#include<iostream>
#include<string>
using namespace std;

class Autobuz {

private:
	static int nrAutobuze;
	const int idAutobuz;
	int capacitate;
	int nrPersoaneImbarcate;
	char* producator;

public:
	// Constructor default fara parametrii
	Autobuz() :idAutobuz(++nrAutobuze) {
		this->capacitate = 50;
		this->nrPersoaneImbarcate = 0;
		this->producator = nullptr;
	}

	// Constructor cu parametrii
	Autobuz(int capac, int nrPersImb, char* prod) :idAutobuz(++nrAutobuze) {
		if (capac > 0) {
			this->capacitate = capac;
		}
		else {
			cout << "Capacitatea autobuzului trebuie sa fie un numar pozitiv" << endl;
		}

		if (nrPersImb > 0 && nrPersImb <= this->capacitate) {
			this->nrPersoaneImbarcate = nrPersImb;
		}
		else {
			cout << "Numarul de persoane imbarcate nu poate fi negativ si nici mai mare decat capacitatea autobuzului!" << endl;
		}

		if (prod != nullptr && strlen(prod) > 0) {
			this->producator = new char[strlen(prod) + 1];
			for (int i = 0; i < strlen(prod) + 1; i++) {
				this->producator[i] = prod[i];
			}
		}
		else {
			cout << "Producator invalid" << endl;
		}
	}

	// Destructor
	~Autobuz() {
		if (this->producator != nullptr) {
			delete[] this->producator;
		}
	}

	// Constructor de copiere
	Autobuz(const Autobuz& newAutobuz) :idAutobuz(++nrAutobuze) {
		this->capacitate = newAutobuz.capacitate;
		this->nrPersoaneImbarcate = newAutobuz.nrPersoaneImbarcate;

		if (newAutobuz.producator != nullptr) {
			this->producator = new char[strlen(newAutobuz.producator) + 1];
			for (int i = 0; i < strlen(newAutobuz.producator) + 1; i++) {
				this->producator[i] = newAutobuz.producator[i];
			}
		}
		else {
			this->producator = nullptr;
		}
	}


	// Metode accesor

	// Getteri

	int getCapacitate() {
		return this->capacitate;
	}

	int getNrPersoaneImbarcate() {
		return this->nrPersoaneImbarcate;
	}

	// Setteri
	void setCapacitate(int capac) {
		if (capac > 0 && capac >= this->nrPersoaneImbarcate) {
			this->capacitate = capac;
		}
		else {
			cout << "Capacitatea nu poate fi negativa si nici mai mica decat numarul persoanelor imbarcate" << endl;
		}
	}

	void setNrPersoaneImbarcate(int nrPersImbarcate) {
		if (nrPersImbarcate > 0 && nrPersImbarcate < this->capacitate) {
			this->nrPersoaneImbarcate = nrPersImbarcate;
		}
		else {
			cout << "Numarul de persoane este invalid." << endl;
		}
	}

	// Supraincarcare operator = 
	Autobuz operator=(const Autobuz& newAutobuz) {
		if (this != &newAutobuz) { // Verificare auto-atribuire
			// eliberare memorie
			if (this->producator != nullptr) {
				delete[] this->producator;
			}
			this->capacitate = newAutobuz.capacitate;
			this->nrPersoaneImbarcate = newAutobuz.nrPersoaneImbarcate;

			if (newAutobuz.producator != nullptr) {
				this->producator = new char[strlen(newAutobuz.producator) + 1];
				for (int i = 0; i < strlen(newAutobuz.producator) + 1; i++) {
					this->producator[i] = newAutobuz.producator[i];
				}
			}
			else {
				this->producator = nullptr;
			}
		}
		return *this;
	}

	// Supraincarcarea operatorului <<
	friend ostream& operator<<(ostream& os, const Autobuz& autobuz) {
		os << "ID Autobuz: " << autobuz.idAutobuz << "; Capacitate: " << autobuz.capacitate
			<< "; Nr. Persoane Imbarcate: " << autobuz.nrPersoaneImbarcate << "; Producator: " << autobuz.producator;
		return os;
	}

	// Calculeaza si returneaza numarul de locuri libere ramase in autobuz
	int getNumarLocuriLibere() {
		return this->capacitate - this->nrPersoaneImbarcate;
	}


	// Supraincarcarea operator de cast la int
	operator int() {
		return nrPersoaneImbarcate;
	}

	// Supraincarcare operator >
	bool operator>(const Autobuz& newAutobuz) {
		return this->capacitate > newAutobuz.capacitate;
	}

	// Supraincarare operator ==
	bool operator==(const Autobuz& newAutobuz) {
		return this->capacitate == newAutobuz.capacitate;
	}

	// Metoda de afisare
	void afiseazaAutobuz() {
		cout << "Autobuzul cu id-ul: " << this->idAutobuz << " are capacitatea de: " << this->capacitate << " persoane."
			<< " Numarul total de persoane imbarcate este: " << this->nrPersoaneImbarcate << endl;
		if (this->producator != nullptr) {
			cout << "Producatorul autobuzului este: " << this->producator << endl;
		}
		else {
			cout << "Producatorul autobuzului nu este cunoscut!" << endl;
		}
	}
};

int Autobuz::nrAutobuze = 0; // initializare variabila statica nrAutobuze

int main() {

	cout << "Afisare autobuz1" << endl;
	Autobuz a1;
	a1.afiseazaAutobuz();
	cout << endl;
	char producator[] = "Volvo";

	cout << "Afisare autobuz 2" << endl;
	Autobuz a2(50, 20, producator);
	a2.afiseazaAutobuz();
	cout << endl;

	cout << "Setare capacitatea si afisare autobuz 2" << endl;
	a2.setCapacitate(10);
	a2.afiseazaAutobuz();
	cout << endl;

	// testare constructor de copiere
	cout << "Afisare autobuz 3" << endl;
	Autobuz a3(a2);
	a3.afiseazaAutobuz();
	cout << endl;

	// testare operator atribuire '='
	cout << "Testare operator atribuire" << endl;
	a1 = a2;
	a1.afiseazaAutobuz();
	a2.afiseazaAutobuz();
	cout << endl;

	// testare operator <<
	cout << "Autobuzul 1: " << a1 << endl;
	cout << "Autobuzul 2: " << a2 << endl;
	cout << endl;

	// testare metoda getNumarLocuriLibere
	cout << "Testare metoda getNumarLocuriLibere" << endl;
	cout << "Locuri libere in autobuzul: " << a2.getNumarLocuriLibere() << endl;
	cout << endl;

	// testare operator cast la int
	cout << "Testare operator de cast la int" << endl;
	int nrPersoane = a2;
	cout << "Numar de persoane in acest autobuz: " << nrPersoane << endl;
	cout << endl;

	// testare operator '>'
	if (a1 > a2) {
		cout << "Autobuzul 1 are o capacitate mai mare decat Autobuzul 2." << endl;
	}
	else if (a1 == a2) {
		cout << "Autobuzele au aceeasi capacitate." << endl;
	}
	else {
		cout << "Autobuzul 2 are o capacitate mai mare decat Autobuzul 1." << endl;
	}

	return 0;
}