#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LEN 20

struct file {
    char name[MAX_FILENAME_LEN];
    int size;
};

struct file directory[MAX_FILES];
int num_files = 0;

int main() {
    int choice;
    
    do {
        printf("\nSingle-level Directory System\n");
        printf("--------------------------------\n");
        printf("1. Create a file\n");
        printf("2. Delete a file\n");
        printf("3. Display all files\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: 
                if (num_files == MAX_FILES) {
                    printf("Error: Directory is full.\n");
                    break;
                }
                
                printf("Enter file name: ");
                scanf("%s", directory[num_files].name);
                printf("Enter file size: ");
                scanf("%d", &directory[num_files].size);
                num_files++;
                printf("File created successfully.\n");
                break;
                
            case 2: 
                if (num_files == 0) {
                    printf("Error: Directory is empty.\n");
                    break;
                }
                
                char filename[MAX_FILENAME_LEN];
                printf("Enter file name: ");
                scanf("%s", filename);
                
                int i;
                for (i = 0; i < num_files; i++) {
                    if (strcmp(directory[i].name, filename) == 0) {
                        break;
                    }
                }
                
                if (i == num_files) {
                    printf("Error: File not found.\n");
                } else {
                    for (int j = i; j < num_files - 1; j++) {
                        strcpy(directory[j].name, directory[j+1].name);
                        directory[j].size = directory[j+1].size;
                    }
                    num_files--;
                    printf("File deleted successfully.\n");
                }
                break;
                
            case 3:
                if (num_files == 0) {
                    printf("Directory is empty.\n");
                    break;
                }
                
                printf("Filename\tSize\n");
                for (int i = 0; i < num_files; i++) {
                    printf("%s\t\t%d\n", directory[i].name, directory[i].size);
                }
                break;
                
            case 4:
                printf("Exiting program.\n");
                exit(0);
                
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}
