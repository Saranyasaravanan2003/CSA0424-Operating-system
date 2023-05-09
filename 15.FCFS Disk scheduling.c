#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_REQUESTS 100

int main() {
    int requests[MAX_REQUESTS];
    int num_requests = 0;
    int current_pos = 0;
    int total_head_movement = 0;
    
    // read input from user
    printf("Enter the number of tracks: ");
    int num_tracks;
    scanf("%d", &num_tracks);
    
    printf("Enter the track requests (enter -1 to stop):\n");
    int request;
    scanf("%d", &request);
    while (request != -1 && num_requests < MAX_REQUESTS) {
        requests[num_requests] = request;
        num_requests++;
        scanf("%d", &request);
    }
    
    // add initial position to requests
    requests[num_requests] = current_pos;
    num_requests++;
    
    // execute FCFS algorithm
    for (int i = 0; i < num_requests-1; i++) {
        int diff = abs(requests[i+1] - requests[i]);
        total_head_movement += diff;
        printf("Moved from %d to %d, head movement = %d\n", requests[i], requests[i+1], diff);
    }
    
    // calculate and print average head movement
    double avg_head_movement = (double) total_head_movement / (num_requests-1);
    printf("\nTotal head movement: %d\n", total_head_movement);
    printf("Average head movement: %.2f\n", avg_head_movement);
    
    return 0;
}
