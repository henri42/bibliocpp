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
	cin.ignore();
	cout << "Quel est la collection ?" << endl;
	getline(cin, m_collection);
	cout << "Fournissez un rapide résumé ci-dessous :" << endl;
	getline(cin, m_resume);
}

livre::livre(int annee, int pages, std::string collection, std::string resume, std::string auteur, std::string nom, int dispo, int client) : media(auteur, nom, LIVRE, dispo, client)
{	
	m_annee = annee;
	m_pages = pages;
	m_collection = collection;
	m_resume =  resume;
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
	bool search_m = media::search(buffer);
	string stock_annee = to_string(m_annee);
	string stock_pages = to_string(m_pages);
	if (stock_annee == buffer || stock_pages == buffer || m_collection == buffer || m_resume == buffer || search_m)
		return true;
	else
		return false;
}