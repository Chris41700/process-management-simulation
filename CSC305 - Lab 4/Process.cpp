#include "Process.h"

void Process::calculateWaitingTime(vector<Process> process, int numOfProcesses) {
	//The waiting time for the first process is always 0
	process[0].waitingTime = 0;

	//Calculate the waiting timee
	for (int i = 1; i < numOfProcesses; i++) {
		process[i].waitingTime = process[i - 1].executionTime + process[i - 1].waitingTime;
	}
}

void Process::calculateTurnaroundTime(vector<Process> process, int numOfProcesses) {
	for (int i = 0; i < numOfProcesses; i++) {

	}
} 

void Process::firstComeFirstServe(vector<Process> process, int numOfProcesses) {
	
}

void Process::processPriority(vector<Process> process, int numOfProcesses) {

}

void Process::shortestJobNext(vector<Process> process, int numOfProcesses) {

}