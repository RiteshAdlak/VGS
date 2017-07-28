
#ifndef SERVICE_H
#define SERVICE_H
#include"string.h"

#include <iostream>
using namespace std;

class service
{
	TString desc;
public:
	virtual void display();
	TString get_desc();					//g
	virtual void input();
	virtual double price()=0;			//pure virtual function
	service();							//c
	service(const TString& desc);		//c
	void set_desc(const TString& desc);	//s


};
#endif
