/* mediatheque.cpp */
#include "mediatheque.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

mediatheque::mediatheque()
{
	m_nb_media = 0;
}

mediatheque::~mediatheque()
{
	
}

void mediatheque::affiche() //Affiche les informations de toute la liste des médias de la médiatheque
{
	for (int i=0; i<m_biblio.size(); i++)
	{
		cout << i;
		m_biblio[i] -> media::affiche();
	}
}

void mediatheque::affiche(int indice) //Affiche le média d'indice "indice" en détails
{
	m_biblio[indice] -> affiche();
}



void mediatheque::ajout(media* const new_media)
{
	m_biblio.push_back(new_media); //ajout
}


void mediatheque::suppr(int indice)
{
	m_biblio.erase(m_biblio.begin() + indice);
}