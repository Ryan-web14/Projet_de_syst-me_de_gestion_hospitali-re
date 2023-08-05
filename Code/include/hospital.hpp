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
std::vector<std::shared_ptr<DoctorAppointment>> DoctorAppointmentList;
std::vector<std::shared_ptr<Consultation>> _consultationList;
std::vector<std::shared_ptr<Prescription>> _prescriptionList;

};

