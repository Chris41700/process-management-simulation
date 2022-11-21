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

	//Store the 
	for (int i = 0; i < numOfProcesses; i++) {
		cin >> process[i].executionTime;
		process[i].id = i + 1;
	}
}