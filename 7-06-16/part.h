#include"string.h"

class part
{
	TString desc;
	double rate;
public:
	TString get_desc();
	double get_rate();

	void set_desc(const TString& desc);
	void set_rate(double rate);

	void input();
	part();
	part(const TString& desc,double rate);
	void disp();


};