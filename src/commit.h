#ifndef COMMIT_H
#define COMMIT_H

void generate_hash(const char *commit_message, char *hash); //function to generate commit hash
void save_commit(const char *hash, const char *message); //function to save the commit message
void print_commit_history(); // function to print commit history

#endif
