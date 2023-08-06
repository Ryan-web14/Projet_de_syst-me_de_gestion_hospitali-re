#pragma once

#include <string> 
#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>
#include "patient.hpp"
#include "doctor.hpp"
#include "appointment.hpp"
#include "doctorAppointment.hpp"
#include "doctorSchedule.hpp"
#include "prescription.hpp"
#include "consultation.hpp"




class Hospital
{
public:
//constructor and destructor
//default constructor
Hospital() = default;
//constructor with a parameter name 
Hospital(std::string name);

//methods
void AddPatient(std::shared_ptr<Patient> patient); //add a patient in the vector of patient
void DeletePatient(const std::string patientId); //delete a patient in the vector of patient
void AddDoctor(std::shared_ptr<Doctor> doctor); //add a doctor in the vector of doctor
void DeleteDoctor(const std::string doctorId); //delete a doctor in the vector of doctor
void AddPrescription(std::shared_ptr<Prescription> prescription); //add a prescription in the vector of prescription
void DeletePrescription(const std::string prescriptionId); //delete a prescription in the vector of prescription
void AddConsultation(std::shared_ptr<Consultation> consultation); //add a consultation in the vector of consultation
void DeleteConsultation(const std::string consultationId); //delete a consultation in the vector of consultation
void AddAppointment(std::shared_ptr<Appointment> appointment); //add an appointment in the vector of appointment
void DeleteAppointment(const std::string appointmentId); //delete an appointment in the vector of appointment
void AddDoctorAppointment(std::shared_ptr<DoctorAppointment> doctorApppointment); //add a doctorAppointment in the vector of doctorAppointment
void DeleteDoctorAppointment(std::shared_ptr<Appointment> appointment, std::shared_ptr<Doctor> doctor); //delete a doctorAppointment in the vector of doctorAppointment
void AddToDoctorSchedule(std::shared_ptr<Doctor> doctor, std::shared_ptr<Appointment> appointment); //add an appointment in the vector of appointment of the doctor
void DeleteFromDoctorSchedule(std::shared_ptr<Doctor> doctor, std::shared_ptr<Appointment> appointment); //delete an appointment in the vector of appointment of the doctor
//more specifics methods
std::shared_ptr<Patient> FindPatient(const std::string patientId); //find a patient in the vector of patient by id
std::shared_ptr<Doctor> FindDoctor(const std::string doctorId); //find a doctor in the vector of doctor by id
std::shared_ptr<Prescription> FindPrescription(const std::string prescriptionId); //find a prescription in the vector of prescription by id
std::shared_ptr<Consultation> FindConsultation(const std::string consultationId); //find a consultation in the vector of consultation by id
std::shared_ptr<DoctorAppointment> FindDoctorAppointment(std::shared_ptr<Appointment> appointment, std::shared_ptr<Doctor> doctor); //find a doctorAppointment in the vector of doctorAppointment by appointment and doctor
std::vector<std::shared_ptr<Patient>> FindPatientByName(const std::string name); //find a patient in the vector of patient by name
std::vector<std::shared_ptr<Doctor>> FindDoctorByName(const std::string name); //find a doctor in the vector of doctor by name



//getter and setter
//getter 
std::string getName() const; //return the name of hospital
std::shared_ptr<Patient> getPatient(); //return the patient 
std::shared_ptr<Doctor> getDoctor();//return the doctor;
std::shared_ptr<Consultation> getConsultation();//return the consultation
std::shared_ptr<Appointment> getAppointment();//return the appointment
std::shared_ptr<DoctorAppointment> getDoctorAppointment();//return the doctorAppointment 
std::vector<std::shared_ptr<Patient>> getPatientList();//return the patientList
std::vector<std::shared_ptr<Doctor>> getDoctorList();//return the doctorList
std::vector<std::shared_ptr<Appointment>> getAppointmentList();//return the appointmentList
std::vector<std::shared_ptr<DoctorAppointment>> getDoctorAppointmentList();//return the doctorAppointmentList
std::vector<std::shared_ptr<Consultation>> getConsultationList();//return the consultationList
std::vector<std::shared_ptr<Prescription>> getPrescriptionList();//return the prescriptionList
//setter
void setName(std::string name); //set the name of the hospital 
void setPatientName(std::shared_ptr<Patient> patient, const std::string name); //set the patient name
void setPatientSurname(std::shared_ptr<Patient> patient, const std::string surname);//set the patient surname
void setPatientAddress(std::shared_ptr<Patient> patient, const std::string address);
void setPatientPhoneNumber(std::shared_ptr<Patient> patient, const std::string phoneNumber);
void setDoctorName(std::shared_ptr<Doctor> doctor, const std::string name);
void setDoctorSurname (std::shared_ptr<Doctor> doctor, const std::string surname);
void setDoctorAddressPhoneNumber(std::shared_ptr<Doctor> doctor,const std::string address);
void setDoctorPhoneNumber(std::shared_ptr<Doctor> doctor, const std::string phoneNumber);
void setConsultationDiagnosis(std::shared_ptr<Consultation> consultation, std::string diagnosis); //set the diagnosis of the consultation
void setConsultationSymptoms(std::shared_ptr<Consultation> consultation, std::string symptoms); //set the symptoms of the consultation
void setConsultationNote (std::shared_ptr<Consultation> consultation, std::string note); //set the notes of the consultation
void setConsultationPatient(std::shared_ptr<Consultation> consultation,std::shared_ptr<Patient> patient); //set the patient of the consultation
void setConsultationDoctor(std::shared_ptr<Consultation> consultation, std::shared_ptr<Doctor> doctor); //set the doctor of the consultation
//void setAppointmentAppoint

private:
std::string _name;
std::shared_ptr<Patient> _patient;
std::shared_ptr<Doctor> _doctor;
std::shared_ptr<Consultation> _consultation;
std::shared_ptr<Appointment> _appointment;
std::shared_ptr<DoctorAppointment> _doctorAppointment;
std::vector<std::shared_ptr<Patient>> _patientList;
std::vector<std::shared_ptr<Doctor>> _doctorList;
std::vector<std::shared_ptr<Appointment>> _appointmentList;
std::vector<std::shared_ptr<DoctorAppointment>> _doctorAppointmentList;
std::vector<std::shared_ptr<Consultation>> _consultationList;
std::vector<std::shared_ptr<Prescription>> _prescriptionList;

};

