#include"string.h"
#include<list>
#include"oil.h"
#include"maintenance.h"
#include"ser_req.h"
#include"bill.h"
#include"cust.h"
#include"vehicle.h"
#include"ser_stat.h"
#include<vector>

enum garageenum
{
	EXIT = 0, New_customer, Service_request, Total

};
service_station s;

int menu()
{
	int ch;
	cout << "\t\t****** RITESH GARAGE****** "<<endl<<endl;
	cout << "Enter the Choice : "<<endl;
	cout << "1.NEW_CUSTOMER\n2.SERVICE_REQUEST\n3.TOTAL_CASH"<<endl<<endl;
	cout << "Choice is :: ";
	cin >> ch;
	
	return ch;
}
int main()
{
	
	int ch;
	s.load_customer_details();
	while ((ch=::menu())!= 0)
	{
		switch (ch)
		{
		
		
		case 1:s.new_customer();
			break;

		case 2:s.handle_service_request();
			break;

		case 3:double cash=s.compute_cash();
			cout << "Total cash :: "<<cash<<endl<<endl;
			break;
		}
		
	}
	s.store_customer_details();
	return 0;
}



/*
int main()
{
	TString s1, s2("brake");
	cout << "String is :: ";
	cout << s2<<endl;

	cout <<"enter string :: ";
	cin >> s1;

	if (s1 == s2)
		cout << "strings r same "<<endl;

	if (s1 != s2)
		cout << "strings are not same"<<endl;



	return 0;

}




int main()
{
	
	int ch=0;
	double pr = 0;
	list<service *> loz;

	
	
	
	service *ptr = NULL;
	while (ch!=4)
	{
		cout << "Enter the choice :: " << endl;
		cout << "1.OIL\n2.MAINTENANCE\n3.DISPLAY\n4.EXIT" << endl;
		cin >> ch;

		switch (ch)
		{
		case 1:ptr = new oil;
			break;

		case 2:ptr = new maint;
			break;

		case 3:
			list<service *>::iterator itr = loz.begin();
			cout << "----------------------------------";
			while (itr != loz.end())
			{

				(*itr)->display();

				pr = pr + (*itr)->price();
				cout << "\n";

				itr++;
			}
			cout << "total price is :: " << pr << endl;
			exit(0);
			break;
		}

		

		if (ptr != NULL)
		{
			ptr->input();
			loz.push_back(ptr);
		}
	}
	return 0;
}
*/

/*int main()
{
	customer *c1=new customer();
	vehicle v1;
	/*c1->input();
	c1->new_vehicle();
	c1->new_vehicle();
	ofstream fout;
	c1->store_customer(fout);
	*/
	
	
	
	/*ifstream fin;
	c1->load_customer(fin);
	c1->display_veh();
	*/
	
	

	

/*	
	c1->display_veh();

	int ind;
	cout << "Enter which vehicle u want to service :: "<<endl;
	cin >> ind;

	vector<vehicle> e;
	e=c1->get_veh_list();
 
	ser_req *req = new ser_req(c1->get_name(), e[ind-1].get_number());

	bill *b1 = new bill(req);
	req->process_request();

	b1->print();

	cout << "Customer has to pay Bill Amount :: "<<b1->compute_total_bill();

	c1->pay_bill(*b1);*/

	/*return 0;

}*/