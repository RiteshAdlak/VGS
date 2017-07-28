
#ifndef MAINTAIN_H
#define MAINTAIN_H

#include"string.h"
#include"service.h"
#include"part.h"

#include<list>

#include <iostream>
using namespace std;

class maint :public service
{
	double labcharge;
	list<part> lop;
public:
	maint();
	maint(const TString& desc,double rate);
	double get_labcharge();
	void display();
	void input();
	void set_labcharge(double labour);
	double price();
	void add_part(part &part);
	list<part> &get_part_list();
};
#endif
