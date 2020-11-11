#ifndef PAGES_H
#define PAGES_H

using namespace std;

//------------------------------------------------- Includes Systemes

#include <list>
#include <utility>
#include <map>
#include <set>

//------------------------------------------------- Includes personnels

#include "Log.h"
#include "Util.h"

class Pages 
{
		public :
	
//------------------------------------------------- Methodes publiques

		list<pair<const string *, int> > * GetTop(int n) const;
		// Mode d'emploi :
		// renvoi les n documents les plus consultes, sous
		// la forme d'une liste de paires ordonnes du moins demande au plus demande
		
		void CreateGraphViz(string nomFichier, string nomDomaine) const;
		// Mode d'emploi :
		// cree un fichier nomFichier au format .dot contenant les caracteristiques d'un graphViz

//------------------------------------------------- Constructeur/destructeur

		Pages(multimap<string, const Log *> * histo, set<const string *, StrLess> * cle);
		virtual ~Pages();

	private :
	
//------------------------------------------------- methodes privees

	void insert(list<pair<const string *, int> > & top, const pair<const string *, int> & objet, int n) const;
	// Mode d'emploi :
	// insert eventuellement un objet a sa place dans le top n, si il y appartient
	
	void compte(const string & cle, const string & nomDomaine, string & strLiens) const;
	// Mode d'emploi :
	// compte le nombre d'elements correspondant a une cle en fonction du referenceur, et 
	// les classe dans strLiens. 
	// Le nom de domaine previent d'une url non locale
		
//------------------------------------------------- Attributs prives

	multimap<string, const Log *> * historique;
	set<const string *, StrLess> * cles;
	
};

#endif //PAGES_H