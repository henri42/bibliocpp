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
    cout << "Quel est la taille en octets de la ressource ?" << endl;
    cin >> m_taille;
}

ressource_num::ressource_num(int taille, string format, string chemin, string auteur, string nom, int dispo) : media(auteur, nom, RESSOURCE, dispo)
{
    m_taille = taille;
    m_format = format;
    m_chemin = chemin;
}

ressource_num::ressource_num(string taille, string format, string chemin, string auteur, string nom) : media(auteur, nom, RESSOURCE, DISPONIBLE)
{
    m_taille = stoi(taille);
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