/* main.cpp */
#include "mediatheque.hpp"
#include "media.hpp"
#include "livre.hpp"

using namespace std;

int main(int argc, char const *argv[])
{

	mediatheque test;
	livre* book = new livre();
	test.m_liste.push_back(book);

	(test.m_liste[0])->affiche();

	return 0;
}