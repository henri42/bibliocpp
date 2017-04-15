#include "mediatheque.hpp"

mediatheque::mediatheque()
{
	m_nb_media = 0;
	m_indices.push_back(m_nb_media);
}

void mediatheque::ajout(media* new_media)
{
	m_nb_media ++;
	
	int new_id = m_indices.back(); // on recupere l'id que va prendre le media ajoute
	m_indices.pop_back(); 

	if (m_indices.size() == 0) // si il ne reste aucun indice dispo
	{
		m_liste.push_back(new_media); // on ajoute a la fin
		(m_liste.back())->set_id(new_id); 
		m_indices.push_back(m_nb_media); 
	}
	else
	{
		m_liste[new_id]=new_media;
		m_liste[new_id]->set_id(new_id);
	}
}

