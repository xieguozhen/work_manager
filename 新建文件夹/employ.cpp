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
	cout << "Ա�����: " << this->id << endl << "Ա������:  " << this->name << endl << "Ա�����ű��:  " << this->depid << endl;
}
string Employ::getDepName()
{
	return string("Ա��");
}
