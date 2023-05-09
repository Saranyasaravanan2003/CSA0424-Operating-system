#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FRAMES 3
#define MAX_REF_STR_LEN 20

int main() {
    int frames[MAX_FRAMES] = {-1, -1, -1};
    int page_faults = 0;
    int ref_str[MAX_REF_STR_LEN] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int ref_str_len = 20;
    int frame_index = 0;
    int ref_str_index = 0;
    
    while (ref_str_index < ref_str_len) {
        int page = ref_str[ref_str_index];
        bool found = false;
        
        // check if page is already in a frame
        for (int i = 0; i < MAX_FRAMES; i++) {
            if (frames[i] == page) {
                found = true;
                break;
            }
        }
        
        // if page not found, find the page that won't be used for longest time
        if (!found) {
            int farthest = ref_str_index;
            int farthest_frame = 0;
            for (int i = 0; i < MAX_FRAMES; i++) {
                int j;
                for (j = ref_str_index+1; j < ref_str_len; j++) {
                    if (frames[i] == ref_str[j]) {
                        if (j > farthest) {
                            farthest = j;
                            farthest_frame = i;
                        }
                        break;
                    }
                }
                if (j == ref_str_len) {
                    farthest_frame = i;
                    break;
                }
            }
            
            frames[farthest_frame] = page;
            page_faults++;
        }
        
        printf("Page %d: ", page);
        for (int i = 0; i < MAX_FRAMES; i++) {
            printf("%d ", frames[i]);
        }
        printf("\n");
        
        ref_str_index++;
    }
    
    printf("\nTotal page faults: %d\n", page_faults);
    
    return 0;
}
