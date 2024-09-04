#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lit.h"
#include "file_handeling.h"
#include "commit.h"

// function to initialize lit and making a hidden folder in local_repo
void lit_init() {
    char local_repo_path[512];
    snprintf(local_repo_path, sizeof(local_repo_path), "local_repo");

    // to create the local repository
    if (create_directory(local_repo_path) == 0) {
        printf("Local repository initialized!\n");
    } else {
        printf("Error: Failed to create local repository.\n");
        return;
    }

    // to create the .lit directory inside local_repo
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

    snprintf(dest_path, sizeof(dest_path), "local_repo/.lit/%s", base_filename);
    if (copy_file(filename, dest_path) == 0) {
        printf("File %s added to .lit.\n", base_filename);
    } else {
        perror("Failed to add file");
    }
}

// function used to commit the staged files with a commit message
void lit_commit(const char *message) {
    printf("Committing changes...\n");
    char hash[16];
    generate_hash(message, hash);  
    save_commit(hash, message);

    printf("Commit created with hash: %s\n", hash);
}

// function to push the .lit directory to the remote_repo

void lit_push() {
    printf("Pushing to remote repository...\n");
    if (create_directory("remote_repo") == 0) {
        printf("Remote repository created!\n");
    } else {
        printf("Error: Failed to create remote repository.\n");
        return; 
    }

    // to create .lit directory inside remote_repo
    if (create_directory("remote_repo/.lit") != 0) {
        printf("Error: Failed to create remote_repo/.lit directory.\n");
        return;
    }

    // to copy the .lit directory from local_repo to remote_repo
    int result = copy_directory("local_repo/.lit", "remote_repo/.lit");
    if (result == 0) {
        printf("Push completed successfully!\n");
    } else {
        printf("Error: Push failed during file copy.\n");
    }
}
