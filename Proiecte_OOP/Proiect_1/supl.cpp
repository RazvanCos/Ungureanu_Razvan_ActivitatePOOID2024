//#include<iostream>
//#include<string>
//
//using namespace std;
//
//void modifica(int* p) {
//	*p = 30; // modifica valoarea prin pointer
//}
//
//int suma(int a, int b) {
//	return a + b;
//}
//
//void main() {
//	char character = 'a'; // variabile 'character' stocata pe stack(stiva), tipul variabilei: 'char', ocupa 1 octet = 8 biti
//	int intreg = 10; // variabila 'intreg' stocata pe stack, tipul variabile: 'int', ocupa 4 octeti = 32 biti
//	long int longInteger = 30000; // variabile 'longInteger' stocata pe stack, tipul variabilei: 'long int', ocupa 4 octeti = 32 biti
//	float realFloat = 3.4f; // variabila 'realFloat' stocata pe stack, tipul variabilei: 'float', ocupa 4 octeti = 32 biti
//	double realDouble = 4.56; // variabila 'realDouble' stocata pe stack, tipul variabilei: 'double', ocupa 8 octeti = 64 biti
//	bool boolean = true; // variabila 'boolean' stocata pe stack, tipul variabilei: 'bool', ocupa 1 octet = 8 biti
//	string sirCaractere = "Sir caractere"; // variabila 'sirCaractere' stocata pe stack(variabila sirCaractere este o instanta a clasei string)
//										   // Obiectul 'sirCaractere' este de tip std::string care stockeaza intern un pointer catre continutul efectiv
//										   // al sirului de caractere, valoare care este stocata pe heap; valoarea stringului este "Sir caractere"
//
//	int* pIntreg = &intreg; // variabila 'pIntreg' stocata pe stack
//							// pIntreg este un pointer local care ocupa o adresa de memorie deci este o VARIABILA locala
//							// pIntreg va stoca adresa adresa variabilei 'intreg' care este si ea stocata pe stack
//	cout << *pIntreg<< " se afla la adresa: " << pIntreg << endl;
//	
//	float* pFloat = new float(45.3); // variabila 'pFloat' stocata pe stack, deoarece este un pointer care indica spre un bloc de memorie alocat pe heap
//									 // pentru un obiect de tip float
//									 // valoarea 45.3(adica variabila de tip float) este stocata pe heap deoarece este alocata dinamic cu new  
//
//	cout << *pFloat << " se afla la adresa: " << pFloat << endl;
//
//	int** ppIntreg = &pIntreg; // tipul int** = pointer de tip int*
//							   // ppIntreg va stoca adresa pointerului pIntreg
//
//
//
//	cout << "-------" << endl;
//	int variabila = 10;	// declararea unui variabile de tip int cu valoarea 10
//	cout << variabila << endl; // 10 => valoarea variabilei 'variabila'
//
//	int* pointer = &variabila; // declararea unui pointer care stocheaza adresa variabilei 'variabila'
//	cout << pointer << endl; // 000000408BB8F964 => valoarea variabilei pointer (adresa variabilei 'variabila)
//	cout << &variabila << endl; //000000408BB8F964 => adresa variabilei 'variabila' direct folosind operatorul '&'
//	cout << "---------" << endl;
//
//	int** pnt = &pointer; // pnt = pointer dublu; stocheaza adresa pointerului
//	cout << pnt << endl; // 000000408BB8F988 =>  adresa pointerului
//	cout << &pointer << endl; //000000408BB8F988 => adresa pointerului direct folosind operatorul '&'
//
//	cout << "---------" << endl;
//	int var = 10;
//	int* point = &var;
//	*point = 20; // modifica valoarea lui variabila prin pointer; '*' = operator de dereferentiere
//	cout << var << endl; // 20
//	
//	cout << "----------" << endl;
//	int variabila1 = 10;
//	modifica(&variabila1); // transmiterea adresei lui variabila1
//	cout << variabila1 << endl; // 30 => transmiterea adresei in functii
//
//	// Aritmetica pointerilor
//	cout << "--------------" << endl;
//
//	int intreg2 = 10;
//	double real = 20.20;
//	double real2 = 10.10;
//
//	int* pIntreg2 = &intreg2;
//	double* pReal = &real;
//	double* pReal2 = &real2;
//
//	cout << "Adresa variabilei intreg2 este: " << pIntreg2 << endl;
//	cout << "Adresa variabile real este: " << pReal << endl;
//	
//	pIntreg++; // asigura deplasarea inainte cu sizeof(tip_variabila) exprimat in octeti; in cazul nostru cu 4 octeti
//	cout << "Noua adresa: " << pIntreg << endl;
//	pIntreg = pIntreg - 2; // asigura deplasarea cu sizeof(tip_variabila) exprimat in octeti cu "-2" octeti in cazul nostru
//	cout << "Noua adresa2: " << pIntreg << endl;
//	double newPnt = pReal - pReal2; // numarul de elemente aflate intre cei 2 pointer
//	cout << "New pnt: " << newPnt << endl;
//	
//	// spatiul alocat de catre programator cu ajutorul operatorului new se afla in memoria Heap nu in Stack
//	
//	cout << "---------" << endl;
//
//	// Vectori
//	int initialValues[] = { 1, 0, 5, 30, 2, 12, 9, 8,6, 3 };
//	int* v = new int[10];
//	for (int i = 0; i < 10; i++) {
//		v[i] = initialValues[i];
//	}
//	int a = *v;
//	cout << "Adresa lui v: " << v << endl; // Adresa primului element din array
//	cout << "Valoarea lui v[0]: " << v[0] << endl; // Valoarea primului element
//	cout << "Valoarea lui v[0] scrisa altfel: " << *v << endl; // Valoarea primului element al vectorului
//	cout << "Valoarea stocata la adresa lui v ( v[0] ): " << *v << endl; // valoarea primului element al vectorului
//	cout << a << endl; // valoarea stocata in a care reprezinta valoarea primului element din vector
//
//	cout << "---------" << endl;
//	cout << "Adresa lui &v(pointer la pointer): " << &v << endl; // Adresa pointerului v
//	cout << "Adresa lui &v[0]: " << &v[0] << endl; // Adresa primului element echivalent cu v
//	cout << "Adresa lui &v[1]: " << &v[1] << endl; //Adresa celui de-al doilea element
//	cout << "Valoare lui v[1]: " << v[1] << endl; // Valoarea celui de-al doilea element
//
//	delete[] v; // eliberarea memoriei
//
//	cout << "-----------" << endl;
//
//	//	Pointeri la functii
//
//	int(*pf)(int x, int y); // pointer la o functie cu semnatura int f(int a, int b)
//							// tip returnat(*nume_pointer)(lista parametrii functie)
//	pf = suma; // initializare => nume_pointer = nume_functie;
//
//	int rez = pf(7, 8); // apel functie
//	cout << rez << endl;
//
//	cout << "-------" << endl;
//	
//	/*Referinte
//	-> pointer constanti care vor fi dereferentiati automat de catre compilator */
//
//	int intr = 10;
//	int intr2 = intr; // Valoare lui intr este copiata in intr2; dupa aceasta operatiune, intr si intr2 devin variabile independente;
//					  // Orice modificare a lui intr dupa acest moment nu va afecta valoare lui intr2
//	cout << "Valoarea lui intr: " << intr << endl; // 10
//	cout << "Valoarea lui intre2: " << intr2 << endl; // 10
//	int* pIntr = &intr; // Pointer care stocheaza adresa lui intr
//	int* pIntr2 = &intr2; // Pointer care stocheaza adresa lui intr2
//	cout << "Adresa lui intr este: " << pIntr << endl; // 012FF568
//	cout << "Adresa lui pIntr2 este: " << pIntr2 << endl; //0055F7B8
//
//	intr++; // Incrementare valoarea lui intr
//	cout << "Noua valoare a lui intr: " << intr << endl; // 11
//	cout << "Noua valoare a lui intr2: " << intr2 << endl; // 10
//	int* pIntr3 = &intr;
//	int* pIntr4 = &intr2;
//	cout << "Adresa lui intr dupa incrementare: " << pIntr3 << endl; //012FF568
//	cout << "Adresa noii valori a lui intr2: " << pIntr4 << endl; // 0055F7B8
//	
//}