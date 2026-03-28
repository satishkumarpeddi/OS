#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int choice;
    char input[100];

    while (1) {
        printf("\n--- UNIX Networking Commands ---\n");
        printf("1. ping\n");
        printf("2. ifconfig\n");
        printf("3. netstat\n");
        printf("4. nslookup\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 5)
            break;

        pid_t pid = fork();

        if (pid == 0) {
            // Child process
            switch (choice) {

                case 1:
                    printf("Enter host (e.g., google.com): ");
                    scanf("%s", input);
                    execl("/bin/ping", "ping", input, NULL);
                    perror("execl failed");
                    break;

                case 2:
                    execl("/sbin/ifconfig", "ifconfig", NULL);
                    perror("execl failed");
                    break;

                case 3:
                    execl("/bin/netstat", "netstat", NULL);
                    perror("execl failed");
                    break;

                case 4:
                    printf("Enter domain: ");
                    scanf("%s", input);
                    execl("/usr/bin/nslookup", "nslookup", input, NULL);
                    perror("execl failed");
                    break;

                default:
                    printf("Invalid choice\n");
            }
        } 
        else {
            // Parent waits for child
            wait(NULL);
        }
    }

    return 0;
}