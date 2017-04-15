/* media.cpp */
#include "media.hpp"
#include <iostream>

media::media()
{
	m_nom = "wars";
}

media::~media()
{
	
}

void media::affiche()
{
	std::cout << m_auteur << std::endl;
	std::cout << m_nom << std::endl;
	std::cout << m_type << std::endl;
	std::cout << m_dispo << std::endl;
	std::cout << m_id << std::endl;
}

int media::get_id()
{
	return m_id;
}

void media::set_id(int id)
{
	m_id = id;
}