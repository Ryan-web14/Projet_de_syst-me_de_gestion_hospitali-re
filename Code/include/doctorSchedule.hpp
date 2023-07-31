#ifndef __DOCTORSCHEDULE__
#define __DOCTORSCHEDULE__

//will manage the schedule of the doctor and the appointment

#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>
#include "doctorAppointment.hpp"


class DoctorSchedule
{
public:
//default constructor
DoctorSchedule() = default;
//constructor with parameters
DoctorSchedule(std::shared_ptr<Doctor> doctor);
//methods
//add an appointment to the schedule
void AddAppointment(std::shared_ptr<Appointment> appointment);
//remove an appointment from the schedule
void DeleteAppointment(std::shared_ptr<Appointment> appointment);
//display the schedule of the doctor
void DisplaySchedule() const;
//check if the doctor is available at a specific date
bool IsAvalaible(const Date& date) const;

private:
std::shared_ptr<Doctor> _doctor;
std::vector<std::shared_ptr<DoctorAppointment>> _appointmentList ;

};





#endif 