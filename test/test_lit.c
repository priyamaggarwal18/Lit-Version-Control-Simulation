#include <stdio.h>
#include <assert.h>
#include <time.h>
#include "../src/file_handeling.h"
#include "../src/commit.h"
#include "../src/lit.h"

//include library for windows
#ifdef _WIN32
#include <windows.h>
#define sleep(seconds) Sleep((seconds) * 1000)  // Convert seconds to milliseconds

#else
//include library for linux
#include <unistd.h>
#endif

void test_create_directory() {
    printf("Testing create_directory...\n");
    sleep(1);
    assert(create_directory("test_dir") == 0);
    assert(create_directory("test_dir") == 0); // Directory already exists
    assert(create_directory("") == -1);        // Invalid directory creation
    printf("Passed create_directory tests!\n");
    sleep(1);
}

void test_copy_file() {
    printf("Testing copy_file...\n");
    sleep(1);
    FILE *src = fopen("test_src.txt", "w");
    fprintf(src, "This is a test file.");
    fclose(src);

    assert(copy_file("test_src.txt", "test_dest.txt") == 0);  // Valid file copy
    assert(copy_file("nonexistent.txt", "test_dest.txt") == -1);  // Nonexistent file
    printf("Passed copy_file tests!\n");
    sleep(1);

    remove("test_src.txt");
    remove("test_dest.txt");
}

void test_file_exists() {
    printf("Testing file_exists...\n");
    sleep(1);
    FILE *test_file = fopen("test_exists.txt", "w");
    fclose(test_file);

    assert(file_exists("test_exists.txt") == 1);  // File exists
    assert(file_exists("nonexistent.txt") == 0);  // File doesn't exist

    printf("Passed file_exists tests!\n");
    sleep(1);

    remove("test_exists.txt");
}

void test_commit_functions() {
    printf("Testing commit functions...\n");
    sleep(1);
    char hash[16];
    generate_hash("Test commit", hash);
    assert(hash[0] != '\0');

    save_commit(hash, "Test commit message");
    print_commit_history();

    printf("Passed commit function tests!\n");
    sleep(1);
}

void test_lit_system() {
    printf("Testing Lit system functions...\n");
    sleep(1);

    lit_init();
    
    FILE *f1 = fopen("local_repo/test1.txt", "w");
    fprintf(f1, "Test file 1 contents");
    fclose(f1);
    lit_add("local_repo/test1.txt");

    FILE *f2 = fopen("local_repo/test2.txt", "w");
    fprintf(f2, "Test file 2 contents");
    fclose(f2);
    lit_add("local_repo/test2.txt");

    lit_commit("Initial commit with test1.txt and test2.txt");
    lit_push();
    lit_history();

    printf("Passed Lit system tests!\n");
    sleep(1);
}

int main() {
    test_create_directory();
    test_copy_file();
    test_file_exists();
    test_commit_functions();
    test_lit_system();

    printf("All tests passed!\nLit it now🔥!");
    sleep(1);
    return 0;
}
