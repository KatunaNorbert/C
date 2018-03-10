
using namespace std;
#include "Functii.h"


int main() {
	Dictionar dictionar;

	Introducere_cuvinte_in_dictionar("Dictionar.txt", dictionar);
	Inlocuire_cuvinte("Fisier_sursa.txt", "Fisier_destinatie.txt", dictionar);

	system("pause");
	return 0;

}




