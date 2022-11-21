#pragma once
#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <vector>

using namespace std;

class Process {
public:
	int id;
	int priority;
	int waitingTime;
	int turnaroundTime;
	int startTime;
	int completeTime;
	int executionTime;
private:
	void calculateWaitingTime(vector<Process> process, int num_of_processes);
	void calculateTurnaroundTime(vector<Process> process, int num_of_processes);
	void firstComeFirstServe(vector<Process> process, int num_of_processes);
	void processPriority(vector<Process> process, int num_of_processes);
	void shortestJobNext(vector<Process> process, int num_of_processes);
};

enum Actions { stop, fcfs, priority, sjn };

#endif