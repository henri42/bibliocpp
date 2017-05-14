/* main.cpp */
#include <string>
#include "mediatheque.hpp"
#include "admin.hpp"

using namespace std;

const string password = "sarkozy";

bool auth(string pass)
{
    cout << "Mot de passe admin :" << endl;
    getline(cin, pass);

    if (!pass.compare(password))
    {
        cout << "Connexion réussie" << endl;
        return true;
    }
    else
    {
        cout << "Mot de passe incorrect, connexion en tant qu'utilisateur" << endl;
        return false;
    }
}


int main(int argc, char const *argv[]) {

    string pass;
    int id;
    mediatheque test;
    user* user1;

    //authentification
    if (auth(pass))
    {
        user1 = new admin(&test);
        cout << "User ID : " << user1->getIdUser() << endl;
    }
    else {
        cout << "Entrez votre ID :" << endl;
        cin >> id;
        user1 = new user(&test, id);
        cin.ignore();
    }

	while(user1->is_active())
		user1->lecture_commande();

    delete user1;

	return 0;
}