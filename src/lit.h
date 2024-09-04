#ifndef LIT // Used guards to prevent multiple inclusions of this header file.
#define LIT 

void initialize_repo(const char*path); // to initialize repo
void add_file(const char *filename); // to add a file
void commit_changes(const char*message,const char* repo_path);// to commit a file
void push_changes(const char* local_repo,const char* remote_repo);// to push changes

#endif // Its a Good Practice to Include guards.