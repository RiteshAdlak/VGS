#include"service.h"


service::service()
{
	this->desc = "";
}
service::service(const TString& desc)
{
	this->desc = desc;
}
TString service::get_desc()
{
	return this->desc;
}
void service::input()
{
	cout << "Enter the service :: ";
	//cout << "1.oil change\n2.maintenance/repairing";
	cin >> desc;
}
void service::set_desc(const TString& desc)
{
	this->desc = desc;
};
//double service::price()
//{
	
	//made pure virtual class
//}
void service::display()
{
	cout << "servicing is :: "<<desc<<endl;
}

/*int main()
{
	service s1;
	s1.input();

	//s1.display();



	return 0;
}

*/

