
#include "consultation.hpp"
#include "doctorSchedule.hpp"
#include <memory>





int main()
{
Patient patient1("Jean", "Dupont", "12 rue de la paix", "066950431");
//patient1.DisplayPatient();

Doctor doctor("Jean-luc", "Moretti", "12 rue de la paix", "066950431");
//doctor.DisplayDoctor();

Date date(12, 12, 2023);
std::string reason = "I have a headache";
Appointment appointment(date, patient1, reason);

Times timeslot(12, 30);

appointment.setAppointmentTime(timeslot);

appointment.DisplayAppointment();
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

    std::shared_ptr<Patient> patientPtr = std::make_shared<Patient>(patient1);
    // Creating a new consultation
    Consultation consultation(patientPtr,docPtr, doctorAppointment,"Paludisme");
    consultation.DisplayConsultationWithDiagnosis();
 consultation.AddSymptom("Fievre");
    consultation.AddSymptom("Maux de tete");
    consultation.AddSymptom("Maux de ventre");
    consultation.AddSymptom("Maux de dos");
    consultation.AddSymptom("Maux de gorge");
    consultation.DisplayConsultationWithDiagnosisAndSymptoms();
    consultation.AddNote("Le patient a de la fievre");
    consultation.AddNote ("Le patient a mal a la tete");
    consultation.AddNote ("Le patient a mal au ventre");
    consultation.DisplayConsultationWithDiagnosisAndSymptomsAndNotes();

    std::cout << consultation.getDiagnosis();
return 0;
}