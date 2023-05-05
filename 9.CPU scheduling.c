#include<stdio.h>

int main() {
   int i,n = 3; // number of processes
   int bt[] = {2, 4, 8}; // burst times of the processes
   int wt[n], tat[n], total_wt = 0, total_tat = 0;

   wt[0] = 0; // waiting time of first process is 0

   // calculating waiting time of each process
   for(i = 1; i < n; i++) {
      wt[i] = bt[i-1] + wt[i-1];
   }

   // calculating turnaround time of each process
   for( i = 0; i < n; i++) {
      tat[i] = bt[i] + wt[i];
   }

   // calculating total waiting time and total turnaround time
   for(i = 0; i < n; i++) {
      total_wt += wt[i];
      total_tat += tat[i];
   }

   // calculating average waiting time and average turnaround time
   float avg_wt = (float)total_wt/n;
   float avg_tat = (float)total_tat/n;

   // printing results
   printf("Average Waiting Time: %.2f\n", avg_wt);
   printf("Average Turnaround Time: %.2f", avg_tat);

   return 0;
}
