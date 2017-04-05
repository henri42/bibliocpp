/* mediatheque.hpp */
#include <media.hpp>

class mediatheque
{
	private :
		int nb_media;
		vector<media> list_media;
	
	public :
		// constructeurs et destructeurs
		mediatheque();
		mediatheque(filename);
		~mediatheque();
		
}
