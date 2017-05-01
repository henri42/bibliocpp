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

void admin::add(int type)
{
    m_mediatheque->ajout(type);
}

bool admin::del(int id)
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

bool admin::load(string filename)
{
    return m_mediatheque->load_from_file(filename);
}

bool admin::save(string filename)
{
    return m_mediatheque->save_to_file(filename);
}

void admin::reset()
{
    m_mediatheque->reset();
}

