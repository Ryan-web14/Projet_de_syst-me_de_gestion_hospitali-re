#include "doctor.hpp"


Doctor::Doctor()
{
    //_doctorNumber = NumberGenerator(1000000, 9999999);
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
 
    _doctorNumber = NumberGenerator(1000000, 9999999);

    _licenseNumber = NumberGenerator(10000000, 99999999);

}

void Doctor::DisplayDoctor() const
{
    std::cout << "\n\033[1;35m=====================================================\033[0m\n";
    std::cout << "\033[1;36m\t\t\tDOCTOR DETAILS\033[0m\n";
    std::cout << "\033[1;35m=====================================================\033[0m\n";

    std::cout << "\033[1;33mName:\033[0m " << std::left << std::setw(0) << _name << "\n\n";
    std::cout << "\033[1;33mSurname:\033[0m " << std::left << std::setw(0) << _surname << "\n\n";
    std::cout << "\033[1;33mAddress:\033[0m " << std::left << std::setw(0) << _address << "\n\n";
    std::cout << "\033[1;33mPhone number:\033[0m " << std::left << std::setw(0) << _phoneNumber << "\n\n";
    std::cout << "\033[1;33mDoctor number:\033[0m " << std::left << std::setw(0) << _doctorNumber << "\n\n";
    std::cout << "\033[1;33mLicense number:\033[0m " << std::left << std::setw(0) << _licenseNumber << "\n\n";

    std::cout << "\033[1;35m=====================================================\033[0m\n\n";
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
