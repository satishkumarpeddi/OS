#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    char cmd[100];

    while(1) {
        printf("\n--- UNIX File & Directory Management ---\n");
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. Copy File\n");
        printf("4. Rename File\n");
        printf("5. Create Directory\n");
        printf("6. Remove Directory\n");
        printf("7. List Files\n");
        printf("8. Show Current Directory\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter filename: ");
                scanf("%s", cmd);
                sprintf(cmd, "touch %s", cmd);
                system(cmd);
                break;

            case 2:
                printf("Enter filename: ");
                scanf("%s", cmd);
                sprintf(cmd, "rm %s", cmd);
                system(cmd);
                break;

            case 3: {
                char src[50], dest[50];
                printf("Enter source file: ");
                scanf("%s", src);
                printf("Enter destination file: ");
                scanf("%s", dest);
                sprintf(cmd, "cp %s %s", src, dest);
                system(cmd);
                break;
            }

            case 4: {
                char oldname[50], newname[50];
                printf("Enter old name: ");
                scanf("%s", oldname);
                printf("Enter new name: ");
                scanf("%s", newname);
                sprintf(cmd, "mv %s %s", oldname, newname);
                system(cmd);
                break;
            }

            case 5:
                printf("Enter directory name: ");
                scanf("%s", cmd);
                sprintf(cmd, "mkdir %s", cmd);
                system(cmd);
                break;

            case 6:
                printf("Enter directory name: ");
                scanf("%s", cmd);
                sprintf(cmd, "rmdir %s", cmd);
                system(cmd);
                break;

            case 7:
                system("ls");
                break;

            case 8:
                system("pwd");
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}