#include <stdio.h>
#include <limits.h>

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
    int n;
    Process P[MAX_PROCESSES];

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

    for (int proc_i = 0; proc_i < n; proc_i++) {
        int proc = -1;
        for (int i = 0; i < n; i++) {
            if (P[i].arrival_time <= time && !P[i].served) {
                proc = i;
                break;
            }
        }
        if (proc == -1) {
            int arrival_time_min = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (P[i].arrival_time < arrival_time_min && !P[i].served) {
                    arrival_time_min = P[i].arrival_time;
                    proc = i;
                }
            }
        }

        if (P[proc].arrival_time > time) {
            time = P[proc].arrival_time;
            P[proc].waiting_time = 0;
        } else {
            P[proc].waiting_time = time - P[proc].arrival_time;
        }

        P[proc].completion_time = time + P[proc].burst_time;
        time = P[proc].completion_time;

        P[proc].served = 1;

        printf("\nProcess num. %d\n", P[proc].i);
        printf("Arrival time: %d\n", P[proc].arrival_time);
        printf("Waiting time: %d\n", P[proc].waiting_time);
        printf("Turn around time: %d\n", P[proc].completion_time - P[proc].arrival_time);

        tat_sum += P[proc].completion_time - P[proc].arrival_time;
        wt_sum += P[proc].waiting_time;
    }

    printf("\n\nAvg waiting time: %f\n", wt_sum/n);
    printf("Avg turn around time: %f\n", tat_sum/n);
}
