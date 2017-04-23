/* media.cpp */
#include "media.hpp"
#include <string>
#include <iostream>

using namespace std;

media::media()
{
	
}

media::media(std::string auteur, std::string nom, int type, int dispo, int id)
{
	m_auteur = auteur;
	m_nom = nom;
	m_type = type;
 	m_dispo = dispo;
	m_id = id;
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