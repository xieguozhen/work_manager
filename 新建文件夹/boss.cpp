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
    cout << "�ϰ���: " << this->id << endl << "�ϰ�����:  " << this->name << endl << "�ϰ岿�ű��:  " << this->depid << endl;
}
string Boss::getDepName()
{
    return string("�ϰ�");
}
