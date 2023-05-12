#include<stdio.h>
#include<stdlib.h>

struct process {
    int pid;
    int burst_time;
    int arrival_time;
    int start_time;
    int finish_time;
    int remaining_time;
    int waiting_time;
};

void swap(struct process *a, struct process *b) {
    struct process temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n, i, j, time = 0, completed = 0;
    float total_waiting_time = 0, total_turnaround_time = 0;
    struct process *p;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    p = (struct process *) malloc(n * sizeof(struct process));

    printf("Enter the arrival time and burst time of each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
        p[i].pid = i + 1;
        p[i].remaining_time = p[i].burst_time;
    }

    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(p[i].arrival_time > p[j].arrival_time) {
                swap(&p[i], &p[j]);
            }
        }
    }

    printf("\nGantt Chart:\n");
    printf("  ");
    while(completed != n) {
        int min_remaining_time = 999999, min_pid = -1;
        for(i = 0; i < n; i++) {
            if(p[i].arrival_time <= time && p[i].remaining_time > 0) {
                if(p[i].remaining_time < min_remaining_time) {
                    min_remaining_time = p[i].remaining_time;
                    min_pid = i;
                }
            }
        }
        if(min_pid == -1) {
            time++;
            continue;
        }
        p[min_pid].remaining_time--;
        printf("| P%d ", p[min_pid].pid);
        if(p[min_pid].start_time == -1) {
            p[min_pid].start_time = time;
        }
        if(p[min_pid].remaining_time == 0) {
            p[min_pid].finish_time = time + 1;
            p[min_pid].waiting_time = p[min_pid].finish_time - p[min_pid].burst_time - p[min_pid].arrival_time;
            total_waiting_time += p[min_pid].waiting_time;
            total_turnaround_time += p[min_pid].finish_time - p[min_pid].arrival_time;
            completed++;
        }
        time++;
    }
    printf("|\n");

    printf("\nProcess Table:\n");
    printf("PID\tArrival Time\tBurst Time\tStart Time\tFinish Time\tWaiting Time\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].start_time, p[i].finish_time, p[i].waiting_time);
    }

    printf("\nAverage Waiting Time: %f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %f\n", total_turnaround_time / n);

    return 0;
}

