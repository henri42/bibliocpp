/* revue.hpp */
#ifndef DEF_revue
#define DEF_revue

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

		void affiche_articles(int all);		//Renvoit la liste de tous les articles de la revue si "all" vaut 1 ou sinon l'article d'index "m_id_article" si "all" vaut 0

		// constructeurs et destructeurs
		revue();
		~revue();

};

#endif