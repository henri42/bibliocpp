#include "mediatheque.hpp"

mediatheque::mediatheque()
{
	m_nb_media = 0;
	m_next_entry = 0;
}

void mediatheque::ajout(media* new_media)
{

	//new_media.set_id(m_next_entry);		// on donne son index au nouveau media
	m_nb_media ++;
	m_list_media.push_back(new_media);
}

