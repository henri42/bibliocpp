/* mediatheque.cpp */
#include "mediatheque.hpp"
#include <string>
#include <iostream>

using namespace std;

mediatheque::mediatheque()
{
	m_nb_media = 0;
}

mediatheque::~mediatheque()
{
	
}

void mediatheque::ajout(media* const new_media)
{
	m_biblio.push_back(new_media); //ajout
	m_biblio[m_nb_media]->set_id(m_nb_media); //attribution de l'indice
	m_nb_media ++; 
}

void mediatheque::suppr(int indice)
{
	m_biblio.erase(indice); //suppression
	m_nb_media --; //

	for (int i=indice; i<m_nb_media)
		m_biblio[i]->set_id(i);
}


void mediatheque::affiche(int indice)
{
	m_biblio[indice] -> affiche();
}