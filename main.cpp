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
	livre* book1 = new livre(1995, 1000, "House", "Back once again for the ready go master");
	livre* book2 = new livre(19, 50, "AZERTYUI", "OK");

	test -> ajout(book1);
	test -> ajout(book2);

	test -> affiche(0);
	cout << endl;
	test -> affiche(1);

	return 0;
}