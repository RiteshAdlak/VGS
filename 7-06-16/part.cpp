#include"part.h"

part::part()
{
	this->desc = "";
	this->rate = 0;
}
part::part(const TString& desc, double rate)
{
	this->desc = desc;
	this->rate = rate;
}
void part::input()		//INPUT
{
	cout << "Enter the part : ";
	cin >> desc;
	cout << "Enter the rate : ";
	cin >> rate;
}
TString part::get_desc()
{
	return this->desc;
}
double part::get_rate()
{
	return this->rate;
}
void part::set_desc(const TString& desc)
{
	this->desc = desc;
}
void part::set_rate(double rate)
{
	this->rate = rate;
}

void part::disp()
{
	cout << "The Description :: ";
	cout << desc << endl;
	cout << "the rate :: ";
	cout << rate << endl;
}

/*
int main()
{
	
	part p1, p2("light",300);

	cout << "Enter the desc and rate :: "<<endl;
	p1.input();
	p1.disp();

	


	return 0;


}
*/