#include "Fichier.h"

using namespace std;

//------------------------------------------------- Includes Systemes

#include <fstream>
#include <iostream>
#include <set>

//------------------------------------------------- Includes personnels

//------------------------------------------------- Constantes

	static string EXT_IMG[] = {".png", ".css", ".js", ".jpg", ".jpeg", ".bmp", ".ics", "gif", "ico"};
	static int TAILLE_EXT = 9;

//------------------------------------------------- Methodes publiques

Pages * Fichier::Select(bool exclureImg, int creneau)
// Algorithme 
// entree :
// booleen exclusion d'image, entier creneau horaire 
// Pour chaque element du set :
// on fait les verfications qui s'imposent en fonction des arguments passes
// si le log repond aux attentes, on le rajoute
{
	multimap<string, const Log*> * logs = new multimap<string, const Log*>();
	set<const string *, StrLess>  * cles = new set<const string *, StrLess>();
	
	for(list<const Log*>::iterator it=historique.begin(); it != historique.end(); it++)
	{
		if((creneau == -1 || (*it)->date.heure == creneau) && (*it)->typeRequete.find("GET") != string::npos)
		{
			if(!exclureImg)
			{
				logs->insert(make_pair((*it)->documentDemande, *it));
				cles->insert(&((*it)->documentDemande));
			}
			else
			{
				bool isImg = false;
				for(int i=0; i < TAILLE_EXT; i++)
				{
					// on fait l'hypothese (rationnelle) qu'on ne peut pas trouver l'extention en tant que partie du nom du fichier
					// mais uniquement en tant qu'extention
					if((*it)->documentDemande.find(EXT_IMG[i]) != string::npos)
					{
						isImg = true;
						break;
					}
				} // fin for verification extention
				
				if(!isImg)
				{
					logs->insert(make_pair((*it)->documentDemande, *it));
					cles->insert(&((*it)->documentDemande));
				}
				
			} // fin if exclureImg
		} // fin if creneau & requete GET
		
	} // fin for
	
	return new Pages(logs, cles);
}

//------------------------------------------------- Constructeur/destructeur

Fichier::Fichier(string fileName):historique()
{
#ifdef MAP
	cout << "appel du constructeur de <Fichier>" << endl;
#endif
	ifstream file(fileName.c_str());
	if(file)
	{
		string ligne;
		while(getline(file, ligne))
		{
			historique.push_front(new Log(ligne));
		}
		file.close();
	}
	else
	{
		throw string("Impossible d'ouvrir le fichier <" + fileName + ">\n");
	}
}
Fichier::~Fichier()
{
#ifdef MAP
	cout << "appel du destructeur de <Fichier>" << endl;
#endif
	
	for(list<const Log *>::iterator it = historique.begin(); it != historique.end(); it++)
	{
		delete *it;
	}

}
