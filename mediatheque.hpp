/* mediatheque.hpp */
#ifndef DEF_MEDIATHEQUE
#define DEF_MEDIATHEQUE

#include <string>
#include <iostream>
#include <vector>
#include "media.hpp"

class mediatheque
{
//Attributs
private :
	std::vector<media*> m_biblio;

public :
	int m_nb_media;				// nombre de media dans la mediatheque

	int m_next_entry; 			// indice que prendra le prochain media ajoute

	std::vector<media*> m_liste; //
	std::vector<int> m_indices;	// indices que prendront les prochains medias ajoutes



public :
	// constructeurs et destructeurs
	mediatheque();
	// mediatheque(char* filename);//constructeurs d'une bilbliotèque a partir d'un fichier
	~mediatheque();

	//methodes
	void ajout(media* const new_media);
	void affiche(int indice);


	// void suppr(media del_media);

	// void consulter(int id_cible);

	// void reserver(int id_cible);
	// void emprunter(int id_cible);
	// void rendre(int id_cible);

	// void rechercher(char* nom);
};

#endif