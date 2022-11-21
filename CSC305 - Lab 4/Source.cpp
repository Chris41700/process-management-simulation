#include "Process.h"

int main() {
	//Number of processes for each algorithm
	int numOfProcesses = 0;

	//Prompt the user for the number of processes
	cout << "Enter the number of processes: ";
	cin >> numOfProcesses;

	//Create a vector to store each process;
	vector<Process> process(numOfProcesses);

	//Prompt the user to enter the time require for each process
	cout << "\nEnter the burst time for each process:" << endl;

	//Store the execution and assign an ID for each process
	for (int i = 0; i < numOfProcesses; i++) {
		cin >> process[i].executionTime;
		process[i].id = i + 1;
	}	

	//Prompt the user to enter the arrival time for each process
	cout << "\nEnter the arrival time for each process:" << endl;

	//Store the arrival time for each process
	for (int i = 0; i < numOfProcesses; i++) {
		cin >> process[i].startTime;
	}

	//Prompt the user to set priority for each processes
	cout << "\nEnter the priority for each process:" << endl;
	
	//Store the priority for each process
	for (int i = 0; i < numOfProcesses; i++) {
		cin >> process[i].priority;
	}

	for (int i = 0; i < numOfProcesses; i++) {
		cout << process[i].id << '\t' << process[i].executionTime << '\t' << process[i].startTime << '\t' << process[i].priority << endl;
	}

	int action;

	//User menu to choose a process management algorithm
	do {
		cout << "\n================Process Management Algorithm Menu===============" << endl;
		cout << "0 - Stop" << endl;
		cout << "1 - First Come First Serve" << endl;
		cout << "2 - Priority" << endl;
		cout << "3 - Shortest Job Next" << endl;
		cin >> action;

		//Switch statement to choose an action
		switch (action) {
		case stop:
			exit(0);
			break;
		case fcfs:
			firstComeFirstServe(process, numOfProcesses);
			break;
		case priority:
			processPriority(process, numOfProcesses);
			break;
		case sjn:
			shortestJobNext(process, numOfProcesses);
			break;
		}

	} while (action != stop);

	return 0;
}