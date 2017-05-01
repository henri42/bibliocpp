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
	~mediatheque();

	//methodes
	int taille();

	void affiche();
	void affiche(int indice);
	void affiche_short(); //affiche les elements de la mediathèque de facon condensée

	void ajout(media* const new_media);

	void ajout(int type, std::vector<std::string> donnees, std::vector<std::string> articles);

	void ajout(int type);

	void suppr(int indice);

	// void consulter(int id_cible);

	//void reserver(int indice);
	int emprunter(int indice);
	void rendre(int indice);

	void search_media();
    int search_media_bib(std::string saisie, std::vector<media*> stock_recherche);
	void search_media(std::vector<media*> biblio, std::vector<std::string> buffer);

	bool load_from_file(std::string filename);
    bool save_to_file(std::string filename);

    void reset();
	void clear();

};

#endif