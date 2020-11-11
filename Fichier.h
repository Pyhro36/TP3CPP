#ifndef FICHIER_H
#define FICHIER_H

using namespace std;

//------------------------------------------------- Includes Systemes

#include <list>
#include <string>

//------------------------------------------------- Includes personnels

#include "Log.h"
#include "Pages.h"

class Fichier
{
		public :
	
//------------------------------------------------- Methodes publiques

		Pages * Select(bool exclureImg = false, int creneau = -1);
		// Mode d'emploi :
		// renvoi une multimap contenant les elements de la liste tries par document demande
		// ne contient que les logs repondants aux criteres passes en parametre :
		// exclureImg : si true, ne prend pas en compte les elements d'extention 
		// {".png", ".css", ".js", ".jpg", ".jpeg", ".bmp", ".ico"}
		// creneau : ne prend en compte que les logs ayant ete enregistres a l'heure demande (de creneau:00:00 a creneau:59:59)
		// conditions :
				// creneau < 24
				// creneau >= -1

//------------------------------------------------- Constructeur/destructeur

		Fichier(string fileName);
		virtual ~Fichier();

	private :
		
//------------------------------------------------- Attributs prives

		list<const Log *> historique;
	
};

#endif //FICHIER_H