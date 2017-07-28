
#ifndef STRING_H
#define STRING_H

#include<cstring>
#include <iostream>
using namespace std;





class TString
{
	char buff[64];
	
public:
	TString();
	TString(const char buf[64]);
	char* tostring();
	bool operator==(const TString& other)const;
	bool operator!=(const TString& other)const;
	friend istream& operator>>(istream& in,TString &s);
	friend ostream& operator<<(ostream& out, TString &s);
};
#endif

