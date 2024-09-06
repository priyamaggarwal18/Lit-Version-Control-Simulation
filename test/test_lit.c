#include <stdio.h>
#include <assert.h>
#include <time.h>
#include "../src/file_handeling.h"
#include "../src/commit.h"
#include "../src/lit.h"

// include windows 
#ifdef _WIN32
#include <windows.h>
#define sleep(seconds) Sleep((seconds) * 1000)  // Convert seconds to milliseconds

#else
// include LINUX library
#include <unistd.h>
#endif

// test for directory creation
void test_create_directory() {
    printf("Testing create_directory...\n");
    sleep(1);
    assert(create_directory("test_dir") == 0);  // Should create directory successfully
    assert(create_directory("test_dir") == 0);  // Directory already exists, no failure
    assert(create_directory("") == -1);         // Invalid directory, should fail
    printf("Passed create_directory tests!\n");
    sleep(1);
}

// test for file copying
void test_copy_file() {
    printf("Testing copy_file...\n");
    sleep(1);
    
    // creating the source file for testing
    FILE *src = fopen("test_src.txt", "w");
    fprintf(src, "This is a test file.");
    fclose(src);

    // test the copy file functionality
    assert(copy_file("test_src.txt", "test_dest.txt") == 0);      // Valid file copy
    assert(copy_file("nonexistent.txt", "test_dest.txt") == -1);  // Nonexistent file copy, should fail
    printf("Passed copy_file tests!\n");
    sleep(1);

    // clean up the test files
    remove("test_src.txt");
    remove("test_dest.txt");
}

// testing the file existence
void test_file_exists() {
    printf("Testing file_exists...\n");
    sleep(1);

    // create a file for testing
    FILE *test_file = fopen("test_exists.txt", "w");
    fclose(test_file);

    assert(file_exists("test_exists.txt") == 1);  // File exists
    assert(file_exists("nonexistent.txt") == 0);  // File doesn't exist

    printf("Passed file_exists tests!\n");
    sleep(1);

    // Clean up test file
    remove("test_exists.txt");
}

// test for commit functionality
void test_commit_functions() {
    printf("Testing commit functions...\n");
    sleep(1);

    char hash[16];
    generate_hash("Test commit", hash);
    assert(hash[0] != '\0');

    save_commit(hash, "Test commit message");

    printf("Commit saved. Checking commit history...\n");
    print_commit_history();
}

// testing the entire lit
void test_lit_system() {
    printf("Testing Lit system functions...\n");
    sleep(1);

    // initializing the repository
    lit_init();

    FILE *f1 = fopen("test_dir/local_repo/test1.txt", "w");
    fprintf(f1, "Test file 1 contents");
    fclose(f1);
    lit_add("test_dir/local_repo/test1.txt");

    FILE *f2 = fopen("test_dir/local_repo/test2.txt", "w");
    fprintf(f2, "Test file 2 contents");
    fclose(f2);
    lit_add("test_dir/local_repo/test2.txt");

    // commit and push changes
    lit_commit("Initial commit with test1.txt and test2.txt");
    lit_push();

    // print the commit history
    print_commit_history();

    printf("Passed Lit system tests!\n");
    sleep(1);
}

int main() {
    // enable the test mode
    enable_test_mode();

    test_create_directory();
    test_copy_file();
    test_file_exists();
    test_commit_functions();
    test_lit_system();

    // disable test mode
    disable_test_mode();

    printf("All tests passed!\nLit it now!\n");
    sleep(1);
    return 0;
}
