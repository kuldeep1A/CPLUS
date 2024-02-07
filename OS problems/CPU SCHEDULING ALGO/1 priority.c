#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int pno;
    int pri;
    int btime;
    int wtime;
} sp;
int main() {
    int i, j, n;
    int tbm = 0, totwtime = 0, totttime = 0;
    sp *p, t;
    printf("\n PRIORITY SCHEDULING.\n");
    printf("\n enter the number of processes: ");
    scanf("%d", &n);
    p = (sp *)malloc(n * sizeof(sp));
    printf("enter the burst time and priority:\n");
    for (i = 0; i < n; i++) {
        printf("process %d:", i + 1);
        scanf("%d %d", &p[i].btime, &p[i].pri);
        p[i].pno = i + 1;
        p[i].wtime = 0;
    }
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].pri > p[j].pri) {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }
    printf("\n process\tburst time\twaiting time\tturnaround time\n");
    for (i = 0; i < n; i++) {
        totwtime += p[i].wtime = tbm;
        tbm += p[i].btime;
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].pno, p[i].btime, p[i].wtime, p[i].wtime + p[i].btime);
    }
    totttime = tbm;
    printf("\n total waiting time: %d\n", totwtime);
    printf(" average waiting time: %.2f\n", (float)totwtime / n);
    printf(" total turnaround time: %d\n", totttime);
    printf(" avg turnaround time: %.2f\n", (float)totttime / n);
    free(p);
    return 0;
}
