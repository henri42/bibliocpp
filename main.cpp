/* main.cpp */
#include "mediatheque.hpp"
#include "media.hpp"
#include "livre.hpp"

using namespace std;

int main(int argc, char const *argv[])
{

	mediatheque test;
	livre* book1 = new livre();
	livre* book2 = new livre();
	test.ajout(book1);
	test.ajout(book2);	

	(test.m_liste[0])->affiche();
	(test.m_liste[1])->affiche();

	return 0;
}