/* mediatheque.hpp */
#ifndef DEF_MEDIATHEQUE
#define DEF_MEDIATHEQUE

#include <string>
#include <iostream>
#include <vector>
#include "media.hpp"
#include "livre.hpp"
#include "VHS.hpp"
#include "cd_dvd.hpp"
#include "revue.hpp"
#include "ressource_num.hpp"

class mediatheque
{
//Attributs
private :
	std::vector<media*> m_biblio; //Liste des médias de la mediatheque

public :
	// constructeurs et destructeurs
	mediatheque();
	//mediatheque(char* filename);//constructeurs d'une bilbliotèque a partir d'un fichier
	~mediatheque();

	//methodes
	void affiche();
	void affiche(int indice);

	void ajout(media* const new_media);
	void ajout(int type, std::vector<std::string> data, std::vector<std::string> articles);
	void suppr(int indice);

	// void consulter(int id_cible);

	//void reserver(int indice);
	int emprunter(int indice);
	void rendre(int indice);

	// void rechercher(char* nom);

	bool load_from_file(std::string filename);

};

#endif