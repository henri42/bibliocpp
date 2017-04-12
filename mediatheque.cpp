#include <mediatheque.hpp>

mediatheque::mediatheque()
{
	m_nb_media = 0;
}

void mediatheque::ajout(media new_media)
{
	m_nb_media ++;
	m_list_media.push_back(new_media);
}

void