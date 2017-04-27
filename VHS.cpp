/* VHS.cpp */
#include "VHS.hpp"

using namespace std;

vhs::vhs() : media(VHS)
{
	cout << "Quel est la maison de production ?" << endl;
	getline(cin, m_maison_production);	
	cout << "Quelle est la durée du média (en secondes) ?" << endl;
	cin >> m_duree;
}

vhs::vhs(int duree, string maison_production, string auteur, string nom, int dispo) : media(auteur, nom, VHS, dispo)
{	
	m_maison_production = maison_production;
	m_duree = duree;
}

vhs::vhs(string duree, string maison_production, string auteur, string nom) : media(auteur, nom, VHS, DISPONIBLE)
{	
	m_duree = stoi(duree); //string to integer
	m_maison_production = maison_production;
}

vhs::~vhs()
{
	
}

void vhs::affiche()
{
	media::affiche();
	cout << "Maison de production: " << m_maison_production << endl;
	cout << "Durée: " << m_duree << " minutes" << endl;
}

void vhs::save_media(ofstream* file)
{
	*file << VHS << endl;
	*file << m_maison_production << endl;
	*file << m_duree << endl;
	media::save_media(file);
}