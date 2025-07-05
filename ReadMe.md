# Multithreaded Grep-like Utility in C++

## Overview

This project is a C++ implementation of a grep-like command-line utility. It recursively searches for a given query string in all files under a specified directory. To speed up the search, the implementation uses multithreading with a thread pool to utilize all CPU cores.


## Features

- **Multithreaded**: Utilizes all CPU cores using a thread pool.
- **Testable**: Abstracted file system interaction allows mocking and unit testing.
- **Modular**: Clean separation between components (I/O, threading, logic).
- **Cross-platform**: Uses standard C++17 and STL only.

## Software Design

### 1. **SearchEngine**

- Orchestrates the search operation.
- Accepts a `FileHandler` and a number of threads.
- Submits file search jobs to the thread pool.
- Avoids direct file system access for better testability.

```cpp
SearchEngine engine(file_handler, std::thread::hardware_concurrency());
engine.search("query", "directory");
```

### 2. **FileHandler (Interface)**

- Abstract class defining the API for file operations:
  - Listing files recursively.
  - Reading a file’s contents line by line.

- Two implementations:
  - `RealFileHandler` for actual filesystem usage.
  - `MockFileHandler` for testing with in-memory data.

### 3. **ThreadPool**

- Manages a fixed number of worker threads.
- Accepts jobs using `enqueue()`.
- Gracefully shuts down on destruction.

### 4. **MockFileHandler**

- Used in tests to simulate file contents.
- Enables fast and deterministic unit tests without real file access.

```cpp
mock_handler->file_contents = {
    { "file1.txt", { "line1", "line2", "search here" } },
    { "file2.txt", { "nothing", "to", "see" } }
};
```

---

## Directory Structure

```
.
├── include/
│   ├── FileHandler.hpp
│   ├── SearchEngine.hpp
│   └── ThreadPool.hpp
├── src/
│   ├── FileHandler.cpp
│   ├── SearchEngine.cpp
│   ├── ThreadPool.cpp
│   └── main.cpp
├── tests/
│   ├── test_search.cpp
│   └── mock_filehandler.hpp
├── CMakeLists.txt
└── README.md
```

---
## Outputs matched lines to the console

### Usage

./search_utility <query_string> <directory_path>

### Example

./search_utility TODO ./my_project

## Build & Run

### Prerequisites

- C++17-compatible compiler (GCC, Clang, MSVC)
- CMake ≥ 3.14
- Git (for cloning dependencies)

### Build Instructions

```bash
git clone <your-repo-url>
cd MultithreadedSearchUtility
mkdir build && cd build
cmake ..
make

