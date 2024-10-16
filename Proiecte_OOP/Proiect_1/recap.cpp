#include<iostream>
#include<string>

using namespace std;

void modifica(int* p) {
	*p = 30; // modifica valoarea prin pointer
}

void main() {
	char character = 'a'; // variabile 'character' stocata pe stack(stiva), tipul variabilei: 'char', ocupa 1 octet = 8 biti
	int intreg = 10; // variabila 'intreg' stocata pe stack, tipul variabile: 'int', ocupa 4 octeti = 32 biti
	long int longInteger = 30000; // variabile 'longInteger' stocata pe stack, tipul variabilei: 'long int', ocupa 4 octeti = 32 biti
	float realFloat = 3.4f; // variabila 'realFloat' stocata pe stack, tipul variabilei: 'float', ocupa 4 octeti = 32 biti
	double realDouble = 4.56; // variabila 'realDouble' stocata pe stack, tipul variabilei: 'double', ocupa 8 octeti = 64 biti
	bool boolean = true; // variabila 'boolean' stocata pe stack, tipul variabilei: 'bool', ocupa 1 octet = 8 biti
	string sirCaractere = "Sir caractere"; // variabila 'sirCaractere' stocata pe stack(variabila sirCaractere este o instanta a clasei string)
										   // Obiectul 'sirCaractere' este de tip std::string care stockeaza intern un pointer catre continutul efectiv
										   // al sirului de caractere, valoare care este stocata pe heap; valoarea stringului este "Sir caractere"

	int* pIntreg = &intreg; // variabila 'pIntreg' stocata pe stack
							// pIntreg este un pointer local care ocupa o adresa de memorie deci este o VARIABILA locala
							// pIntreg va stoca adresa adresa variabilei 'intreg' care este si ea stocata pe stack
	cout << *pIntreg<< " se afla la adresa: " << pIntreg << endl;
	
	float* pFloat = new float(45.3); // variabila 'pFloat' stocata pe stack, deoarece este un pointer care indica spre un bloc de memorie alocat pe heap
									 // pentru un obiect de tip float
									 // valoarea 45.3(adica variabila de tip float) este stocata pe heap deoarece este alocata dinamic cu new  

	cout << *pFloat << " se afla la adresa: " << pFloat << endl;

	int** ppIntreg = &pIntreg; // tipul int** = pointer de tip int*
							   // ppIntreg va stoca adresa pointerului pIntreg



	cout << "-------" << endl;
	int variabila = 10;	// declararea unui variabile de tip int cu valoarea 10
	cout << variabila << endl; // 10 => valoarea variabilei 'variabila'

	int* pointer = &variabila; // declararea unui pointer care stocheaza adresa variabilei 'variabila'
	cout << pointer << endl; // 000000408BB8F964 => valoarea variabilei pointer (adresa variabilei 'variabila)
	cout << &variabila << endl; //000000408BB8F964 => adresa variabilei 'variabila' direct folosind operatorul '&'
	cout << "---------" << endl;

	int** pnt = &pointer; // pnt = pointer dublu; stocheaza adresa pointerului
	cout << pnt << endl; // 000000408BB8F988 =>  adresa pointerului
	cout << &pointer << endl; //000000408BB8F988 => adresa pointerului direct folosind operatorul '&'

	cout << "---------" << endl;
	int var = 10;
	int* point = &var;
	*point = 20; // modifica valoarea lui variabila prin pointer; '*' = operator de dereferentiere
	cout << var << endl; // 20
	
	cout << "----------" << endl;
	int variabila1 = 10;
	modifica(&variabila1); // transmiterea adresei lui variabila1
	cout << variabila1; // 
}