#include"maintenance.h"


TString nam;
maint::maint()
{
	this->labcharge = 0;
}
maint::maint(const TString& desc, double rate) :service(desc)
{
	this->set_desc(desc);
	this->labcharge = rate;
}
double maint::get_labcharge()
{
	return this->labcharge;
}

list<part>& maint::get_part_list()
{
	return lop;
}

void maint::set_labcharge(double labour)
{
	this->labcharge = labour;
}

void maint::add_part(part &parts)
{
	this->lop.push_back(parts);
}
void maint::input()			//INPUT
{
	cout << "\n";
	cout << "What do you want: MAINTENANCE or REPAIRING ::  "<<endl;
	
	cin >> nam;
	//set_desc(nam);
	char ans;

	while (true)
	{
		cout << "\n";
		cout << "Do you want to add more : <Y/N>            ::  ";
		cin >> ans;
		cout << "\n\n";

		if (!(ans == 'Y' || ans == 'y'))
			break;

		part s1;
		s1.input();

		this->add_part(s1);
	}
	cout << "Enter Labour Charge                        :: ";
	cin >> labcharge;
}
void maint:: display()			//DISPLAY
{

	list<part>::iterator itr = this->lop.begin();

	cout << "	" << "PART NAME" << "	" << "PRICE OF PART" << endl;
	while (itr != this->lop.end())
	{
		cout << "	" << itr->get_desc() << "		" << itr->get_rate()<<endl;
		itr++;
		cout << "\n";
	}
	//cout << "total price is :: " << price();
	
}
double maint::price()			//PRICE
{
	double pricec;
	pricec= 0;

	list<part>::iterator itr = this->lop.begin();
	while (itr != this->lop.end())
	{
		pricec += (*itr).get_rate();
		itr++;
	}
	
	double total = pricec;
	total += labcharge;
	return total;

}
/*
int main()
{
	maint *m1=new maint();

	m1->input();
	m1->display();
	
	//double total=m1->price();
	//total += m1->get_labcharge();

	cout << "total price is :: "<<m1->price() ;

	return 0;
	cout << "What do you want: MAINTENANCE or REPAIRING ::  "<<endl;
	cout << "Do you want to add more : <Y/N>            ::  ";
	cout << "Enter Labour Charge                        :: ";
}*/