/* livre.hpp */
#ifndef DEF_LIVRE
#define DEF_LIVRE

#include <string>
#include <iostream>
#include "media.hpp"

class livre : public media
{
//Attributs
protected :
	int m_annee;
	int m_pages;
	std::string m_collection;
	std::string m_resume;
	
//Méthodes
public :
	// constructeurs et destructeurs
	livre();
	livre(int annee, int pages, std::string collection, std::string resume, std::string auteur, std::string nom, int dispo);
		//constructeur pour chargement depuis fichier texte
	livre(std::string annee, std::string pages, std::string collection, std::string resume, std::string auteur, std::string nom);
	~livre();

	bool search(std::string buffer);
	void affiche(); //pas besoin de preciser virtual car le virtual s'herite
    void save_media(std::ofstream* file);
};

#endif