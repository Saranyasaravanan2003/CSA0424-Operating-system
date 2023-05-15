#include <stdio.h>
int i;
void worst_fit(int mem[], int n, int process[], int m)
{
    int i, j, index;
    for (i = 0; i < m; i++) {
        index = -1;
        for (j = 0; j < n; j++) {
            if (mem[j] >= process[i]) {
                if (index == -1) {
                    index = j;
                } else if (mem[index] < mem[j]) {
                    index = j;
                }
            }
        }
        if (index != -1) {
            mem[index] -= process[i];
            printf("Process %d allocated to partition %d\n", i+1, index+1);
        } else {
            printf("Process %d cannot be allocated\n", i+1);
        }
    }
}

int main()
{
    int n = 6; // number of memory partitions
    int m = 5; // number of processes
    int mem[] = {300, 600, 350, 200, 750, 125}; // memory partitions in KB
    int process[] = {115, 500, 358, 200, 375}; // processes in KB

    printf("Memory partitions:\n");
    for ( i = 0; i < n; i++) {
        printf("%d KB\t", mem[i]);
    }
    printf("\n");

    printf("Processes:\n");
    for ( i = 0; i < m; i++) {
        printf("%d KB\t", process[i]);
    }
    printf("\n");

    worst_fit(mem, n, process, m);

    return 0;
}

