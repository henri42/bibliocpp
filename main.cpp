/* main.cpp */
#include <string>
#include <iostream>
#include <vector>
#include "mediatheque.hpp"
#include "media.hpp"
#include "livre.hpp"
#include "VHS.hpp"
#include "revue.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
	vector<string> titre = {"Titre 1", "Titre 2", "Titre 3", "Titre 4", "Titre 5"};
	mediatheque* test = new mediatheque();
	media* book1 = new livre(1995, 1000, "House", "Back once again for the ready go master", "Telmo", "Wars", EMPRUNTE);
	media* book2 = new livre(19, 50, "AZERTYUI", "OK", "Victor Hugo", "Paris", DISPONIBLE);
	media* revue1 = new revue(titre.size(), "Boris", titre, 2017, 100, "Test", "Deep Inside", "Telmo", "Wars", DISPONIBLE);
	//media* book3 = new livre();

	test->load_from_file("test_bib.txt");
	test -> ajout(revue1);
	// test -> affiche(0);
	// cout << endl;
	// test -> affiche(1);
	// cout << endl;
	test -> affiche();
	// cout << endl;
	// test -> suppr(0);
	// test -> affiche();

	return 0;
}