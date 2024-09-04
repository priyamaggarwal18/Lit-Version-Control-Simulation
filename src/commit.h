#ifndef COMMIT_H //gaurd for avoiding multiple inclusions
#define COMMIT_H

// function to generate a hash value which is similiar to a commit id in git
void generate_hash(const char *commit_message, char *hash);

// function that will maintain the logs of commits
void save_commit(const char *hash, const char *message);

// function to print my commit history
void print_commit_history();

#endif
