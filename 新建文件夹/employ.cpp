//#include "worker.h"
#include "employ.h"
#include "iostream"

using namespace std;
Employ::Employ(int a, string b, int c)
{
	id = a;
	name = b;
	depid = c;
	//this->id = id;
	//this->name = name;
	//this->depid = depid;
}
void Employ::showInfo()
{
	cout << "员工编号: " << this->id << endl << "员工名字:  " << this->name << endl << "员工部门编号:  " << this->depid << endl;
}
string Employ::getDepName()
{
	return string("员工");
}
