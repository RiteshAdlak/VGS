#ifndef VEHICLE_H
#define VEHICLE_H


#include"string.h"
#include<list>
#include"oil.h"
#include"maintenance.h"
#include"ser_req.h"
#include"bill.h"


class vehicle
{
	TString company;
	TString model;
	TString number;
public:
	vehicle();
	vehicle(const TString& company, const TString& model, const TString& number);
	TString get_company();
	TString get_model();
	TString get_number();
	void input();
	void set_company(const TString& company);
	void set_model(const TString& model);
	void set_number(const TString& number);
};
#endif