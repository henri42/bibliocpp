/* VHS.hpp */
#ifndef DEF_VHS
#define DEF_VHS

#include <string>

class VHS : public media 
{
	//Attributs
	private :

		int m_duree;					//Durée de la vidéo en minutes

		std::string m_maison_production;
		std::string m_auteur;
	
	//Méthodes
	public :
		// constructeurs et destructeurs
		VHS();
		~VHS();

};

#endif