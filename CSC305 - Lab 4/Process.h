#pragma once
#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <ctime>

using namespace std;

struct Process {
	int id;
	int priority;
	double turnaroundTime;
	double startTime;
	double completionTime;
	double executionTime;
};

enum Actions { stop, fcfs, priority, sjn };

#endif