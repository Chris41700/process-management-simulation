#pragma once
#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <vector>

using namespace std;

struct Process {
	int id;
	int priority;
	int turnaroundTime;
	int startTime;
	int completionTime;
	int executionTime;
};

enum Actions { stop, fcfs, priority, sjn };

#endif