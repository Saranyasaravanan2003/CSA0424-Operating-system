#include<stdio.h>
#include<stdlib.h>

int main() {
    int i,j,n = 5, head_pos = 50, total_distance = 0;
    int tracks[] = {55, 58, 60, 70, 18};

    // sort the tracks in increasing order
    for( i = 0; i < n-1; i++) {
        for( j = i+1; j < n; j++) {
            if(tracks[i] > tracks[j]) {
                int temp = tracks[i];
                tracks[i] = tracks[j];
                tracks[j] = temp;
            }
        }
    }

    // find the position of the head in the sorted list
    for(i = 0; i < n; i++) {
        if(head_pos < tracks[i]) {
            break;
        }
    }

    // determine the direction of movement
    int direction = (i == n) ? -1 : 1;

    // initialize the current track position
    int current_pos = (direction == 1) ? i : i-1;

    // move the head from the current position to the nearest end
    while(current_pos >= 0 && current_pos < n) {
        total_distance += abs(head_pos - tracks[current_pos]);
        head_pos = tracks[current_pos];
        current_pos += direction;
    }

    // print the total head movement
    printf("Total head movement = %d\n", total_distance);
    printf("Average head movement = %.2f\n", (float)total_distance/n);

    return 0;
}

