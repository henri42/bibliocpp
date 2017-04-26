/* revue.hpp */
#ifndef DEF_REVUE
#define DEF_REVUE

#include "livre.hpp"
#include <string>
#include <vector>

class revue : public livre
{
	//Attributs
	private :

		int m_article;					//Nombres d'articles contenus dans la revue
		int m_id_article;

		std::string m_editeur;

		std::vector<revue*> m_liste_article;	//Collection d'articles contenus dans la revue
	
	//Méthodes
	public :

		void affiche();
		void affiche_articles(int index);		//Renvoit la liste de tous les articles de la revue si "index" vaut -1 ou sinon l'article d'index "index"

		// constructeurs et destructeurs
		revue();
		~revue();

};

#endif