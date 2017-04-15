#include "mediatheque.hpp"

mediatheque::mediatheque()
{
	m_nb_media = 0;
	m_next_entry = 0;
}

void mediatheque::ajout(livre* new_livre)
{
	//new_media.set_id(m_next_entry);		// on donne son index au nouveau media
	m_liste.push_back(new_livre);
	m_nb_media ++;
}

