#include <vector>
#include <string>

class FileHandler {
public:
    virtual std::vector<std::string> list_files_recursively(const std::string& directory) = 0;
    virtual std::vector<std::string> read_file_lines(const std::string& filepath) = 0;
    virtual ~FileHandler() = default;
};
