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
class Appointment
{
Appointment(Date& date, Patient& patient,Doctor& doctor, std::string reason);
Appointment(Date& date, Patient& patient, std::string reason);

private:
std::string appointment_id;
std::vector <Date> appointmentDate;
//Doctor doctor_info;
std::string appointment_reason;
Patient patient_info;

};
#endif