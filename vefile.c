#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int choice;
    char filename[100];

    while (1) {
        printf("\n--- UNIX Commands using execl() ---\n");
        printf("1. View File (cat)\n");
        printf("2. Edit File (nano)\n");
        printf("3. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 3)
            break;

        printf("Enter filename: ");
        scanf("%s", filename);

        pid_t pid = fork();

        if (pid == 0) {
            // Child process
            if (choice == 1) {
                execl("/bin/cat", "cat", filename, NULL);
            } 
            else if (choice == 2) {
                execl("/bin/nano", "nano", filename, NULL);
            } 
            else {
                printf("Invalid choice\n");
            }
        } 
        else {
            // Parent process waits
            wait(NULL);
        }
    }

    return 0;
}