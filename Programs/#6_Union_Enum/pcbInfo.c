#include <stdio.h>
/*
Process Control Block (PCB):
A Process Control Block (PCB) is a data structure used by operating systems to store information about a running process. This information includes the process's state, program counter, CPU registers, and other relevant data. Since different types of processes might have varying attributes, a union can be employed within the PCB to optimize memory usage.

In this example, the specificData union within the PCB allows the system to store different types of information based on the process's context:

If the process is a file-based application, the fileDescriptor integer can be used to store the file descriptor associated with the process.

If the process is a memory-bound application, the memoryInfo struct can be used to store details about the process's memory allocation.

If the process is a network application, the networkInfo struct can be used to store information about the process's network connections.

By using a union for specificData, the operating system ensures that only the relevant data structure is allocated memory for each process, optimizing memory usage while providing a consistent interface for accessing process-specific information.
*/
typedef struct {
    int processID;
    int priority;
    union {
        int fileDescriptor;
        struct {
            int baseAddress;
            int limit;
        } memoryInfo;
        struct {
            int openSockets;
            int connectionStatus;
        } networkInfo;
    } specificData;
} PCB;

void displayPCBInfo(PCB pcb) {
    printf("Process ID: %d\n", pcb.processID);
    printf("Priority: %d\n", pcb.priority);

    if (pcb.specificData.fileDescriptor) {
        printf("File Descriptor: %d\n", pcb.specificData.fileDescriptor);
    } else if (pcb.specificData.memoryInfo.baseAddress) {
        printf("Base Address: %d\n", pcb.specificData.memoryInfo.baseAddress);
        printf("Memory Limit: %d\n", pcb.specificData.memoryInfo.limit);
    } else if (pcb.specificData.networkInfo.openSockets) {
        printf("Open Sockets: %d\n", pcb.specificData.networkInfo.openSockets);
        printf("Connection Status: %d\n", pcb.specificData.networkInfo.connectionStatus);
    } else {
        printf("No specific data available.\n");
    }
}

int main() {
    PCB process1 = {1, 10, {123}};
    PCB process2 = {2, 5, .specificData.memoryInfo = {4096, 8192}};
    PCB process3 = {3, 8, .specificData.networkInfo = {3, 1}};

    printf("Process 1:\n");
    displayPCBInfo(process1);

    printf("\nProcess 2:\n");
    displayPCBInfo(process2);

    printf("\nProcess 3:\n");
    displayPCBInfo(process3);

    return 0;
}
/*
In this example, I've created three PCB instances (process1, process2, and process3) with different types of information stored in their specificData unions. The displayPCBInfo function takes a PCB as input and uses the union to determine which type of information is stored and prints it accordingly.
*/
