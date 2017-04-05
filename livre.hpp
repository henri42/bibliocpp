/* livre.hpp */
#include <revue.hpp>
#include <string>

class mediatheque
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
		void ajoutlivre(livre &livre);
		void suppressionlivre(livre &livre);

}
