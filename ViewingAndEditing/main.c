#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void searchPattern() {
    char fname[100], pattern[100], line[200];
    FILE *fp;

    printf("Enter file name: ");
    scanf("%s", fname);

    printf("Enter pattern to search: ");
    scanf("%s", pattern);

    fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("File not found!\n");
        return;
    }

    printf("\n--- Matching Lines ---\n");
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, pattern)) {
            printf("%s", line);
        }
    }

    fclose(fp);
}

void wordCount() {
    char fname[100], ch;
    FILE *fp;
    int lines = 0, words = 0, chars = 0;

    printf("Enter file name: ");
    scanf("%s", fname);

    fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("File not found!\n");
        return;
    }

    while ((ch = fgetc(fp)) != EOF) {
        chars++;
        if (ch == '\n')
            lines++;
        if (ch == ' ' || ch == '\n')
            words++;
    }

    fclose(fp);

    printf("\nLines: %d\nWords: %d\nCharacters: %d\n", lines, words, chars);
}

void filterLines() {
    char fname[100], line[200];
    FILE *fp;
    int minLength;

    printf("Enter file name: ");
    scanf("%s", fname);

    printf("Enter minimum line length: ");
    scanf("%d", &minLength);

    fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("File not found!\n");
        return;
    }

    printf("\n--- Filtered Lines ---\n");
    while (fgets(line, sizeof(line), fp)) {
        if (strlen(line) >= minLength) {
            printf("%s", line);
        }
    }

    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        printf("\n--- UNIX Search & Filter Commands ---\n");
        printf("1. Search Pattern (grep)\n");
        printf("2. Word Count (wc)\n");
        printf("3. Filter Lines by Length\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            searchPattern();
            break;
        case 2:
            wordCount();
            break;
        case 3:
            filterLines();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}