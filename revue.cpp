/* revue.cpp */
#include "revue.hpp"
#include <iostream>
using namespace std;

std::vector<revue*>::const_iterator ii;
int i = 1;

revue::revue()
{
	m_article = 0;
	m_id_article = 0;
}

revue::~revue()
{
	
}

void revue::affiche_articles(int index)
{
	if (id == -1)
	{
		for (ii = article.begin(); ii != article.end(); ii++)
		{
				cout << i << ". " << *ii << endl;
				i++;
		}
	}

	else
	{
		cout << article[index] << endl;
	}

}