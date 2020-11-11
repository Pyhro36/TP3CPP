#include "Log.h"

using namespace std;

//------------------------------------------------- Includes Systemes

#include <sstream>

//------------------------------------------------- Includes personnels

#include "Util.h"

//------------------------------------------------- Methodes publiques

string Log::GetOrigine() const
{
	return referenceur;
}
	
//------------------------------------------------- Constructeurs/destructeur
Log::Log(string strLog)
{
#ifdef MAP
	cout << "Appel du constructeur de <Log>" << endl;
#endif

	ip = getPart(strLog, " ");
	logName = getPart(strLog, " ");
	userName = getPart(strLog, " [");
	date = getDate(getPart(strLog, "] \""));
	typeRequete = getPart(strLog, " ");
	documentDemande = getPart(strLog, " ");
	typeRequete += (" " + getPart(strLog, "\" "));
	
	istringstream ssStatus(getPart(strLog, " "));
	ssStatus >> status;
	
	istringstream ssQuantite(getPart(strLog, " \""));
	ssQuantite >> quantite;
	
	referenceur = getPart(strLog, "\" \"");
	idNavigateur = getPart(strLog, "\"");

}

Log::Log(const Log & l): date(l.date), ip(l.ip), logName(l.logName), userName(l.userName), typeRequete(l.typeRequete), documentDemande(l.documentDemande), status(l.status), quantite(l.quantite), referenceur(l.referenceur), idNavigateur(l.idNavigateur)
{
#ifdef MAP
	cout << "Appel du constructeur de copie de <Log>" << endl;
#endif
}

Log::~Log()
{
#ifdef MAP
	cout << "Appel du destructeur de <Log>" << endl;
#endif
}

//------------------------------------------------- Operateurs

/*bool Log::operator<(const Log & log2) const
{
	ostringstream s1;
	ostringstream s2;
	s1 << *this;
	s2 << log2;
	return s1.str() < s2.str();
}*/

ostream & operator<<(ostream & out, const Log & l)
{
	string tpsType = l.typeRequete;
	out << l.ip << " " 
		<< l.logName << " "
		<< l.userName << " [" 
		<< l.date << "] \"" 
		<< getPart(tpsType, " ") << " " 
		<< l.documentDemande << " "
		<< tpsType << "\" "
		<< l.status << " " 
		<< l.quantite << " \"" 
		<< l.referenceur << "\" \"" 
		<< l.idNavigateur << "\"";
		
	return out;
}