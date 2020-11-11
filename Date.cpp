#include "Date.h"

using namespace std;

//------------------------------------------------- Includes Systemes

#include <sstream>

//------------------------------------------------- Includes personnels

#include "Util.h"

//------------------------------------------------- Fonctions

Date getDate(string strDate)
{
	Date renvoi;
	
	istringstream ssJour(getPart(strDate, "/"));
	renvoi.mois = getPart(strDate, "/");
	istringstream ssAnnee(getPart(strDate, ":"));
	istringstream ssHeure(getPart(strDate, ":"));
	istringstream ssMinute(getPart(strDate, ":"));
	istringstream ssSeconde(getPart(strDate, " +"));
	istringstream ssGmt(strDate);
	
	ssJour >> renvoi.jour;
	ssAnnee >> renvoi.annee;
	ssHeure >> renvoi.heure;
	ssMinute >> renvoi.minute;
	ssSeconde >> renvoi.seconde;
	ssGmt >> renvoi.gmt;
	
	return renvoi;
	
}

//------------------------------------------------- Operateurs

ostream & operator<<(ostream & out, const Date & d)
{
	string gmtPref;
	if(d.gmt <1000)
	{
		gmtPref = " +0";
	}
	else
	{
		gmtPref = " +";
	}
	out << d.jour << "/" << d.mois << "/" << d.annee << " :" << d.heure << ":" << d.minute << ":" << d.seconde << gmtPref << d.gmt;
	return out;
}