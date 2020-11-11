#include "Pages.h"
#include "Fichier.h"

#include <cstring>
#include <sstream>

using namespace std;

int main(int argc, const char* argv[])
{
	const string nomDomaine("http://intranet-if.insa-lyon.fr");
	try
	{
		Fichier file(argv[argc-1]);
		string nomGraphViz("");
		int creneau(-1);
		bool exclureImg = false;
		
		// comparaison d'arguments
		for(int i=1; i<argc-1; i++) 
		{
			if(strcmp(argv[i], "-g") == 0) // demande graphViz
			{
				if(argv[i+1][0] != '-' && i+1 !=argc-1)
				{
					nomGraphViz = argv[i+1];
				}
				else
				{
					nomGraphViz = argv[0];
					nomGraphViz += ".dot";
				}
			}
			else if(strcmp(argv[i], "-e") == 0) // demande image
			{
				exclureImg = true;
			}
			else if(strcmp(argv[i], "-t") == 0) // demande creneau
			{
				istringstream tps(string(argv[i+1]));
				tps >> creneau;
				if(creneau > 23 || creneau < 0)
				{
					creneau = -1;
				}
			}
		} // fin de comparaison d'arguments
		
		Pages  * pagesDemandees = file.Select(exclureImg, creneau);
		
		if(nomGraphViz != "") // creation graphViz
		{
			pagesDemandees->CreateGraphViz(nomGraphViz, nomDomaine);
		}
		else // affichage Top
		{
			list<pair<const string *, int> > * top = pagesDemandees->GetTop(10);
			for(list<pair<const string *, int> >::iterator it=top->begin(); it != top->end(); it++)
			{
				cout << *(it->first) << "\t"<< right << it->second << endl;
			}
			
			delete top;
		}
		
		delete pagesDemandees;
		
	}
	catch(string e)
	{
		cerr << e;
		return 1;
	}
	return 0;
}