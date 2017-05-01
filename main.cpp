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
    mediatheque *test = new mediatheque();
    user *user1;

    //authentification
    if (auth(pass))
	    user1 = new admin(test);
    else
        user1 = new user(test);

	while(user1->is_active())
		user1->lecture_commande();

	return 0;
}