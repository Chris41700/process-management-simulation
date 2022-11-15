#include "Process.h"

int main() {
	//Number of processes for each algorithm
	int numOfProcesses = 0;

	//Prompt the user for the number of processes
	cout << "Enter the number of processes: ";
	cin >> numOfProcesses;

	//Create a vector to store each process;
	vector<Process> process(numOfProcesses);

	cout << "\nEnter the burst time for each process:" << endl;

	//Store the pid for each process
	for (int i = 0; i < numOfProcesses; i++) {
		process[i].id = i + 1;
	}
}