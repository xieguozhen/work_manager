
#pragma once
#include "worker.h"
#include <iostream>
#include "fstream"
#define filename "www.txt"
using namespace  std;
class A
{
public:  A();
      ~A();
      void show_menu();
      void exist();
      void save();
      //��¼�ļ��е���������
      int m_EmpNum;
      //void show_employ();
      //Ա�������ָ��
      Worker** m_EmpArray;
      void Add_Emp();
      bool m_FileIsEmpty;
      int get_EmpNum();
      void show_employ();
      void init_Emp();
      void findemploy();
      int isexist();
      void Delete();
      void modify();
      void sort();
      void cleanall();
};
