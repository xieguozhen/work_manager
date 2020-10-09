//#include "worker.h"
#include "boss.h"
#include "iostream"
using namespace std;
Boss::Boss(int a, string b, int c)
{
    id = a;
    name = b;
    depid = c;
    //this->id = id;
    //this->name = name;
    //this->depid = depid;
}
void Boss::showInfo()
{
    cout << "老板编号: " << this->id << endl << "老板名字:  " << this->name << endl << "老板部门编号:  " << this->depid << endl;
}
string Boss::getDepName()
{
    return string("老板");
}
