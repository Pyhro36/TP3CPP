#include "Log.h"

#include <iostream>

using namespace std;

int main()
{
	Log l("192.168.0.0 - - [08/Sep/2012 :11:16:02 +0200] \"GET /temps/4IF16.html HTTP/1.1\" 200 12106 \"http://intranet-if.insa-lyon.fr/temp/4IF15.html\" \"Mozilla/5.0 (Windows NT 6.1; WOW64; rv14.0) Gecko/20100101 Firefox/14.0.1\"");
	cout << l;
	
	return 0;
}