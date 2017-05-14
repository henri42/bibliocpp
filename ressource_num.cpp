/* ressource_num.cpp */

#include "ressource_num.hpp"
#include <string>

using namespace std;

ressource_num::ressource_num() : media(RESSOURCE)//constructeur bateau
{
    cout << "Quel est l'URL de la ressource ?" << endl;
    getline(cin, m_chemin);
    cout << "Quel est le format de la ressource ?" << endl;
    getline(cin, m_format);
    cout << "Quel est la taille en Mo de la ressource ?" << endl;
    cin >> m_taille;
    cin.ignore();
}

ressource_num::ressource_num(int taille, string format, string chemin, string auteur, string nom, int dispo, int client) : media(auteur, nom, RESSOURCE, dispo, client)
{
    m_taille = taille;
    m_format = format;
    m_chemin = chemin;
}

ressource_num::~ressource_num()
{

}

void ressource_num::affiche() // affichage a mettre en forme
{
    media::affiche();
    cout << m_taille << endl;
    cout << m_format << endl;
    cout << m_chemin << endl;
}

void ressource_num::save_media(ofstream* file)
{
    *file << RESSOURCE << endl;
    *file << m_taille << endl;
    *file << m_format << endl;
    *file << m_chemin << endl;
    media::save_media(file);
}

bool ressource_num::search(string buffer)
{
    bool search_m = media::search(buffer);
    string stock_taille = to_string(m_taille);
    if (stock_taille == buffer || m_format == buffer || m_chemin == buffer || search_m)
        return true;
    else
        return false;
}