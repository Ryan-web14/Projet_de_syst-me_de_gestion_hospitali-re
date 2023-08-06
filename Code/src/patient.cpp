#include "patient.hpp"
#include <locale>

// initialization of the static variable
NumberGenerator Patient::_numberGenerator(100000, 999999);

Patient::Patient(std::string name, std::string surname,Birth birthday, std::string adress, std::string phone_number)
{

    for (char c : name)
    {
        if (isdigit(c)) // check if the name contains a number
        {
            throw std::invalid_argument("Invalid name");
        }
    }


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
    else if (!name.empty()) 
    {
        name [0] = std::toupper(name[0]); //capitalize the first letter of the name
        
        for (std::size_t i = 1; i < name.size(); i++)
        {
            name[i] = std::tolower(name[i]);
        }
        std::cout <<"hello" <<"\n";
    }


       for (auto &sur : surname)
    {
        sur = std::toupper(sur);
    }
    for (auto &sur : surname)
    {
        sur = std::toupper(sur);
    }
    _name = name;
    _surname = surname;
    _birthday = birthday;
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

//methods
void Patient::DisplayPatient() const
{
    std::cout << "\n\033[1;35m=====================================================\033[0m\n";
    std::cout << "\033[1;36m\t\t\tDETAILS PATIENT\033[0m\n";
    std::cout << "\033[1;35m=====================================================\033[0m\n";

    std::cout << "\033[1;33mPrenom:\033[0m " << std::left << std::setw(0) << _name << "\n\n";
    std::cout << "\033[1;33mNom:\033[0m " << std::left << std::setw(0) << _surname << "\n\n";
    std::cout << "\033[1;33mDate de naissance:\033[0m " << std::left << std::setw(0) << _birthday.day<<"/"<< _birthday.month<<"/"<<_birthday.year << "\n\n";
    std::cout << "\033[1;33mAdresse:\033[0m " << std::left << std::setw(0) << _address << "\n\n";
    std::cout << "\033[1;33mTelephone:\033[0m " << std::left << std::setw(0) << _phone_number << "\n\n";
    std::cout << "\033[1;33mNumero temporaire:\033[0m " << std::left << std::setw(0) << _temporary_number << "\n\n";
    std::cout << "\033[1;33mNumero permanent:\033[0m " << std::left << std::setw(0) << _permanent_number << "\n\n";

    std::cout << "\033[1;35m=====================================================\033[0m\n\n";
}

bool Patient::IsValidPhoneNumber(const std::string &phone_number)
{
    std::regex phoneregex("^0[456]\\d{7}$");
    return std::regex_match(phone_number, phoneregex);
}

bool Patient::IsValidBirthDate(const Birth& birthday)
{
    if(birthday.year<1900 || birthday.year>2022)
    {
        return false;
    }
    if(birthday.month<1 || birthday.month>12)
    {
        return false;
    }
    if(birthday.day<1 || birthday.day>31)
    {
        return false;
    }
    return true;
    if(birthday.month==2)
    {
        if(birthday.day>29)
        {
            return false;
        }
    }
}

//getter and setter
//setters
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

//getters
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

bool Patient::operator ==(std::shared_ptr<Patient> patient) const
{
    return _permanent_number == patient->getPermanentNumber();
}




