#include <string>
#include <iostream>
using namespace std;

class Dictionar {
	private:
		static const int Dimensiune_tabel = 11;

		struct element {
			string cuvant;
			string sinonim;
			element*next;
		};

		element *Tabela_de_dispersie[Dimensiune_tabel];
	public:
		Dictionar();
		~Dictionar();
		int Returneaza_index(string cheie);
		void Adauga_cuvant(string cuvant, string sinonim);
		int Numar_elemente_din_index(int index);
		void Afiseaza_tabela();
		string Schimbare_cuvinte(string cuvant);
		bool Verificare_daca_cuvantul_este_in_dictionar(string cuvant);
};
