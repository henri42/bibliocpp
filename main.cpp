/* main.cpp */
#include <string>
#include <iostream>
#include <vector>
#include "mediatheque.hpp"
#include "user.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
	vector<string> titre = {"Titre 1", "Titre 2", "Titre 3", "Titre 4", "Titre 5"};
	mediatheque* test = new mediatheque();
	media* book1 = new livre(1995, 1000, "House", "Back once again for the ready go master", "Telmo", "Wars", EMPRUNTE);
	media* book2 = new livre(19, 50, "AZERTYUI", "OK", "Victor Hugo", "Paris", DISPONIBLE);
	//media* revue1 = new revue(titre.size(), "Boris", titre, 2017, 100, "Test", "Deep Inside", "Telmo", "Wars", DISPONIBLE);
	//media* book3 = new livre();

    //test -> ajout(book1);
    //test -> ajout(book2);
	user* henri = new user(test);
	henri->lecture_commande();


	//test->load_from_file("/Users/Sophie/bibliocpp/test_bib.txt");
	// test -> affiche(0);
	// cout << endl;
	// test -> affiche(1);
	// cout << endl;
	//test -> affiche();
    //test -> save_to_file("saving.txt");
	// cout << endl;
	// test -> suppr(0);
	// test -> affiche();

	return 0;
}