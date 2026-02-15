#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <algorithm>

using namespace std;

/* -------- Process Structure -------- */
struct Process {
    int pid;
    int burstTime;
    int remainingTime;
    int priority;
    int waitingTime = 0;
    int turnaroundTime = 0;
};

/* -------- Global Sync Objects -------- */
mutex cpuMutex;
condition_variable cpuCV;
bool cpuAvailable = true;

/* -------- Round Robin Scheduler -------- */
void roundRobinScheduler(vector<Process>& processes, int timeQuantum) {
    queue<int> readyQueue;

    for (int i = 0; i < processes.size(); i++)
        readyQueue.push(i);

    int currentTime = 0;

    while (!readyQueue.empty()) {
        int idx = readyQueue.front();
        readyQueue.pop();

        unique_lock<mutex> lock(cpuMutex);
        cpuCV.wait(lock, [] { return cpuAvailable; });
        cpuAvailable = false;

        int executionTime = min(timeQuantum, processes[idx].remainingTime);

        cout << "[RR] Process " << processes[idx].pid
             << " executing for " << executionTime << " units\n";

        this_thread::sleep_for(chrono::milliseconds(executionTime * 100));

        currentTime += executionTime;
        processes[idx].remainingTime -= executionTime;

        if (processes[idx].remainingTime > 0) {
            readyQueue.push(idx);
        } else {
            processes[idx].turnaroundTime = currentTime;
            processes[idx].waitingTime =
                processes[idx].turnaroundTime - processes[idx].burstTime;
        }

        cpuAvailable = true;
        lock.unlock();
        cpuCV.notify_all();
    }
}

/* -------- Priority Scheduler -------- */
void priorityScheduler(vector<Process>& processes) {
    sort(processes.begin(), processes.end(),
         [](const Process& a, const Process& b) {
             return a.priority < b.priority;
         });

    int currentTime = 0;

    for (auto& p : processes) {
        cout << "[PR] Process " << p.pid
             << " (Priority " << p.priority << ") executing\n";

        this_thread::sleep_for(chrono::milliseconds(p.burstTime * 100));

        currentTime += p.burstTime;
        p.turnaroundTime = currentTime;
        p.waitingTime = p.turnaroundTime - p.burstTime;
    }
}

/* -------- Metrics -------- */
void printMetrics(const vector<Process>& processes) {
    double totalWT = 0, totalTAT = 0;

    cout << "\nPID\tWaiting\tTurnaround\n";
    for (const auto& p : processes) {
        cout << p.pid << "\t"
             << p.waitingTime << "\t"
             << p.turnaroundTime << "\n";
        totalWT += p.waitingTime;
        totalTAT += p.turnaroundTime;
    }

    cout << "\nAverage Waiting Time: "
         << totalWT / processes.size() << endl;
    cout << "Average Turnaround Time: "
         << totalTAT / processes.size() << endl;
}

/* -------- Main -------- */
int main() {
    vector<Process> processes = {
        {1, 5, 5, 2},
        {2, 3, 3, 1},
        {3, 8, 8, 3},
        {4, 6, 6, 2}
    };

    cout << "===== ROUND ROBIN SCHEDULING =====\n";
    vector<Process> rrProcesses = processes;
    thread rrThread(roundRobinScheduler, ref(rrProcesses), 3);
    rrThread.join();
    printMetrics(rrProcesses);

    cout << "\n===== PRIORITY SCHEDULING =====\n";
    vector<Process> prProcesses = processes;
    priorityScheduler(prProcesses);
    printMetrics(prProcesses);

    return 0;
}
