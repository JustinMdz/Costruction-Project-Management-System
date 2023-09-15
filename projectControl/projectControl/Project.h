#pragma once
#include "Librarys.h"
#include "Task.h"
class Project
{
	private:
	int taskInProject = 0;
	string name;
	Task* task;
	double totalCost = 0.0;
	double manPowerCost = 0.0;
	double machineryCost = 0.0;
	double materialCost = 0.0;

	public:

	Project();
	void addTask(Task*);
	void copyTask(int&,Task*);
	double calculateTotalCost();
	double calculateManPowerCost();
	double calculateMachineryCost();
	double calculateMaterialCost();

	~Project();
};

