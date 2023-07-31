
#include "patient.hpp"
#include "doctorSchedule.hpp"





int main()
{
Patient patient1("Jean", "Dupont", "12 rue de la paix", "066950431");
patient1.DisplayPatient();

Doctor doctor("Jean-luc", "Moretti", "12 rue de la paix", "066950431");
doctor.DisplayDoctor();

Date date(12, 12, 2020);
std::string reason = "I have a headache";
Appointment appointment(date, patient1, reason);

Times timeslot(12, 30);

appointment.setAppointmentTime(timeslot);

appointment.DisplayAppointment();

return 0;
}