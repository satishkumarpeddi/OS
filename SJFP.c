#include <stdio.h>

int main() {
    int n, i, j, t = 0, completed = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], at[n], rt[n], wt[n], tat[n];
    int p[n];  // Process numbers

    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter Arrival Time for Process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];  // Remaining time initialized
    }

    int min_rem_time;
    int process_index;
    int flag;

    float total_wt = 0, total_tat = 0;

    printf("\nGantt Chart (Process execution over time):\n");

    while (completed != n) {
        min_rem_time = 100000; // a large number
        process_index = -1;
        flag = 0;

        // Find process with minimum remaining time at current time
        for (i = 0; i < n; i++) {
            if (at[i] <= t && rt[i] > 0 && rt[i] < min_rem_time) {
                min_rem_time = rt[i];
                process_index = i;
                flag = 1;
            }
        }

        if (flag == 0) {
            t++; // No process ready, idle time
            continue;
        }

        // Execute process for 1 time unit
        rt[process_index]--;
        printf("P%d ", p[process_index]);

        // If process finished
        if (rt[process_index] == 0) {
            completed++;
            tat[process_index] = t + 1 - at[process_index];
            wt[process_index] = tat[process_index] - bt[process_index];
            total_wt += wt[process_index];
            total_tat += tat[process_index];
        }
        t++;
    }

    printf("\n\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);
    printf("Average Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}