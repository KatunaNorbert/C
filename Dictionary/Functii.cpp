#include <iostream>
using namespace std;
#include <fstream>
#include <ostream>
#include "Functii.h";




void Inlocuire_cuvinte(char* locatie, char* destinatie, Dictionar &dictionar) {
	//Functia citeste cuvinte dintr-un fisier si le scrie intr-un alt fisier cu cuvintele semnate modificate
	string punctuatie;
	string semne = ",.!?";
	fstream Fisier_sursa;
	fstream Fisier_destinatie;
	Fisier_sursa.open(locatie);
	Fisier_destinatie.open(destinatie);
	if (Fisier_sursa.is_open()) {
		while (!Fisier_sursa.eof()) {
			string cuvant;
			while(Fisier_sursa >> cuvant) {
				if (cuvant[0] == '*') {
					for (int i = 0; i < semne.length(); i++) {
						if (cuvant[cuvant.length() - 1] == semne[i]) {
							punctuatie = "";
							punctuatie = cuvant[cuvant.length()-1];
							cuvant.pop_back();
						}
					}
					if (dictionar.Verificare_daca_cuvantul_este_in_dictionar(cuvant.substr(1)) == true) {
						Fisier_destinatie << dictionar.Schimbare_cuvinte(cuvant.substr(1)) <<punctuatie<< " ";
						punctuatie = "";
					}
					else {
						Fisier_destinatie << cuvant <<" ";
						cout << "\nCuvantul:" << cuvant.substr(1) << " nu se afla in dictionar\n" << endl;
					}
				}
				else {
					Fisier_destinatie << cuvant << " ";
				}
			}
		}
		Fisier_destinatie.close();
		Fisier_sursa.close();
		cout << "Cuvintele au fost inlocuite" << endl;
	}
	else cout << "Source not found" << endl;

}

void Introducere_cuvinte_in_dictionar(char* locatie, Dictionar &dictionar) {
	//Functia citeste cuvinte impreuna cu sinonimele lor din fisier si le incarca in dictionat/tabel
	ifstream Fisier_dict(locatie);
	string linie;
	if (Fisier_dict.is_open()) {
		while (getline(Fisier_dict, linie)) {
			string cuvant = linie.substr(0, linie.find("="));
			string sinonim = linie.substr(linie.find("=") + 1);
			dictionar.Adauga_cuvant(cuvant, sinonim);
		}
		cout << "Cuvintele au fost incarcate in dictionar" << endl;
	}
	else cout << "Dictionary not found" << endl;
}



