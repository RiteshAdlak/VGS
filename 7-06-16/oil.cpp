#include"string.h"
#include"oil.h"

TString name;
	void oil :: display()		//DISPLAY
	{
		cout << "\n";
		cout << "Name of Oil is              : " << name << endl;

		cout << "The Cost of Oil is          : " << cost << endl;
		
	}
	void oil::input()			//INPUT
	{
		
		cout << "Enter Name of oil to change : ";
		cin >> name;
		set_desc(name);
		
		cout << "Enter the Cost of the Oil   : ";
		cin >> cost;
		
		//service::display();
	}
	double oil::get_cost()
	{
		return this->cost;
	}
	oil::oil()
	{
		cost = 0;
	}
	oil::oil(const TString& desc, double cost) :service(desc)
	{
		this->cost = cost;
		this->set_desc(desc);
	}
	double oil::price()		//PRICE
	{
		return cost;
	}
	void oil::set_cost(double cost)
	{
		this->cost = cost;
	}

/*	int main()
	{
		oil o1, o2("servoT4",500);

		o1.input();
		//o1.disp();

	//	service *p1 = &o1;
		//p1->display();
	
		service *p1 = new oil("castrol", 5000);//base ptr accessess derived class functions
		p1->display();


	}

	cout << "Enter Name of oil to change : ";
	cout << "Enter the Cost of the Oil   : ";
	cout << "Name of Oil is              : "<<name<<endl;
	cout << "The Cost of Oil is          : "<<cost<<endl;
*/