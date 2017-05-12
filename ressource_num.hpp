/* ressource_num.hpp */
#ifndef DEF_RESSOURCE
#define DEF_RESSOURCE

#include <string>
#include <iostream>
#include "media.hpp"

class ressource_num : public media
{
	//Attributs
	private :

		int m_taille;					//Taille en octets
		std::string m_format;			//format (pdf, txt, ...)
		std::string m_chemin;			//Chemin d'accès de type URL

	
	//Méthodes
	public :
		// constructeurs et destructeurs
		ressource_num();
        ressource_num(int taille, std::string format, std::string chemin, std::string auteur, std::string nom, int dispo, int client);
		~ressource_num();

        void affiche();
		void save_media(std::ofstream* file);
		bool search(std::string buffer);

};

#endif