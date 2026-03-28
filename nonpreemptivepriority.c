#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;        // Process ID
    int atime;      // Arrival Time
    int btime;      // Burst Time
    int priority;   // Priority
    int wtime;      // Waiting Time
    int ctime;      // Completion Time
    int tatime;     // Turnaround Time
    int completed;  // Status flag
} Process;

int main() {
    int n, i, completed = 0, t = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process *p = (Process*)malloc(n * sizeof(Process));

    // Input
    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;

        printf("Enter Arrival Time for Process %d: ", i + 1);
        scanf("%d", &p[i].atime);

        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &p[i].btime);

        printf("Enter Priority for Process %d: ", i + 1);
        scanf("%d", &p[i].priority);

        p[i].completed = 0;
        p[i].wtime = 0;
        p[i].ctime = 0;
        p[i].tatime = 0;
    }

    printf("\nGantt Chart:\n");

    while (completed != n) {
        int idx = -1;
        int highest_priority = 100000;

        // Select highest priority process among arrived & not completed
        for (i = 0; i < n; i++) {
            if (p[i].atime <= t && p[i].completed == 0) {
                if (p[i].priority < highest_priority) {
                    highest_priority = p[i].priority;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            t++; // CPU idle
            continue;
        }

        // Execute process completely (NON-PREEMPTIVE)
        printf("P%d ", p[idx].pid);
        t += p[idx].btime;

        p[idx].ctime = t;
        p[idx].tatime = p[idx].ctime - p[idx].atime;
        p[idx].wtime = p[idx].tatime - p[idx].btime;
        p[idx].completed = 1;

        completed++;
    }

    // Output
    printf("\n\nProcess\tAT\tBT\tPriority\tWT\tTAT\n");

    float total_wt = 0, total_tat = 0;

    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n",
               p[i].pid, p[i].atime, p[i].btime,
               p[i].priority, p[i].wtime, p[i].tatime);

        total_wt += p[i].wtime;
        total_tat += p[i].tatime;
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    free(p);
    return 0;
}