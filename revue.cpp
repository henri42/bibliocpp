/* revue.cpp */
#include "revue.hpp"
#include <iostream>
using namespace std;

std::vector<revue*>::const_iterator ii;

revue::revue()
{
	m_article = 0;
	m_id_article = 0;
}

revue::~revue()
{
	
}

void revue::affiche_articles(int all)
{
	if (all)
	{
		for (ii = article.begin(); ii != article.end(); ii++)
			cout << *ii << endl;
	}

	else
		cout << article[m_id_article] << endl;

}