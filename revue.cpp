/* revue.cpp */
#include "revue.hpp"
#include <iostream>
using namespace std;

std::vector<revue*>::const_iterator ii;
int i = 1;

revue::revue()
{
	m_nb_articles = 0;
}

revue::revue(int nb_articles, std::string editeur, int annee, int pages, std::string collection, std::string resume, std::string auteur, std::string nom, int dispo) : livre(annee, pages, collection, resume, auteur, nom, dispo)
{
	m_nb_articles = nb_articles;
	m_editeur = editeur;
}

revue::~revue()
{
	
}

void revue::affiche_articles(int index)
{
	if (index == -1)
	{
		for (ii = m_liste_article.begin(); ii != m_liste_article.end(); ii++)
		{
				cout << i << ". " << *ii << endl;
				i++;
		}
		i = 0;
	}

	else
	{
		cout << m_liste_article[index] << endl;
	}

}

void revue::affiche() // affichage a mettre en forme
{
	livre::affiche();
	cout << "Le nombre d'articles de cette revue est :" << m_nb_articles << endl;
	cout << "La liste de tous les articles de la revue est la suivante:" << endl;
	affiche_articles(-1);
	cout << endl << endl;
	cout << "Entrez l'index d'un article si vous voulez un résumé de celui-ci" << endl;
	cin >> m_id_article;
	affiche_articles(m_id_article);
	cout << endl;
}