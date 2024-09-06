#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

int create_directory(const char *path); // function to create directory
void build_directory_path(char *full_path, const char *base, const char *subdir); //function to build directory
int copy_file(const char *src, const char *dest); // function to copy file
int copy_directory(const char *src, const char *dest);// function to copy directory
int file_exists(const char *path); // to check if file exist or not

#endif
