/* mediatheque.hpp */
#include <media.hpp>
#include <livre.hpp>

class mediatheque
{
private :
	int nb_media;
	vector<media> list_media;

public :
	// constructeurs et destructeurs
	mediatheque();
	mediatheque(char* filename);//constructeurs d'une bilbliotèque a partir d'un fichier
	~mediatheque();

	//methodes
	ajout(livre new_livre);
	ajout(revue new_revue);
	ajout(vhs new_vhs);
	ajout(cd new_cd);
	ajout(dvd new_dvd);
	ajout(ressource new_revue);

	suppr(livre _livre);
	suppr(revue _revue);
	suppr(vhs _vhs);
	suppr(cd _cd);
	suppr(dvd _dvd);
	suppr(ressource _revue);
		
	consulter(media cible);

	reserver(media cible);
	emprunter(media cible);
	rendre(media cible);

	rechercher(char* nom);
}
