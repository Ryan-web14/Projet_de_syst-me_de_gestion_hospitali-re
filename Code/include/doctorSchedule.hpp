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
//constructor and destructor
//default constructor
DoctorSchedule() = default;
//constructor with parameters
DoctorSchedule(std::shared_ptr<Doctor> doctor);
//desctructor
~DoctorSchedule() = default;

//methods
//add an appointment to the schedule
void AddAppointment(std::shared_ptr<Appointment> appointment);
//remove an appointment from the schedule
void DeleteAppointment(std::shared_ptr<Appointment> appointment);
//display the schedule of the doctor
void DisplaySchedule() const;
//check if the doctor is available at a specific date
bool IsAvalaible(const Date& date) const;

//getter 
std::shared_ptr<Doctor> getDoctor() const; //return the pointer doctor associated to the schedule
std::vector<std::shared_ptr<DoctorAppointment>> getAppointmentList() const; //return the pointer appointment associated to the schedule 
private:
std::shared_ptr<Doctor> _doctor;
std::vector<std::shared_ptr<DoctorAppointment>> _appointmentList ;

};





#endif 