/* revue.cpp */
#include "revue.hpp"
#include <iostream>
using namespace std;


revue::revue()
{
	m_nb_articles = 0;
}

revue::revue(int nb_articles, string editeur, vector<string> liste_articles, int annee, int pages, string collection, string resume, string auteur, string nom, int dispo) : livre(annee, pages, collection, resume, auteur, nom, dispo)
{
	m_nb_articles = nb_articles;
	m_editeur = editeur;
	m_liste_articles = liste_articles;
}

revue::revue(string editeur, vector<string> liste_articles, string annee, string pages, string collection, string resume, string auteur, string nom) : livre(annee, pages, collection, resume, auteur, nom)
{
	m_nb_articles = liste_articles.size()/2;
	m_editeur = editeur;
	m_liste_articles = liste_articles;
}

revue::~revue()
{
	
}

void revue::affiche_articles(int index)
{
    std::vector<string>::const_iterator ii;
    int i;
    int j = 1;

	if (index == -1)
	{
		for (i = 0; i < (m_nb_articles*2); i++)
		{
				cout << j << ". " << m_liste_articles[i] << endl;
				i++;
				j++;
		}
		i = 0;
	}

	else
	{ 	
		if ((index <= (m_nb_articles*2)) && (0 < index))
			cout << m_liste_articles[index-1] << endl;
		else
			cout << "ERROR - L'index rentré est incorrecte" << endl;
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
	affiche_articles(m_id_article*2);
	cout << endl;
}

void revue::save_media(ofstream* file)
{
	*file << RESSOURCE << endl;
	*file << m_nb_articles << endl;
	*file << m_editeur << endl;
	media::save_media(file);
	*file << "---" << endl;
	//sauvegarde des articles
	*file << "---" << endl;
}