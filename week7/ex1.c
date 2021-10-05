/*
 * Round robin algorithm.
 *
 * It got rid of the disadvantages of the greedy algorithm,
 * so each process gets an equal amount of CPU time, that makes round-robin the most efficient on big numbers of processes.
 * But for little numbers it could be less efficient (depending on the quantum factor).
 */

#include <stdio.h>
#include <limits.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX_PROCESSES 100

typedef struct Process{
    int i;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int completion_time;
    int served;
} Process;

int main(){
    int n, q;
    Process P[MAX_PROCESSES];

    printf("Quantum: ");
    scanf("%d",&q);

    printf("Number of processes: ");
    scanf("%d",&n);

    for (int i = 0; i < n; i++) {
        printf("\nProcess num. %d\n", i);
        printf("Arrival time: ");
        scanf("%d", &P[i].arrival_time);
        printf("Burst time: ");
        scanf("%d", &P[i].burst_time);
        P[i].served = 0;
        P[i].i = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (P[j].burst_time > P[j+1].burst_time){
                Process t = P[j];
                P[j] = P[j+1];
                P[j+1] = t;
            }
        }
    }

    int time = 0;

    float tat_sum = 0;
    float wt_sum = 0;

    int prev_proc = -1;

    printf("\nP#\tAT\tBT\tCT\tTAT\tWT");
    int loop = 1;
    while (loop) {
        int proc = -1;
        for (int i = 0; i < n; i++) {
            if (P[i].arrival_time <= time && P[i].served < P[i].burst_time) {
                proc = i;
                break;
            }
        }
        if (proc == -1) {
            int arrival_time_min = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (P[i].arrival_time < arrival_time_min && P[i].served < P[i].burst_time) {
                    arrival_time_min = P[i].arrival_time;
                    proc = i;
                }
            }
        }

        if (P[proc].arrival_time > time || prev_proc == P[proc].i) {
            time = P[proc].arrival_time;
            P[proc].waiting_time = 0;
        } else {
            P[proc].waiting_time = time - P[proc].arrival_time - P[proc].served;
        }

        P[proc].completion_time = time + MIN(P[proc].burst_time - P[proc].served, q);
        time = P[proc].completion_time;

        int served_now = MIN(P[proc].burst_time - P[proc].served, q);

        P[proc].served += served_now;

        printf("\n%d\t%d\t%d\t%d\t%d\t%d", P[proc].i, P[proc].arrival_time, P[proc].burst_time, P[proc].completion_time, served_now + P[proc].waiting_time, P[proc].waiting_time);

        tat_sum += served_now + P[proc].waiting_time;
        wt_sum += P[proc].waiting_time;

        prev_proc = P[proc].i;

        if (P[proc].served < P[proc].burst_time) {
            Process t = P[proc];
            for (int i = proc; i < n-1; i++) {
                P[i] = P[i+1];
            }
            P[n-1] = t;
        }

        loop = 0;
        for (int i = 0; i < n; i++) {
            if (P[i].served < P[i].burst_time) {
                loop = 1;
                break;
            }
        }
    }

    printf("\n\nAvg waiting time: %f\n", wt_sum/n);
    printf("Avg turn around time: %f\n", tat_sum/n);
}
