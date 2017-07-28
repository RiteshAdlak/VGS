#include"ser_req.h"
#include"oil.h"
#include"maintenance.h"

void ser_req::add_item(service* serv)
{
	this->serv_list.push_back(serv);
}
void ser_req::process_request()
{
	int ch = 0;
	double pr = 0;
	
	service *ptr = NULL;
	while (ch != 3)
	{
		
		cout << "\n";
		cout << "Enter the Choice :: " << endl;
		cout << "1.OIL\n2.MAINTENANCE\n3.EXIT" << endl;
		cin >> ch;

		switch (ch)
		{
		case 1:ptr = new oil;
			break;

		case 2:ptr = new maint;
			break;
		}

		
		
		if (ch == 1 || ch == 2)
		{

			if (ptr != NULL)
			{
				ptr->input();
				this->serv_list.push_back(ptr);
			}
		}
		
	}
}
ser_req::ser_req()
{
	this->cust_name = "";
	this->veh_no = "";
}

TString ser_req::get_cust_name()
{
	return this->cust_name;
}
list<service*>& ser_req::get_serv_list()
{
	return serv_list;
}
TString ser_req::get_veh_no()
{
	return this->veh_no;
}
ser_req::ser_req(const TString& cust_name, const TString& veh_no)
{
	this->cust_name = cust_name;
	this->veh_no = veh_no;
}
void ser_req::set_cust_name(const TString& cust_name)
{
	this->cust_name = cust_name;
}
void ser_req::set_veh_no(const TString& veh_no)
{
	this->veh_no = veh_no;
}

/*
int main()
{
	ser_req *s1=new ser_req();

	s1->process_request();



}*/