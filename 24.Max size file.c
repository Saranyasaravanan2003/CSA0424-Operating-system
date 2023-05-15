#include<stdio.h>

#define BLOCK_SIZE 8192
#define POINTER_SIZE 4

int main() {
    int direct_blocks = 12;
    int single_indirect_blocks = BLOCK_SIZE/POINTER_SIZE;
    int double_indirect_blocks = single_indirect_blocks*single_indirect_blocks;
    int triple_indirect_blocks = single_indirect_blocks*double_indirect_blocks;

    // calculate the maximum file size
    long long max_size = direct_blocks*BLOCK_SIZE;
    max_size += single_indirect_blocks*BLOCK_SIZE;
    max_size += double_indirect_blocks*BLOCK_SIZE;
    max_size += triple_indirect_blocks*BLOCK_SIZE;

    // print the maximum file size
    printf("Maximum file size = %lld bytes\n", max_size);

    return 0;
}

