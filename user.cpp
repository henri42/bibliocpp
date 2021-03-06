/* user.cpp */
#include <stdlib.h>
#include "user.hpp"

using namespace std;

user::user()
{
    m_id_user = 0;
}

user::user(mediatheque* new_mediatheque, int id)
{
    m_id_user = id;
    m_mediatheque = new_mediatheque;
    m_actif = true;
}

user::~user()
{

}
int user::getIdUser()
{
    return m_id_user;
}

bool user::is_active()
{
    return m_actif;
}

void user::bye()
{
    m_mediatheque->reset();
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

void user::help()
{
    cout << "--- Liste des commandes ---" << endl << endl
         << "BYE" << endl
         << "SEARCH saisie" << endl
         << "CLEAR" << endl
         << "LIST" << endl
         << "SHOW id" << endl
         << "EMPRUNTER id" << endl
         << "RENDRE id" << endl
         << "RESERVER id" << endl;
}

bool user::transaction(int id, int trans)
{
    bool res = false;
    if (trans == EMPRUNTER)
       res = m_mediatheque->emprunter(id, m_id_user);
    else if (trans == RESERVER)
       res = m_mediatheque->reserver(id, m_id_user);
    else if (trans == RENDRE)
       res = m_mediatheque->rendre(id, m_id_user);
    return res;
}

bool user::reload()
{
    return m_mediatheque->load_from_file("active_bib.txt");
}

void user::add(int type)
{
    cout << "Vous n'avez pas les droit d'administrateur" << endl;
}

bool user::del(int id)
{
    cout << "Vous n'avez pas les droit d'administrateur" << endl;
    return true;
}

bool user::load(string filename)
{
    cout << "Vous n'avez pas les droit d'administrateur" << endl;
    return false;
}

bool user::save(string filename)
{
    cout << "Vous n'avez pas les droit d'administrateur" << endl;
    return false;
}

void user::reset()
{
    cout << "Vous n'avez pas les droit d'administrateur" << endl;
}

void user::lecture_commande()
{
    string saisie;
    string cmd;
    string arg;
    unsigned long espace;
    int type = (-1);
    int id, res;

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
            if (type != (-1))
                add(type); //ajout
            type = (-1);
        }

        else if (!cmd.compare("BYE"))
        {
            cout << "Fermeture de la bibliothèque" << endl;
            bye();
        }

        else if (!cmd.compare("LOAD"))
        {
            if (load(arg))
                cout << "Chargement de la médiathèque depuis " << arg << " réussi" << endl;
            else
                cout << "Chargement non effectué" << endl;
        }

        else if (!cmd.compare("RELOAD"))
        {
            if (reload())
                cout << "Actualisation de la bibliothèque active réussie" << endl;
            else
                cout << "Actualisation non effectuée" << endl;
        }

        else if (!cmd.compare("SAVE"))
        {
            if (save(arg))
                cout << "Sauvegarde de la médiathèque vers " << arg << " réussie" << endl;
            else
                cout << "Sauvegarde non effectuée" << endl;
        }


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
            if (!show(id))
                cout << "ID non présent dans la bibliothèque" << endl;
        }

        else if (!cmd.compare("DELETE"))
        {
            id = stoi(arg);
            if(!del(id))
                cout << "ID non présent dans la bibliothèque" << endl;
        }

        else if (!cmd.compare("RESET"))
        {
            cout << "Réinitialisation de la médiathèque" << endl;
            reset();
        }

        else if (!cmd.compare("EMPRUNTER"))
        {
            id = stoi(arg);
            if (transaction(id, EMPRUNTER))
                cout << "Emprunt effectué" << endl;
            else
                cout << "Vous ne pouvez pas emprunter ce media" << endl;
        }

        else if (!cmd.compare("RESERVER"))
        {
            id = stoi(arg);
            if (transaction(id, RESERVER))
                cout << "Reservation effectuée" << endl;
            else
                cout << "Vous ne pouvez pas reserver ce media" << endl;
        }

        else if (!cmd.compare("RENDRE"))
        {
            id = stoi(arg);
            if (transaction(id, RENDRE))
                cout << "Media rendu" << endl;
            else
                cout << "Erreur le media est disponible ou vous n'êtes pas le locataire" << endl;
        }

        else if (!cmd.compare("HELP"))
        {
            help();
        }
        else
        {
            cout << "Commande non reconnue, tapez HELP pour connaître la liste des commandes." << endl;
        }

    }
}
