cmake_minimum_required(VERSION 3.14)
project(MultithreadedSearchUtility)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(inc)

# Source files
set(SRC_FILES
    src/FileHandler.cpp
    src/SearchEngine.cpp
    src/ThreadPool.cpp
    src/main.cpp
)

# Add the main executable
add_executable(search_utility ${SRC_FILES})

# =================== Tests ===================

enable_testing()

# Add test executable
add_executable(test_search
    tests/test_search.cpp
)

# Link mocks and core
target_include_directories(test_search PRIVATE include tests)
target_link_libraries(test_search pthread)

add_test(NAME SearchTest COMMAND test_search)