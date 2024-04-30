#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    // Create a child process
    pid_t child_pid = fork();
    if (child_pid == 0) {
        // Child process
        printf("Child process: %d\n", getpid());
        sleep(3600); // Simulate some work
        exit(0); // Exit the child process
    } else {
        // Parent process
        printf("Parent process: %d\n", getpid());
        // Simulate some work
        sleep(10);
        // Do not wait for the child process to finish
        // This will cause the child process to become a zombie
        printf("Parent process exiting...\n");
        exit(0);
    }
    return 0;
}
