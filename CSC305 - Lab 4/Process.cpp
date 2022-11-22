#include "Process.h"

void calculateWaitingTime(vector<Process> process, int numOfProcesses) {
	//The waiting time for the first process is always 0
	process[0].waitingTime = 0;

	//Calculate the waiting time for each process
	for (int i = 1; i < numOfProcesses; i++) {
		process[i].waitingTime = process[i - 1].executionTime + process[i - 1].waitingTime;
	}
}

void firstComeFirstServe(vector<Process> process, int numOfProcesses) {
	int totalTurnaroundTime = 0;
	int averageTurnaroundTime = 0;

	//Calculate the completion and execution time for each process
	for (int i = 0; i < numOfProcesses; i++) {
		process[i].completeTime = process[i].startTime + process[i].executionTime;
	}

	//Calculate the turnaround time for each process
	for (int i = 0; i < numOfProcesses; i++) {
		process[i].turnaroundTime = process[i].completeTime - process[i].startTime;
	}

	cout << "\n===============First Come First Serve Algorithm===============" << endl;
	cout << "Processes\tArrival Time\tCompletion Time\tTurnaround Time" << endl;
	//Calculate the total turnaround time
	for (int i = 0; i < numOfProcesses; i++) {
		totalTurnaroundTime += process[i].turnaroundTime;
		cout << process[i].id << '\t' << process[i].startTime << '\t' << process[i].completeTime << '\t' << process[i].turnaroundTime << endl;
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
	cout << "\n=============================================================" << endl;
}

void processPriority(vector<Process> process, int numOfProcesses) {

}

void shortestJobNext(vector<Process> process, int numOfProcesses) {

}