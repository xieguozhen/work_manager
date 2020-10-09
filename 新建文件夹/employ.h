#pragma once
#include "worker.h"
#include <iostream>
using namespace std;
class Employ : public Worker
{
public:
	virtual void showInfo();
	virtual string getDepName();
	Employ(int id, string name, int depid);
};

