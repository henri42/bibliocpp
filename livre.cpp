/* livre.cpp */
#include "livre.hpp"
#include "media.hpp"

livre::livre() //constructeur bateau
{
	m_auteur = "gainsbourg";
	m_nom = "bonnie";
	m_type = LIVRE;
	m_dispo = DISPONIBLE;
	m_id = 1;

	m_annee = 1992;
	m_pages = 321;
	m_collection = "hachette";
	m_resume = "petite histoire sympathique";
}

livre::~livre()
{
	
}

void livre::affiche() // affichage a mettre en forme
{
	media::affiche();
	std::cout << m_annee << std::endl;
	std::cout << m_pages << std::endl;
	std::cout << m_collection << std::endl;
	std::cout << m_resume << std::endl;
}