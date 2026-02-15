# Multithreaded CPU Scheduler Simulator

A C++ project that simulates core CPU scheduling algorithms to demonstrate Operating System concepts such as process scheduling, concurrency, and performance evaluation.

---

## Overview

This project models how an operating system schedules processes on a CPU using classic scheduling strategies. It compares different algorithms by analyzing key performance metrics like waiting time and turnaround time.

The implementation focuses on **OS fundamentals and multithreading**, without relying on any OS-specific internals.

---

## Scheduling Algorithms

- **Round Robin Scheduling**
  - Time-sliced execution using a fixed time quantum
  - Ensures fair CPU sharing among processes

- **Priority Scheduling**
  - Processes executed based on priority
  - Lower value indicates higher priority
  - Useful for latency-sensitive workloads

---

## Concepts Covered

- CPU Scheduling (Operating Systems)
- Multithreading using `std::thread`
- Synchronization using `std::mutex` and `std::condition_variable`
- Shared resource coordination
- Performance metrics:
  - Waiting Time
  - Turnaround Time
- Comparative analysis of scheduling strategies

---

## Sample Results

For the same workload, the simulator produced the following results:

**Round Robin**
- Average Waiting Time: 10 units
- Average Turnaround Time: 15.5 units

**Priority Scheduling**
- Average Waiting Time: 6.25 units
- Average Turnaround Time: 11.75 units

This shows a **37.5% reduction in average waiting time** using Priority Scheduling compared to Round Robin.

---

## Tech Stack

- Language: C++ (C++17)
- Concurrency: C++ Standard Library Threads
- Compiler: GCC
- Environment: MSYS2 MinGW64 (Windows)

---

## Build and Run

### Requirements
- C++17 compatible compiler
- Thread support enabled

### Compile
```bash
g++ -std=c++17 scheduler.cpp -o scheduler -pthread


