//#include "worker.h"
#include "manage.h"
#include "iostream"

using namespace std;
Manager::Manager(int a, string b, int c)
{
	id = a;
	name = b;
	depid = c;
}
void Manager::showInfo()
{
	cout << "经理编号: " << this->id << endl << "经理名字:  " << this->name << endl << "经理部门编号:  " << this->depid << endl;
}
string Manager::getDepName()
{
	return string("经理");
}
