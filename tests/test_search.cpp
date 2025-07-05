#include "SearchEngine.hpp"
#include "mock_filehandler.hpp"
#include <iostream>

int main() {
    auto mock_handler = std::make_shared<MockFileHandler>();
    mock_handler->file_contents = {
        {"file1.txt", {"hello", "world", "search here"}},
        {"file2.txt", {"another line", "search again"}}
    };

    SearchEngine engine(mock_handler, 2);
    engine.search("search", "mock_dir");

    return 0;
}