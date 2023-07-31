#pragma once

#include <random>
#include <iostream>
#include <string>
#include <set>
#include <sstream>

class NumberGenerator
{
public:
//constructor and destructor
//constructor by default
NumberGenerator() = default;
//constructor with parameters which are the min and the max
NumberGenerator(int min, int max);

//generate a new number
std::string generateNumber();

private:
std::mt19937 gen;
std::uniform_int_distribution<> distrib;
std::set<std::string> existing_numbers;
};


