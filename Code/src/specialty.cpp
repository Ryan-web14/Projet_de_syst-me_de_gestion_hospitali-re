#include "specialty.hpp"

NumberGenerator Specialty::_numberGenerator(10,100 );
//contructor with parameters
Specialty::Specialty(std::string name, std::string description)
{
    _name = name;
    _description = description;
    _specialtyId = _numberGenerator.generateNumber();
}

//getter and setter
//getter
std::string Specialty::GetName() const
{
    return _name;
}

std::string Specialty::GetDescription() const
{
    return _description;
}

//setter
void Specialty::SetName(std::string name)
{
    if(name.empty())
        throw std::invalid_argument("The name of the specialty cannot be empty, Please enter a valid name");
     
    _name = name;
}

void Specialty::SetDescription(std::string description)
{
    if(description.empty())
        throw std::invalid_argument("The description of the specialty cannot be empty, Please enter a valid description");
    _description = description;
}