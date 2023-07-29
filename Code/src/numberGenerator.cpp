#include "numberGenerator.hpp"

std::string NumberGenerator(int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::stringstream ss;
    std::uniform_int_distribution<> dis(min, max);
    ss << dis(gen);
    std::string number = ss.str();
    while(existing_numbers.find(number) != existing_numbers.end())
    {
       ss.str(std::string());
       ss << dis(gen);
       number = ss.str();
    }
    existing_numbers.insert(number);
    return number;
}