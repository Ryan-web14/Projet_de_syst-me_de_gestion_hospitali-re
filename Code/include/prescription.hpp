#pragma once

#include <vector>
//#include <map>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <memory>
#include <chrono>
#include <format>
#include <ctime>
#include "patient.hpp"
#include "doctor.hpp"

struct Medecine
{
std::string name;
std::string dosage;
std::string frequency;
std::string duration;
std::string precision;
};
class Prescription
{
public:
//constructor and destructor
//default constructor
Prescription() = default;
//constructor with parameters which are the patient, doctor 
Prescription(std::shared_ptr<Patient> patient, std::shared_ptr<Doctor> doctor);
//destructor
~Prescription() = default;

//methods
//add a medecine to the prescription
void AddMedecine(std::string name, std::string dosage, std::string frequency, std::string duration, std::string precision);
void RemoveMedecine(std::string name);
void DisplayPrescription() const;

//getter and setter
//getter
std::shared_ptr<Patient> getPatient() const;
std::shared_ptr<Doctor> getDoctor() const;
std::vector<Medecine> getMedecines() const;

//setter 
void setPatient(std::shared_ptr<Patient> patient);
void setDoctor(std::shared_ptr<Doctor> doctor);

private:
static NumberGenerator _numberGenerator;
std::string _prescriptionId;
std::shared_ptr<Patient> _patient;
std::shared_ptr<Doctor> _doctor;
std::vector<Medecine> _medecines;
std::time_t _prescriptionDate;

};