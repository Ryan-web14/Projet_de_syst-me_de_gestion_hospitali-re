#pragma once 

#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>
#include <algorithm>
#include "consultation.hpp"
#include "prescription.hpp"
#include "doctorAppointment.hpp"
#include "numberGenerator.hpp"
#include "treatment.hpp"


class MedicalRecord
{
public:
//constructor and destructor
//default constructor
MedicalRecord();
//default destructor
~MedicalRecord() = default;

//methods
//add an appointment to the appointment list
void AddAppointment(std::shared_ptr<Appointment> appointment);
//add a consultation to the consultation list
void AddConsultation(std::shared_ptr<Consultation> consultation);
//add a prescription to the prescription list
void AddPrescription(std::shared_ptr<Prescription> prescription);
//add a doctor appointment to the doctor appointment list
void AddDoctorAppointment(std::shared_ptr<DoctorAppointment> doctorAppointment);
//add chronic disease
void AddChronicDisease(std::string ChronicDisease);
//add chronic medication
void AddChronicMedication(std::string ChronicMedication);
//add allergy
void AddAllergy(std::string Allergy);
//add treatment
void AddTreatement(std::shared_ptr<Treatment> treatment);
//remove treatment
void RemoveTreatment(std::string treatmentId);
//add xray exam
void AddXrayExam(std::shared_ptr<XrayExam> xray);
//remove xray exam
void RemoveXrayExam(std::string xrayId);
//add biological exam
void AddBiologicalExam(std::shared_ptr<BiologicalExam> biologicalExam);
//remove bio exam
void RemoveBiologicalExam(std::string bioExamId);
//remove allergy
void RemoveAllergy(std::string Allergy);
//remove chronic medication
void RemoveChronicMedication(std::string ChronicMedication);
//remove chronic disease
void RemoveChronicDisease(std::string ChronicDisease);
//remove an appointment from the appointment list
void RemoveAppointment(std::shared_ptr<Appointment> appointment);
//remove a consultation from the consultation list
void RemoveConsultation(std::shared_ptr<Consultation> consultation);
//remove a prescription from the prescription list
void RemovePrescription(std::shared_ptr<Prescription> prescription);
//remove a doctor appointment from the doctor appointment list
void RemoveDoctorAppointment(std::shared_ptr<Appointment> appointment, std::shared_ptr<Doctor> doctor);
//display all the medical record of the patient
void DisplayMedicalRecord() const;
//display all the appointment of the patient
void DisplayAppointmentList() const;
//display all the consultation of the patient
void DisplayConsultationList() const;
//display all the prescription of the patient
void DisplayPrescriptionList() const;
//display all the doctor appointment of the patient
void DisplayDoctorAppointmentList() const;
//display treatment
void DisplayTreatmentList() const;
//display xray exam
void DisplayXrayExamList() const;
//display bio exam
void DisplayBiologicalExamList() const;
 
//getters and setters
//getter
std::string getMedicalRecordId() const;
std::vector<std::string> getAllergies() const;
std::vector<std::string> getChronicDiseases() const;
std::vector<std::string> getChronicMedications() const;
std::vector<std::shared_ptr<Appointment>> getAppointmentList() const;
std::vector<std::shared_ptr<Consultation>> getConsultationList() const;
std::vector<std::shared_ptr<Prescription>> getPrescriptionList() const;
std::vector<std::shared_ptr<DoctorAppointment>> getDoctorAppointmentList() const;
std::vector<std::shared_ptr<Treatment>> getTreatmentList() const;
//implémentation à réaliser 
//setter
// void setAllergies(std::vector<std::string> allergies);
// void setChronicDiseases(std::vector<std::string> chronicDiseases);
// void setChronicMedications(std::vector<std::string> chronicMedications);




private:
static NumberGenerator _numberGenerator;
std::string _medicalRecordId; //unique
std::vector<std::string> _allergies;
std::vector<std::string> _chronicDiseases;
std::vector<std::string> _chronicMedications;
//std::vector<std::string> medicalHistory;
std::vector<std::shared_ptr<Appointment>> _appointmentList; //all the appointment of the patient
std::vector<std::shared_ptr<Consultation>> _consultationList; //all the consultation of the patient
std::vector<std::shared_ptr<Prescription>> _prescriptionList; //all the prescription of the patient
std::vector<std::shared_ptr<DoctorAppointment>> _doctorAppointmentList; //all the doctor appointment of the patient
std::vector<std::shared_ptr<Treatment>>_treatmentList;
std::vector<std::shared_ptr<XrayExam>> _xrayExamList;
std::vector<std::shared_ptr<BiologicalExam>> _biologicalExamList;

};