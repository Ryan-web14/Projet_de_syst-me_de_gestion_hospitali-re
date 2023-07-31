
#include "patient.hpp"
#include "doctorSchedule.hpp"
#include <memory>





int main()
{
Patient patient1("Jean", "Dupont", "12 rue de la paix", "066950431");
//patient1.DisplayPatient();

Doctor doctor("Jean-luc", "Moretti", "12 rue de la paix", "066950431");
doctor.DisplayDoctor();

Date date(12, 12, 2020);
std::string reason = "I have a headache";
Appointment appointment(date, patient1, reason);

Times timeslot(12, 30);

appointment.setAppointmentTime(timeslot);

//appointment.DisplayAppointment();
std::cout << "\n\n";


    // Creating a new appointment

    std::shared_ptr<Appointment> _appointment = std::make_shared<Appointment>(date, patient1, "Regular checkup");
    _appointment->setAppointmentTime(timeslot);
    // Creating a new doctor appointment
    std::shared_ptr<Doctor> docPtr = std::make_shared<Doctor>(doctor);
    std::shared_ptr<DoctorAppointment> doctorAppointment = std::make_shared<DoctorAppointment>(_appointment, docPtr);

    // Creating a new doctor schedule and adding appointments
    DoctorSchedule doctorSchedule(docPtr);

    doctorSchedule.AddAppointment(_appointment);

    // Displaying the doctor's schedule
    doctorSchedule.DisplaySchedule();

return 0;
}