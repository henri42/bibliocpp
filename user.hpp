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

    void bye();
    void show(int id);
    void search(std::string saisie);

    bool lecture_commande();

};

#endif //DEF_USER
