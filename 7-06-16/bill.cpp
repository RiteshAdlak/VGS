#include"bill.h"

#include <time.h>

void bill:: getTodaysDate()
{
	time_t t = time(NULL);
	struct tm now = *localtime(&t);
	int Day = now.tm_mday;
	int Month = now.tm_mon + 1;
	int Year = now.tm_year + 1900;
	cout << "Service date	:: " << Day << "/" << Month << "/" << Year;
	
}


bill::bill(ser_req *req)
{
	this->req = req;
}
double bill::compute_amount()
{
	this->amount = 0;
	
	typedef list<service*> service_list;
	service_list& serv_list = this->req->get_serv_list();

	list<service *>::iterator itr = serv_list.begin();
	//cout << "------------------------------"<<endl;
	while (itr != serv_list.end())
	{
		this->amount+=  (*itr)->price();
		itr++;
	}
	
	return this->amount;
}
double bill::compute_tax()
{
	double amt = this->compute_amount();
	return ((amt*12.6)/100);
}
double bill::compute_total_bill()
{
	this->paid_amount = this->compute_amount() + this->compute_tax();
	return this->paid_amount;
}
double bill::get_paid_amount()
{
	return this->paid_amount;
}
void bill::set_paid_amount(double amt)
{
	this->paid_amount = amt;
}
void bill:: print()
{
	cout << "\t\t  *****BILL*****";
	cout << "\n";
	this->getTodaysDate();
	cout << "\n";
	cout << "Customer Name   :: "<<this->req->get_cust_name()<<endl;
	cout << "Vehicle Details ::"<<this->req->get_veh_no()<<endl<<endl;
	
	
	this->amount = 0;
	typedef list<service*> service_list;
	service_list& serv_list = this->req->get_serv_list();

	list<service *>::iterator itr = serv_list.begin();
	cout << "\t\*****VEHICLE SERVICE DISPLAY*****"<<endl;
	cout << "\t----------------------------------" << endl;
	while (itr != serv_list.end())
	{
		cout << "\n";
		(*itr)->display();
	
		itr++;
	}
	
	cout << endl<<endl;
	cout << "TAX is		:: "<<this->compute_tax()<<endl;
	cout << "Amount is  ::  "<<this->compute_amount()<<endl;
	cout << "Final bill :: "<<this->compute_total_bill()<<endl<<endl;
}

/*int main()
{
	ser_req *req = new ser_req("ritesh", "7885");
	
		bill *b1 = new bill(req);
		req->process_request();
		b1->print();

		return 0;

}*/