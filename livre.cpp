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
	cout << m_annee << endl;
	cout << m_pages << endl;
	cout << m_collection << endl;
	cout << m_resume << endl;
}