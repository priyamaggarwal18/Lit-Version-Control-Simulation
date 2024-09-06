#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lit.h"
#include "file_handeling.h"
#include "commit.h"

int test_mode = 0;  // global variable to track if test mode is enabled

// function to enable test mode
void enable_test_mode() {
    test_mode = 1;
}

// function to disable test mode
void disable_test_mode() {
    test_mode = 0;
}

// function to initialize lit and making a hidden folder in local_repo
void lit_init() {
    char local_repo_path[512];
    snprintf(local_repo_path, sizeof(local_repo_path), test_mode ? "test_dir/local_repo" : "local_repo");

    // create the local repository
    if (create_directory(local_repo_path) == 0) {
        printf("Local repository initialized!\n");
    } else {
        printf("Error: Failed to create local repository.\n");
        return;
    }

    // create the .lit directory inside local_repo or test_dir/local_repo
    char lit_path[512];
    build_directory_path(lit_path, local_repo_path, ".lit");

    if (create_directory(lit_path) == 0) {
        printf(".lit directory created!\n");
    } else {
        printf("Error: Failed to create .lit directory.\n");
    }
}

// to add a file in .lit directory
void lit_add(const char *filename) {
    printf("Adding file: %s\n", filename);
    char dest_path[512];

    const char *base_repo = test_mode ? "test_dir/local_repo" : "local_repo";

    // to extract the filename from the full path
    const char *base_filename = strrchr(filename, '/');
    if (base_filename == NULL) {
        base_filename = strrchr(filename, '\\');
    }
    if (base_filename == NULL) {
        base_filename = filename;
    } else {
        base_filename++;  // skip the slash
    }

    snprintf(dest_path, sizeof(dest_path), "%s/.lit/%s", base_repo, base_filename);
    if (copy_file(filename, dest_path) == 0) {
        printf("File %s added to .lit.\n", base_filename);
    } else {
        perror("Failed to add file");
    }
}

// function to commit the staged files with a commit message
void lit_commit(const char *message) {
    printf("Committing changes...\n");
    char hash[16];
    generate_hash(message, hash);  
    save_commit(hash, message);

    printf("Commit created with hash: %s\n", hash);
}

// function to push the .lit directory to the remote_repo
void lit_push() {
    const char *base_local_repo = test_mode ? "test_dir/local_repo" : "local_repo";
    const char *base_remote_repo = test_mode ? "test_dir/remote_repo" : "remote_repo";
    char remote_lit_path[512];  // Buffer to store the remote .lit path
    char local_lit_path[512];   // Buffer to store the local .lit path

    printf("Pushing to remote repository...\n");

    // create the remote repository
    if (create_directory(base_remote_repo) == 0) {
        printf("Remote repository created!\n");
    } else {
        printf("Error: Failed to create remote repository.\n");
        return;
    }
    snprintf(remote_lit_path, sizeof(remote_lit_path), "%s/.lit", base_remote_repo);
    if (create_directory(remote_lit_path) != 0) {
        printf("Error: Failed to create remote_repo/.lit directory.\n");
        return;
    }
    
    snprintf(local_lit_path, sizeof(local_lit_path), "%s/.lit", base_local_repo);

    // copy the .lit directory from local_repo to remote_repo
    int result = copy_directory(local_lit_path, remote_lit_path);
    if (result == 0) {
        printf("Push completed successfully!\n");
    } else {
        printf("Error: Push failed during file copy.\n");
    }
}
