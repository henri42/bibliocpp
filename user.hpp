#ifndef DEF_USER
#define DEF_USER

#include "mediatheque.hpp"
#define EMPRUNTER 0
#define RESERVER 1
#define RENDRE 2

class user
{
protected:
    mediatheque* m_mediatheque;
    int m_id_user;
    bool m_actif;
    bool m_is_saved;

public:
    user();
    user(mediatheque* new_mediatheque, int id);
    ~user();

    bool is_active();
    int getIdUser();

    // methodes accessible client
    void bye();
    bool show(int id);
    void list();
    int search(std::string saisie);
    void clear();
    virtual void help();
    bool reload();
    bool transaction(int id, int trans); //emprunter, reserver, rendre

    // methodes accessibles admin
    virtual void add(int type);
    virtual bool del(int id);
    virtual bool load(std::string filename);
    virtual bool save(std::string filename);
    virtual void reset();


    void lecture_commande();

};

#endif //DEF_USER
