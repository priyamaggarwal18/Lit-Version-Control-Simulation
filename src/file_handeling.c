#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h> 
#include <errno.h>// For handeling Errors

#ifdef _WIN32 // to check if the MACRO is of windows if yes then declare for windows else declare for linux
#include <direct.h>  // for mkdir of Windows
#define MKDIR(x) _mkdir(x)
#define SEPARATOR '\\' //separator in Windows

#else
#include <unistd.h>  // For mkdir on Linux/macOS
#define MKDIR(x) mkdir(x, 0700)
#define SEPARATOR '/' //seprator in LINUX

#endif

// function created to make directories with error handling
int create_directory(const char *path) {
    printf("Attempting to create directory: %s\n", path);
    if (MKDIR(path) == 0) {
        printf("Directory created: %s\n", path);
        return 0;
    } else if (errno == EEXIST) {
        printf("Directory already exists: %s\n", path);
        return 0;
    } else {
        perror("Unable to create directory");
        return -1;
    }
}

// helper function made to handel cross platform path creation
void build_directory_path(char *full_path, const char *base, const char *subdir) {
    snprintf(full_path, 512, "%s%c%s", base, SEPARATOR, subdir);
}

// function to copy file from source to destination
int copy_file(const char *src, const char *dest) {
    FILE *sourceFile = fopen(src, "rb");
    if (!sourceFile) {
        perror("Source file not found");
        return -1;
    }

    FILE *destFile = fopen(dest, "wb");
    if (!destFile) {
        perror("Unable to open destination file");
        fclose(sourceFile);
        return -1;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
        fwrite(buffer, 1, bytes, destFile);
    }

    fclose(sourceFile);
    fclose(destFile);
    return 0;
}

// check if the file exists
int file_exists(const char *path) {
    struct stat buffer;
    return (stat(path, &buffer) == 0);
}

// function recursivly copies files from source to destination
int copy_directory(const char *src, const char *dest) {
    DIR *dir = opendir(src);
    if (!dir) {
        perror("Unable to open source directory");
        return -1;
    }

    // creats the destination directory if it does not exists
    if (create_directory(dest) != 0) {
        closedir(dir);
        return -1; 
    }

    struct dirent *entry;
    char src_path[512], dest_path[512];

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; 
        }

        // defining path from source to destination
        snprintf(src_path, sizeof(src_path), "%s/%s", src, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest, entry->d_name);

        // check if the file already exists in the destination (to prevent duplicates)
        if (file_exists(dest_path)) {
            printf("Skipping existing file: %s\n", dest_path);
            continue;
        }

        // copy the file from src to dest
        if (copy_file(src_path, dest_path) != 0) {
            printf("Failed to copy file: %s\n", entry->d_name);
            closedir(dir);
            return -1;
        }
    }

    closedir(dir);
    return 0;
}
