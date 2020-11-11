#ifndef DATE_H
#define DATE_H

using namespace std;

//------------------------------------------------- Includes Systemes

#include <iostream>

//------------------------------------------------- Structure 

typedef struct Date Date;
struct Date
{
	int jour;
	string mois;
	int annee;
	int heure;
	int minute;
	int seconde;
	int gmt;
};

//------------------------------------------------- Fonctions

Date getDate(string strDate);
// Mode d'emploi :
// convertie une date sous forme de chaine au format
// Date, et le renvoi en valeur de retour.
// Condition :
		//strDate de la forme 00/XXX/0000 :00:00:00 +0000
		
//------------------------------------------------- Operateurs

ostream & operator<<(ostream & out, const Date & d);

#endif //DATE_H