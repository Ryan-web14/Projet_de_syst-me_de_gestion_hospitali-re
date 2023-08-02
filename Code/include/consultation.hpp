#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <map>
#include "Patient.hpp"
#include "doctorAppointment.hpp"
#include "numberGenerator.hpp"

class Consultation
{
public:
//constructor and destructor
//default constructor
Consultation() = default;
//constructor with parameters which are the patient, the doctor, the doctorAppointment and the diagnosis
Consultation(std::shared_ptr<Patient> patient, std::shared_ptr<Doctor> doctor ,std::shared_ptr<DoctorAppointment> doctorAppointment,std::string diagnosis);
//destructors
~Consultation() = default;

//methods
//add a symptom to the consultation
void AddSymptom(std::string symptom);
//To deleter a symptom from the consultation
bool DeleteSymptom(std::string symptom);
//add a note to the consultation
void AddNote (std::string note);
//display the consultation
void DisplayConsultation() const;
//display the consultation with the diagnosis
void DisplayConsultationWithDiagnosis() const;
//display the consultation with the diagnosis and the symptoms
void DisplayConsultationWithDiagnosisAndSymptoms() const;
//display the consultation with the diagnosis, the symptoms and the notes
void DisplayConsultationWithDiagnosisAndSymptomsAndNotes() const;
//display the consultation with the diagnosis, the symptoms, the notes and the cost
void DisplayConsultationWithDiagnosisAndSymptomsAndNotesAndCost() const;
////display the consultation with the diagnosis, the symptoms, the notes, the cost and the doctorAppointment
////void DisplayConsultationWithDiagnosisAndSymptomsAndNotesAndCostAndDoctorAppointment() const;




//getters and setters
//getter
std::string getConsultationId() const;
std::string getDiagnosis() const; //return the diagnosis of the consultation
std::vector<std::string> getSymptoms() const; //return the symptoms of the consultation
std::vector<std::string> getNotes() const; //return the notes of the consultation
std::shared_ptr<Patient> getPatient() const; //return the patient of the consultation
std::shared_ptr<Doctor> getDoctor() const; //return the doctor of the consultation
double getCost() const; //return the cost of the consultation
std::shared_ptr<DoctorAppointment> getDoctorAppointment() const; //return the doctorAppointment of the consultation
bool getIsPaid() const; //return if the consultation is paid or not
std::string getMostFrequentSymptoms() const;
std::string getMostFrequentSymptomsFromConsultation(std::vector<std::shared_ptr<Consultation>> consultationList) const;
std::string getMostFrequentDiagnosisFromConsultation(std::vector<std::shared_ptr<Consultation>> consultationList) const;
//setter
void setDiagnosis(std::string diagnosis); //set the diagnosis of the consultation
void setSymptoms(std::string symptoms); //set the symptoms of the consultation
void setNote (std::string note); //set the notes of the consultation
void setPatient(std::shared_ptr<Patient> patient); //set the patient of the consultation
void setDoctor(std::shared_ptr<Doctor> doctor); //set the doctor of the consultation
void setCost(double cost); //set the cost of the consultation
void setFollowUps(std::shared_ptr<DoctorAppointment> followUps); //set the followUps of the consultation


private:
static NumberGenerator _numberGenerator; //numberGenerator object to generate the consultationId
std::string  _consultationId;
std::shared_ptr<Patient> _patient; //patient object associated with the consultation
std::shared_ptr<Doctor> _doctor; //doctor smart_ptr associated with the consultation
std::shared_ptr<DoctorAppointment> _doctorAppointment; //doctorAppointment smart_ptr associated with the consultation
std::vector<std::string> _notes; //vector of strings containing the notes of the consultation
std::string _diagnosis; //string containing the diagnosis of the consultation
std::vector<std::string>_symptoms; //vector of strings containing the symptoms of the consultation
std::shared_ptr<DoctorAppointment> _followUps; 
double _cost; //double containing the cost of the consultation
bool _isPaid; //boolean to know if the consultation is paid or not
//static std::map<std::string, int> _symptomFrequency;
};

