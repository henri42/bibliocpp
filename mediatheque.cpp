/* mediatheque.cpp */
#include "mediatheque.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

std::vector<media*> stock_recherche;

mediatheque::mediatheque()
{

}

mediatheque::~mediatheque()
{
	
}

int mediatheque::taille()
{
	return (int)m_biblio.size();
}

int mediatheque::search_media_bib(string saisie, vector<media*> stock_recherche)
{
    int counter = 0;        //compte les resultats positifs de la recherches
    string flag;

    cout << "--- RECHERCHE LANCEE ---" << endl;

    for (int i = 0; i < m_biblio.size(); i++)
    {
        if(m_biblio[i]->search(saisie))
        {
            stock_recherche.push_back(m_biblio[i]);
            counter++;
        }
    }

    if (counter != 0)
        m_biblio = stock_recherche;

    return counter;
}


bool mediatheque::load_from_file(string filename)
{
	string buffer;
	vector<string> donnees;
	vector<string> articles;
	int i;
	int type;
	int flag = 0; //flag pour load articles

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
					articles.push_back("0"); //On remplit article d'un "0" pour ne pas qu'il soit vide
				ajout(type, donnees, articles);
				articles.clear(); //effacement du vector articles
				donnees.clear(); //puis effacement de donnees
			}
			else
			{
				if (buffer.compare("---")==0) //début/fin des articles
					flag = !flag;

                else if (buffer.compare("---") != 0)
                {
				    if (flag)	// si les articles d'une revue commencent, on remplit le tableau article
						articles.push_back(buffer);
				    else		// sinon on continu à remplir donnees
						donnees.push_back(buffer);
				}
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

void mediatheque::affiche_short() //Affiche les informations de toute la liste des médias de la médiatheque
{
	for (int i=0; i<m_biblio.size(); i++)
	{
		cout << "ID: " << i << " ";
		m_biblio[i] -> affiche_short();
		if (i < m_biblio.size() - 1)
			cout << endl;
	}
}

void mediatheque::affiche(int indice) //Affiche le média d'indice "indice" en détails
{
	m_biblio[indice] -> affiche();
}


void mediatheque::ajout(int type, std::vector<std::string> donnees, std::vector<std::string> articles)
{
	switch(type)
	{
		case LIVRE :
			m_biblio.emplace_back(new livre(donnees[1], donnees[2], donnees[3], donnees[4], donnees[5], donnees[6]));
			break;
		case REVUE :
			m_biblio.emplace_back(new revue(donnees[1], articles, donnees[2], donnees[3], donnees[4], donnees[5], donnees[6], donnees[7]));
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

bool mediatheque::emprunter(int indice, int client)
{
	return m_biblio[indice]->emprunter(client);
}

bool mediatheque::reserver(int indice, int client)
{
	return m_biblio[indice]->reserver(client);
}

bool mediatheque::rendre(int indice, int client)
{
	return m_biblio[indice]->rendre(client);
}

void mediatheque::reset()
{
	m_biblio.clear();
}

void mediatheque::clear()
{
    //
}