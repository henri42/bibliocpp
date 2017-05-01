/* admin.cpp */
#include <stdlib.h>
#include "admin.hpp"

using namespace std;

admin::admin() : user()
{}

admin::admin(mediatheque* new_mediatheque) : user(new_mediatheque)
{}

admin::~admin()
{}

void user::add(int type)
{
    m_mediatheque->ajout(type);
}

bool user::del(int id)
{
    if ( (id >= 0) && (id < m_mediatheque->taille()) ) //
    {
        m_mediatheque->suppr(id);
        return true;
    }
    else
    {
        cout << "ID non présent dans la bibliothèque" << endl;
        return false;
    }
}

bool user::load(string filename)
{
    return m_mediatheque->load_from_file(filename);
}

bool user::save(string filename)
{
    return m_mediatheque->save_to_file(filename);
}

void user::reset()
{
    m_mediatheque->reset();
}

