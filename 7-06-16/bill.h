#ifndef BILL_H
#define BILL_H

#include"string.h"
#include"ser_req.h"
#include<list>

#include<iostream>
using namespace std;

class bill
{
	double amount;
	double paid_amount;
	ser_req *req;

public:
	bill(ser_req *req);
	double compute_amount();
	double compute_tax();
	double compute_total_bill();
	double get_paid_amount();
	void print();
	void set_paid_amount(double amount);
	void getTodaysDate();
};
#endif