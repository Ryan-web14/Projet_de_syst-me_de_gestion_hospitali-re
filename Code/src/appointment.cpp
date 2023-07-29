#include "appointment.hpp"



void Appointment::getPatientInfo() const
{
    patient_info.DisplayPatient();
}

void Appointment::getDoctorInfo() const
{
    doctor_info.DisplayDoctor();
}