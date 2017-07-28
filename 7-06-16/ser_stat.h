#ifndef SERVICESTATION_H
#define SERVICESTATION_H

#include<iostream>
using namespace std;
#include"bill.h"
#include"cust.h"
#include"string.h"
#include<list>


class service_station
{
	list<bill> bill_list;
	list<customer> cust_list;
	TString name;
public:
	service_station();
	double compute_cash();
	void display_customer_list();
	customer *find_customer(const TString &name);
	list<bill>& get_bill_list();
	list<customer>& get_cust_list();
	TString get_name();
	void handle_service_request();
	void load_customer_details();
	void new_customer();
	service_station(const TString& name);
	void store_customer_details();
};
#endif