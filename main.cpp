/* main.cpp */
#include <string>
#include <iostream>
#include <vector>
#include "mediatheque.hpp"
#include "user.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
	//gerer authentification

	mediatheque* test = new mediatheque();
	user* user1 = new user(test);

	while(user1->is_active())
		user1->lecture_commande();

	exit(0);

	return 0;
}