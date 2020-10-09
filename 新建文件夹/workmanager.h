
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
      //记录文件中的人数个数
      int m_EmpNum;
      //void show_employ();
      //员工数组的指针
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
