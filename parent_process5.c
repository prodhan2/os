#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Usage: %s <number_of_children> <child_1_name> <child_2_name> ...\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]); // child সংখ্যা

    if (argc != n + 2) {
        printf("Error: Number of child names doesn't match the specified count.\n");
        return 1;
    }

    printf("Parent Process Started. Name: parent_process | PID: %d\n\n", getpid());

    for (int i = 0; i < n; i++) {
        pid_t pid = fork();

        if (pid == 0) {
            // Child process
            printf("Child %d Started. Name: %s | PID: %d | PPID: %d\n", i+1, argv[i+2], getpid(), getppid());
            exit(0); // child exits
        }
        else if (pid < 0) {
            perror("Fork failed");
            return 1;
        }
        // Parent continues to create next child
    }

    // Parent waits for all children
    for (int i = 0; i < n; i++) {
        wait(NULL);
    }

    printf("\nParent Process Ends. PID: %d\n", getpid());

    return 0;
}
