#include <stdio.h>
#include <stdlib.h>
struct fcfs {
    int pid;
    int btime;
    int wtime;
    int ttime;
} p[10];
int main() {
    int i, n;
    int totwtime = 0, totttime = 0;
    printf("\nFCFS scheduling...\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nEnter burst time for process %d: ", p[i].pid);
        scanf("%d", &p[i].btime);
    }
    p[0].wtime = 0;
    p[0].ttime = p[0].btime;
    totttime += p[0].ttime;
    for (i = 1; i < n; i++) {
        p[i].wtime = p[i - 1].wtime + p[i - 1].btime;
        p[i].ttime = p[i].wtime + p[i].btime;
        totttime += p[i].ttime;
        totwtime += p[i].wtime;
    }
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].btime, p[i].wtime, p[i].ttime);
    }
    printf("\nTotal Waiting Time: %d\n", totwtime);
    printf("Average Waiting Time: %.2f\n", (float)totwtime / n);
    printf("Total Turnaround Time: %d\n", totttime);
    printf("Average Turnaround Time: %.2f\n", (float)totttime / n);
    return 0;
}
