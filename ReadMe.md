Multithreaded Grep-like Utility in C++ (No )

Overview

This project is a C++ implementation of a grep-like command-line utility. It recursively searches for a given query string in all files under a specified directory. The tool uses POSIX directory traversal functions (opendir, readdir) to avoid C++17's <filesystem>. To speed up the search, the implementation uses multithreading with a thread pool to utilize all CPU cores.

Features

Recursive directory traversal

String matching in regular files

Multithreaded file processing

Fast and scalable (parallel file reading and searching)

Outputs matched lines to the console

Usage

./grep_utility <query_string> <directory_path>

Example

./grep_utility TODO ./my_project

Design

Components

Directory Walker

Uses opendir() and readdir() to recursively traverse a directory tree.

Filters out . and .., skips symbolic links.

Work Queue

A thread-safe queue of file paths to be searched.

Thread Pool

A fixed number of worker threads equal to hardware concurrency.

Each thread dequeues a file path and searches for the query string.

Searcher

Reads each file line-by-line using std::ifstream.

Prints matching lines to the console along with the file path and line number.

Threading Model

The main thread performs directory traversal.

Worker threads consume files from the queue and search them in parallel.

Synchronization

A std::mutex protects shared resources (queue, output).

std::condition_variable handles waiting when the queue is empty.

Error Handling

Skips unreadable files and outputs a warning.

Ignores symbolic links and directories.

Limitations

Only supports basic string matching (no regex).

Does not handle binary files specially.

Assumes UTF-8 encoded text files.

Tests

Test Plan

Create a test directory tree:

Contains text files with and without the query string

Includes subdirectories, symbolic links, and non-readable files

Run the utility and verify console output manually or via redirection.

Example Test

mkdir -p testdir/subdir
echo "TODO: implement function" > testdir/file1.txt
echo "nothing here" > testdir/file2.txt
echo "TODO: add unit test" > testdir/subdir/file3.txt
./grep_utility TODO testdir

Expected Output:

testdir/file1.txt:1: TODO: implement function
testdir/subdir/file3.txt:1: TODO: add unit test

Build

g++ -std=c++17 -pthread grep_utility.cpp -o grep_utility

Conclusion

This project demonstrates a performant, multithreaded text search utility using low-level POSIX directory functions and modern C++ concurrency tools. It's designed to be fast, simple, and compatible with systems that do not support <filesystem>.

