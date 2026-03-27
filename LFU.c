#include <stdio.h>

int main() {
    int rs[30], st[10], freq[10], time[10];
    int n, f, i, j, k, pf = 0, count = 0;

    printf("Enter number of references: ");
    scanf("%d", &n);

    printf("Enter reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &rs[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames
    for (i = 0; i < f; i++) {
        st[i] = -1;
        freq[i] = 0;
        time[i] = 0;
    }

    printf("\nPage Replacement Process:\n");

    for (i = 0; i < n; i++) {
        int found = -1;

        // 🔍 Check if page is already in frame
        for (j = 0; j < f; j++) {
            if (st[j] == rs[i]) {
                found = j;
                break;
            }
        }

        // ✅ If HIT
        if (found != -1) {
            freq[found]++;
        }
        // ❌ If PAGE FAULT
        else {
            int pos = 0;

            // Find LFU page
            for (j = 1; j < f; j++) {
                if (freq[j] < freq[pos] ||
                   (freq[j] == freq[pos] && time[j] < time[pos])) {
                    pos = j;
                }
            }

            st[pos] = rs[i];
            freq[pos] = 1;
            time[pos] = ++count;
            pf++;
        }

        // Print frames
        for (j = 0; j < f; j++)
            printf("%d\t", st[j]);

        if (found == -1)
            printf("PF No. %d", pf);

        printf("\n");
    }

    printf("\nTotal Page Faults (LFU): %d\n", pf);

    return 0;
}