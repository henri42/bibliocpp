/* livre.cpp */
#include "livre.hpp"
#include <string>
#include <iostream>

using namespace std;

livre::livre() : media(LIVRE)//constructeur bateau
{
	cout << "Quel est l'annee de publication ?" << endl;
	cin >> m_annee;
	cout << "Quel est le nombre de page du livre ?" << endl;
	cin >> m_pages;
	cout << "Quel est la collection ?" << endl;
	getline(cin, m_collection);
	cout << "Fournissez un rapide résumé ci-dessous :" << endl;
	getline(cin, m_resume);
}

livre::livre(int annee, int pages, std::string collection, std::string resume, std::string auteur, std::string nom, int dispo) : media(auteur, nom, LIVRE, dispo)
{	
	m_annee = annee;
	m_pages = pages;
	m_collection = collection;
	m_resume =  resume;
}

livre::livre(std::string annee, std::string pages, std::string collection, std::string resume, std::string auteur, std::string nom) : media(auteur, nom, LIVRE, DISPONIBLE)
{	
	m_annee = stoi(annee); //string to integer
	m_pages = stoi(pages);
	m_collection = collection;
	m_resume = resume;	
}

livre::~livre()
{
	
}

void livre::affiche() // affichage a mettre en forme
{
	media::affiche();
	cout << "Année: " << m_annee << endl;
	cout << m_pages << " pages" << endl;
	cout << "Collection: " << m_collection << endl;
	cout << "Résumé: " << m_resume << endl;
}

void livre::save_media(ofstream* file)
{
    *file << LIVRE << endl;
	*file << m_annee << endl;
	*file << m_pages << endl;
	*file << m_collection << endl;
	*file << m_resume << endl;
    media::save_media(file);
}

bool livre::search(string buffer)
{
	string stock_type = to_string(m_type);
	string stock_dispo = to_string(m_dispo);
	string stock_annee = to_string(m_annee);
	string stock_pages = to_string(m_pages);
	if (stock_annee == buffer || stock_pages == buffer || m_collection == buffer || m_resume == buffer || stock_type == buffer || stock_dispo == buffer || m_auteur == buffer || m_nom == buffer)
		return true;
	else
		return false;
}