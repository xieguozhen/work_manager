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
	cout << "������: " << this->id << endl << "��������:  " << this->name << endl << "�����ű��:  " << this->depid << endl;
}
string Manager::getDepName()
{
	return string("����");
}
