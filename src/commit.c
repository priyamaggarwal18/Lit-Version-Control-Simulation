#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "commit.h"

// function to generate a hash value of a commit based on time
void generate_hash(const char *commit_message, char *hash) {
    time_t current_time = time(NULL);
    snprintf(hash, 16, "%lx%lx", (unsigned long)current_time, (unsigned long)strlen(commit_message));
}

// save the commit hash and message to the commit history file
void save_commit(const char *hash, const char *message) {
    char commit_file[512];
    snprintf(commit_file, sizeof(commit_file), "local_repo/.lit/commit_history.txt");

    FILE *file = fopen(commit_file, "a");
    if (!file) {
        perror("Failed to open commit history file");
        return;
    }
    time_t current_time = time(NULL);
    fprintf(file, "Commit: %s\nMessage: %s\nTime: %s\n\n", hash, message, ctime(&current_time));
    fclose(file);
}

// function to print the commit history
void print_commit_history() {
    char commit_file[512];
    snprintf(commit_file, sizeof(commit_file), "local_repo/.lit/commit_history.txt");

    FILE *file = fopen(commit_file, "r");
    if (!file) {
        perror("Failed to open commit history file");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}
