#include <stdio.h>

int main()
{
    int i, j, min;
    int rs[25], m[10], count[10], flag[25];
    int n, f, pf = 0, next = 1;

    printf("Enter the length of reference string -- ");
    scanf("%d", &n);

    printf("Enter the reference string -- ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &rs[i]);
    }

    printf("Enter the number of frames -- ");
    scanf("%d", &f);

    // Initialize memory and counters
    for (i = 0; i < f; i++)
    {
        m[i] = -1;
        count[i] = 0;
    }

    printf("\nThe Page Replacement process is -- \n");

    for (i = 0; i < n; i++)
    {
        flag[i] = 0;   // 🔥 FIX: Reset flag for each iteration

        // Check if page already in memory (HIT)
        for (j = 0; j < f; j++)
        {
            if (m[j] == rs[i])
            {
                flag[i] = 1;
                count[j] = next++;
                break;
            }
        }

        // If page not found (PAGE FAULT)
        if (flag[i] == 0)
        {
            if (i < f)
            {
                m[i] = rs[i];
                count[i] = next++;
            }
            else
            {
                min = 0;
                for (j = 1; j < f; j++)
                {
                    if (count[j] < count[min])
                        min = j;
                }

                m[min] = rs[i];
                count[min] = next++;
            }

            pf++;
        }

        // Print frames
        for (j = 0; j < f; j++)
            printf("%d\t", m[j]);

        if (flag[i] == 0)
            printf("PF No. -- %d", pf);

        printf("\n");
    }

    printf("\nThe number of page faults using LRU are %d\n", pf);

    return 0;
}