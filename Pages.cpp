#include "Pages.h"

//------------------------------------------------- Includes Systemes

#include <fstream>
#include <sstream>

//------------------------------------------------- Methodes publiques

list<pair<const string *, int> > * Pages::GetTop(int n) const
// Algorithme
// sortie :
// une liste triee des n elements les plus consultes
// debut :
// on parcourt les cles
// pour chaque element, on cree une paire composee de la cle et du nombre d'elements
// qu'elle contient
// ensuite, on l'insere dans le top n eventuellement 
{
	list<pair<const string *, int> > * renvoi = new list<pair<const string *, int> >(); 
	for(set<const string *, StrLess>::iterator it = cles->begin(); it != cles->end(); it++)
	{
		insert(*renvoi, make_pair(*it, historique->count(**it)), n);
	}
	return renvoi;
}

void Pages::CreateGraphViz(string nomFichier, string nomDomaine) const
// Algorithme
// entree :
// nom du fichier ou ecrire, nom du domaine etudie
// debut :
// on parcourt les cles,
// pour chaque cles, on modifie deux chaine (strCles et strLiens)
// on ecrit ensuite ces chaines dans le fichier nomFichier
{
	string graphViz = "digraph {\n\t other;\n";
	string strCles;
	string strLiens;
	
	for(set<const string *, StrLess>::iterator it = cles->begin(); it != cles->end(); it++)
	{
		strCles += ("\t\"" + **it + "\";\n");
		compte(**it, nomDomaine, strLiens);
	}
	graphViz += (strCles + strLiens + "}");
	
	ofstream file(nomFichier.c_str());

	file << graphViz;
	file.close();
}

//------------------------------------------------- Constructeur/destructeur

Pages::Pages(multimap<string, const Log *> * histo, set<const string *, StrLess> * cle) : historique(histo), cles(cle)
{
#ifdef MAP
	cout << "appel du constructeur de <Pages>" << endl;
#endif	
}

Pages::~Pages()
{
#ifdef MAP
	cout << "appel du destructeur de <Pages>" << endl;
#endif		
	delete historique;
	delete cles;
}

//------------------------------------------------- methodes privees

void Pages::insert(list<pair<const string *, int> > & top, const pair<const string *, int> & objet, int n) const
// Algorithme
// entree :
// la liste ou l'on veut ajouter un element, l'element a rajouter
// debut :
// on parcourt la liste jusqu'a ce que l'element a rajouter soit inferieur a l'objet
// pointe par l'iterateur;
// On ajoute l'objet juste avant l'objet pointe par l'iterateur
// si la liste contient deja 10 elements, on supprime le premier (plus petit)
{
	list<pair<const string *, int> >::iterator it;
	for(it = top.begin(); it != top.end(); it++)
	{
		if(objet.second < it->second)
		{
			break;
		}
	}
	
	// it pointe vers le plus petit element superieur a notre objet
	
	top.insert(it, objet);
	if(top.size() > n)
	{
		top.pop_front();
	}
	
}

void Pages::compte(const string & cle, const string & nomDomaine, string & strLiens) const
// Algorithme
// entree :
// la cle de la multimap, le nom de domaine, et la chaine a modifier
// declarations :
// une map transitoire, avec en cle les referenceurs de l'URL d'arrivee indiquee par "cle",
// et qui prend comme valeur des entiers indiquant le nombre de fois qu'on les a rencontre
// debut :
// Pour chaque element correspondant a la cle, on releve son referenceur et on l'adapte :
// Si il est locale, on supprime la base de l'URL
// Sinon, on le considere comme "other"
// Ensuite on incremente la valeur de la map transitoire correspondante a l'url
// ou on la cree si elle n'existe pas.
// Enfin, on parcourt cette map et on rempli les liens avec les valeurs definitives trouvees
{
	pair<multimap<string, const Log *>::iterator, multimap<string, const Log *>::iterator > ret = historique->equal_range(cle);
	map<string, int> nbLiens;
	
	// comptage des liens vers cette cle
	for(multimap<string, const Log *>::iterator it = ret.first; it != ret.second; it++)
	{
		string origine = it->second->GetOrigine();
		//verification de l'adresse d'origine (adresses externes regroupees)
		if(origine.find(nomDomaine) != 0)
		{
			origine = "other";
		}
		else
		{
			// on coupe la partie absolue de l'url si elle est locale
			origine = origine.substr(nomDomaine.size());	
		} // fin if origine locale
		
		if(nbLiens.count(origine) == 0)
		{
			nbLiens[origine] = 1;
		}
		else
		{
			nbLiens[origine] += 1;
		}// fin if existe
	} // fin for multimap
	
	// rajout dans les liens;
	for(map<string, int>::iterator it = nbLiens.begin(); it != nbLiens.end(); it++)
	{
		strLiens += ("\t\""
					+ it->first
					+ "\" -> \""
					+ cle
					+ "\"[label=\"");
		ostringstream tps;
		tps << it->second;
		strLiens += tps.str();
		strLiens += "\"];\n";
	} // fin for map nbLiens
	
}

