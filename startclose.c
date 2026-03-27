#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

// Simulating start() using fork + exec
void start_process() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Process creation failed!\n");
        return;
    }
    else if (pid == 0) {
        // Child process
        printf("Child Process Started (PID: %d)\n", getpid());
        execlp("ls", "ls", NULL);  // execute ls command
        perror("exec failed");
        exit(1);
    }
    else {
        // Parent process
        wait(NULL);
        printf("Parent Process: Child completed\n");
    }
}

// Demonstrating close() system call
void close_file() {
    int fd;
    char buffer[100];
    int n;

    fd = open("sample.txt", O_RDONLY);

    if (fd < 0) {
        printf("Error opening file!\n");
        return;
    }

    printf("File opened successfully. FD = %d\n", fd);

    n = read(fd, buffer, sizeof(buffer)-1);
    buffer[n] = '\0';

    printf("File Content:\n%s\n", buffer);

    close(fd);  // close system call
    printf("File closed successfully.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- OS Calls Menu ---\n");
        printf("1. Start Process\n");
        printf("2. Close File\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                start_process();
                break;

            case 2:
                close_file();
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}