/* mediatheque.cpp */
#include "mediatheque.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

mediatheque::mediatheque()
{

}

mediatheque::~mediatheque()
{
	
}

bool mediatheque::load_from_file(string filename)
{
	string buffer;
	vector<string> donnees;
	int i;
	int type;

	ifstream infile;

	infile.open(filename.c_str());
	if (infile.is_open())
	{
		while (!infile.eof())
		{
			getline(infile, buffer);
			if (buffer.compare("###")==0)// si on est a la fin d'un media
			{
				//creation du media precedent grace a donnees
				type = stoi(donnees[0]);
				ajout(type, donnees);
				donnees.clear(); //puis effacement de donnees
			}
			else
			{
				donnees.push_back(buffer);
			}

		}	 
		infile.close();
		return true;
	}
	//remplir m_biblio en utilisant les constructeurs et ajout()
	else
		return false;
}

void mediatheque::affiche() //Affiche les informations de toute la liste des médias de la médiatheque
{
	for (int i=0; i<m_biblio.size(); i++)
	{
		cout << "ID: " << i << endl;
		m_biblio[i] -> affiche();
		if (i < m_biblio.size() - 1)
			cout << endl;
	}
}

void mediatheque::affiche(int indice) //Affiche le média d'indice "indice" en détails
{
	m_biblio[indice] -> affiche();
}


void mediatheque::ajout(media* const new_media)
{
	m_biblio.push_back(new_media); //ajout
}

void mediatheque::ajout(int type, std::vector<std::string> donnees)
{
	switch(type)
	{
		case LIVRE :
			m_biblio.emplace_back(new livre(donnees[1], donnees[2], donnees[3], donnees[4], donnees[5], donnees[6]));
			break;
	}
}


void mediatheque::suppr(int indice)
{
	m_biblio.erase(m_biblio.begin() + indice);
}

int mediatheque::emprunter(int indice)
{
	int dispo = m_biblio[indice]->get_dispo();
	if (dispo == DISPONIBLE)
	{
		m_biblio[indice]->set_dispo(EMPRUNTE);
		return 1;
	}
	else
		return 0;
}

void mediatheque::rendre(int indice)
{
	m_biblio[indice]->set_dispo(DISPONIBLE);
}

