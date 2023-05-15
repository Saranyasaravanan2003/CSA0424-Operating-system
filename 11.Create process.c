#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
int i;
void print_odds() {
    printf("Printing odd numbers (PID %d):\n", GetCurrentProcessId());
    for( i=1; i<=10; i+=2) {
        printf("%d ", i);
    }
    printf("\n");
}

void print_evens() {
    printf("Printing even numbers (PID %d):\n", GetCurrentProcessId());
    for( i=2; i<=10; i+=2) {
        printf("%d ", i);
    }
    printf("\n");
}

void print_multiples_of_three() {
    printf("Printing multiples of 3 (PID %d):\n", GetCurrentProcessId());
    for( i=3; i<=30; i+=3) {
        printf("%d ", i);
    }
    printf("\n");
}

void print_multiples_of_five() {
    printf("Printing multiples of 5 (PID %d):\n", GetCurrentProcessId());
    for(i=5; i<=50; i+=5) {
        printf("%d ", i);
    }
    printf("\n");
}

int main() {
    HANDLE h[4];
    DWORD pid[4];

    h[0] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)print_odds, NULL, 0, &pid[0]);
    h[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)print_evens, NULL, 0, &pid[1]);
    h[2] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)print_multiples_of_three, NULL, 0, &pid[2]);
    h[3] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)print_multiples_of_five, NULL, 0, &pid[3]);

    // Wait for all threads to finish
    WaitForMultipleObjects(4, h, TRUE, INFINITE);

    // Close thread handles
    for( i=0; i<4; i++) {
        CloseHandle(h[i]);
    }

    // Print process IDs of all threads
    printf("Parent process (PID %d) created 4 child processes with PIDs %d, %d, %d, %d.\n", GetCurrentProcessId(), pid[0], pid[1], pid[2], pid[3]);

    return 0;
}

