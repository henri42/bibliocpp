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
	return m_biblio.size();
}


void mediatheque::search_media()
{
	int counter = 0;
	string mot;
	vector<string> buffer;
	string flag;

	cout << "Vous êtes en mode recherche d'un média dans la bibliothèque" << endl;
	cout << "Entrez un titre, un auteur, une collection, etc. qui correspond au média recherché" << endl;
    getline(cin, mot);
	buffer.push_back(mot);
	cout << "Les médias correspondant sont:" << endl;
	
		for (int i = 0; i < m_biblio.size(); i++)
		{
			if(m_biblio[i]->search(mot))
			{
				affiche(i);
				cout << endl << endl;
				stock_recherche.push_back(m_biblio[i]);
				counter++;
			}
		}

		cout << "Voulez incrémenter la recherche ? (oui, non)." << endl;
        getline(cin, flag);
        if (flag.compare("oui")==0)
			search_media(stock_recherche, buffer);
		else if (flag.compare("non")==0)
		{
			cout << "FIN de la recherche, le nombre de médias contenant le mot clé '" << mot <<"' est: " << counter << endl;
			stock_recherche.clear();
		}

}

void mediatheque::search_media(vector<media*> biblio, vector<string> buffer)
{
	int counter = 0;
	string mot;
	string flag;
	std::vector<media*> stock_recherches;


	cout << "Vous êtes en mode recherche d'un média dans la bibliothèque" << endl;
	cout << "Entrez un titre, un auteur, une collection, etc. qui correspond au média recherché" << endl;
    getline(cin, mot);
	buffer.push_back(mot);
	cout << "Les médias correspondant sont:" << endl;
	
		for (int i = 0; i < biblio.size(); i++)
		{
			if(biblio[i]->search(mot))
			{
				stock_recherches.push_back(biblio[i]);
				counter++;
			}
		}

		for (int j = 0; j < stock_recherches.size(); j++)
		{
			cout << endl;
			stock_recherches[j] -> affiche();
			cout << endl;
		}

		cout << "Voulez incrémenter la recherche ? (oui, non)." << endl;
        getline(cin, flag);
		if (flag.compare("oui")==0)
			search_media(stock_recherches, buffer);
		else if (flag.compare("non")==0)
		{
			cout << "FIN de la recherche, le nombre de médias contenant le mot clé ";
			for (int k = 0; k < buffer.size(); k++)
			{
				cout << "'" << buffer[k] << "', ";
			}
			cout << " est: " << counter << endl;
			stock_recherches.clear();
		}
}


bool mediatheque::load_from_file(string filename)
{
	string buffer;
	vector<string> donnees;
	vector<string> articles;
	int i;
	int type;
	int flag = 0;

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
				if (buffer.compare("___")==0) //début des articles
					flag = 1;
				else if (buffer.compare("---")==0)
					flag = 0;



				if (flag)	// si les articles d'une revue commencent, on remplit le tableau articles
				{
					if (!(buffer.compare("---")==0) && !(buffer.compare("___")==0))
						articles.push_back(buffer);
				}
				else		// sinon on continu à remplir donnees
				{
					if (!(buffer.compare("---")==0) && !(buffer.compare("---")==0))
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