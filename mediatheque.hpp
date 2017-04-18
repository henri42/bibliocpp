/* mediatheque.hpp */
#ifndef DEF_MEDIATHEQUE
#define DEF_MEDIATHEQUE

#include "media.hpp"
#include "livre.hpp"
#include <vector>

class mediatheque
{
public :
	int m_nb_media;				// nombre de media dans la mediatheque
	int m_next_entry; 			// indice que prendra le prochain media ajoute
	std::vector<media*> m_media;
	std::vector<livre*> m_livre;
	// std::vector<revue*> m_revue;
	// std::vector<vhs*> m_vhs;
	// std::vector<cd*> m_cd;
	// std::vector<ressource*> m_ressource;

public :
	// constructeurs et destructeurs
	mediatheque();
	// mediatheque(char* filename);//constructeurs d'une bilbliotèque a partir d'un fichier
	~mediatheque();

	//methodes
	void ajout(media* new_media);
	// void ajout(revue* new_revue);
	// void ajout(vhs* new_vhs);
	// void ajout(media* new_cd);
	// void ajout(media* new_dvd);

	void affiche(media* media);

	// void suppr(media del_media);
		
	// void consulter(int id_cible);

	// void reserver(int id_cible);
	// void emprunter(int id_cible);
	// void rendre(int id_cible);

	// void rechercher(char* nom);
};

#endif
