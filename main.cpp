/* main.cpp */
#include <string>
#include <iostream>
#include "mediatheque.hpp"
#include "media.hpp"
#include "livre.hpp"
#include "VHS.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
	mediatheque* test = new mediatheque();
	media* book1 = new livre(1995, 1000, "House", "Back once again for the ready go master", "Telmo", "Wars", EMPRUNTE);
	media* book2 = new livre(19, 50, "AZERTYUI", "OK", "Victor Hugo", "Paris", DISPONIBLE);
	//media* book3 = new livre();

	test->load_from_file("/Users/Sophie/bibliocpp/test_bib.txt");

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