#include <stdio.h>
int main()
{
	// P0, P1, P2, P3 are the Process names here

	int n, m, i, j, k;
	n = 5; // Number of processes
	m = 3; // Number of resources
	int alloc[5][3] = {
	{1,1,2},
	 { 2,1,2 }, // P0 // Allocation Matrix
						{ 3,0,1 }, // P1
						{ 0,2,0 }, // P2
						{ 1,1,2}}; // P3

	int max[5][3] = { {5,4,4},// P0 // MAX Matrix
					{ 4,3,3 }, // P1
					{ 9,1,3 }, // P2
					{ 8,6,4 }, // P3
					{ 2,2,3 } }; 

	int avail[3] = { 3,2,1}; // Available Resources

	int f[n], ans[n], ind = 0;
	for (k = 0; k < n; k++) {
		f[k] = 0;
	}
	int need[n][m];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}
	printf("Need matrix:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++){
		
			printf("%d",need[i][j]);
		}
		printf("\n");
}	
}
