/* cd_dvd.hpp */
#ifndef DEF_CDDVD
#define DEF_CDDVD

#include <string>

class cd_dvd : public vhs
{
	//Attributs
	private :

		int m_piste;					//Nombre de pistes
	
	//Méthodes
	public :
		// constructeurs et destructeurs
		cd_dvd();
		~cd_dvd();

};

#endif