#ifndef DEF_USER
#define DEF_USER

#include "mediatheque.hpp"

class user
{
private:
    mediatheque* m_mediatheque;
    int m_id_user;

public:
    user();
    user(mediatheque* new_mediatheque);
    ~user();

    bool lecture_commande();

};

#endif //DEF_USER
