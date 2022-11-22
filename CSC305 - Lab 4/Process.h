#pragma once
#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <vector>

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

void calculateWaitingTime(vector<Process> process, int numOfProcesses);
void calculateTurnaroundTime(vector<Process> process, int numOfProcesses);
void firstComeFirstServe(vector<Process> process, int numOfProcesses);
void processPriority(vector<Process> process, int numOfProcesses);
void shortestJobNext(vector<Process> process, int numOfProcesses);

#endif