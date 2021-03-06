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
    load_from_file("active_bib.txt");
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

    while (!stock_recherche.empty())
    {
        delete stock_recherche.back();
        stock_recherche.pop_back();
    }

    return counter;
}


bool mediatheque::load_from_file(string filename)
{
	string buffer;
	vector<string> donnees;
	vector<string> articles;
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
    int dispo, client, annee, pages, duree, piste, taille;
    client = stoi(donnees.back());
    donnees.pop_back();
	dispo = stoi(donnees.back());

	switch(type)
	{
		case LIVRE :
            annee = stoi(donnees[1]);
            pages = stoi(donnees[2]);
			m_biblio.emplace_back(new livre(annee, pages, donnees[3], donnees[4], donnees[5], donnees[6], dispo, client));
			break;
		case REVUE :
			annee = stoi(donnees[2]);
			pages = stoi(donnees[3]);
			m_biblio.emplace_back(new revue(donnees[1], articles, annee, pages, donnees[4], donnees[5], donnees[6], donnees[7], dispo, client));
			break;
		case VHS :
			duree = stoi(donnees[1]);
			m_biblio.emplace_back(new vhs(duree, donnees[2], donnees[3], donnees[4], dispo, client));
			break;
        case CD :
        case DVD :
			piste = stoi(donnees[1]);
			duree = stoi(donnees[2]);
            m_biblio.emplace_back(new cd_dvd(piste, duree, donnees[3], donnees[4], donnees[5], type, dispo, client));
			break;
		case RESSOURCE :
			taille = stoi(donnees[1]);
            m_biblio.emplace_back(new ressource_num(taille, donnees[2], donnees[3], donnees[4], donnees[5], dispo, client));
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
			m_biblio.emplace_back(new revue());
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
    delete m_biblio[indice];
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
    while (!m_biblio.empty())
    {
        delete m_biblio.back();
        m_biblio.pop_back();
    }
}