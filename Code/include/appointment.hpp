#ifndef __APPOINTMENT__
#define __APPOINTMENT__


#include <random>
#include <vector>
#include "patient.hpp"
#include "date.hpp"

class Appointment
{
Appointment();

private:
std::string appointment_id;
Date appointment_date; // we are going to simplify the concept of time 
//std::string appointment_hour;
//Doctor doctor_info;
std::string appointment_reason;
Patient patient_info;

};
#endif