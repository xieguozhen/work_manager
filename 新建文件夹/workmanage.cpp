#include "workmanager.h"
#include "boss.h"
#include "manage.h"
#include "employ.h"
#include "worker.h"
A::A()
{
	//初始化人数
	m_EmpNum = 0;

	//初始化数组指针
	m_EmpArray = NULL;

	ifstream ifs;
	ifs.open(filename, ios::in);

	//文件不存在情况
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl; //测试输出
		this->m_EmpNum = 0;  //初始化人数
		this->m_FileIsEmpty = true; //初始化文件为空标志
		this->m_EmpArray = NULL; //初始化数组
		ifs.close(); //关闭文件
		return;
	}
	char ch;
	ifs >> ch;	// 文件结尾标EOF
	if (ifs.eof())
	{
		//cout << "文件为空!" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}
	int num = this->get_EmpNum();
	//cout << "职工个数为：" << num << endl;  //测试代码
	this->m_EmpNum = num;  //更新成员属性
	//根据职工数创建数组
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//初始化职工
	init_Emp();

	this->m_FileIsEmpty = false;

	//测试代码
	
}
A::~A()
{


}
void A::show_menu()
{
	cout << "******欢迎使用职工管理系统******" << endl;
	cout << "*********0.退出管理程序**********" << endl;
	cout << "*********1.增加职工信息**********" << endl;
	cout << "*********2.显示职工信息**********" << endl;
	cout << "*********3.删除职工信息**********" << endl;
	cout << "*********4.修改职工信息**********" << endl;
	cout << "*********5.查找职工信息**********" << endl;
	cout << "*********6.按照编号排序**********" << endl;
	cout << "*********7.清空所有文档**********" << endl;


}

void A::exist()
{
	cout << "欢迎下次" << endl;
	system("pause");
	exit(0);

}

void A::Add_Emp()
{
	cout << "请输入增加职工数量： " << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//计算新空间大小
		int newSize = m_EmpNum + addNum;

		//开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//将原空间下内容存放到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//输入新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
			cin >> id;


			cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
			cin >> name;


			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;


			Worker* worker=NULL ;
			switch (dSelect)
			{
			case 1: //普通员工
				worker = new Employ(id, name, 1);
				break;
			case 2: //经理
				worker = new Manager(id, name, 2);
				break;
			case 3:  //老板
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}


			newSpace[this->m_EmpNum + i] = worker;
		}

		//释放原有空间
		delete[] this->m_EmpArray;

		//更改新空间的指向
		this->m_EmpArray = newSpace;

		//更新新的个数
		this->m_EmpNum = newSize;

		this->m_FileIsEmpty = false;

		//提示信息
		cout << "成功添加" << addNum << "名新职工！" << endl;
	}
	else
	{
		cout << "输入有误" << endl;
	}
	this->save();
	system("pause");
	system("cls");
	
}


void A::save()
{
	ofstream ofs;
	ofs.open(filename, ios::out);
	for (int i = 0; i < m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->id <<"   ";
		ofs << this->m_EmpArray[i]->name << "   ";
		ofs	<< this->m_EmpArray[i]->depid << endl;
	}
	ofs.close();
}
int A::get_EmpNum()
{
	ifstream ifs;
	ifs.open(filename, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//记录人数
		num++;
	}
	ifs.close();

	return num;
}
void A::show_employ()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多态调用接口
			this->m_EmpArray[i]->showInfo();
			cout << endl;
		}
	}

	system("cls");
}
void A::init_Emp()
{
	ifstream ifs;
	ifs.open(filename, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		//根据不同的部门Id创建不同对象
		if (dId == 1)  // 1普通员工
		{
			worker = new Employ(id, name, dId);
		}
		else if (dId == 2) //2经理
		{
			worker = new Manager(id, name, dId);
		}
		else //总裁
		{
			worker = new Boss(id, name, dId);
		}
		//存放在数组中
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}
int A::isexist()
{
	
	    int id;
		cout << "请输入编号" << endl;
		cin >> id;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (id == this->m_EmpArray[i]->id)
			{
				return i;
				break;
			}
		}
		return -1;
	
}
void A::findemploy()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空" << endl;
	}
	else
	{
		int number = isexist();
		if (number != -1)
			this->m_EmpArray[number]->showInfo();
		else
			cout << "没有该员工" << endl;

	}
	system("pause");
	system("cls");
}
	void A::Delete()
	{
		if (this->m_FileIsEmpty)
		{
			cout << "文件为空" << endl;
		}
		else
		{
			int number = isexist();
			if (number != -1)
			{
				for (int i = number; i < m_EmpNum-1; i++)
				{
					this->m_EmpArray[i] = this->m_EmpArray[i + 1];
				}
				cout << "删除成功" << endl;

				m_EmpNum--;
			}
			else
				cout << "没有该员工" << endl;
		}
		this->save();
		system("pause");
		system("cls");
		
	}

	void A::modify()
	{
		int id;
		string name;
		int depid;
		if (this->m_FileIsEmpty)
		{
			cout << "文件为空" << endl;
		}
		else
		{
			int number = isexist();
			if (number != -1)
			{
				cout << "请输入想修改的数据" << endl;
				cin >> id >> name >> depid;
				Worker* worker = NULL;
				switch (depid)
				{
				case 1:
					worker = new Employ(id, name, depid);
					break;
				case 2:
					worker = new Manager(id, name, depid);
					break;
				case 3:
					worker = new Boss(id, name, depid);
					break;
				default:
					break;
				}

				//更改数据 到数组中
				this->m_EmpArray[number] = worker;

			}
			else
				cout << "没有该员工" << endl;
		}
		this->save();
		system("pause");
		system("cls");
	}

	void A::sort()
	{
		int a;
		if (this->m_FileIsEmpty)
		{
			cout << "文件为空" << endl;
		}
		else
		{
			cout << "输入1：表示降序；输入2：表示升序" << endl;
			cin >> a;
			if (a == 1)
			{
				for (int i = 0; i < m_EmpNum-1; i++)
				{
						for (int j = i+1; j < m_EmpNum; j++)
						{
							if (this->m_EmpArray[i]->id < this->m_EmpArray[j]->id)
							{
								Worker* work = NULL;
								work = this->m_EmpArray[i];
								this->m_EmpArray[i] = this->m_EmpArray[j];
								this->m_EmpArray[j] = work;

							}
						}
				}
			}
			else
			{
				for (int i = 0; i < m_EmpNum; i++)
				{
						for (int j = i + 1; j < m_EmpNum; j++)
						{
							if (this->m_EmpArray[i]->id > this->m_EmpArray[j]->id)
							{
								Worker* work = NULL;
								work = this->m_EmpArray[i];
								this->m_EmpArray[i] = this->m_EmpArray[j];
								this->m_EmpArray[j] = work;

							}
						}
				}
			}
		}
		this->save();
		this->show_employ();
		system("pause");
		system("cls");
	}

	void A::cleanall()
	{
		int i = 0;
		if (this->m_FileIsEmpty)
		{
			cout << "文件为空" << endl;
		}
		else
		{
			//ofstream ofs(filename, ios::trunc);
			//ofs.close();
			if (this->m_EmpArray != NULL)
			{
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					if (this->m_EmpArray[i] != NULL)
					{
						delete this->m_EmpArray[i];
					}
				}
				this->m_EmpNum = 0;
				delete[] this->m_EmpArray;
				this->m_EmpArray = NULL;
				this->m_FileIsEmpty = true;
			}
			cout << "清空成功" << endl;
		
		}
		this->save();
		system("pause");
		system("cls");
	}