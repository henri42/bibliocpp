/* main.cpp */
#include <string>
#include <iostream>
#include "mediatheque.hpp"
#include "media.hpp"
#include "livre.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
	mediatheque* test = new mediatheque();
	livre* book1 = new livre(1995, 1000, "House", "Back once again for the ready go master", "Telmo", "Wars", 0, 0, 20);
	livre* book2 = new livre(19, 50, "AZERTYUI", "OK", "Victor Hugo", "Paris", 2, 0, 42);

	test -> ajout(book1);
	test -> ajout(book2);

	test -> affiche(0);
	cout << endl;
	test -> affiche();
	cout << endl;
	test -> suppr(0);
	cout << endl;
	test -> affiche();

	return 0;
}