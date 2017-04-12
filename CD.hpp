/* CD.hpp */
#include <string>

class CD
{
	//Attributs
	private :

		int m_duree;					//Durée du CD en minutes
		int m_piste;					//Nombre de pistes

		std::string m_maison_production;
		std::string m_titre;
		std::string m_auteur;
	
	//Méthodes
	public :
		// constructeurs et destructeurs
		CD();
		~CD();

}