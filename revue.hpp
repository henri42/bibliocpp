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

		int m_nb_articles;					//Nombres d'articles contenus dans la revue
		int m_id_article;

		std::string m_editeur;

		std::vector<std::string> m_liste_articles;	//Collection d'articles contenus dans la revue
	
	//Méthodes
	public :

		void affiche();
		void affiche_articles(int index);		//Renvoit la liste de tous les articles de la revue si "index" vaut -1 ou sinon l'article d'index "index"

		// constructeurs et destructeurs
		revue();
		revue(std::string editeur, std::vector<std::string> liste_articles, int annee, int pages, std::string collection, std::string resume, std::string auteur, std::string nom, int dispo, int client);
		~revue();
        void save_media(std::ofstream* file);
       	bool search(std::string buffer);

};

#endif