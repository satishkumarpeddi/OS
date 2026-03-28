#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;        // Process ID
    int atime;      // Arrival time
    int btime;      // Burst time
    int rtime;      // Remaining time
    int wtime;      // Waiting time
    int ctime;      // Completion time
    int tatime;     // Turnaround time
} Process;

int main() {
    int n, i, completed = 0, t = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process *p = (Process*)malloc(n * sizeof(Process));
    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time for Process %d: ", i + 1);
        scanf("%d", &p[i].atime);
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &p[i].btime);
        p[i].rtime = p[i].btime; // initialize remaining time
        p[i].wtime = 0;
        p[i].ctime = 0;
        p[i].tatime = 0;
    }

    printf("\nGantt Chart (process execution over time):\n");

    while (completed != n) {
        int min_rtime = 100000; // large number
        int idx = -1;

        // find process with shortest remaining time among arrived processes
        for (i = 0; i < n; i++) {
            if (p[i].atime <= t && p[i].rtime > 0 && p[i].rtime < min_rtime) {
                min_rtime = p[i].rtime;
                idx = i;
            }
        }

        if (idx == -1) { // no process ready
            t++;
            continue;
        }

        // execute process for 1 time unit
        printf("P%d ", p[idx].pid);
        p[idx].rtime--;
        t++;

        // if process completes
        if (p[idx].rtime == 0) {
            completed++;
            p[idx].ctime = t;
            p[idx].tatime = p[idx].ctime - p[idx].atime;
            p[idx].wtime = p[idx].tatime - p[idx].btime;
        }
    }

    printf("\n\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
    float total_wt = 0, total_tat = 0;
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].atime, p[i].btime, p[i].wtime, p[i].tatime);
        total_wt += p[i].wtime;
        total_tat += p[i].tatime;
    }

    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);
    printf("Average Turnaround Time = %.2f\n", total_tat / n);

    free(p);
    return 0;
}