#include "doctorAppointment.hpp"


//constructors
DoctorAppointment::DoctorAppointment(std::shared_ptr<Appointment> appointment, std::shared_ptr<Doctor> doctor)
{
    _appointment = appointment;
    _doctor = doctor;
}


//getter
std::shared_ptr<Doctor> DoctorAppointment::getDoctor() const
{
    return _doctor;
}

std::shared_ptr<Appointment> DoctorAppointment::getAppointment() const
{
    return _appointment;
}

Date DoctorAppointment::getAppointmentDate() const
{
     return _appointment->getAppointmentDate();
}

//method
void DoctorAppointment::DisplayDoctorAppointment() const
{
     std::cout << "Doctor: " << _doctor->getName() << std::endl;
    _appointment->DisplayAppointment();
    return;
}
