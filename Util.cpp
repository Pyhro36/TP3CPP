#include "Util.h"

using namespace std;

//------------------------------------------------- Fonctions

string getPart(string & chaine, const string & separateur)
// Algorithme :
// entree : chaine a separer, chaine separatrice
// sortie : deux chaines (1 et 2) telles que ch1 + separateur + ch2 = chaine initiale
// debut :
// trouver l'indice du debut du separateur;
// renvoi = premiere partie de la chaine
// chaine = deuxieme partie de la chaine
// fin;
{
	int indice = chaine.find(separateur);
	string renvoi = chaine.substr(0, indice);
	chaine = chaine.substr(indice + separateur.length());
	return renvoi;
}

bool StrLess::operator()(const string * s1, const string * s2) const
{
	return *s1 < *s2;
}