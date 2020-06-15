#include "read_words.hpp"
#include <utility>
#include <fstream>


std::vector<std::string> readAllWords(std::string file) {
    std::vector<std::string> words{};
    std::ifstream fileStream(file);
    if (!fileStream) {
        throw std::runtime_error("Cannot open file " + file);
    }

    std::string line;
    while (std::getline(fileStream, line)) {
        words.emplace_back(std::move(line));
    }

    words.shrink_to_fit();
	return words;
}

