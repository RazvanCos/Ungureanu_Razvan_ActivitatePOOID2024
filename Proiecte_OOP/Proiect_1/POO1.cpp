#include<iostream>

using namespace std;

class Angajat {

public:
	string nume;
	string pozitie;
	float salariu;
	int nrAbilitati;
	const int id;
	static int nrAngajati;
	string* abilitati;


	// constructor implicit
	Angajat():id(++nrAngajati) {
		this->nume = "Necunoscut";
		this->pozitie = "Necunoscuta";
		this->salariu = 1000;
		this->nrAbilitati = 0;
		this->abilitati = nullptr;
	};

	// constructor partial
	Angajat(string nume, string pozitie, float salariu):id(++nrAngajati){
		this->nume = nume;
		this->pozitie = pozitie;
		this->salariu = salariu;
	}

	// constructor complet
	Angajat(string numeAngajat, string pozitie, float salariu, int nrAbilitati, string* abilitati) :id(++nrAngajati) {
		this->nume = numeAngajat;
		this->pozitie = pozitie;
		this->salariu = salariu;
		this->nrAbilitati = nrAbilitati;
		// alocara memorie dinamica pentru vectorul de stringuri care contile abilitati
		this->abilitati = new string[nrAbilitati];
		// Deep copy -> copierea elem din vectorul primiit in vectorul nou creat al obiectului
		for (int i = 0; i < nrAbilitati; i++) {
			this->abilitati[i] = abilitati[i];
		}		
	}

	// Destructor pentru eliberarea memoriei
	~Angajat() {
		if (this->abilitati != nullptr) {
			delete[] abilitati;
		}
	}
	
	// Metoda pentru afisarea angajatilor
	void afisreAngajat() {
		cout << "Angajatul #" << this->id << ":" << this->nume << ", pozitie: " << this->pozitie
			<< ", salariu: " << this->salariu << endl;
		if (this->abilitati && nrAbilitati > 0) {
			cout << "Abilitati: "<<endl;
			for (int i = 0; i < nrAbilitati; i++) {
				cout << this->abilitati[i] << endl;
			}
			cout << endl;
		}
		else {
			cout << "Nu are abilitati." << endl;
		}
	}
};

// declararea si intializarea membrului static in afara clasei
int Angajat::nrAngajati = 0;


class Recrutare {

public:
	const int id;
	string numeCandidat;
	string pozitie;
	string stadiu;
	int nrFeedback;
	static int nrRecrutari;
	string* feedback;

	// constructor implicit
	Recrutare(): id(++nrRecrutari){
		this->numeCandidat = "Necunoscut";
		this->pozitie = "Necunoscuta";
		this->stadiu = "In asteptare";
		this->nrFeedback = 0;
		this->feedback = nullptr;
	}

	// constructor complet
	Recrutare(string numeCandidat, string pozitie, string stadiu, int nrFeedback, string* feedback): id(++nrRecrutari){
		this->numeCandidat = numeCandidat;
		this->pozitie = pozitie;
		this->stadiu = stadiu;
		this->nrFeedback = nrFeedback;
		// alocare memorie
		this->feedback = new string[nrFeedback];
		for (int i = 0; i < nrFeedback; i++) {
			this->feedback[i] = feedback[i];
		}
	}

	// constructor partial
	Recrutare(string numeCandidat, string pozitie): id(++nrRecrutari){
		this->numeCandidat = numeCandidat;
		this->pozitie = pozitie;
		this->stadiu = "On hold";
		this->nrFeedback = 0;
		this->feedback = nullptr;
	}

	~Recrutare(){
		if (this->feedback != nullptr) {
			delete[] feedback;
		}
	}

	void afisareRecrutare() {
		cout << "Recrutare #" << this->id << ": Candidat: " << this->numeCandidat << ", pozitie: " << this->pozitie << ", este in stadiul: " << this->stadiu << endl;
		if (this->feedback && nrFeedback > 0) {
			cout << "Feedback: " << endl;
			for (int i = 0; i < nrFeedback; i++) {
				cout << this->feedback[i] << endl;
			}
		}
		else {
			cout << "Candidatul: " << this->numeCandidat << " nu are feedback momentan!" << endl;
		}
	}
};

int Recrutare::nrRecrutari = 0;

class Organizatie {
public:
	const int id;
	static int nrUnitati;
	string denumire;
	string manager;
	int nrObiective;
	string* obiective;

	// constructor implicit
	Organizatie(): id(++nrUnitati){
		this->denumire = "Necunoscuta";
		this->manager = "necunoscut";
		this->nrObiective = 0;
		this->obiective = nullptr;
	};

	// constructor complet
	Organizatie(string denumire, string manager, int nrObiective, string* obiective): id(++nrUnitati){
		this->denumire = denumire;
		this->manager = manager;
		this->nrObiective = nrObiective;
		this->obiective = new string[nrObiective];
		for (int i = 0; i < nrObiective; i++) {
			this->obiective[i] = obiective[i];
		}
	}

	// constructor partial
	Organizatie(string denumire, string manager): id(++nrUnitati){
		this->denumire = denumire;
		this->manager = manager;
		this->nrObiective = 0;
		this->obiective = nullptr;
	}


	~Organizatie(){
		if (this->obiective != nullptr) {
			delete[] obiective;
		}
	}

	void afisareOrganizatie() {
		cout << "Organizatie: #" << this->id << ", Denumire: " << this->denumire << ", Manager: " << this->manager << endl;
		if (this->obiective && this->nrObiective > 0) {
			cout << "Obiective: " << endl;
			for (int i = 0; i < this->nrObiective; i++) {
				cout << this->obiective[i] << endl;
			}
		}
		else {
			cout << "Organizatia: " << this->denumire << " nu are obiective!";
		}
	}
};

int Organizatie::nrUnitati = 0;




int main() {
	string abilitati[] = { "C++", "Java", "Databases", "Frontend", "Backend" };
	Angajat a1;
	Angajat a2("Radu", "software developer", 2000, 5, abilitati);
	a1.afisreAngajat();
	cout << endl;
	a2.afisreAngajat();
	cout << endl;


	string feedback[] = { "Inteviu tehnic pozitiv", "Experienta relevanta" };
	Recrutare r1("Virgil", "software developer", "Interviu finalizat", 2, feedback);
	Recrutare r2;
	Recrutare r3;
	r1.afisareRecrutare();
	cout << endl;
	r2.afisareRecrutare();
	cout << endl;
	r3.afisareRecrutare();

	string obiective[] = {"Imbunatatire performanta", "Extindere pe piata", "Reducere costuri"};
	/*Organizatie org1("TechCorp", "Popescu Ionut", 3, obiective);*/
	Organizatie org2("ITSolution", "Ionescu Marian");

	//org1.afisareOrganizatie();
	cout << endl;
	org2.afisareOrganizatie();
	cout << endl;


	return 0;

}