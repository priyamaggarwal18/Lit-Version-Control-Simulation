#ifndef FILE_HANDEL
#define FILE_HANDEL

void copy_file(const char* src,const char* dest);// copies the content of file from source file to destination file.
void copy_directory(const char* src,const char* dest);// copies the content of the directory recursively
char* hash_file(const char* file_path); //Hashes a file and returns a hashed string

#endif