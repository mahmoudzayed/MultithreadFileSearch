#ifndef MOCK_FILEHANDLER_HPP
#define MOCK_FILEHANDLER_HPP

#include "FileHandler.hpp"
#include <unordered_map>

class MockFileHandler : public FileHandler {
public:
    std::unordered_map<std::string, std::vector<std::string>> file_contents;

    std::vector<std::string> list_files_recursively(const std::string&) override {
        std::vector<std::string> files;
        for (const auto& kv : file_contents) {
            files.push_back(kv.first);
        }
        return files;
    }

    std::vector<std::string> read_file_lines(const std::string& filepath) override {
        return file_contents[filepath];
    }
};
