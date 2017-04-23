/* mediatheque.cpp */
#include "mediatheque.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

mediatheque::mediatheque()
{
	m_nb_media = 0;
	m_indices.push_back(m_nb_media);
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
	m_biblio.push_back(new_media);
	m_nb_media ++;
	//new_media.set_id(m_next_entry);		// on donne son index au nouveau media
	
	//int new_id = m_biblio.end(); // on recupere l'id que va prendre le media ajoute
	//m_biblio.pop_back(); 

	// if (m_indices.size() == 0) // si il ne reste aucun indice dispo
	// {
	// 	m_liste.push_back(new_media); // on ajoute a la fin
	// 	(m_liste.back())->set_id(new_id); 
	// 	m_indices.push_back(m_nb_media); 
	// }
	// else
	// {
	// 	m_liste[new_id]=new_media;
	// 	m_liste[new_id]->set_id(new_id);
	// }
}

void mediatheque::suppr(int indice)
{
	m_biblio.erase(m_biblio.begin() + indice);
}