#include "Process.h"

bool compareArrival(Process p1, Process p2) {
	return p1.arrivalTime < p2.arrivalTime;
}

void firstComeFirstServe(vector<Process> process, int numOfProcesses) {
	int totalTurnaroundTime = 0;
	int averageTurnaroundTime = 0;

	//Sort from arrival time
	sort(process.begin(), process.end(), compareArrival);

	//Compute start, completion, turnaround, and waiting time of each process
	for (int i = 0; i < numOfProcesses; i++) {
		process[i].startTime = (i == 0) ? process[i].arrivalTime:max(process[i - 1].completeTime, process[i].arrivalTime);
		process[i].completeTime = process[i].startTime + process[i].executionTime;
		process[i].turnaroundTime = process[i].completeTime - process[i].arrivalTime;
		process[i].waitingTime = process[i].turnaroundTime - process[i].executionTime;
		totalTurnaroundTime += process[i].turnaroundTime;
	}

	cout << "\n=================First Come First Serve Algorithm=================" << endl;
	cout << "Processes\tStart Time\tCompletion Time\tTurnaround Time" << endl;
	//Print each process
	for (int i = 0; i < numOfProcesses; i++) {
		cout << process[i].id << "\t\t" << process[i].startTime << "\t\t" << process[i].completeTime << "\t\t" << process[i].turnaroundTime << endl;
	}
	
	//Calculate average turnaround time for all processes
	averageTurnaroundTime = totalTurnaroundTime / numOfProcesses;

	cout << "Order of Execution: ";

	//Display process order of execution in the queue
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

//Return the priority that is higher
bool comparePriority(Process p1, Process p2) {
	return p1.priority < p2.priority;
}

//Return starter id
bool compareID(Process p1, Process p2) {
	return p1.id < p2.id;
}

//Check if execution of process is complete
bool isCompleted(vector<Process> process, int n) {
	int completed = true;
	
	for (int i = 0; i < n; i++) {
		if (process[i].executionTime > 0) {
			completed = false;
			break;
		}
	}

	return completed;

}

void priorityScheduling(vector<Process> process, int numOfProcesses) {
	double totalTurnaroundTime = 0;
	double averageTurnaroundTime = 0;
	int time = 0;
	int highest = 0;
	int idx = 1;
	string order = "";
	bool running = !isCompleted(process, numOfProcesses);
	int currentProcess = 0;

	//Start of the queue
	while (running) {
		int count = 0;
		highest = 999;
		//Iterate through the number of processes
		for (int i = 0; i < numOfProcesses; i++) {

			//Increment the count
			if (process[i].executionTime > 0 && process[i].arrivalTime <= time) {
				count++;

				//Set the current process as the highest priority
				if (process[i].priority < highest) {
					highest = process[i].priority;
				}
			}
		}
		if (count > 0) {
			bool ran = false;

			//Excute each process
			for (int i = 0; i < numOfProcesses; i++) {
				if (process[i].priority == highest && !ran && process[i].arrivalTime <= time) {
					if (process[i].executionTime > 0) {
						//Store the process order of execution
						if (i != currentProcess) {
							order = order + "P" + to_string(process[i].id) + " -> ";
						}
						//The process start time will be the current time
						if (process[i].startTime == 0) {
							process[i].startTime = time;
						}
						//Decrement the process execution time
						process[i].executionTime--;
						currentProcess = i;
						//Store the process completion time
						if (process[i].executionTime == 0) {
							process[i].completeTime = time + 1;
							idx++;
						}
						ran = true;

					}
				}
			}
		}
		//Increment the time
		time++;
		//Break once all processes are completed
		if (isCompleted(process, numOfProcesses)) {
			break;
		}
	} 

	//Calculate the turnaround time for each process and total turnaround time
	for (int i = 0; i < numOfProcesses; i++) {
		process[i].turnaroundTime = process[i].completeTime - process[i].arrivalTime;
		totalTurnaroundTime += process[i].turnaroundTime;
	}
	for (int i = 0; i < numOfProcesses; i++) {
		for (int j = 0; j < numOfProcesses; j++) {
			if (process[i].startTime < process[j].startTime) {
				Process temp = process[i];
				process[i] = process[j];
				process[j] = temp;
			}
		}
	}

	//Sort processes from ID
	sort(process.begin(), process.end(), compareID);

	cout << "\n=================Priority Scheduling Algorithm=================" << endl;
	cout << "Processes\tStart Time\tCompletion Time\tTurnaround Time" << endl;
	
	//Display each process id, start time, completion time, and turnaround time
	for (int i = 0; i < numOfProcesses; i++) {
		cout << process[i].id << "\t\t" << process[i].startTime << "\t\t" << process[i].completeTime << "\t\t" << process[i].turnaroundTime << endl;
	}

	//Calculate average turnaround time for all processes
	averageTurnaroundTime = totalTurnaroundTime / numOfProcesses;

	cout << "Order of Execution: " << order << endl;
	cout << "Average Turnaround Time: " << averageTurnaroundTime << endl;
}

//Returns the shorter execution time between the two processes
bool compareShortestExecution(Process p1, Process p2) {
	return p2.executionTime > p1.executionTime;
}

void shortestJobNext(vector<Process> process, int numOfProcesses) {
	double totalTurnaroundTime = 0;
	double averageTurnaroundTime = 0;
	int time = 0;
	int idx = 0;
	bool completed = !isCompleted(process, numOfProcesses);
	int initialShortest = 999;
	int indexc[5];
	string order = "";
	while (completed) {
		int shortest = initialShortest;

		//Iterate through the number of processes
		for (int i = 0; i < numOfProcesses; i++) {
			if (process[i].executionTime > 0 && process[i].arrivalTime <= time) {
				if (process[i].executionTime < shortest) {
					shortest = process[i].executionTime;
					idx = i;
				}
			}
		}

		//Execute each process with the shortest execution time
		if (shortest != initialShortest) {
			if (process[idx].executionTime > 0) {
				process[idx].startTime = time;
				time += process[idx].executionTime;
				process[idx].completeTime = time;
				indexc[idx] = idx + 1;
				process[idx].executionTime = 0;
				order = order + "P" + to_string(indexc[idx]) + " -> ";
			}
		}
		else {
			//Increment the timer
			time++;
		}
		//Break once all processes are executed
		if (isCompleted(process, numOfProcesses)) {
			break;
		}
	}
	//Calculate the turnaround time and total turnaround time of all processes
	for (int i = 0; i < numOfProcesses; i++) {
		process[i].turnaroundTime = process[i].completeTime - process[i].arrivalTime;
		totalTurnaroundTime += process[i].turnaroundTime;
	}
	for (int i = 0; i < numOfProcesses; i++) {
		for (int j = 0; j < numOfProcesses; j++) {
			if (process[i].startTime < process[j].startTime) {
				Process temp = process[i];
				process[i] = process[j];
				process[j] = temp;
			}
		}
	}

	//Sort the processes from id
	sort(process.begin(), process.end(), compareID);

	cout << "\n=================Shortest Job Next Algorithm=================" << endl;
	cout << "Processes\tStart Time\tCompletion Time\tTurnaround Time" << endl;
	//Display the process id, start time, completion time, and turnaround time of each process
	for (int i = 0; i < numOfProcesses; i++) {
		cout << process[i].id << "\t\t" << process[i].startTime << "\t\t" << process[i].completeTime << "\t\t" << process[i].turnaroundTime << endl;
	}

	//Calculate the average turnaround time for all processes
	averageTurnaroundTime = totalTurnaroundTime / numOfProcesses;

	cout << "Order of Execution: " << order << endl;
	cout << "Average Turnaround Time: " << averageTurnaroundTime << endl;
}