#include "patient.hpp"

// initialization of the static variable
NumberGenerator Patient::_numberGenerator(100000, 999999);

Patient::Patient(std::string name, std::string surname, std::string adress, std::string phone_number)
{
    _name = name;
    for (auto &sur : surname)
    {
        sur = std::toupper(sur);
    }
    _surname = surname;
    //_birthday = birthday;
    _address = adress;
    _temporary_number = _numberGenerator.generateNumber();
    _permanent_number = _surname.substr(0, 2) + _numberGenerator.generateNumber();
    ;
    if (IsValidPhoneNumber(phone_number)) // verify if the phone number is valid
    {
        _phone_number = phone_number;
    }
    else
    {
        std::cout << "Invalid phone number" << std::endl;
    }
}

void Patient::setName(const std::string &name)
{
    _name = name;
}

void Patient::setSurname(const std::string &surname)
{
    for (auto sur : surname)
    {
        sur = std::toupper(sur);
    }
    _surname = surname;
}

void Patient::setBirthday(Birth birthday)
{
    _birthday = birthday;
}

void Patient::setAdress(const std::string &adress)
{
    _address = adress;
}

void Patient::DisplayPatient() const
{
    std::cout << "\n\033[1;35m=====================================================\033[0m\n";
    std::cout << "\033[1;36m\t\t\tPATIENT DETAILS\033[0m\n";
    std::cout << "\033[1;35m=====================================================\033[0m\n";

    std::cout << "\033[1;33mName:\033[0m " << std::left << std::setw(0) << _name << "\n\n";
    std::cout << "\033[1;33mSurname:\033[0m " << std::left << std::setw(0) << _surname << "\n\n";
    std::cout << "\033[1;33mAddress:\033[0m " << std::left << std::setw(0) << _address << "\n\n";
    std::cout << "\033[1;33mPhone number:\033[0m " << std::left << std::setw(0) << _phone_number << "\n\n";
    std::cout << "\033[1;33mTemporary number:\033[0m " << std::left << std::setw(0) << _temporary_number << "\n\n";
    std::cout << "\033[1;33mPermanent number:\033[0m " << std::left << std::setw(0) << _permanent_number << "\n\n";

    std::cout << "\033[1;35m=====================================================\033[0m\n\n";
}

std::string Patient::getTemporaryNumber() const
{
    return _temporary_number;
}

std::string Patient::getPermanentNumber() const
{
    return _permanent_number;
}

std::string Patient::getName() const
{
    return _name;
}

std::string Patient::getSurname() const
{
    return _surname;
}

Birth Patient::getBirthday() const
{
    return _birthday;
}

std::string Patient::getAdress() const
{
    return _address;
}

std::string Patient::getPhoneNumber() const
{
    return _phone_number;
}

bool Patient::IsValidPhoneNumber(const std::string &phone_number)
{
    std::regex phoneregex("^0[456]\\d{7}$");
    return std::regex_match(phone_number, phoneregex);
}

void Patient::setPhoneNumber(const std::string &phone_number)
{
    if (IsValidPhoneNumber(phone_number))
    {
        _phone_number = phone_number;
    }
    else
    {
        std::cout << "Invalid phone number" << std::endl;
    }
}
