#ifndef DEF_LIVRE
#define DEF_LIVRE

/* livre.hpp */
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
	~livre();

	void affiche(); //la fonction herite du virtual de media::affiche()
};

#endif