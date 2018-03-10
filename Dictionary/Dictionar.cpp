
#include <string>
#include <iostream>
using namespace std;
#include "Dictionar.h";

Dictionar::Dictionar() {
	//Constructorul creeaza tabela punand NULL pe fiecare pozitie
	for (int i = 0; i < Dimensiune_tabel; i++) {
		Tabela_de_dispersie[i] = NULL;
	}
}

Dictionar::~Dictionar() {
	//Destructorul sterge fiecare element de pe fiecare pozitie
	for (int i = 0; i < Dimensiune_tabel; i++) {
		element* current = Tabela_de_dispersie[i];
		if (current != NULL) {
			while (current->next != NULL) {
				element *urmator = current->next;
				delete current;
				current = urmator;
			}
			delete current;
		}
	}
}

int Dictionar::Returneaza_index(string cheie) {
	//Functia returneaza cheia citita in pozitia pe care se va afla in tabel
	int suma_cod_ascii = 0;
	int index;

	for (int i = 0; i < cheie.length(); i++) {
		suma_cod_ascii = suma_cod_ascii + int(cheie[i]);
	}
	index = suma_cod_ascii % Dimensiune_tabel;
	return index;
}

void Dictionar::Adauga_cuvant(string cuvant, string sinonim) {
	//Functia adauga un element la indexul returnat de functia hash
	int index = Returneaza_index(cuvant);
	element*element_nou = new element;
	element_nou->cuvant = cuvant;
	element_nou->sinonim = sinonim;
	element_nou->next = NULL;

	if (Tabela_de_dispersie[index] == NULL)
	{
		Tabela_de_dispersie[index] = element_nou;
	}
	else
	{
		element*pointer = Tabela_de_dispersie[index];
		while (pointer->next != NULL) {
			pointer = pointer->next;
		}
		pointer->next = element_nou;
	}

}

int Dictionar::Numar_elemente_din_index(int index) {
	//Functia returneaz numarul de elemente de la un index
	int numar = 0;
	if (Tabela_de_dispersie[index] == NULL) {
		return numar;
	}
	else
	{
		numar++;
		element*pointer = Tabela_de_dispersie[index];
		while (pointer->next != NULL) {
			numar++;
			pointer = pointer->next;
		}
	}
	return numar;
}

void Dictionar::Afiseaza_tabela() {
	//Functia parcurge tabelul si afiseaza elementele
	int numar;
	for (int i = 0; i < Dimensiune_tabel; i++) {
		numar = Numar_elemente_din_index(i);
		if (Tabela_de_dispersie[i] == NULL) {
			cout << "\nindex=" << i << endl;
			cout << "Adresa goala\n" << endl;
		}
		else {
			element*pointer = Tabela_de_dispersie[i];
			cout << "\n" << endl;
			cout << "index=" << i << endl;
			cout << "cuvat=" << Tabela_de_dispersie[i]->cuvant << endl;
			cout << "sinonim=" << Tabela_de_dispersie[i]->sinonim << endl;
			cout << "Numarul de elem din cutie=" << numar << endl;;
			cout << "\n" << endl;
			while (pointer->next != NULL) {
				cout << "\n" << endl;
				cout << "index=" << i << endl;
				cout << "cuvat=" << pointer->next->cuvant << endl;
				cout << "sinonim=" << pointer->next->sinonim << endl;
				cout << "Numarul de elem din cutie=" << numar << endl;;
				cout << "\n" << endl;
				pointer = pointer->next;
			}
		}

	}

}



string Dictionar::Schimbare_cuvinte(string cuvant_dat) {
	//Functia schimba cuvantul primit ca parametru cu sinonimul sau si il returneaza
	int index = Returneaza_index(cuvant_dat);
	if (Tabela_de_dispersie[index] == NULL)
		cout << "Cuvantul nu exista in dictionar" << endl;
	else {
		element*pointer = Tabela_de_dispersie[index];
		while (pointer->cuvant != cuvant_dat) {
			pointer = pointer->next;
		}
		cuvant_dat = pointer->sinonim;
	}
	return cuvant_dat;
}

bool Dictionar::Verificare_daca_cuvantul_este_in_dictionar(string cuvant) {
	//Returneaza true daca elementul a fost gasit in tabel si false in caz contrar
	int index = Returneaza_index(cuvant);
	bool gasit = false;

	if (Tabela_de_dispersie[index] == NULL)
		gasit = false;
	else {
		if (cuvant == Tabela_de_dispersie[index]->cuvant) {
			gasit = true;
		}
		element*pointer = Tabela_de_dispersie[index];
		while ((pointer->cuvant != cuvant) && (pointer->next != NULL)) {
			pointer = pointer->next;
			if (pointer->cuvant == cuvant)
				gasit = true;
		}
	}
	return gasit;
}
