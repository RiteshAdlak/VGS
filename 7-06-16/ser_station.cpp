#include"ser_stat.h"
const char* db_file = "customers.dat";

double service_station::compute_cash()
{
	double cash = 0;
	list<bill>::iterator b_list = this->bill_list.begin();
	while (b_list != this->bill_list.end())
	{
		
		cash = cash + (*b_list).get_paid_amount();
		
		b_list++;
	
	}
	return cash;
}
void service_station::display_customer_list()
{
	int i;
	list<customer> ::iterator c_itr = cust_list.begin();
	for (i = 1; c_itr != cust_list.end(); i++)
	{
		cout << i << "." << "\t" << (*c_itr).get_name() << "\t" << (*c_itr).get_mobile() << "\t" << (*c_itr).get_add()<<endl;
		c_itr++;
		
	}
}
customer* service_station::find_customer(const TString& name)		//find customer 
{
	
	
	list<customer> ::iterator c_itr = cust_list.begin();
	while (c_itr != cust_list.end())
	{
		if (c_itr->get_name()==name)
		{
			return &(*c_itr);
		}
		c_itr++;
	
	}
	
	return NULL;
}
list<bill>& service_station::get_bill_list()		//getter
{
	return this->bill_list;
}
list<customer>& service_station::get_cust_list()	//getter
{
	return this->cust_list;
}
TString service_station::get_name()					//getter
{
	return this->name;
}
void service_station::handle_service_request()		//HANDLE SERVICE REQUEST
{
	customer *cust = new customer();
	vehicle *veh=new vehicle();
	TString cust_name;
	int option;

	system("cls");

	//this->load_customer_details();
	this->display_customer_list();

	
	cout << "Enter Customer Name :: ";
	cin >> cust_name;

	if (NULL == (find_customer(cust_name)))
	{
		cout << "Customer is not registered " << endl;
		cust->input();
		
	}
	else
	{
		cout << "Customer is Registered."<<endl<<endl;
		cust = this->find_customer(cust_name);
		cout << "Select Vehicle to SERVICE :: "<<endl<<endl;
		
		cout << "0.New vehicle"<<endl;
		cust->display_veh();
		cin >> option;
		

		if (option == 0)
			cust->new_vehicle();
		else
		veh= &(cust->get_veh_list()[option-1]);


		
		ser_req *req = new ser_req(cust->get_name(), veh->get_number());

		bill *b1 = new bill(req);
		req->process_request();

		b1->print();

		cout << "Customer has to pay Bill Amount :: " << b1->compute_total_bill()<<endl;
		cust->pay_bill(*b1);
		this->bill_list.push_back(*b1);


	}

	
	


}

void service_station::new_customer()
{
	customer c1;
	c1.input();
	
	cust_list.push_back(c1);
}
service_station::service_station(const TString& name)
{
	this->name = name;
}
service_station::service_station()
{
	this->name = "";
}
void service_station::store_customer_details()//fout::write
{
	ofstream fout;
	fout.open(db_file, ios::binary | ios::out | ios::trunc);
	if (!fout)
	{
		cout << "Cannot open";
		return ;
	}

	int cust_count =this->cust_list.size();
	fout.write((char*)&cust_count, sizeof(cust_count));

	list<customer> ::iterator c_itr = cust_list.begin();

	while (c_itr != cust_list.end())
	{
		c_itr->store_customer(fout);
		c_itr++;
	}
}
void service_station::load_customer_details()
{
	

	ifstream fin;
	fin.open(db_file, ios::binary | ios::in);
	if (!fin)
	{
		cout << "Database file cannot be opened." << endl;
		return;
	}
	int cust_count;
	fin.read((char*)&cust_count, sizeof(cust_count));

	int i;
	for (i = 0; i<cust_count; i++)
	{
		customer c1;
		c1.load_customer(fin);
		cust_list.push_back(c1);
	}


}
/*
int main()
{
	
	service_station s; 
	s.handle_service_request();


	/*s.new_customer();
	s.new_customer();						1 do store n comment load
	s.store_customer_details();*/

/*	s.load_customer_details();				2 do load n comment store
	s.display_customer_list();



	TString cust_name;
	cout<<"Enter customer :: ";
	cin >> cust_name;
	if (NULL == (s.find_customer(cust_name)))
	{
		cout << "not present";
	}
	else
		cout << "Present";
	
	return 0;
	
	
}
*/