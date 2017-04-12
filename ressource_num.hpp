/* ressource_num.hpp */
#include <string>

class ressource_num
{
	//Attributs
	private :

		int m_taille;					//Durée du DVD en minutes

		std::string m_type;
		std::string m_auteur;
		std::string m_chemin;			//Chemin d'accès de type URL

	
	//Méthodes
	public :
		// constructeurs et destructeurs
		ressource_num();
		~ressource_num();

}