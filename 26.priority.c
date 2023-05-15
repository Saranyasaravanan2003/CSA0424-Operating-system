#include<stdio.h>

struct process {
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

int main() {
    struct process p[3];
    float avg_waiting_time = 0.0, avg_turnaround_time = 0.0;
	int j,i;
    // initialize the processes
    p[0].burst_time = 30;
    p[0].priority = 2;
    p[1].burst_time = 5;
    p[1].priority = 1;
    p[2].burst_time = 12;
    p[2].priority = 3;

    // sort the processes by priority
    for(i = 0; i < 3; i++) {
        for(j = i+1; j < 3; j++) {
            if(p[i].priority > p[j].priority) {
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // calculate waiting time and turnaround time for each process
    p[0].waiting_time = 0;
    p[0].turnaround_time = p[0].burst_time;
    for( i = 1; i < 3; i++) {
        p[i].waiting_time = p[i-1].turnaround_time;
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }

    // calculate the average waiting time and average turnaround time
    for( i = 0; i < 3; i++) {
        avg_waiting_time += p[i].waiting_time;
        avg_turnaround_time += p[i].turnaround_time;
    }
    avg_waiting_time /= 3.0;
    avg_turnaround_time /= 3.0;

    // print the results
    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < 3; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i+1, p[i].burst_time, p[i].priority, p[i].waiting_time, p[i].turnaround_time);
    }
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}

