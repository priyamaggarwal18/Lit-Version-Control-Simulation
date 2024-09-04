#ifndef FILE_HANDELING_H
#define FILE_HANDELING_H

// declarations for file and directory handling
int create_directory(const char *path);
void build_directory_path(char *full_path, const char *base, const char *subdir);
int copy_file(const char *src, const char *dest);
int copy_directory(const char *src, const char *dest);
int file_exists(const char *path);

#endif
