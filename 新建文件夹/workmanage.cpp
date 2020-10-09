#include "workmanager.h"
#include "boss.h"
#include "manage.h"
#include "employ.h"
#include "worker.h"
A::A()
{
	//��ʼ������
	m_EmpNum = 0;

	//��ʼ������ָ��
	m_EmpArray = NULL;

	ifstream ifs;
	ifs.open(filename, ios::in);

	//�ļ����������
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl; //�������
		this->m_EmpNum = 0;  //��ʼ������
		this->m_FileIsEmpty = true; //��ʼ���ļ�Ϊ�ձ�־
		this->m_EmpArray = NULL; //��ʼ������
		ifs.close(); //�ر��ļ�
		return;
	}
	char ch;
	ifs >> ch;	// �ļ���β��EOF
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��!" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}
	int num = this->get_EmpNum();
	//cout << "ְ������Ϊ��" << num << endl;  //���Դ���
	this->m_EmpNum = num;  //���³�Ա����
	//����ְ������������
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//��ʼ��ְ��
	init_Emp();

	this->m_FileIsEmpty = false;

	//���Դ���
	
}
A::~A()
{


}
void A::show_menu()
{
	cout << "******��ӭʹ��ְ������ϵͳ******" << endl;
	cout << "*********0.�˳��������**********" << endl;
	cout << "*********1.����ְ����Ϣ**********" << endl;
	cout << "*********2.��ʾְ����Ϣ**********" << endl;
	cout << "*********3.ɾ��ְ����Ϣ**********" << endl;
	cout << "*********4.�޸�ְ����Ϣ**********" << endl;
	cout << "*********5.����ְ����Ϣ**********" << endl;
	cout << "*********6.���ձ������**********" << endl;
	cout << "*********7.��������ĵ�**********" << endl;


}

void A::exist()
{
	cout << "��ӭ�´�" << endl;
	system("pause");
	exit(0);

}

void A::Add_Emp()
{
	cout << "����������ְ�������� " << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//�����¿ռ��С
		int newSize = m_EmpNum + addNum;

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//��ԭ�ռ������ݴ�ŵ��¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//����������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
			cin >> id;


			cout << "������� " << i + 1 << " ����ְ��������" << endl;
			cin >> name;


			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;


			Worker* worker=NULL ;
			switch (dSelect)
			{
			case 1: //��ͨԱ��
				worker = new Employ(id, name, 1);
				break;
			case 2: //����
				worker = new Manager(id, name, 2);
				break;
			case 3:  //�ϰ�
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}


			newSpace[this->m_EmpNum + i] = worker;
		}

		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//�����µĸ���
		this->m_EmpNum = newSize;

		this->m_FileIsEmpty = false;

		//��ʾ��Ϣ
		cout << "�ɹ����" << addNum << "����ְ����" << endl;
	}
	else
	{
		cout << "��������" << endl;
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
		//��¼����
		num++;
	}
	ifs.close();

	return num;
}
void A::show_employ()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//���ö�̬���ýӿ�
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
		//���ݲ�ͬ�Ĳ���Id������ͬ����
		if (dId == 1)  // 1��ͨԱ��
		{
			worker = new Employ(id, name, dId);
		}
		else if (dId == 2) //2����
		{
			worker = new Manager(id, name, dId);
		}
		else //�ܲ�
		{
			worker = new Boss(id, name, dId);
		}
		//�����������
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}
int A::isexist()
{
	
	    int id;
		cout << "��������" << endl;
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
		cout << "�ļ�Ϊ��" << endl;
	}
	else
	{
		int number = isexist();
		if (number != -1)
			this->m_EmpArray[number]->showInfo();
		else
			cout << "û�и�Ա��" << endl;

	}
	system("pause");
	system("cls");
}
	void A::Delete()
	{
		if (this->m_FileIsEmpty)
		{
			cout << "�ļ�Ϊ��" << endl;
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
				cout << "ɾ���ɹ�" << endl;

				m_EmpNum--;
			}
			else
				cout << "û�и�Ա��" << endl;
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
			cout << "�ļ�Ϊ��" << endl;
		}
		else
		{
			int number = isexist();
			if (number != -1)
			{
				cout << "���������޸ĵ�����" << endl;
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

				//�������� ��������
				this->m_EmpArray[number] = worker;

			}
			else
				cout << "û�и�Ա��" << endl;
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
			cout << "�ļ�Ϊ��" << endl;
		}
		else
		{
			cout << "����1����ʾ��������2����ʾ����" << endl;
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
			cout << "�ļ�Ϊ��" << endl;
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
			cout << "��ճɹ�" << endl;
		
		}
		this->save();
		system("pause");
		system("cls");
	}