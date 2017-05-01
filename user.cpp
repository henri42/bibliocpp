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

int user::search(string saisie)
{
    vector<media*> result_search;

    if (!m_is_saved)
        m_is_saved = m_mediatheque->save_to_file("save_search.txt");

    return m_mediatheque->search_media_bib(saisie, result_search);
}

void user::clear()
{
    if (m_is_saved)
        m_is_saved = !(m_mediatheque->load_from_file("save_search.txt"));
}

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

void user::lecture_commande()
{
    string saisie;
    string cmd;
    string arg;
    unsigned long espace;
    int type, id, res;

    cout << endl;
    cout << "Entrez une commande: " << endl;

    getline(cin, saisie);
    unsigned long taille = saisie.size();

    cout << endl;

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
            else
                cout << "Les types de médias sont: 'livre' 'revue' 'vhs' 'cd' 'dvd' 'ressource'" << endl;

            add(type); //ajout
        }

        else if (!cmd.compare("BYE"))
            bye();


        else if (!cmd.compare("LOAD"))
            load(arg);

        else if (!cmd.compare("SAVE"))
            save(arg);

        else if (!cmd.compare("SEARCH"))
        {
            res = search(arg);
            cout << res << " résulats" << endl;
        }

        else if (!cmd.compare("CLEAR"))
        {
            cout<< "--- FIN DE LA RECHERCHE ---" << endl;
            clear();
        }

        else if (!cmd.compare("LIST"))
            list();

        else if (!cmd.compare("SHOW"))
        {
            id = stoi(arg);
            show(id);
        }

        else if (!cmd.compare("DELETE"))
        {
            id = stoi(arg);
            del(id);
        }

        else if (!cmd.compare("RESET"))
        {
            cout << "Réinitialisation de la médiathèque" << endl;
            reset();
        }

        else if (!cmd.compare("HELP"))
        {
            cout << "--- Liste des commandes ---" << endl << endl
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

        else
        {
            cout << "Commande non reconnue, tapez HELP pour connaître la liste des commandes." << endl;
        }

    }
}
