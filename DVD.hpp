/* DVD.hpp */
#include <string>

class DVD
{
	//Attributs
	private :

		int m_duree;					//Durée du DVD en minutes
		int m_piste;					//Nombre de pistes

		std::string m_maison_production;
		std::string m_auteur;
	
	//Méthodes
	public :
		// constructeurs et destructeurs
		DVD();
		~DVD();

};