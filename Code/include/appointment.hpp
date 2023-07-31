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
#include "numberGenerator.hpp"
#include <locale>
#include <iomanip>



class Appointment
{
public:
//constructor and destructor
//constructor with parameters which are the date, the patient and the reason of the appointment
Appointment(Date& date, Patient& patient, std::string reason);
//constructor by default
Appointment() = default;
//destructor
~Appointment() = default;

//methods   
//display the appointment
void DisplayAppointment() const;

//getter and setter
//getter
std::string getAppointmentId() const; //return appointment id
Date getAppointmentDate() const; //return appointment date
std::string getAppointmentReason() const; //return appointment reason
void getPatientInfo() const; // display patient info
//setter
void setAppointmentDate(Date& date); //set appointment date
void setAppointmentTime(Times& time); //set appointment time
//void setAppointmentReason(std::string reason); //set appointment reason

private:
std::string _appointmentId;
Date appointmentDate;
std::string _appointmentReason;
Patient _patient; //patient_info
std::string _reason;
Date _date;
//Times _timeslot;
static NumberGenerator _numberGenerator;

};
#endif