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
	std::vector<media*> m_liste; //
	std::vector<int> m_indices;	// indices


public :
	// constructeurs et destructeurs
	mediatheque();
	// mediatheque(char* filename);//constructeurs d'une bilbliotèque a partir d'un fichier
	~mediatheque(){}

	//methodes
	void ajout(livre* new_livre);
	// void ajout(revue* new_revue);
	// void ajout(vhs* new_vhs);
	// void ajout(cd* new_cd);
	// void ajout(ressource* new_ressource);

	// void suppr(media del_media);
		
	// void consulter(int id_cible);

	// void reserver(int id_cible);
	// void emprunter(int id_cible);
	// void rendre(int id_cible);

	// void rechercher(char* nom);
};

#endif
