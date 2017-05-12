/* VHS.cpp */
#include "VHS.hpp"

using namespace std;

vhs::vhs() : media(VHS)
{
	cout << "Quel est la maison de production ?" << endl;
	getline(cin, m_maison_production);	
	cout << "Quelle est la durée du média (en minutes) ?" << endl;
	cin >> m_duree;
	cin.ignore();
}

vhs::vhs(int duree, string maison_production, string auteur, string nom, int dispo, int client) : media(auteur, nom, VHS, dispo, client)
{	
	m_maison_production = maison_production;
	m_duree = duree;
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
	*file << m_duree << endl;
	*file << m_maison_production << endl;
	media::save_media(file);
}

bool vhs::search(string buffer)
{
	bool search_m = media::search(buffer);
	string stock_duree = to_string(m_duree);
	if (stock_duree == buffer || m_maison_production == buffer || search_m)
		return true;
	else
		return false;
}