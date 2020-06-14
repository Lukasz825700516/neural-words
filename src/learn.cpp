#include "learn.hpp"
#include <cstdlib>
#include "convert.hpp"
#include <random>

constexpr double good{1.0};
constexpr double bad{0.0};

void learn(genann* ann, std::vector<std::string> &positiveWords, std::vector<std::string> &negativeWords, int repetitionsMultiplier) {
    std::string learningWord;
    int repetitions = (positiveWords.size() + negativeWords.size()) * repetitionsMultiplier;
    std::random_device rd;
    std::default_random_engine gen{rd()};
    std::uniform_int_distribution<int> posDis{0, positiveWords.size() - 1};
    std::uniform_int_distribution<int> negDis{0, negativeWords.size() - 1};

    for(int i{}; i < repetitions; ++i) {
        learningWord = positiveWords[posDis(gen)];
        genann_train(ann, convertToInputs(learningWord.c_str(), learningWord.size()).data(), &good, 3);
        
        learningWord = negativeWords[negDis(gen)];
        //let's try with higher learning rate for negative words because program is braver on positive words more than on negative
        genann_train(ann, convertToInputs(learningWord.c_str(), learningWord.size()).data(), &bad, 7);
    }
}