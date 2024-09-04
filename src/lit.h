#ifndef LIT_H
#define LIT_H

// Function declarations for initializing, adding, committing, and pushing
void lit_init();
void lit_add(const char *filename);
void lit_commit(const char *message);
void lit_push();

#endif
