#ifndef __APPOINTMENT__
#define __APPOINTMENT__


#include <random>
#include <vector>
#include "patient.hpp"
#include "date.hpp"
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "doctor.hpp"
#include "numberGenerator.hpp"
class Appointment
{
public:
//constructor and destructor
//constructor with parameters which are the date, the patient, the doctor and the reason of the appointment
Appointment(Date& date, Patient& patient,Doctor& doctor, std::string reason); 
//constructor with parameters which are the date, the patient and the reason of the appointment
Appointment(Date& date, Patient& patient, std::string reason);
//constructor by default
Appointment() = default;

//getter and setter
std::string getAppointmentId() const;
std::vector<Date> getAppointmentDate() const;
std::string getAppointmentReason() const;
void getPatientInfo() const;
void getDoctorInfo() const;


private:
std::string appointment_id;
std::vector <Date> appointmentDate;
//Doctor doctor_info;
std::string appointment_reason;
Patient patient_info;
Doctor doctor_info;
std::string _reason;
Date _date;
Times _timeslot;

};
#endif