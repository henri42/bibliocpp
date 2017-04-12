/* main.cpp */
#include "mediatheque.hpp"
#include "media.hpp"
#include "livre.hpp"

using namespace std;

int main(int argc, char const *argv[])
{

	mediatheque* test = new mediatheque();
	livre* book = new livre();
	test->ajout(book);

	return 0;
}