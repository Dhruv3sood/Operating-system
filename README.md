# OperatingSystem
This project focuses on solving the Dining Philosophers Problem, a classic synchronization problem in computer science, and implementing inter-process communication techniques using Unix domain sockets, FIFOs, and shared memory. The project consists of two main parts: resolving deadlock in the dining philosophers scenario and implementing a communication mechanism between two programs, P1 and P2, using different IPC techniques.

Part 1: Dining Philosophers Problem
The dining philosophers problem involves five philosophers sitting at a round table, alternating between eating and thinking. However, if the philosophers have unrestricted access to the forks (resources), it may lead to a deadlock situation. This project aims to simulate the philosophers using threads and resolve the deadlock using two techniques:

Strict Ordering of Resource Requests: Implement strict ordering of resource requests to prevent deadlock by allowing philosophers to acquire the forks in a specific order.
Utilization of Semaphores: Use semaphores to control access to the forks, ensuring that philosophers can only acquire the necessary resources and release them when finished.
Part 2: Inter-Process Communication (IPC)
The second part of the project involves implementing a communication mechanism between two programs, P1 and P2, using three different IPC techniques: Unix domain sockets, FIFOs, and shared memory. The objective is to exchange data between P1 and P2 in a coordinated manner.

Unix Domain Sockets: Implement IPC using Unix domain sockets to establish a communication channel between P1 and P2. P1 generates an array of random strings and sends a group of five consecutive elements to P2 along with their corresponding IDs. P2 receives the strings and sends back the highest received ID as an acknowledgment to P1. P2 then prints the IDs and strings on the console. P1 continues sending the next group of strings starting from the successor of the acknowledged ID until all strings have been acknowledged.
FIFOs: Implement IPC using FIFOs (named pipes) to facilitate communication between P1 and P2. Follow a similar process as in Unix domain sockets, with P1 sending strings and IDs to P2, and P2 acknowledging the received strings by sending back the highest ID.
Shared Memory: Implement IPC using shared memory to establish a shared memory region between P1 and P2. P1 writes the array of random strings to shared memory and sends the corresponding IDs to P2. P2 reads the strings from shared memory, prints the IDs and strings, and acknowledges by sending back the highest received ID.
Implementation Time Analysis
Measure and record the time required to finish receiving the acknowledgment of all 50 strings for each of the three IPC techniques mentioned above. Compare and analyze the performance of the different techniques based on their execution time.

Kernel Module
In addition to the IPC implementations, the project requires the development of a kernel module. The kernel module implements a system call that reads the entries of the process task_struct for a given process and prints the values of the following fields: pid, user id, process group id (pgid), and command path. The system call is functional only when the module is loaded, providing valuable information about a specific process.

By combining the resolution of the Dining Philosophers Problem and the implementation of different IPC techniques, this project showcases knowledge and proficiency in synchronization, inter-process communication, and kernel module development.
