#include "numberGenerator.hpp"

// constructor with parameters which are the min and the max
NumberGenerator::NumberGenerator(int min, int max) : distrib(min, max)
{
  std::random_device rd;
  gen = std::mt19937(rd());
}

std::string NumberGenerator::generateNumber()
{
  std::stringstream ss;
  ss << distrib(gen);
  std::string generatedNumber = ss.str();
  while (existing_numbers.find(generatedNumber) != std::end(existing_numbers))
  {
    ss.str(std::string());
    ss << distrib(gen);
    generatedNumber = ss.str();
  }
  existing_numbers.insert(generatedNumber);
  return generatedNumber;
}
