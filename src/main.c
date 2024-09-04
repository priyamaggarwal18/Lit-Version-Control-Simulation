#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lit.h"
#include "commit.h"

int main(int argc, char *argv[]) {
    // check if the user provided at least one command
    if (argc < 2) {
        printf("Usage: lit <command>\n");
        return 1;
    }

    // handle the 'init' command to initialize the repository
    if (strcmp(argv[1], "init") == 0) {
        lit_init(); 
    }
    // handle the ad' command to stage a file
    else if (strcmp(argv[1], "add") == 0) {
        if (argc < 3) {
            printf("Usage: lit add <file>\n");  // tell user to provide a filename when using 'add'
            return 1;
        }
        lit_add(argv[2]); 
    }

    // handle the commit command to commit staged changes with a message
    else if (strcmp(argv[1], "commit") == 0) {
        if (argc < 3) {
            printf("Usage: lit commit <message>\n");  // to tell the user to provide a commit message
            return 1;
        }
        lit_commit(argv[2]);
    }

    // handle the push command to push local changes to a remote repository
    else if (strcmp(argv[1], "push") == 0) {
        lit_push();
    }
    // handle the history command to show the commit history
    else if (strcmp(argv[1], "history") == 0) {
        print_commit_history();
    }

    // handle unknown commands
    else {
        printf("Unknown command: %s\n", argv[1]);
    }
    return 0;
}
