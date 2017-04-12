/* mediatheque.hpp */
#include <media.hpp>
#include <livre.hpp>
#include <vector>

class mediatheque
{
private :
	int m_nb_media;				// nombre de media dans la mediatheque
	int m_next_entry; 			// indice que prendra le prochain media ajoute
	vector<media*> m_list_media;	

public :
	// constructeurs et destructeurs
	mediatheque();
	// mediatheque(char* filename);//constructeurs d'une bilbliotèque a partir d'un fichier
	~mediatheque();

	//methodes
	void ajout(media new_media);

	// void suppr(media del_media);
		
	// void consulter(int id_cible);

	// void reserver(int id_cible);
	// void emprunter(int id_cible);
	// void rendre(int id_cible);

	// void rechercher(char* nom);
}
