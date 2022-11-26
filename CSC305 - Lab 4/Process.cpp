#include "Process.h"

bool compareArrival(Process p1, Process p2) {
	return p1.arrivalTime < p2.arrivalTime;
}

void firstComeFirstServe(vector<Process> process, int numOfProcesses) {
	int totalTurnaroundTime = 0;
	int averageTurnaroundTime = 0;

	sort(process.begin(), process.end(), compareArrival);

	for (int i = 0; i < numOfProcesses; i++) {
		process[i].startTime = (i == 0) ? process[i].arrivalTime:max(process[i - 1].completeTime, process[i].arrivalTime);
		process[i].completeTime = process[i].startTime + process[i].executionTime;
		process[i].turnaroundTime = process[i].completeTime - process[i].arrivalTime;
		process[i].waitingTime = process[i].turnaroundTime - process[i].executionTime;
		totalTurnaroundTime += process[i].turnaroundTime;
	}

	cout << "\n=================First Come First Serve Algorithm=================" << endl;
	cout << "Processes\tStart Time\tCompletion Time\tTurnaround Time" << endl;
	//Calculate the total turnaround time
	for (int i = 0; i < numOfProcesses; i++) {
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

bool comparePriority(Process p1, Process p2) {
	return p1.priority < p2.priority;
}

bool compareID(Process p1, Process p2) {
	return p1.id < p2.id;
}

void priorityScheduling(vector<Process> process, int numOfProcesses) {
	int totalTurnaroundTime = 0;
	int averageTurnaroundTime = 0;

	sort(process.begin(), process.end(), compareArrival);
	sort(process.begin(), process.end(), comparePriority);

	for (int i = 0; i < numOfProcesses; i++) {
			process[i].startTime = (i == 0) ? process[i].arrivalTime : max(process[i - 1].completeTime, process[i].arrivalTime);
			process[i].completeTime = process[i].startTime + process[i].executionTime;
			process[i].turnaroundTime = process[i].completeTime - process[i].arrivalTime;
			process[i].waitingTime = process[i].turnaroundTime - process[i].executionTime;
			totalTurnaroundTime += process[i].turnaroundTime;
	}

	cout << "\n=================Priority Scheduling Algorithm=================" << endl;
	cout << "Processes\tStart Time\tCompletion Time\tTurnaround Time" << endl;
	//Calculate the total turnaround time
	for (int i = 0; i < numOfProcesses; i++) {
		//totalTurnaroundTime += process[i].turnaroundTime;
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

bool compareShortestExecution(Process p1, Process p2) {
	return p2.executionTime > p1.executionTime;
}

void shortestJobNext(vector<Process> process, int numOfProcesses) {
	int totalTurnaroundTime = 0;
	int averageTurnaroundTime = 0;

	sort(process.begin(), process.end(), compareShortestExecution);

	for (int i = 0; i < numOfProcesses; i++) {
		process[i].startTime = (i == 0) ? process[i].arrivalTime : max(process[i - 1].completeTime, process[i].arrivalTime);
		process[i].completeTime = process[i].startTime + process[i].executionTime;
		process[i].turnaroundTime = process[i].completeTime - process[i].arrivalTime;
		process[i].waitingTime = process[i].turnaroundTime - process[i].executionTime;
		totalTurnaroundTime += process[i].turnaroundTime;
	}

	cout << "\n=================Shortest Job Next Algorithm=================" << endl;
	cout << "Processes\tStart Time\tCompletion Time\tTurnaround Time" << endl;
	//Calculate the total turnaround time
	for (int i = 0; i < numOfProcesses; i++) {
		//totalTurnaroundTime += process[i].turnaroundTime;
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