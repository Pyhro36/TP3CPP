#ifndef LOG_H
#define LOG_H

using namespace std;

//------------------------------------------------- Includes Systemes

#include <string>
#include <iostream>

//------------------------------------------------- Includes personnels

#include "Date.h"

class Log
{

	public :
	
//------------------------------------------------- Methodes publiques

		string GetOrigine() const;
		// Mode d'emploi :
		// renvoie le referenceur

//------------------------------------------------- Constructeur/destructeur

		Log(string strLog);
		Log(const Log & l);
		virtual ~Log();
		
//------------------------------------------------- Classes amies

		friend class Fichier;
		
//------------------------------------------------- Fonctions amies

		friend ostream & operator<<(ostream & out, const Log & l);
		
//------------------------------------------------- Operateurs

//bool operator<(const Log & log2) const;

	private :
		
//------------------------------------------------- Attributs prives

		string ip;
		string logName;
		string userName;
		Date date;
		string typeRequete;
		string documentDemande;
		int status;
		int quantite;
		string referenceur;
		string idNavigateur;
};

//------------------------------------------------- Operateurs

ostream & operator<<(ostream & out, const Log & l);

#endif //LOG_H