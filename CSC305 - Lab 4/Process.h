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
	int turnaroundTime;
	int startTime;
	int completeTime;
	int executionTime;
	void first_come_first_serve(vector<Process> process, int processSize);
	void process_priority(vector<Process> process, int processSize);
	void shortest_job_next(vector<Process> process, int processSize);
private:
};

enum Actions { stop, fcfs, priority, sjn };

#endif