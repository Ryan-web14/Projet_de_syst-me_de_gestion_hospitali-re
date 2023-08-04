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
       if(reason.empty())
    {
        throw std::invalid_argument("La raison de votre rendez-vous ne peut pas etre vide!");
        return;
    }
    
    for(auto& c : reason)
    {
        if(!std::isalpha(c) && !std::isspace(c))
        {
            throw std::runtime_error("La raison de votre rendez-vous ne peut pas contenir des chiffres!");
            return;
        }
    }
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
    std::cout << "\033[1;36m\t\tDETAIL DE RENDEZ-VOUS\033[0m\n";
    std::cout << "\033[1;35m=====================================================\033[0m\n";

    std::cout << "\033[1;33m ID rendez-vous:\033[0m " << std::left << std::setw(0) << _appointmentId << "\n\n";

   std::cout << "\033[1;33m Date rendez-vous:\033[0m " << std::left << std::setw(0) << appointmentDate.ToLongDate() <<" a " <<appointmentDate.getTime() << std::setw(0) << "\n\n";

    std::cout << "\033[1;33m Raison de rendez-vous :\033[0m \n" << std::left << std::setw(0) << _appointmentReason << "\n\n";

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

void Appointment::setPatient(Patient& patient)
{
    _patient = patient;
    return;
}

void Appointment::setReason(std::string reason)
{
    if(reason.empty())
    {
        throw std::invalid_argument("La raison de votre rendez-vous ne peut pas etre vide!");
        return;
    }

    for(auto& c : reason)
    {
        if(!std::isalpha(c) && !std::isspace(c))
        {
            throw std::runtime_error("La raison de votre rendez-vous ne peut pas contenir des chiffres!");
            return;
        }
    }
    _appointmentReason = reason;
    return;
}