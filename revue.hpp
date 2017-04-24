/* revue.hpp */
#ifndef DEF_REVUE
#define DEF_REVUE

#include "livre.hpp"
#include <string>
#include <vector>

class revue
{
	//Attributs
	private :

		int m_article;					//Nombres d'articles contenus dans la revue
		int m_id_article;				//Index de l'article

		std::string m_editeur;

		std::vector<revue*> article;	//Collection d'articles contenus dans la revue
	
	//Méthodes
	public :

		void affiche_articles(int index);		//Renvoit la liste de tous les articles de la revue si "index" vaut -1 ou sinon l'article d'index "index"

		// constructeurs et destructeurs
		revue();
		~revue();

};

#endif