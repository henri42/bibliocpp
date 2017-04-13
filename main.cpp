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
	(test->m_list_media)[1]->test1();

	return 0;
}