/* user.cpp */
#include <stdlib.h>
#include "user.hpp"

using namespace std;

user::user()
{
    m_id_user = 0;
}

user::user(mediatheque* new_mediatheque)
{
    m_id_user = 0;
    m_mediatheque = new_mediatheque;
    m_actif = true;
}

user::~user()
{

}

bool user::is_active()
{
    return m_actif;
}

void user::bye()
{
    cout << "Fermeture de la bibliothèque" << endl;
    m_actif = false;
}

bool user::show(int id)
{
    if ( (id >= 0) && (id < m_mediatheque->taille()) ) //
    {
        m_mediatheque->affiche(id);
        return true;
    }
    else
    {
        cout << "ID non présent dans la bibliothèque" << endl;
        return false;
    }
}

void user::list()
{
    m_mediatheque->affiche_short();
}

void user::search(string saisie)
{
    m_mediatheque->search_media();
}

void user::clear()
{
    // fonction recherche de mediatheque a revoir
}

bool user::lecture_commande()
{
    string saisie;
    string cmd;
    string arg;
    unsigned long espace;
    int type, id;

    cout << endl;
    cout << "Entrez une commande: " << endl;

    getline(cin, saisie);
    unsigned long taille = saisie.size();

    if (taille != 0)
    {
        espace = saisie.find(" ");
        if (espace != (-1))
        {
            cmd = saisie.substr(0, espace); // commande
            arg = saisie.substr(espace+1, taille);
        }
        else
            cmd = saisie;

        if (!cmd.compare("ADD"))
        {
            if (!arg.compare("livre"))
                type = LIVRE;
            else if (!arg.compare("revue"))
                type = REVUE;
            else if (!arg.compare("vhs"))
                type = VHS;
            else if (!arg.compare("cd"))
                type = CD;
            else if (!arg.compare("dvd"))
                type = DVD;
            else if (!arg.compare("ressource"))
                type = RESSOURCE;
            else {
                cout << "Les types de médias sont: livre revue vhs cd dvd et ressource" << endl;
                return false;
            }
            m_mediatheque->ajout(type); //add()
            return true;
        }

        else if (!cmd.compare("BYE"))
            exit(0); //bye()

        else if (!cmd.compare("LOAD"))
            return m_mediatheque->load_from_file(arg); //load()

        else if (!cmd.compare("SAVE"))
            return m_mediatheque->save_to_file(arg); //save()

        else if (!cmd.compare("SEARCH"))
        {
            search(arg);
            return true;
        }

        else if (!cmd.compare("CLEAR"))
            // clear ()
            return true;

        else if (!cmd.compare("LIST"))
        {
            list();
            return true;
        }

        else if (!cmd.compare("SHOW"))
        {
            id = stoi(arg);
            return show(id);
        }

        else if (!cmd.compare("DELETE"))
        {
            id = stoi(arg);
            if ( (id >= 0) && (id < m_mediatheque->taille()) ) //delete(id)
            {
                cout << "Suppression du média " << id << endl;
                m_mediatheque->suppr(id);
                return true;
            }
            else {
                cout << "ID non présent dans la bibliothèque" << endl;
                return false;
            } //
        }

        else if (!cmd.compare("RESET"))
        {
            cout << "Réinitialisation de la médiathèque" << endl;
            m_mediatheque->clear(); //reset
            return true;
        }

        else return false;

    }

    else return false;
}
