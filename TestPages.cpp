#include "Pages.h"
#include "Fichier.h"

using namespace std;

int main()
{
	
	Fichier fichier("historique.log");
	Pages * interessantes(fichier.select(true));
	interessantes->createGraphViz("test.dot","http://intranet-if.insa-lyon.fr");
	delete interessantes;
	
	return 0;
}
