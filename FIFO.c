#include <stdio.h>
#include <stdlib.h>

void main()
{
    int m[20], rs[10], n, f;
    int count = 0, pg = 0, k;

    printf("Enter the length of the reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &rs[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames to -1
    for (int i = 0; i < f; i++)
        m[i] = -1;

    for (int i = 0; i < n; i++)
    {
        // Check if page already exists
        for (k = 0; k < f; k++)
        {
            if (m[k] == rs[i])
                break;
        }

        // If page fault
        if (k == f)
        {
            m[count] = rs[i];
            count = (count + 1) % f;
            pg++;

            printf("Page Fault %d -> ", pg);

            for (int j = 0; j < f; j++)
                printf("%d ", m[j]);

            printf("\n");
        }
    }

    printf("\nTotal Page Faults (FIFO): %d\n", pg);
}