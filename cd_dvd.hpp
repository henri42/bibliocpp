/* cd_dvd.hpp */
#ifndef DEF_CDDVD
#define DEF_CDDVD

#include <string>
#include <iostream>
#include "VHS.hpp"

class cd_dvd : public vhs
{
	//Attributs
	private :
		int m_piste;					//Nombre de pistes
	
	//Méthodes
	public :
		// constructeurs et destructeurs
		cd_dvd(int type);
        cd_dvd(int piste, int duree, std::string maison_production, std::string auteur, std::string nom, int dispo, int type);
        cd_dvd(std::string piste, std::string duree, std::string maison_production, std::string auteur, std::string nom, int type);
        ~cd_dvd();

		void affiche();
		void save_media(std::ofstream* file);
};

#endif