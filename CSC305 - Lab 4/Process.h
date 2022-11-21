#pragma once
#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <vector>

using namespace std;

struct Process {
	int id;
	int priority;
	double turnaroundTime;
	double startTime;
	int completionTime;
	int executionTime;
};

enum Actions { stop, fcfs, priority, sjn };

#endif