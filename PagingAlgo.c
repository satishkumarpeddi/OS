/*
    ms -> memory size
    ps -> page size
    nop -> number of pages
    np -> number of processes
    rempages -> Remaining free pages
    page[i] -> number of pages required for process i
    frame[i][j] -> frame number where page j of process i is stroed
    pno -> process number
    page -> page number
    offset -> displacement within page
    pa -> physical address


    number of page (nop) = total memory / page size
    nop = ms/ps
    logical address = (Process , Page, Offset)
*/
#include <stdio.h>

#define MAX 10

int main() {
    int ms, ps, nop, np;
    int rempages, i, j;
    int pages[MAX], frame[MAX][20];
    int pno, page, offset, pa;

    printf("\n--- PAGING TECHNIQUE ---\n");

    // Input memory and page size
    printf("Enter Memory Size: ");
    scanf("%d", &ms);

    printf("Enter Page Size: ");
    scanf("%d", &ps);

    nop = ms / ps;
    printf("Number of pages available: %d\n", nop);

    // Number of processes
    printf("Enter number of processes: ");
    scanf("%d", &np);

    rempages = nop;

    // Input for each process
    for (i = 0; i < np; i++) {
        printf("\nEnter number of pages for Process P%d: ", i);
        scanf("%d", &pages[i]);

        if (pages[i] > rempages) {
            printf("Memory Full! Cannot allocate more pages.\n");
            break;
        }

        rempages -= pages[i];

        printf("Enter page table (frame numbers) for P%d:\n", i);
        for (j = 0; j < pages[i]; j++) {
            scanf("%d", &frame[i][j]);
        }
    }

    // Logical address input
    printf("\nEnter Logical Address (Process No, Page No, Offset): ");
    scanf("%d %d %d", &pno, &page, &offset);

    // Validation
    if (pno >= np || page >= pages[pno] || offset >= ps) {
        printf("\nInvalid Process/Page/Offset!\n");
    } else {
        pa = frame[pno][page] * ps + offset;
        printf("\nPhysical Address = %d\n", pa);
    }

    return 0;
}