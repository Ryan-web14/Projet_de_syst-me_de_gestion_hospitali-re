#ifndef __PATIENT__ //if this class is not define then define it
#define __PATIENT__

#include "birth.hpp"
#include <string>
#include <algorithm>
#include <iostream>
#include <regex>
#include "numberGenerator.hpp"
#include <iomanip>

class Patient
{
public:
Patient() = default;
Patient( std::string name, std::string surname,std::string adress, std::string phone_number); 


//Modification menu for a patient
void ModifyPatient();
//Display the information of a patient
void DisplayPatient() const;

//verify if the phone number is valid
bool IsValidPhoneNumber(const std::string& phone_number);


//getter
std::string getTemporaryNumber() const;
std::string getPermanentNumber() const;
std::string getName() const;
std::string getSurname() const;
Birth getBirthday() const;
std::string getAdress() const;
std::string getPhoneNumber() const;

//setter
void setName(const std::string& name) ;
void setSurname(const std::string& surname) ;
void setBirthday(Birth birthday) ;
void setAdress(const std::string& adress) ;
void setPhoneNumber(const std::string& phone_number) ;

private:
std::string _permanent_number;
std::string _temporary_number;
std::string _name;
std::string _surname;
Birth _birthday;
std::string _address;
std::string _phone_number;
static NumberGenerator _numberGenerator;
//std::vector<Hospitalisation> hospitalisation;
//std::vector<Appointment> appointment;
//std::vector<Billing> billing;

};





#endif