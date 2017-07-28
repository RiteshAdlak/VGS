#ifndef OIL_H
#define OIL_H

#include"string.h"
#include"service.h"

#include<iostream>
using namespace std;

class oil :public service 
{
	double cost;
	
public:
	void display();
	void input();
	double get_cost();
	oil();
	oil(const TString& desc, double cost);
	double price();
	void set_cost(double cost);

};
#endif