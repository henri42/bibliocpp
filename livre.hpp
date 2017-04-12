#ifndef DEF_LIVRE
#define DEF_LIVRE

/* livre.hpp */
#include <string>
#include "media.hpp"

class livre : public media
{
//Attributs
private :
	std::string m_auteur;
	int m_annee;
	int m_pages;
	std::string m_collection;
	std::string m_titre;
	std::string m_resume;
	
//Méthodes
public :
	// constructeurs et destructeurs
	livre();
	~livre();
};

#endif