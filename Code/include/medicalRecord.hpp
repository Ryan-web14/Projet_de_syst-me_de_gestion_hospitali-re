#pragma once 

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include "appointment.hpp"
#include "consultation.hpp"
#include "prescription.hpp"
#include "doctorAppointment.hpp"
#include "numberGenerator.hpp"


class MedicalRecord
{
public:
//constructor and destructor
//default constructor
MedicalRecord() = default;
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
//remove an appointment from the appointment list
void RemoveAppointment(std::shared_ptr<Appointment> appointment);
//remove a consultation from the consultation list
void RemoveConsultation(std::shared_ptr<Consultation> consultation);
//remove a prescription from the prescription list
void RemovePrescription(std::shared_ptr<Prescription> prescription);
//remove a doctor appointment from the doctor appointment list
void RemoveDoctorAppointment(std::shared_ptr<DoctorAppointment> doctorAppointment);
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
//setter
void setMedicalRecordId(std::string medicalRecordId);
void setAllergies(std::vector<std::string> allergies);
void setChronicDiseases(std::vector<std::string> chronicDiseases);
void setChronicMedications(std::vector<std::string> chronicMedications);
void setAppointmentList(std::vector<std::shared_ptr<Appointment>> appointmentList);
void setConsultationList(std::vector<std::shared_ptr<Consultation>> consultationList);
void setPrescriptionList(std::vector<std::shared_ptr<Prescription>> prescriptionList);
void setDoctorAppointmentList(std::vector<std::shared_ptr<DoctorAppointment>> doctorAppointmentList);



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
};