#include <stdio.h>

int main()
{
    int i, j, k, f, pf = 0, count = 0;
    int rs[25], m[10], n;

    printf("\nEnter the length of reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &rs[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames as empty
    for (i = 0; i < f; i++)
        m[i] = -1;

    printf("\nPage Replacement Process (FIFO):\n");

    for (i = 0; i < n; i++)
    {
        // Check if page already exists (HIT)
        for (k = 0; k < f; k++)
        {
            if (m[k] == rs[i])
                break;
        }

        // If page not found (MISS)
        if (k == f)
        {
            m[count] = rs[i];  // Replace using FIFO
            count = (count + 1) % f;  // Circular increment
            pf++;  // Page fault
        }

        // Display frame contents
        for (j = 0; j < f; j++)
            printf("\t%d", m[j]);

        // Show page fault
        if (k == f)
            printf("\tPF No. %d", pf);

        printf("\n");
    }

    printf("\nTotal Page Faults (FIFO): %d\n", pf);

    return 0;
}