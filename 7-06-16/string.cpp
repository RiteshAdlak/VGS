#include"string.h"

TString::TString()
{
	strcpy(buff,"");
}

TString::TString(const char *buf)
{
	strcpy(buff, buf);
}

char *TString::tostring()
{
	return buff;
}

bool TString::operator==(const TString& other)const
{
	if (strcmp(this->buff, other.buff))
		return 0;
	else
		return 1;
}


bool TString::operator!=(const TString& other)const
{
	if (strcmp(this->buff, other.buff))
		return 1;
	else
		return 0;
}
 istream&::operator>>(istream& in, TString &s)
{
	 in >>s.buff;
	 return in;
}
ostream&::operator<<(ostream& out, TString &s)
 {
	out <<s.buff;
	return out;
}