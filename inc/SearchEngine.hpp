#ifndef SEARCHENGINE_HPP
#define SEARCHENGINE_HPP

#include "FileHandler.hpp"
#include "ThreadPool.hpp"
#include <memory>
#include <string>

class SearchEngine {
public:
    SearchEngine(std::shared_ptr<FileHandler> file_handler, size_t num_threads);
    void search(const std::string& query, const std::string& directory);

private:
    void process_file(const std::string& file, const std::string& query);
    std::shared_ptr<FileHandler> file_handler_;
    ThreadPool thread_pool_;
};

#endif // SEARCHENGINE_HPP