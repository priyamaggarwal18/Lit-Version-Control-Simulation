#ifndef LIT_H //gaurd to avoid multiple inclusions within different header files
#define LIT_H

// declared functions for initializing, adding, committing and pushing
void lit_init();
void lit_add(const char *filename);
void lit_commit(const char *message);
void lit_push();

#endif