#ifndef CUST_H
#define CUST_H

#include <vector>
#include <fstream>
using namespace std;
#include"vehicle.h"



class customer
{
	TString address;
	TString mobile;
	TString name;
	vector<vehicle> veh_list;
public:
	customer();
	customer(const TString& name, const TString& address, const TString& mobile);
	void display_veh();
	TString get_add();
	TString get_name();
	TString get_mobile();
	vector<vehicle>& get_veh_list();
	void input();
	void load_customer(ifstream& fin);
	vehicle *new_vehicle();
	void pay_bill(bill& bill);
	void set_add(const TString& address);
	void set_name(const TString& name);
	void set_mobile(const TString& mobile);
	void store_customer(ofstream& fout);
	
};
#endif


/*
class Temp		//custumber
{
int sal;
TString name;
public:
Temp()
{
this->name = "";
this->sal = 0;
}
Temp(int sal, TString name)
{
this->name = name;
this->sal = sal;
}
void AcceptEmployeeInfo()
{
cout << "Enter emp Details : " << endl;
cout << "Name : ";
cin >> this->name;
cout << "salary : ";
cin >> this->sal;

}
void setsalary(int sal)
{
this->sal = sal;
}
void setName(TString name)
{
this->name = name;
}
int getsalary()
{
return this->sal;
}
TString getName()
{
return this->name = name;
}

};

vector<Temp> loe;		//list of vehichles
const char* db_file = "TSH.dat";

Temp* addnew()
{
Temp e1;
int index = loe.size();
e1.AcceptEmployeeInfo();
loe.push_back(e1);		//list of vehicles (lov)

return &loe[index];
}

void display()
{
vector<Temp>::iterator itr = loe.begin();
int i;

for (i = 1; itr != loe.end(); i++)
{
cout << i << "." << (*itr).getName() << ":" << (*itr).getsalary() << endl;
itr++;
}
}

void store_emp()
{

}*/
