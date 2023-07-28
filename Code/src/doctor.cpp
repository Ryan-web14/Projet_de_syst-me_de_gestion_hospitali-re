#include "doctor.hpp"


Doctor::Doctor()
{
    _doctorNumber = NumberGenerator(1000000, 9999999);
}

Doctor::Doctor(std::string name, std::string surname, std::string adress, std::string phone_number):
_name(name), _surname(surname), _address(adress)
{
    try
    {
       if(IsValidPhoneNumber(phone_number))
       {
        _phoneNumber = phone_number;
       }
       else
       {
         throw std::runtime_error("Invalid phone number");
       }
    }
    catch(const std::runtime_error& e)
    {
        std::cout << e.what();
    }

    _doctorNumber = _surname.substr(0,2) + NumberGenerator(1000000, 9999999);

    _licenseNumber = NumberGenerator(100000000, 99999999);

}

void Doctor::DisplayDoctor() const
{
    std::cout << "Name: " << _name << std::endl;
    std::cout << "Surname: " << _surname << std::endl;
    std::cout << "Adress: " << _address << std::endl;
    std::cout << "Phone number: " << _phoneNumber << std::endl;
    std::cout << "Doctor number: " << _doctorNumber << std::endl;
    std::cout << "License number: " << _licenseNumber << std::endl;
    std::cout << std::endl;
    std::vector<int> v;
   
}

std::string Doctor::getName() const
{
    return _name;
}

std::string Doctor::getSurname() const
{
    return _surname;
}

std::string Doctor::getAddress() const
{
    return _address;
}

std::string Doctor::getPhoneNumber() const
{
    return _phoneNumber;
}

std::string Doctor::getDoctorNumber() const
{
    return _doctorNumber;
}

std::string Doctor::getLicenseNumber() const
{
    return _licenseNumber;
}

void Doctor::setName(const std::string& name)
{
    _name = name;
}

void Doctor::setSurname(const std::string& surname)
{
    _surname = surname;
}

void Doctor::setAddress(const std::string& address)
{
    _address = address;
}

void Doctor::setPhoneNumber(const std::string& phone_number)
{
    try
    {
       if(IsValidPhoneNumber(phone_number))
       {
        _phoneNumber = phone_number;
       }
       else
       {
         throw std::runtime_error("Invalid phone number");
       }
    }
    catch(const std::runtime_error& e)
    {
        std::cout << e.what();
    }
}

bool Doctor::IsValidPhoneNumber(const std::string& phone_number)
{
    std::regex phoneregex ("^0[456]\\d{7}$");
     return std::regex_match(phone_number,phoneregex);
}

std::string Doctor::NumberGenerator(int min, int max)
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

std::set<std::string> Doctor::existing_numbers; //set of existing numbers
