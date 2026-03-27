#include <stdio.h>
#include <stdlib.h>

void viewFile() {
    char fname[100], ch;
    FILE *fp;

    printf("Enter file name to view: ");
    scanf("%s", fname);

    fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("File not found!\n");
        return;
    }

    printf("\n--- File Content ---\n");
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);

    fclose(fp);
}

void editFile() {
    char fname[100], ch;
    FILE *fp;

    printf("Enter file name to edit (append mode): ");
    scanf("%s", fname);

    fp = fopen(fname, "a");
    if (fp == NULL) {
        printf("Unable to open file!\n");
        return;
    }

    printf("Enter text to append (press # to stop):\n");
    while ((ch = getchar()) != '\n'); // clear buffer

    while ((ch = getchar()) != '#')
        fputc(ch, fp);

    fclose(fp);
}

void copyFile() {
    char src[100], dest[100], ch;
    FILE *fs, *fd;

    printf("Enter source file: ");
    scanf("%s", src);
    printf("Enter destination file: ");
    scanf("%s", dest);

    fs = fopen(src, "r");
    if (fs == NULL) {
        printf("Source file not found!\n");
        return;
    }

    fd = fopen(dest, "w");
    while ((ch = fgetc(fs)) != EOF)
        fputc(ch, fd);

    fclose(fs);
    fclose(fd);

    printf("File copied successfully.\n");
}

void moveFile() {
    char src[100], dest[100];

    printf("Enter source file: ");
    scanf("%s", src);
    printf("Enter destination file: ");
    scanf("%s", dest);

    if (rename(src, dest) == 0)
        printf("File moved/renamed successfully.\n");
    else
        printf("Error moving file.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- UNIX File Commands ---\n");
        printf("1. View File (cat)\n");
        printf("2. Edit File (append)\n");
        printf("3. Copy File (cp)\n");
        printf("4. Move/Rename File (mv)\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            viewFile();
            break;
        case 2:
            editFile();
            break;
        case 3:
            copyFile();
            break;
        case 4:
            moveFile();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
}