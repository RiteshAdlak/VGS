
#include"vehicle.h"
#include"string.h"



	vehicle::vehicle()
	{
		company = "";
		model = "";
		number = "";
	}
	vehicle::vehicle(const TString& company, const TString& model, const TString& number)
	{
		this->company = company;
		this->model = model;
		this->number = number;
	}

	TString vehicle::get_company()
	{
		return this->company;
	}
	TString vehicle::get_model()
	{
		return this->model;
	}
	TString vehicle::get_number()
	{
		return this->number;
	}
	void vehicle::input()
	{
		cout << "Enter the Company name	 : ";
		cin >> company;
		//cout << endl;
		cout << "Enter the Model Number  : ";
		cin >> model;
		//cout << endl;
		cout << "Enter the Number        : ";
		cin >> number;
		//cout << endl;
	}
	void vehicle::set_company(const TString& company)
	{
		this->company = company;
	}
	void vehicle::set_model(const TString& model)
	{
		this->model = model;
	}
	void vehicle::set_number(const TString& number)
	{
		this->number = number;
	}



/*
int main()
{
	vehicle v1;

	v1.input();

	return 0;


	cout << "Enter the Company name	 : ";
	cout << "Enter the Model Number  : ";
	cout << "Enter the Number        : ";
}*/