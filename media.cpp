/* media.cpp */
#include "media.hpp"
#include <string>
#include <iostream>

using namespace std;
string types[6] = {"Livre", "Revue", "VHS", "CD", "DVD", "Ressource numérique"};
string dispos[3] = {"Emprunté", "Disponible", "Réservé"};

media::media()
{
	//vide;
}

media::media(int type)
{
	m_type = type;
	m_dispo = DISPONIBLE;

	cout << "Quel est l'auteur ?" << endl;
	getline(cin, m_auteur);
	cout << "Quel est le titre ?" << endl;
	getline(cin, m_nom);
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
	cout << "Auteur: " << m_auteur << endl;
	cout << "Titre: " << m_nom << endl;
	cout << types[m_type] << endl;
	cout << dispos[m_dispo] << endl;
}

void media::affiche_short()
{
	cout << " | " << m_nom
		 << " | " << types[m_type]
		 << " | " << dispos[m_dispo] << endl;
}

int media::get_dispo()
{
	return m_dispo;
}

void media::set_dispo(int dispo)
{
	m_dispo = dispo;
}

void media::save_media(ofstream* file)
{
    *file << m_auteur << endl;
    *file << m_nom << endl;
    *file << "###" << endl;
}

bool media::search(string buffer)
{
	string stock_type = to_string(m_type);
	string stock_dispo = to_string(m_dispo);
	if (stock_type == buffer || stock_dispo == buffer || m_auteur == buffer || m_nom == buffer)
		return true;
	else
		return false;
}
