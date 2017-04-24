/* livre.cpp */
#include "livre.hpp"
#include <string>
#include <iostream>

using namespace std;

livre::livre() //constructeur bateau
{
	cout << "Quel est l'auteur du livre ?" << endl;
	cin >> m_auteur;

	cout << "Quel est l'auteur du livre ?" << endl;
	cin >> m_auteur;
}

livre::livre(int annee, int pages, std::string collection, std::string resume, std::string auteur, std::string nom, int type, int dispo) : 	media(auteur, nom, type, dispo)
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
	cout << m_annee << endl;
	cout << m_pages << endl;
	cout << m_collection << endl;
	cout << m_resume << endl;
}