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
	m_id_client = 0;

	cout << "Quel est l'auteur ?" << endl;
	getline(cin, m_auteur);
	cout << "Quel est le titre ?" << endl;
	getline(cin, m_nom);
}

media::media(std::string auteur, std::string nom, int type, int dispo, int client)
{
	m_auteur = auteur;
	m_nom = nom;
	m_type = type;
 	m_dispo = dispo;
}

media::~media()
{
	
}

bool media::reserver(int id_client)
{
	if (m_dispo == DISPONIBLE)
	{
		m_id_client = id_client;
		m_dispo = RESERVE;
		return true;
	}
	else
		return false;
}

bool media::rendre(int id_client)
{
	if (m_dispo == EMPRUNTE && m_id_client == id_client )
	{
		m_dispo = DISPONIBLE;
		m_id_client = 0;
		return true;
	}
	else
		return false;
}

bool media::emprunter(int id_client)
{
	if (m_dispo == DISPONIBLE)
	{
		m_dispo = EMPRUNTE;
		m_id_client = id_client;
		return true;
	}
	else if (m_id_client == id_client && m_dispo == RESERVE)
	{
		m_dispo = EMPRUNTE;
		return true;
	}
	else
		return false;
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

void media::save_media(ofstream* file)
{
    *file << m_auteur << endl;
    *file << m_nom << endl;
    *file << m_dispo << endl;
	*file << m_id_client << endl;
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
