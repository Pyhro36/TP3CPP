#ifndef UTIL_H
#define UTIL_H

using namespace std;

//------------------------------------------------- Includes Systemes

#include <string>

//------------------------------------------------- Fonctions

string getPart(string & chaine, const string & separateur);
// Mode d'emploi :
// separe la chaine en deux parties, definies par la premiere
// occurence trouvee du separateur.
// la premiere partie (avant le separateur) est renvoyee,
// la seconde est la chaine tronquee de sa premiere partie.
// Le separateur est egalement retire de la chaine.
// Exemple :
//		string chaine = "un garcon/une fille";
//		string str = getPart(chaine, "/") :
//		//str = un garcon, chaine = une fille

//------------------------------------------------- Operateurs

class StrLess {
		public :
		bool operator()(const string * s1, const string * s2) const;
};
// Fonctionne comme operator<(), seule alternative possible pour comparer les valeurs pointees dans un set

#endif //UTIL_H