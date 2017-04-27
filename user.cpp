/* user.cpp */
#include <stdlib.h>
#include "user.hpp"

using namespace std;

user::user()
{
    m_id_user = 0;
}

user::~user()
{

}

bool user::lecture_commande()
{
    string saisie;
    string cmd;
    string arg;
    unsigned long espace;
    int type, id;

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

        if (cmd.compare("ADD"))
        {
            if (arg.compare("livre"))
                type = LIVRE;
            else if (arg.compare("revue"))
                type = REVUE;
            else if (arg.compare("vhs"))
                type = VHS;
            else if (arg.compare("cd"))
                type = CD;
            else if (arg.compare("dvd"))
                type = DVD
            else if (arg.compare("ressource"))
                type = RESSOURCE;
            else {
                cout << "Les type de médias sont: livre revue vhs cd dvd et ressource" << endl;
                return false;
            }
            m_mediatheque->ajout(type);
            return true;
        }

        else if (cmd.compare("BYE"))
            exit(0);

        else if (cmd.compare("LOAD"))
            return m_mediatheque->load_from_file(arg);

        else if (cmd.compare("SAVE"))
            return m_mediatheque->save_to_file(arg);

        else if (cmd.compare("SEARCH"))
            // a completer
            return true;

        else if (cmd.compare("CLEAR"))
            // a completer
            return true;

        else if (cmd.compare("LIST"))
            // a completer
            return true;

        else if (cmd.compare("SHOW"))
        {
            id = stoi(arg);
            if ( (id >= 0) && (id < m_mediatheque->taille()) )
            {
                m_mediatheque->affiche(id);
                return true;
            }
            else return false;
        }

        else if (cmd.compare("DELETE"))
        {
            id = stoi(arg);
            if ( (id >= 0) && (id < m_mediatheque->taille()) )
            {
                m_mediatheque->suppr(id);
                return true;
            }
            else return false;
        }

        else if (cmd.compare("RESET"))
        {
            cout << "Réinitialisation de la médiathèque" << endl;
            m_mediatheque->clear();
            return true;
        }

    }
}
