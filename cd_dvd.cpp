/* cd_dvd.cpp */

#include "cd_dvd.hpp"
#include <string>

using namespace std;

cd_dvd::cd_dvd(int type) : vhs()//constructeur bateau
{
    cout << "Quel est le nombre de pistes ?" << endl;
    cin >> m_piste;
    m_type = type;
}

cd_dvd::cd_dvd(int piste, int duree, string maison_production, string auteur, string nom, int dispo, int type) : vhs(duree, maison_production, auteur, nom, dispo)
{
    m_piste = piste;
    m_type = type;
}

cd_dvd::cd_dvd(string piste, string duree, string maison_production, string auteur, string nom, int type) : vhs(duree, maison_production, auteur, nom)
{
    m_piste = stoi(piste);
    m_type = type;
}

cd_dvd::~cd_dvd()
{

}

void cd_dvd::affiche() // affichage a mettre en forme
{
    vhs::affiche();
    cout << m_piste << endl;
}

void cd_dvd::save_media(ofstream* file)
{
    *file << m_type << endl;
    *file << m_piste << endl;
    media::save_media(file);
}