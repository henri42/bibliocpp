#ifndef DEF_ADMIN
#define DEF_ADMIN

#include "mediatheque.hpp"
#include "user.hpp"

class admin : public user
{
public:
    admin();
    admin(mediatheque* new_mediatheque);
    ~admin();

    void help();

    // methodes accessibles admin seulement
    void add(int type);
    bool del(int id);
    bool load(std::string filename);
    bool save(std::string filename);
    void reset();
};

#endif //DEF_ADMIN
