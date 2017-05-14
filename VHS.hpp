/* VHS.hpp */
#ifndef DEF_VHS
#define DEF_VHS

#include <string>
#include <iostream>
#include "media.hpp"

class vhs : public media 
{
	//Attributs
	protected :
		int m_duree;					//Durée de la vidéo en minutes
		std::string m_maison_production;
	
	//Méthodes
	public :
		// constructeurs et destructeurs
		vhs();
		vhs(int duree, std::string maison_production, std::string auteur, std::string nom, int dispo, int client);
		~vhs();

		void affiche();
		void save_media(std::ofstream* file);
		bool search(std::string buffer);
};

#endif