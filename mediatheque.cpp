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
	m_biblio.push_back(new_media);
	m_nb_media ++;
}

void mediatheque::affiche(int indice)
{
	m_biblio[indice] -> affiche();
}