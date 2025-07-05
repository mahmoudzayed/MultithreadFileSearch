#include "FileHandler.hpp"
#include "SearchEngine.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc != 3) 
    {
        std::cerr << "Usage: " << argv[0] << " <query> <directory>\n";
        return 1;
    }

    std::string query = argv[1];
    std::string directory = argv[2];

    auto file_handler = std::make_shared<RealFileHandler>();
    SearchEngine engine(file_handler, std::thread::hardware_concurrency());
    engine.search(query, directory);

    return 0;
}