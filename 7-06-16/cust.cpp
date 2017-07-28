#include"cust.h"
#include"vehicle.h"



customer::customer()
{
	this->address = "";
	this->name = "";
	this->mobile = "";
}
customer::customer(const TString& name, const TString& address, const TString& mobile)
{
	this->address = address;
	this->name = name;
	this->mobile = mobile;
}
void customer::display_veh()		//DISPLAY
{
	vector<vehicle>::iterator itr = veh_list.begin();
	int i;
	cout << "SERIAL\tCOMPANY NAME\tMODEL NO.\tNUMBER"<<endl;
	for (i = 1; itr != veh_list.end(); i++)
	{
		cout << i << "." << "\t" << (*itr).get_company() << "\t\t\t"<< (*itr).get_model() << "\t\t" << (*itr).get_number();
		itr++;
		cout << "\n";
	}
}
TString customer::get_add()
{
	return this->address;
}
TString customer::get_name()
{
	return this->name;
}
TString customer::get_mobile()
{
	return this->mobile;
}
vector<vehicle>& customer::get_veh_list()
{
	return this->veh_list;
}
void customer::input()
{
	cout << "Enter the customer name :: ";
	cin >> name;
	cout << "\n";
	cout << "Enter the Address :: ";
	cin >> address;
	cout << "\n";
	cout << "Enter the Mobile NO. :: ";
	cin >> mobile;
	cout << "\n";
}
void customer::load_customer(ifstream& fin)
{
	
	int veh_count;

	fin.read((char*)&this->name, sizeof(name));
	fin.read((char*)&this->address, sizeof(address));
	fin.read((char*)&this->mobile, sizeof(mobile));


	fin.read((char*)&veh_count, sizeof(veh_count));
	int i;
	for ( i = 0; i < veh_count; i++)
	{
		vehicle v1;
		fin.read((char*)&v1, sizeof(vehicle));
		veh_list.push_back(v1);
	}

}
void customer::store_customer(ofstream& fout)
{
//	fout.open(db_file, ios::binary | ios::out | ios::trunc);//open(filename,mode)
	
	fout.write((char*)&this->name, sizeof(name));
	fout.write((char*)&this->address, sizeof(address));
	fout.write((char*)&this->mobile, sizeof(mobile));
	
	int veh_count = this->veh_list.size();


	fout.write((char*)&veh_count, sizeof(veh_count));
	
	for (int i = 0; i < veh_count; i++)
		fout.write((char*)&veh_list[i], sizeof(vehicle));

}
vehicle* customer::new_vehicle()
{
	vehicle c1;
	int index = veh_list.size();
	c1.input();
	veh_list.push_back(c1);

	return &veh_list[index];
}
void customer::pay_bill(bill& bill)
{
	double billpaid=0;
	cout << "Bill paid by customer           :: ";
	cin >> billpaid;
	
	//cout << bill.get_paid_amount();
	double balance = bill.compute_total_bill()- billpaid;
	cout << "\n";
	cout << "The Balance left is :: "<<balance<<endl<<endl;
	bill.set_paid_amount(billpaid);

}
void customer::set_add(const TString& address)
{
	this->address = address;
}
void customer::set_name(const TString& name)
{
	this->name = name;
}
void customer::set_mobile(const TString& mobile)
{
	this->mobile = mobile;
}

/*int main()
{
	customer c1;

	c1.set_name("ritesh");
	c1.set_mobile("22586");
	c1.set_add("kondhwa");

	return 0;
	
}*/

