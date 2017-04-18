/* main.cpp */
#include "mediatheque.hpp"
#include "media.hpp"
#include "livre.hpp"

using namespace std;

int main(int argc, char const *argv[])
{

<<<<<<< HEAD
	mediatheque* test = new mediatheque();
	livre* book = new livre();
	test->ajout(book);
	test->affiche(test->m_media);
=======
	mediatheque test;
	livre* book1 = new livre();
	livre* book2 = new livre();
	test.ajout(book1);
	test.ajout(book2);	

	(test.m_liste[0])->affiche();
	(test.m_liste[1])->affiche();
>>>>>>> da79e827ebc19e9e887767bbc6018e9bd6abe8ae

	return 0;
}