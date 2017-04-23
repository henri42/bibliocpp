/* media.cpp */
#include "media.hpp"
#include <string>
#include <iostream>

using namespace std;

media::media()
{
	
}

media::media(std::string auteur, std::string nom, int type, int dispo)
{
	m_auteur = auteur;
	m_nom = nom;
	m_type = type;
 	m_dispo = dispo;
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
}