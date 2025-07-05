#include "SearchEngine.hpp"
#include <iostream>

SearchEngine::SearchEngine(std::shared_ptr<FileHandler> file_handler, size_t num_threads)
    : file_handler_(file_handler), thread_pool_(num_threads) {}

void SearchEngine::search(const std::string& query, const std::string& directory)
{
    auto files = file_handler_->list_files_recursively(directory);
    for (const auto& file : files)
    {
        thread_pool_.enqueue([=]() { process_file(file, query); });
    }
}

void SearchEngine::process_file(const std::string& file, const std::string& query)
{
    auto lines = file_handler_->read_file_lines(file);
    for (size_t i = 0; i < lines.size(); ++i) 
    {
        if (lines[i].find(query) != std::string::npos)
        {
            std::lock_guard<std::mutex> lock(console_mutex);
            std::cout << file << ":" << i + 1 << ": " << lines[i] << std::endl;
        }
    }
}

std::mutex console_mutex;

