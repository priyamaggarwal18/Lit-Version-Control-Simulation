#ifndef LIT_H
#define LIT_H

// function declarations for initializing, adding, committing, and pushing
void lit_init();
void lit_add(const char *filename);
void lit_commit(const char *message);
void lit_push();

//enable and disable test mode
void enable_test_mode();
void disable_test_mode();

#endif