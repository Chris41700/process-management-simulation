#pragma once
#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
	int id;
	int priority;
	int arrivalTime;
	int waitingTime;
	int turnaroundTime;
	int startTime;
	int completeTime;
	int executionTime;
};

enum Actions { stop, fcfs, priority, sjn };

bool compareArrival(Process p1, Process p2);
bool comparePriority(Process p1, Process p2);
bool compareShortestExecution(Process p1, Process p2);
void firstComeFirstServe(vector<Process> process, int numOfProcesses);
void priorityScheduling(vector<Process> process, int numOfProcesses);
void shortestJobNext(vector<Process> process, int numOfProcesses);

#endif