#include "Project.h"

Project::Project()
{
	task = new Task[0];
}

void Project::addTask(Task* taskToAdd)
{
	if (taskInProject > 0) {
		copyTask(taskInProject, taskToAdd);
	}

	if (taskInProject == 0) {
		task = new Task[1];
		task[0] = taskToAdd;
		taskInProject = 1;
	}
}

void Project::copyTask(int& projectTasks,Task* taskToAdd)
{
	Task* auxTasks = new Task[projectTasks];

	for (int index = 0; index < projectTasks;index++) {
		auxTasks[index] = task[index];
	}

	projectTasks++;

	for (int index1 = 0; index1 < projectTasks; index1++) {
		task[index1] = auxTasks[index1];
	}
	task[projectTasks - 1] = taskToAdd;
}

double Project::calculateTotalCost()
{
	totalCost = calculateMachineryCost() + calculateManPowerCost() + calculateMaterialCost();
	return totalCost;
}

double Project::calculateManPowerCost()
{
	int resourceUnits = 0;
	double priceOfResource = 0.0;

	for (int index = 0; index < taskInProject; index++) {
		resourceUnits = task[index]->getManPower->getResourceToUse();
		priceOfResource = task[index]->getManPower->getResourcePrice();
		manPowerCost += resourceUnits * priceOfResource;
	}
	return manPowerCost;
}

double Project::calculateMachineryCost()
{
	int resourceUnits = 0;
	double priceOfResource = 0.0;

	for (int index = 0; index < taskInProject; index++) {
		resourceUnits = task[index]->getMachinery->getResourceToUse();
		priceOfResource = task[index]->getMachinery->getResourcePrice();
		machineryCost += resourceUnits * priceOfResource;
	}
	return machineryCost;
}

double Project::calculateMaterialCost()
{
	int resourceUnits = 0;
	double priceOfResource = 0.0;

	for (int index = 0; index < taskInProject; index++) {
		resourceUnits = task[index]->getMaterial->getResourceToUse();
		priceOfResource = task[index]->getMaterial->getResourcePrice();
		materialCost += resourceUnits * priceOfResource;
	}
	return materialCost;
}

Project::~Project()
{
	delete task;
}
