<div align="center">
  <img src="./images/Lit.png" alt="Lit Version Control System" />
</div>
<div align="center">
  <img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/priyamaggarwal18/Lit-Version-Control-Simulation-?style=for-the-badge&color=black">
  <img alt="GitHub Repo stars" src="https://img.shields.io/github/stars/priyamaggarwal18/Lit-Version-Control-Simulation-?style=for-the-badge&color=black">&nbsp;&nbsp;
  <img alt="GitHub forks" src="https://img.shields.io/github/forks/priyamaggarwal18/Lit-Version-Control-Simulation-?style=for-the-badge&color=black">&nbsp;&nbsp;
  <img alt="Last commit" src="https://img.shields.io/github/last-commit/priyamaggarwal18/Lit-Version-Control-Simulation-?style=for-the-badge&color=black">
<!--   <img alt="GitHub issues" src="https://img.shields.io/github/issues/priyamaggarwal18/Readme-edits?style=for-the-badge&color=black">
  <img alt="GitHub pull requests" src="https://img.shields.io/github/issues-pr/priyamaggarwal18/Readme-edits?style=for-the-badge&color=black">
  <img alt="License" src="https://img.shields.io/github/license/priyamaggarwal18/Readme-edits?style=for-the-badge&color=black">
  <img alt="GitHub contributors" src="https://img.shields.io/github/contributors/priyamaggarwal18/Readme-edits?style=for-the-badge&color=black">
<!--   <img alt="GitHub release" src="https://img.shields.io/github/v/release/priyamaggarwal18/Readme-edits?style=for-the-badge&color=black"> -->
<!--   <img alt="GitHub Build Status" src="https://img.shields.io/github/workflow/status/priyamaggarwal18/Readme-edits/Build?style=for-the-badge&color=black"> -->
</div>



# 

```Lit``` is a simple version control system simulation built using C. It provides basic functionality like initializing a repository, adding files, committing changes, pushing to a remote repository, and viewing commit history. This project is compatible with both Windows and Linux environments.
#

<br>

## Table of Contents

- [Key Features](#key-features)
- [Project Structure](#project-structure)
- [Pre Requisites](#pre-requisites)
- [Setting Up the Project](#setting-up-the-project)
- [Usage](#usage)
  - [Initialize Repository](#initialize-repository)
  - [Add Files](#add-files)
  - [Commit Changes](#commit-changes)
  - [Push to Remote Repository](#push-to-remote-repository)
  - [View Commit History](#view-commit-history)
- [Libraries Used](#libraries-used)
- [Batch file Overview](#batch-file-overview)
- [Makefile Overview](#makefile-overview)

<br>

## Key Features

- **Repository Initialization**: Creates a new `.lit` directory within the local repository to store version control data.
- **File Addition**: Stages files by adding them to the `.lit` directory inside the repository.
- **Commit System**: Commits staged files with a unique hash and a user-provided commit message.
- **Push Functionality**: Pushes committed changes from the local repository to a simulated remote repository.
- **Cross-Platform**: Compatible with both Windows and Linux environments.
- **Test Mode**: Includes an automated test suite to ensure functionality.


[🔝](#table-of-contents)

<br>

## Project Structure 

```bash
Lit-Version-Control/
├── bin/                     # Binary files (executables) (created on build)
├── obj/                     # Object files generated from source code (created on build)
├── src/                     # Source code for the project
│   ├── lit.c                # Core functionality (init, add, commit, push, history)
│   ├── file_handeling.c      # File handling functions (create, copy, check existence)
│   ├── commit.c             # Commit management (hashing, saving commits)
│   ├── main.c               # Entry point of the program
│   ├── lit.h                # Header for lit functions
│   ├── file_handeling.h      # Header for file handling functions
│   ├── commit.h             # Header for commit functions
├── test/                    # Test file
│   ├── test_lit.c           # Test suite for Lit system and different functions
├── build.bat                # Build automation for Windows
├── Makefile                 # Build automation for Linux
├── README.md                # Project documentation
```
[🔝](#table-of-contents)

## Pre Requisites

1. **GCC** (GNU Compiler Collection) for Linux or MinGW for Windows.
2. **Make** and **Batch** utility.
3. **Basic C programming knowledge**.
4. **Git**: To clone the repository and manage version control.
5. **Text Editor**: Any text editor or IDE like VSCode, Sublime Text, or Vim for editing code.
6. **Terminal/Command Prompt**: Familiarity with using a terminal or command prompt to run commands.

[🔝](#table-of-contents)

<br>

## Setting Up the Project

### 1. Clone the Repository:
    ```bash
    git clone https://github.com/your-username/Lit-Version-Control.git
    cd Lit-Version-Control
    ```
### 2. Open CLI in that folder and run the build command.
### 3. Build the Project:

For **Linux**:
```bash
make run
```

For **Windows**:
```bash
.\build.bat
```

## Usage

#### Initialize Repository

##### For Windows User
```bash
.\bin\lit.exe init
```
##### For Linux User
```bash
./bin/lit init
```

#### Add files 
##### For Windows User
```bash
.\bin\lit.exe add file_location\file_name
```
##### For Linux User
```bash
./bin/lit add file_location\file_name
```

#### Commit Changes
##### For Windows User
```bash
.\bin\lit.exe commit "Your Commit Message"
```
##### For Linux User
```bash
./bin/lit commit "Your Commit Message"
```

#### Push to Remote Repository
##### For Windows User
```bash
.\bin\lit.exe push
```
##### For Linux User
```bash
./bin/lit push
```

#### View Commit History
##### For Windows User
```bash
.\bin\lit.exe history
```
##### For Linux User
```bash
./bin/lit history
```
<br>

[🔝](#table-of-contents)
