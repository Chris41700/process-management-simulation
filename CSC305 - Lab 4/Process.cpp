#include "Process.h"

void firstComeFirstServe(vector<Process> process, int numOfProcesses) {
	int totalTurnaroundTime = 0;
	int averageTurnaroundTime = 0;

	//The first start time is the lowest arrival time
	process[0].startTime = process[0].arrivalTime;
	int temp = process[0].startTime;

	//Calculate the start time for each process
	for (int i = 1; i < numOfProcesses; i++) {
		temp += process[i - 1].executionTime;
		process[i].startTime = temp;
	}

	//Calculate the completion time for each process
	for (int i = 0; i < numOfProcesses; i++) {
		process[i].completeTime = process[i].waitingTime + process[i].executionTime;
	}

	//Calculate the turnaround time for each process
	for (int i = 0; i < numOfProcesses; i++) {
		process[i].turnaroundTime =  (process[i].startTime + process[i].executionTime) - process[i].arrivalTime;
	}

	cout << "\n=================First Come First Serve Algorithm=================" << endl;
	cout << "Processes\tStart Time\tCompletion Time\tTurnaround Time" << endl;
	//Calculate the total turnaround time
	for (int i = 0; i < numOfProcesses; i++) {
		totalTurnaroundTime += process[i].turnaroundTime;
		cout << process[i].id << "\t\t" << process[i].startTime << "\t\t" << process[i].completeTime << "\t\t" << process[i].turnaroundTime << endl;
	}
	
	averageTurnaroundTime = totalTurnaroundTime / numOfProcesses;

	cout << "Order of Execution: ";

	for (int i = 0; i < numOfProcesses; i++) {
		if (i == numOfProcesses - 1) {
			cout << "P" << process[i].id << endl;
		}
		else {
			cout << "P" << process[i].id << " -> ";
		}
	}

	cout << "Average Turnaround Time: " << averageTurnaroundTime << endl;
}

bool priorityComparison(Process a, Process b) {
	//Return the priority 
	if (a.arrivalTime == b.arrivalTime) {
		return a.priority < b.priority;
	}
	else {
		return a.arrivalTime < b.arrivalTime;
	}
}

void priorityScheduling(vector<Process> process, int numOfProcesses) {
	int totalTurnaroundTime = 0;
	int averageTurnaroundTime = 0;
	
	int position;

	for (int i = 0; i < numOfProcesses; i++) {
		position = i;
		for (int j = i + 1; j < numOfProcesses; j++) {
			if (process[j].priority < process[position].priority) {
				position = j;
			}
		}
		Process temp = process[i];
		process[i] = process[position];
		process[position] = temp;
	}

	process[0].waitingTime = 0;

	//Calculate the waiting time for each process
	for (int i = 1; i < numOfProcesses; i++) {
		process[i].waitingTime = 0;
		for (int j = 0; j < i; j++) {
			process[i].waitingTime += process[j].executionTime;
		}
	}

	//The first start time is the lowest arrival time
	process[0].startTime = process[0].arrivalTime;
	int temp = process[0].startTime;

	//Calculate the start time for each process
	for (int i = 1; i < numOfProcesses; i++) {
		temp += process[i - 1].executionTime;
		process[i].startTime = temp;
	}

	//Calculate the completion time for each process
	for (int i = 0; i < numOfProcesses; i++) {
		process[i].completeTime = process[i].waitingTime + process[i].executionTime;
	}

	//Calculate the turnaround time for each process
	for (int i = 0; i < numOfProcesses; i++) {
		process[i].turnaroundTime = process[i].executionTime + process[i].waitingTime;
	}

	cout << "\n=================Priority Scheduling Algorithm=================" << endl;
	cout << "Processes\tStart Time\tCompletion Time\tTurnaround Time" << endl;
	//Calculate the total turnaround time
	for (int i = 0; i < numOfProcesses; i++) {
		totalTurnaroundTime += process[i].turnaroundTime;
		cout << process[i].id << "\t\t" << process[i].startTime << "\t\t" << process[i].completeTime << "\t\t" << process[i].turnaroundTime << endl;
	}

	averageTurnaroundTime = totalTurnaroundTime / numOfProcesses;

	cout << "Order of Execution: ";

	for (int i = 0; i < numOfProcesses; i++) {
		if (i == numOfProcesses - 1) {
			cout << "P" << process[i].id << endl;
		}
		else {
			cout << "P" << process[i].id << " -> ";
		}
	}

	cout << "Average Turnaround Time: " << averageTurnaroundTime << endl;
}

void shortestJobNext(vector<Process> process, int numOfProcesses) {

}