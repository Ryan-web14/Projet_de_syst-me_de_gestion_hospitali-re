#include "doctor.hpp"

NumberGenerator Doctor::_numberGenerator(1000000, 9999999);

Doctor::Doctor(std::string name, std::string surname,Birth birthday,std::string adress,Specialty specialty, std::string phone_number) :  _address(adress), _speciality(specialty)
{
    try
    {
        if (IsValidPhoneNumber(phone_number))
        {
            _phoneNumber = phone_number;
        }
        else
        {
            throw std::runtime_error("Invalid phone number");
        }
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what();
    }

    _doctorNumber = _numberGenerator.generateNumber();

    _licenseNumber = _numberGenerator.generateNumber();

 for (char c : surname) 
    {
        if (isdigit(c)) //check if the name contains a number
        {
            throw std::invalid_argument("Invalid surname");
        }
    }
    if(surname.empty())
    {
        throw std::runtime_error("Invalid surname");
    }

       for (auto &sur : surname)
    {
        sur = std::toupper(sur);
    }
    _surname = surname;

    for (char c : name)
    {
        if (isdigit(c)) // check if the name contains a number
        {
            throw std::invalid_argument("Invalid name");
        }
    }
    if(name.empty())
    {
        throw std::runtime_error("Invalid name");
    }
    else if (!name.empty())
    {
        name[0] = std::toupper(name[0]);//capitalize the first letter of the name
        
        for (std::size_t i = 1; i < name.size(); i++)
        {
            name[i] = std::tolower(name[i]);
        }

       
    }
 _name = name;
    
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

Specialty Doctor::getSpecialty() const
{
    return _speciality;
}

void Doctor::setName(const std::string &name)
{
    for (char c : name)
    {
        if (isdigit(c))
        {
            throw std::invalid_argument("Invalid name");
        }
    }
    if(name.empty())
    {
        throw std::runtime_error("Invalid name");
    }
    _name = name;
}

void Doctor::setSurname(const std::string &surname)
{
    for (char c : surname)
    {
        if (isdigit(c))
        {
            throw std::invalid_argument("Invalid surname");
        }
    }
    if(surname.empty())
    {
        throw std::runtime_error("Invalid surname");
    }
    _surname = surname;
}

void Doctor::setAddress(const std::string &address)
{
    _address = address;
}

void Doctor::setPhoneNumber(const std::string &phone_number)
{
    try
    {
        if (IsValidPhoneNumber(phone_number))
        {
            _phoneNumber = phone_number;
        }
        else
        {
            throw std::runtime_error("Invalid phone number");
        }
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what();
    }
}

void Doctor::setSpecialty(Specialty specialty)
{
    _speciality = specialty;
}

//method
bool Doctor::IsValidPhoneNumber(const std::string &phone_number)
{
    std::regex phoneregex("^0[456]\\d{7}$");
    return std::regex_match(phone_number, phoneregex);
}

bool Doctor::operator ==(std::shared_ptr<Doctor> other) const
{
    return _doctorNumber == other->getDoctorNumber();
}

void Doctor::setBirthday(Birth birthday)
{
    _birthday = birthday
}

