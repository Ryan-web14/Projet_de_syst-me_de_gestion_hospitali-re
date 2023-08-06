#pragma once

#include <string>
#include <set>
#include <random>
#include <vector>
#include <regex>
#include <iostream>
#include <vector>
#include "birth.hpp"
#include <algorithm>
#include <iomanip>
#include "numberGenerator.hpp"

class Doctor
{
public:
//constructor and destructor
//constructor by default
Doctor() = default;
//constructor with parameters which are the name, the surname, the adress and the phone number
Doctor(std::string name, std::string surname,Birth birthday,std::string adress, std::string phone_number);
//destructor
~Doctor() = default;

//Methods
//verify if the phone number is valid
bool IsValidPhoneNumber(const std::string& phone_number);
//Display the information of a doctor
void DisplayDoctor() const;

//getter
std::string getName() const;
std::string getSurname() const;
Birth getBirthday() const;
std::string getAddress() const;
std::string getPhoneNumber() const;
std::string getLicenseNumber() const;
std::string getDoctorNumber() const;


//setter
void setName(const std::string& name);
void setSurname(const std::string& surname);
void setBirthday(Birth birthday);
void setAddress(const std::string& address);
void setPhoneNumber(const std::string& phone_number);

//operator
bool operator ==(std::shared_ptr<Doctor> other) const; //overload the operator == to compare two doctors

private:
std::string _name;
std::string _surname;
std::string _address;
std::string _phoneNumber;
std::string _licenseNumber;
Birth _birthday;
std::string _doctorNumber;
static NumberGenerator _numberGenerator;
//Speciality _speciality;
static std::string NumberGenerator(int min, int max); //generate a new number
};
