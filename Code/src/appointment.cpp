#include "appointment.hpp"
#include "doctor.hpp"

//initialization of the static variable
NumberGenerator Appointment::_numberGenerator(10000, 99999);

//constructor with parameters which are the date, the patient and the reason of the appointment
Appointment::Appointment(Date& date, Patient& patient, std::string reason)
{
    
    _appointmentId = _numberGenerator.generateNumber();
    appointmentDate = date;
    _patient = patient;
    _appointmentReason = reason;
}

//getter
void Appointment::getPatientInfo() const
{
    _patient.DisplayPatient();
}

Date Appointment::getAppointmentDate() const
{
    return appointmentDate;
}

void Appointment::DisplayAppointment() const
{
    std::cout << "\n\033[1;35m=====================================================\033[0m\n";
    std::cout << "\033[1;36m\t\tAPPOINTMENT DETAILS\033[0m\n";
    std::cout << "\033[1;35m=====================================================\033[0m\n";

    std::cout << "\033[1;33mAppointment ID:\033[0m " << std::left << std::setw(0) << _appointmentId << "\n\n";

   std::cout << "\033[1;33mAppointment Date:\033[0m " << std::left << std::setw(0) << appointmentDate.ToLongDate() <<" a " <<appointmentDate.getTime() << std::setw(0) << "\n\n";

    std::cout << "\033[1;33mAppointment Reason:\033[0m \n" << std::left << std::setw(0) << _appointmentReason << "\n\n";

    std::cout << "\033[1;33mPatient Details:\033[0m \n";
    _patient.DisplayPatient();

    std::cout << "\033[1;35m=====================================================\033[0m\n\n";
}


//setter
void Appointment::setAppointmentDate(Date& date)
{
    appointmentDate = date;
    return;
}

void Appointment::setAppointmentTime(Times& time)
{
    appointmentDate.setTime(time);
    return;
}