#pragma once

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <chrono>
#include "treatment.hpp"
#include "patient.hpp"
#include "doctor.hpp"
#include "numberGenerator.hpp"
#include "prescription.hpp"
#include "emergencyContact.hpp"


class Hospitalisation
{
public:
//constructor and destructor
//default contructor 
Hospitalisation() = default;
//constructor with parameters which are the patient, doctor, hospitalisation date, hospitalisation reason, hospitalisation duration
Hospitalisation(std::shared_ptr<Patient> patient, std::shared_ptr<Doctor> doctor,std::string hospitalisationReason, int hospitalisationDuration, std::string hospitalisationLocation);
//destructor
~Hospitalisation() = default;

//methods
void AddTreatment(std::shared_ptr<Treatment> treatment);
void RemoveTreatment(std::string IdTreatment);
void AddPrescription(std::shared_ptr<Prescription> prescription);
void RemovePrescription(std::string IdPrescription);
void AddBiologicalExam(std::shared_ptr<BiologicalExam> bioExam);
void RemoveBiologicalExam(std::string IdbioExam);
void AddXrayExam(std::shared_ptr<XrayExam> xrayExam);
void RemoveXrayExam(std::string IdXrayExam);
void ProlongHospitalisationDuration(int duration);
void DisplayHospitalisation() const;

//getter and setter
//getter
std::string getHospitalisationId() const;
std::shared_ptr<Patient> getPatient() const;
std::shared_ptr<Doctor> getDoctor() const;
std::string getHospitalisationReason() const;
std::string getHospitalisationLocation() const;
int getHospitalisationDuration() const;
time_t getHospitalisationStartDate() const;
time_t getHospitalisationEndDate() const;
std::vector<std::shared_ptr<Treatment>> getTreatmentList() const;
std::vector<std::shared_ptr<Prescription>> getPrescriptionList() const;
std::vector<std::shared_ptr<BiologicalExam>> getBiologicalExamList() const;
std::vector<std::shared_ptr<XrayExam>> getXrayExamList() const;
//setter
void setPatient(std::shared_ptr<Patient> patient);
void setDoctor(std::shared_ptr<Doctor> doctor);
void setHospitalisationReason(std::string& reason); 
void setHospitalisationDuration(int duration);
void setEmergencyContact(EmergencyContact& contact);


private: 
static NumberGenerator _numberGenerator;
std::string _hospitalisationId;
std::shared_ptr<Patient> _patient;
std::shared_ptr<Doctor> _doctor;
std::string hospitalisationDescription;
std::string _hospitalisationReason;
std::string  _hospitalisationLocation;
int _hospitalisationDuration;
time_t _hospitalisationStartDate;
time_t hospitalisationEndDate;
std::vector<std::shared_ptr<Treatment>> _treatments;
std::vector<std::shared_ptr<Prescription>> _prescriptions;
std::vector<std::shared_ptr<BiologicalExam>> _biologicalExams;
std::vector<std::shared_ptr<XrayExam>> _xrayExams;
//std::vector<Surgery> surgeries;
EmergencyContact _contact;
};
