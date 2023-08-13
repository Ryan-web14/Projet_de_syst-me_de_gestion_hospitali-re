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
#include "patientRecord.hpp"




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
void DeletePatient(const std::string& patientId); //delete a patient in the vector of patient
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
void AddPatientRecord(std::shared_ptr<PatientRecord> patientRecord); //add a patientRecord in the vector of patientRecord
//void AddToDoctorSchedule(std::shared_ptr<Doctor> doctor, std::shared_ptr<Appointment> appointment); //add an appointment in the vector of appointment of the doctor
//void DeleteFromDoctorSchedule(std::shared_ptr<Doctor> doctor, std::shared_ptr<Appointment> appointment); //delete an appointment in the vector of appointment of the doctor
//more specifics methods
void FindPatient(const std::string& patientId); //find a patient in the vector of patient by id
std::shared_ptr<Patient> FindPatientById(const std::string& patientId); //complementary method to be use in another function
void FindDoctor(const std::string doctorId); //find a doctor in the vector of doctor by id
void FindPrescription(const std::string& prescriptionId); //find a prescription in the vector of prescription by id
void FindConsultation(const std::string& consultationId); //find a consultation in the vector of consultation by id
void FindDoctorAppointment(std::shared_ptr<Appointment> appointment, std::shared_ptr<Doctor> doctor); //find a doctorAppointment in the vector of doctorAppointment by appointment and doctor
void FindAppointment(const std::string& appointmentId);
void FindPatientByName( std::string& name); //find a patient in the vector of patient by name
void FindDoctorByName( std::string& name); //find a doctor in the vector of doctor by name
void SortAppointmentByDate(std::vector<std::shared_ptr<Appointment>>& appointmentList); //sort the appointment by date
//methods to display information
void DisplayPatientList() const; //display the list of patient
void DisplayDoctorList() const; //display the list of doctor
void DisplayPrescriptionList(std::shared_ptr<Patient> patient) const; //display the list of prescription
void DisplayConsultationList() const; //display the list of consultation
void DisplayAppointmentList() const; //display the list of appointment
void DisplayDoctorAppointmentList(std::shared_ptr<Doctor> doctor) const; //display the appointment list for a specific doctor
void DisplayDoctorSchedule(std::shared_ptr<Doctor> doctor) const; //Display the schedule of a specific doctor 
void DisplayAppointmentListForPatient(std::shared_ptr<Patient> patient) const; //display the list of appointment
void DisplayConsultationForDoctor(std::shared_ptr<Doctor> doctor) const;
//method link to the medicalRecord and patientRecord
void AddAppointmentToPatientRecord(std::string& patientId, std::shared_ptr<Appointment> appointment); //add an appointment in the vector of appointment of the patient in PatientRecord
void AddConsultationToPatientRecord(std::string& patientId, std::shared_ptr<Consultation> consultation); //add a consultation in the vector of consultation of the patient in PatientRecord
void AddPrescriptionToPatientRecord(std::string& patientId, std::shared_ptr<Prescription> prescription);//add a prescription in the vector of prescription of the patient  in PatientRecord 
void AddChronicDiseaseToPatientRecord(std::string& patientId, std::string& chronicDisease); //add a chronic disease in the vector of chronic disease of the patient in PatientRecord
void AddChronicMedicationToPatientRecord(std::string& patientId, std::string& chronicMedication); //add a chronic medication in the vector of chronic medication of the patient in PatientRecord
void AddAllergyToPatientRecord(std::string& patientId, std::string& allergy); //add an allergy in the vector of allergy of the patient in PatientRecord
void AddDoctorAppointmentToPatientRecord(std::string& patientId, std::shared_ptr<DoctorAppointment> doctorAppointment); //add a doctorAppointment in the vector of doctorAppointment of the patient in PatientRecord
void DeleteAppointmentToPatientRecord(std::string& patientId, std::shared_ptr<Appointment> appointment); //delete an appointment in the vector of appointment of the patient in PatientRecord
void DeleteConsultationToPatientRecord(std::string& patientId, std::shared_ptr<Consultation> consultation); //delete a consultation in the vector of consultation of the patient in PatientRecord
void DeletePrescriptionToPatientRecord(std::string& patientId, std::shared_ptr<Prescription> prescription); //delete a prescription in the vector of prescription of the patient in PatientRecord
void DeleteDoctorAppointmentToPatientRecord(std::string& patientId, std::shared_ptr<Appointment> Appointment, std::shared_ptr<Doctor> doctor); //delete a doctorAppointment in the vector of doctorAppointment of the patient in PatientRecord
void DisplayPatientRecord(std::string& patientId); //display the medical record of a patient   
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
std::vector<std::shared_ptr<Patient>> _patientList;
std::vector<std::shared_ptr<PatientRecord>> _patientRecordList;
std::vector<std::shared_ptr<Doctor>> _doctorList;
std::vector<std::shared_ptr<Appointment>> _appointmentList;
std::vector<std::shared_ptr<DoctorAppointment>> _doctorAppointmentList;
std::vector<std::shared_ptr<Consultation>> _consultationList;
std::vector<std::shared_ptr<Prescription>> _prescriptionList;
std::vector<DoctorSchedule> _doctorSchedule;

};

