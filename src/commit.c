#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "commit.h"

extern int test_mode;  // test mode flag

// function to generate a hash value of a commit based on time
void generate_hash(const char *commit_message, char *hash) {
    time_t current_time = time(NULL);
    snprintf(hash, 16, "%lx%lx", (unsigned long)current_time, (unsigned long)strlen(commit_message));
}

// save the commit in commit history
void save_commit(const char *hash, const char *message) {
    char commit_file_path[512];
    const char *base_repo = test_mode ? "test_dir/local_repo/.lit" : "local_repo/.lit";
    snprintf(commit_file_path, sizeof(commit_file_path), "%s/commit_history.txt", base_repo);
    FILE *commit_file = fopen(commit_file_path, "a");
    if (!commit_file) {
        perror("Failed to open commit history file");
        return;
    }

    // making a format to write in the commit history file
    time_t current_time = time(NULL);
    fprintf(commit_file, "Commit: %s\nMessage: %s\nTime: %s\n\n", hash, message, ctime(&current_time));

    fclose(commit_file);
    printf("Commit saved to %s\n", commit_file_path);
}


// function to print the commit history
void print_commit_history() {
    char commit_file_path[512];
    const char *base_repo = test_mode ? "test_dir/local_repo/.lit" : "local_repo/.lit";
    snprintf(commit_file_path, sizeof(commit_file_path), "%s/commit_history.txt", base_repo);
    FILE *commit_file = fopen(commit_file_path, "r");
    if (!commit_file) {
        perror("Failed to open commit history file");
        return;
    }

    // read and print each line from the file
    char line[256];
    while (fgets(line, sizeof(line), commit_file)) {
        printf("%s", line);
    }

    fclose(commit_file);
}