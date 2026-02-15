Multithreaded CPU Scheduler Simulator

A C++ project that simulates core Operating System CPU scheduling algorithms using multithreading and synchronization primitives. The project focuses on process scheduling logic, concurrency, and performance analysis, implemented using modern C++ (C++17).

Project Overview

This simulator models how an operating system schedules processes on a CPU using classic scheduling strategies. It demonstrates how different algorithms impact system performance metrics such as waiting time and turnaround time.

The implementation is platform-independent and focuses on operating system concepts rather than OS-specific internals.

Scheduling Algorithms Implemented
Round Robin Scheduling

Time-sharing based scheduling

Fixed time quantum

Simulates preemption and fair CPU allocation

Priority Scheduling

Processes executed based on priority

Lower numerical value indicates higher priority

Suitable for latency-sensitive workloads

Key Concepts Demonstrated

Operating Systems: CPU Scheduling

Multithreading using std::thread

Synchronization using std::mutex and std::condition_variable

Shared resource coordination (CPU availability)

Performance metric computation:

Waiting Time

Turnaround Time

Comparative analysis of scheduling strategies

Sample Output Metrics

The simulator computes and compares scheduler performance:

Round Robin

Average Waiting Time: 10 units

Average Turnaround Time: 15.5 units

Priority Scheduling

Average Waiting Time: 6.25 units

Average Turnaround Time: 11.75 units

This reflects a 37.5% reduction in average waiting time under Priority Scheduling compared to Round Robin for the same workload.

Tech Stack

Language: C++ (C++17)

Concurrency: C++ Standard Library Threads

Compiler: GCC

Environment: MSYS2 MinGW64 (Windows)

How to Build and Run
Prerequisites

C++17 compatible compiler (GCC / Clang / MSVC)

Thread support enabled

Build
g++ -std=c++17 scheduler.cpp -o scheduler -pthread

Run
./scheduler

Project Structure
CPU_Scheduler_Simulator/
│
├── scheduler.cpp   # Main implementation
├── README.md       # Project documentation
└── .vscode/        # Optional editor configuration

Learning Outcomes

This project strengthened my understanding of:

CPU scheduling mechanisms beyond theoretical concepts

Practical multithreading and synchronization in C++

Performance evaluation and trade-off analysis

Designing clean and modular system simulations

Possible Extensions

Add First Come First Serve (FCFS) scheduling

Implement aging to prevent starvation

Simulate I/O wait and CPU idle time

Visualize scheduling timelines

License

This project is intended for academic and learning purposes.
