#include <stdio.h>

int main() {
    int i, j, min, n, f, pf = 0, next = 1;
    int rs[25], m[10], count[10];

    printf("Enter the length of reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &rs[i]);

    printf("Enter the number of frames: ");
    scanf("%d", &f);

    // Initialize frames and counters
    for (i = 0; i < f; i++) {
        m[i] = -1;
        count[i] = 0;
    }

    printf("\nPage Replacement Process:\n");

    for (i = 0; i < n; i++) {
        int found = 0;

        // Check if page already exists
        for (j = 0; j < f; j++) {
            if (m[j] == rs[i]) {
                found = 1;
                count[j] = next++;
                break;
            }
        }

        // If page not found → Page Fault
        if (!found) {
            int pos;

            // If empty frame exists
            for (j = 0; j < f; j++) {
                if (m[j] == -1) {
                    pos = j;
                    break;
                }
            }

            // If all frames filled → Replace LRU
            if (j == f) {
                pos = 0;
                for (j = 1; j < f; j++) {
                    if (count[j] < count[pos])
                        pos = j;
                }
            }

            m[pos] = rs[i];
            count[pos] = next++;
            pf++;
        }

        // Print frame status
        for (j = 0; j < f; j++)
            printf("%d\t", m[j]);

        if (!found)
            printf("PF No. -- %d", pf);

        printf("\n");
    }

    printf("\nTotal Page Faults (LRU): %d\n", pf);

    return 0;
}