/* media.hpp */
#ifndef DEF_MEDIA
#define DEF_MEDIA

#include <string>
#include <iostream>

#define LIVRE		0
#define REVUE		1
#define VHS			2
#define CD			3
#define DVD			4
#define RESSOURCE	5

#define EMPRUNTE	0
#define DISPONIBLE	1
#define RESERVE		2

class media
{
//Attributs
protected:
	std::string m_auteur;
	std::string m_nom;
	int m_type;
	int m_dispo;
	int m_id;

public:
	media();
	media(std::string auteur, std::string nom, int type, int dispo, int id);
	~media();

	virtual void affiche();
	int get_id();
	void set_id(int id);
};

#endif