#ifndef DEF_USER
#define DEF_USER

#include "mediatheque.hpp"

class user
{
private:
    mediatheque* m_mediatheque;
    int m_id_user;
    bool m_actif;

public:
    user();
    user(mediatheque* new_mediatheque);
    ~user();

    bool is_active();

    // methodes accessible client
    void bye();
    bool show(int id);
    void list();
    void search(std::string saisie);
    void clear();

    // methodes accessibles admin
    /*virtual void add(int type);
    virtual void del(int id);
    virtual bool load(std::string filename);
    virtual bool save(std::string filename);
    virtual void reset();*/


    bool lecture_commande();

};

#endif //DEF_USER
