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
	std::vector<media*> m_biblio; //Liste des médias de la mediatheque

public :
	int m_nb_media;				// nombre de media dans la mediatheque

	int m_next_entry; 			// indice que prendra le prochain media ajoute

	std::vector<int> m_indices;	// indices que prendront les prochains medias ajoutes



public :
	// constructeurs et destructeurs
	mediatheque();
	// mediatheque(char* filename);//constructeurs d'une bilbliotèque a partir d'un fichier
	~mediatheque();

	//methodes
	void affiche();
	void affiche(int indice);

	void ajout(media* const new_media);
	void suppr(int indice);

	// void consulter(int id_cible);

	// void reserver(int id_cible);
	// void emprunter(int id_cible);
	// void rendre(int id_cible);

	// void rechercher(char* nom);
};

#endif