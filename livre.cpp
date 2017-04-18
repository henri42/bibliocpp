/* livre.cpp */
#include "livre.hpp"

livre::livre()
{
	m_auteur = "levy";
	m_annee = 1956;
	m_pages = 345;
	m_collection = "hachette";
	m_dispo = EMPRUNTE;
	m_titre = "tarzan";	
	m_id=1;
}

livre::~livre()
{
	
}