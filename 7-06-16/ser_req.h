#ifndef SREQUEST_H
#define SREQUEST_H

#include"string.h"
#include"service.h"
#include<list>

#include<iostream>
using namespace std;

class ser_req
{
	TString cust_name;
	list<service *> serv_list;
	TString veh_no;
	
public:
	void add_item(service *serv);
	TString get_cust_name();
	list<service *>& get_serv_list();
	TString get_veh_no();
	void process_request();
	ser_req(const TString& cust_name,const TString& veh_no);
	void set_cust_name(const TString& cust_name);
	void set_veh_no(const TString& veh_no);
	ser_req();
};
#endif