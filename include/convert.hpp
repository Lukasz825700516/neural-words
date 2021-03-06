#pragma once
#include <array>

constexpr std::size_t maxLength{24}; //max word length
constexpr std::size_t possibleLetters{26}; //english alphabet

constexpr std::size_t networkEntries{ maxLength * possibleLetters };

// convert text to data which we can give neural network
std::array<double, networkEntries> convertToInputs(const char* text, int length);
