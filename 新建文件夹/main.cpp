#include <iostream>
#include "workmanager.h"
#include "boss.h"
#include "manage.h"
#include "employ.h"
#include "worker.h"
//#include <windows.h>
using namespace std;

int main()
{
	int choice = 0;
	A a;
	while (1)
	{
		a.show_menu();
		cout << "请输入一个数据 " << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:  a.exist(); ; break;
		case 1: a.Add_Emp(); break;
		case 2: a.show_employ(); break;
		case 3:  a.Delete(); break;
		case 4: a.modify(); break;
		case 5: a.findemploy(); break;
		case 6: a.sort(); break;
		case 7: a.cleanall(); break;
		default: system("cls"); break;
		}

	}
	return 0;

}