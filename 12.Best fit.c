#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 6
#define UNUSED -1

// Function to perform Best-Fit Allocation
void bestFitAllocation(int processSize[], int m, int blockSizes[], int n)
{
    int allocation[MAX_SIZE]; // To store block id assigned to each process
    int i, j;

    // Initialize all allocations as unused
    for(i = 0; i < MAX_SIZE; i++)
        allocation[i] = UNUSED;

    // Traverse each process and find the best fit block for it
    for(i = 0; i < m; i++)
    {
        // Find the best fit block for current process
        int bestFitBlockIndex = -1;
        for(j = 0; j < n; j++)
        {
            if(blockSizes[j] >= processSize[i])
            {
                if(bestFitBlockIndex == -1)
                    bestFitBlockIndex = j;
                else if(blockSizes[bestFitBlockIndex] > blockSizes[j])
                    bestFitBlockIndex = j;
            }
        }

        // If we could find a block for current process
        if(bestFitBlockIndex != -1)
        {
            allocation[i] = bestFitBlockIndex;
            blockSizes[bestFitBlockIndex] -= processSize[i];
        }
    }

    // Print the allocation details
    printf("\nProcess No.\tProcess Size\tBlock No.\tBlock Size\n");
    for(i = 0; i < m; i++)
    {
        printf("%d\t\t%d\t\t", i+1, processSize[i]);
        if(allocation[i] != UNUSED)
            printf("%d\t\t%d\n", allocation[i]+1, blockSizes[allocation[i]]);
        else
            printf("Not Allocated\n");
    }
}

int main()
{
    int processSize[] = {115, 500, 358, 200, 375};
    int blockSizes[] = {300, 600, 350, 200, 750, 125};
    int m = sizeof(processSize) / sizeof(processSize[0]);
    int n = sizeof(blockSizes) / sizeof(blockSizes[0]);
	int i;
    printf("Memory partitions: ");
    for( i=0; i<n; i++)
        printf("%d KB ", blockSizes[i]);
    printf("\n");

    printf("Process Sizes: ");
    for(i=0; i<m; i++)
        printf("%d KB ", processSize[i]);
    printf("\n");

    bestFitAllocation(processSize, m, blockSizes, n);

    return 0;
}

