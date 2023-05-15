#include<stdio.h>
#include<stdbool.h>
//  To find the waiting time 

void findWaitingTime(int processes[], int n,
			int bt[], int wt[], int quantum)
{
	//Store remaining burst time
	int rem_bt[n],i;
	for ( i = 0 ; i < n ; i++)
		rem_bt[i] = bt[i];

	int t = 0; // Current time
	while (1)
	{
		bool done = true;
		for ( i = 0 ; i < n; i++)
		{
			
			if (rem_bt[i] > 0)
			{
				done = false; // pending process

				if (rem_bt[i] > quantum)
				{
				
					t += quantum;

					
					rem_bt[i] -= quantum;
				}
				else
				{
					t = t + rem_bt[i];

					// Waiting time = current time- time
					// used in this process
					wt[i] = t - bt[i];
                    //process is fully executed
					rem_bt[i] = 0;
				}
			}
		}

		
		if (done == true)
		break;
	}
}

//  Calculate the turnaround time
void findTurnAroundTime(int processes[], int n,
						int bt[], int wt[], int tat[])
{    int i;
	
	for (i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}

//Calculate the average time
void findavgTime(int processes[], int n, int bt[],
									int quantum)
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;

	//  Find waiting time of all processes
	findWaitingTime(processes, n, bt, wt, quantum);

	//Find turn around time for all processes
	findTurnAroundTime(processes, n, bt, wt, tat);

	printf( "PN   ");
	printf( "BT   ");
    printf("WT"); 
    printf("TAT\n");
	int i;
	for ( i=0; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		printf("%d   %d    %d    %d\n " ,i+1 , bt[i] ,wt[i] , tat[i]);
			}

	printf("Average waiting time =%f\n", (float)total_wt / (float)n);
	printf( "\nAverage turn around time =%f ",(float)total_tat / (float)n);
}

int main()
{
	
	int processes[] = { 1, 2, 3};
	int n = sizeof processes / sizeof processes[0];

	// Burst time of all processes
	int burst_time[] = {24,3,3};
	int quantum = 2;
	findavgTime(processes, n, burst_time, quantum);
	return 0;
}


