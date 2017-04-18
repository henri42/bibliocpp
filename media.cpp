/* media.cpp */
#include "media.hpp"
#include <string>
#include <iostream>

using namespace std;

media::media()
{
	m_auteur = "Telmo";
	m_nom = "Wars";
	m_type = 0;
 	m_dispo = 0;
	m_id = 0;
}

media::~media()
{
	
}

void media::affiche()
{
	cout << m_auteur << endl;
	cout << m_nom << endl;
	cout << m_type << endl;
	cout << m_dispo << endl;
	cout << m_id << endl;
}

int media::get_id()
{
	return m_id;
}

void media::set_id(int id)
{
	m_id = id;
}