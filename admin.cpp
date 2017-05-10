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
        return false;
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

void admin::help()
{
    cout << "--- Liste des commandes admin ---" << endl << endl
         << "BYE" << endl
         << "ADD type" << endl
         << "LOAD filename" << endl
         << "SAVE filename" << endl
         << "SEARCH saisie" << endl
         << "CLEAR" << endl
         << "LIST" << endl
         << "SHOW id" << endl
         << "DELETE id" << endl
         << "RESET" << endl;
}