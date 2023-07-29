#ifndef __DOCTOR__
#define __DOCTOR__


#include "appointment.hpp"
#include <string>
#include <set>
#include "patient.hpp"
#include <random>
#include <vector>
#include <regex>
#include <iostream>
#include <vector>

class Doctor
{
public:
//constructor and destructor
//constructor by default
Doctor();

//constructor with parameters which are the name, the surname, the adress and the phone number
Doctor(std::string name, std::string surname, std::string adress, std::string phone_number);

//Methods
//verify if the phone number is valid
bool IsValidPhoneNumber(const std::string& phone_number);
bool isAvalaible(const Date& date) const;

//Display the information of a doctor
void DisplayDoctor() const;

//getter
std::string getName() const;
std::string getSurname() const;
Birth getBirthday() const;
std::string getAddress() const;
std::string getPhoneNumber() const;
void getPatients() const;
std::string getLicenseNumber() const;
std::string getDoctorNumber() const;
//show the list of appointment for the doctor
void getAppointment() const;

//setter
void setName(const std::string& name);
void setSurname(const std::string& surname);
void setBirthday(Birth birthday);
void setAddress(const std::string& address);
void setPhoneNumber(const std::string& phone_number);

private:
std::string _name;
std::string _surname;
std::string _address;
std::string _phoneNumber;
std::string _licenseNumber;
std::vector<Patient> _patients;
//Speciality _speciality;
//std::vector<Consultation> _consultations;
Birth _birthday;
std::string _doctorNumber;
static std::set<std::string> existing_numbers; //set of existing numbers
static std::string NumberGenerator(int min, int max); //generate a new number
};







#endif 