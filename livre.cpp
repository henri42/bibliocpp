/* livre.cpp */
#include "livre.hpp"
#include <string>
#include <iostream>

using namespace std;

livre::livre() //constructeur bateau
{
	m_annee = 2017;
	m_pages = 100;
	m_collection = "Hachette";
	m_resume = "Coolos";
}

livre::livre(int annee, int pages, std::string collection, std::string resume, std::string auteur, std::string nom, int type, int dispo)
{
	//media::media(auteur, nom, type, dispo);
	m_auteur = auteur;
	m_nom = nom;
	m_type = type;
 	m_dispo = dispo;
 	
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