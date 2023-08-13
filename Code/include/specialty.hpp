#pragma once 

#include <iostream>
#include <string>
#include "numberGenerator.hpp"

class Specialty
{
public:
//constructor and destructor
//default constructor
Specialty() = default;
//constructor with parameters
Specialty(std::string name, std::string description);
//default destructor
~Specialty() = default;

//setter and getter
//getters
std::string GetName() const;
std::string GetDescription() const;
//setters
void SetName(std::string name);
//set the description of the specialty
void SetDescription(std::string description);

//methods
//display the specialty
void DisplaySpecialty() const;

private:
static NumberGenerator _numberGenerator;
std::string _specialtyId;
std::string _name;
std::string _description;
};
