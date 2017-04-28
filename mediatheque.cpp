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

int mediatheque::taille()
{
	return m_biblio.size();
}


bool mediatheque::load_from_file(string filename)
{
	string buffer;
	vector<string> donnees;
	vector<string> articles;
	int i;
	int type;

	ifstream infile;

	infile.open(filename.c_str());
	m_biblio.clear();
	if (infile.is_open())
	{
		while (!infile.eof())
		{

			getline(infile, buffer);
			if (buffer.compare("###")==0)// si on est a la fin d'un media
			{
				//creation du media precedent grace a donnees
				type = stoi(donnees[0]);
				if (type != REVUE)
					articles.push_back("0");
				ajout(type, donnees, articles);
				articles.clear(); //effacement du vector articles
				donnees.clear(); //puis effacement de donnees
			}
			else
			{
				if (buffer.compare("---")==0) //début des articles
				{
					do
					{
						getline(infile, buffer);
						if (!(buffer.compare("---")==0))
							articles.push_back(buffer); //on ajoute le titre des articles et leurs resumés dans le vector articles
					}
					while (!(buffer.compare("---")==0)); //jusqu'à la fin de la liste d'articles
				}
				if (!(buffer.compare("---")==0))
					donnees.push_back(buffer);
			}

		}	 
		infile.close();
		return true;
	}
	else
		return false;
}

bool mediatheque::save_to_file(string filename)
{
    ofstream outfile(filename);

    if(outfile.is_open())
    {
        for (int i=0; i<m_biblio.size(); i++)
        {
            m_biblio[i]->save_media(&outfile);
        }
        outfile.close();
        return true;
    }
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

void mediatheque::ajout(int type, std::vector<std::string> donnees, std::vector<std::string> articles)
{
	switch(type)
	{
		case LIVRE :
			m_biblio.emplace_back(new livre(donnees[1], donnees[2], donnees[3], donnees[4], donnees[5], donnees[6]));
			break;
		case REVUE :
			m_biblio.emplace_back(new revue(articles.size()/2, donnees[1], articles, stoi(donnees[2]), stoi(donnees[3]), donnees[4], donnees[5], donnees[6], donnees[7], stoi(donnees[8])));
			break;
		case VHS :
			m_biblio.emplace_back(new vhs(donnees[1], donnees[2], donnees[3], donnees[4]));
			break;
        case CD :
        case DVD :
            m_biblio.emplace_back(new cd_dvd(donnees[1], donnees[2], donnees[3], donnees[4], donnees[5], type));
			break;
		case RESSOURCE :
            m_biblio.emplace_back(new ressource_num(donnees[1], donnees[2], donnees[3], donnees[4], donnees[5]));
			break;
		default:
			break;
	}
}

void mediatheque::ajout(int type)
{
	switch(type)
	{
		case LIVRE :
			m_biblio.emplace_back(new livre());
			break;
		case REVUE :
			break;
		case VHS :
			m_biblio.emplace_back(new vhs());
			break;
		case CD :
		case DVD :
			m_biblio.emplace_back(new cd_dvd(type));
			break;
		case RESSOURCE :
			m_biblio.emplace_back(new ressource_num());
			break;
		default:
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

void mediatheque::clear()
{
	m_biblio.clear();
}