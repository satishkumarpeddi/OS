#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <pwd.h>
#include <time.h>

void systemInfo() {
    struct utsname sys;

    if (uname(&sys) == 0) {
        printf("\n--- System Information ---\n");
        printf("OS Name: %s\n", sys.sysname);
        printf("Node Name: %s\n", sys.nodename);
        printf("Release: %s\n", sys.release);
        printf("Version: %s\n", sys.version);
        printf("Machine: %s\n", sys.machine);
    } else {
        printf("Unable to fetch system info\n");
    }
}

void currentUser() {
    struct passwd *pw;
    pw = getpwuid(getuid());
    printf("\nCurrent User: %s\n", pw->pw_name);
}

void processID() {
    printf("\nProcess ID: %d\n", getpid());
}

void workingDirectory() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("\nCurrent Directory: %s\n", cwd);
    } else {
        perror("getcwd() error");
    }
}

void systemTime() {
    time_t t;
    time(&t);
    printf("\nSystem Time: %s", ctime(&t));
}

int main() {
    int choice;

    while (1) {
        printf("\n--- System Info Commands ---\n");
        printf("1. System Info (uname)\n");
        printf("2. Current User (whoami)\n");
        printf("3. Process ID (pid)\n");
        printf("4. Working Directory (pwd)\n");
        printf("5. System Time\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: systemInfo(); break;
            case 2: currentUser(); break;
            case 3: processID(); break;
            case 4: workingDirectory(); break;
            case 5: systemTime(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}