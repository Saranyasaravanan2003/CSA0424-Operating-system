#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 3
#define MAX_FILES_PER_USER 3

struct file {
    char name[30];
};

struct user_dir {
    char name[30];
    struct file files[MAX_FILES_PER_USER];
};

struct dir {
    struct user_dir user_dirs[MAX_USERS];
};

int main() {
    struct dir root_dir;
    int i, j;

    // Create user directories
    for (i = 0; i < MAX_USERS; i++) {
        struct user_dir user;
        sprintf(user.name, "user%d", i+1);
        for (j = 0; j < MAX_FILES_PER_USER; j++) {
            sprintf(user.files[j].name, "%s_file%d", user.name, j+1);
        }
        root_dir.user_dirs[i] = user;
    }

    // Print directory structure
    printf("Directory structure:\n");
    for (i = 0; i < MAX_USERS; i++) {
        struct user_dir user = root_dir.user_dirs[i];
        printf("- %s\n", user.name);
        for (j = 0; j < MAX_FILES_PER_USER; j++) {
            printf("  - %s\n", user.files[j].name);
        }
    }

    return 0;
}

