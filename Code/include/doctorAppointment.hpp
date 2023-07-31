#ifndef __DOCTORAPPOINTMENT__
#define __DOCTORAPPOINTMENT__

#include "appointment.hpp"
#include "doctor.hpp"
#include <memory>

class DoctorAppointment
{
public:
//default constructor
DoctorAppointment() {};
//constructor with parameters which are the smart_ptr of appointment and  doctor
DoctorAppointment(std::shared_ptr<Appointment> appointment, std::shared_ptr<Doctor> doctor);
//destructor
~DoctorAppointment() = default;

//memthod
void DisplayDoctorAppointment() const; //display the doctor appointment

//getter
std::shared_ptr<Doctor> getDoctor() const; //return the pointer doctor associated to the appointment
std::shared_ptr<Appointment> getAppointment() const; //return the pointer appointment associated to the doctor 
Date getAppointmentDate() const; //return the date of the appointment

private:
std::shared_ptr<Appointment> _appointment;
std::shared_ptr<Doctor> _doctor;
};



#endif 