#include "patient.hpp"



Patient::Patient( std::string name, std::string surname, std::string adress, std::string phone_number)
{
    _name = name;
    _surname = surname;
    //_birthday = birthday;
    _adress = adress;
    _temporary_number = NumberGenerator();
    _permanent_number = name.substr(0,2) + NumberGenerator();
    if(IsValidPhoneNumber(phone_number)) //verify if the phone number is valid
    {
        _phone_number = phone_number;
    }
    else 
    {
        std::cout << "Invalid phone number" << std::endl;
    }
}

std::string Patient::NumberGenerator()
{
    std::string new_number;
    do
    {
        std::stringstream ss;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(100000, 999999);
        ss << distrib(gen);
        new_number = ss.str();

    } while (std::find(std::begin(existing_numbers),std::end(existing_numbers), new_number) != existing_numbers.end());

    existing_numbers.insert(new_number);
    return new_number;
}

void Patient::setName(const std::string& name)
{
    _name = name;
   
}

void Patient::setSurname(const std::string& surname)
{
    _surname = surname;
   
}

void Patient::setBirthday(Birth birthday)
{
    _birthday = birthday;
   
}

void Patient::setAdress(const std::string& adress)
{
    _adress = adress;
}

void Patient::DisplayPatient() const 
{
    std::cout << "Name : " << _name << std::endl;
    std::cout << "Surname : " << _surname << std::endl;
    //std::cout << "Birthday : " << _birthday.day << std::endl;
    std::cout << "Adress : " << _adress << std::endl;
    std::cout << "Phone number : " << _phone_number << std::endl;
    std::cout << "Temporary number : " << _temporary_number << std::endl;
    std::cout << "Permanent number : " << _permanent_number << std::endl;
}

std::set<std::string> Patient::existing_numbers;

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
    return _adress;
}

std::string Patient::getPhoneNumber() const
{
    return _phone_number;
}

bool Patient::IsValidPhoneNumber(const std::string& phone_number)
{
    std::regex phoneregex ("^0[456]\\d{7}$");
     return std::regex_match(phone_number,phoneregex);
}


void Patient::setPhoneNumber(const std::string& phone_number)
{
  if(IsValidPhoneNumber(phone_number))
  {
    _phone_number = phone_number;
  }
  else 
  {
    std::cout << "Invalid phone number" << std::endl;
  }
  
}






