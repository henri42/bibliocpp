/* revue.hpp */
#include <livre.hpp>
#include <string>
#include <vector>

class revue
{
	//Attributs
	private :

		int m_article;					//Nombres d'articles contenus dans la revue
		int m_id_article;				//Index de l'article

		std::string m_editeur;

		std::vector<string> article;	//Collection d'articles contenus dans la revue
	
	//Méthodes
	public :
		// constructeurs et destructeurs
		revue();
		~revue();

};