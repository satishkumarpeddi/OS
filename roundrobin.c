#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;        // Process ID
    int atime;      // Arrival Time
    int btime;      // Burst Time
    int rtime;      // Remaining Time
    int wtime;      // Waiting Time
    int ctime;      // Completion Time
    int tatime;     // Turnaround Time
} Process;

int main() {
    int n, tq, t = 0, completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process *p = (Process*)malloc(n * sizeof(Process));

    // Input
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;

        printf("Enter Arrival Time for Process %d: ", i + 1);
        scanf("%d", &p[i].atime);

        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &p[i].btime);

        p[i].rtime = p[i].btime;
        p[i].wtime = 0;
        p[i].ctime = 0;
        p[i].tatime = 0;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    printf("\nGantt Chart:\n");

    while (completed < n) {
        int done = 1;

        for (int i = 0; i < n; i++) {

            if (p[i].rtime > 0 && p[i].atime <= t) {
                done = 0;

                printf("P%d ", p[i].pid);

                if (p[i].rtime > tq) {
                    t += tq;
                    p[i].rtime -= tq;
                } else {
                    t += p[i].rtime;
                    p[i].rtime = 0;

                    p[i].ctime = t;
                    p[i].tatime = p[i].ctime - p[i].atime;
                    p[i].wtime = p[i].tatime - p[i].btime;

                    completed++;
                }
            }
        }

        // If no process is ready
        if (done)
            t++;
    }

    // Output
    printf("\n\nProcess\tAT\tBT\tWT\tTAT\n");

    float total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].atime, p[i].btime,
               p[i].wtime, p[i].tatime);

        total_wt += p[i].wtime;
        total_tat += p[i].tatime;
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    free(p);
    return 0;
}