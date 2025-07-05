#include "FileHandler.hpp"
#include <filesystem>
#include <fstream>
#include <sstream>

class RealFileHandler : public FileHandler {
public:
    std::vector<std::string> list_files_recursively(const std::string& directory) override
    {
        std::vector<std::string> result;
        for (const auto& entry : std::filesystem::recursive_directory_iterator(directory))
        {
            if (entry.is_regular_file()) {
                result.push_back(entry.path().string());
            }
        }
        return result;
    }

    std::vector<std::string> read_file_lines(const std::string& filepath) override
    {
        std::vector<std::string> lines;
        std::ifstream file(filepath);
        std::string line;
        while (std::getline(file, line))
        {
            lines.push_back(line);
        }
        return lines;
    }
};
