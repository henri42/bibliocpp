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

	//void reserver(int indice);
	int emprunter(int indice);
	void rendre(int indice);

	// void rechercher(char* nom);
};

#endif