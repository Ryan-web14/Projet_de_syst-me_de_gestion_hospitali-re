
#include "consultation.hpp"
#include "doctorSchedule.hpp"
#include <memory>




#include <iostream>
#include <memory>
#include "Consultation.hpp" // Assuming you have a Consultation.hpp header file

int main() {
    // Creating some mock consultations
    Patient patient1("Jean", "Dupont", "12 rue de la paix", "066950431");
    Doctor doctor("Jean-luc", "Moretti", "12 rue de la paix", "066950431");
    Date date(12, 12, 2023);

    std::shared_ptr<Appointment> _appointment = std::make_shared<Appointment>(date, patient1, "check-up");
    std::shared_ptr<Doctor> docPtr = std::make_shared<Doctor>(doctor);
    std::shared_ptr<DoctorAppointment> doctorAppointment = std::make_shared<DoctorAppointment>(_appointment, docPtr);

    std::shared_ptr<Patient> patientPtr = std::make_shared<Patient>(patient1);

    auto consultation1 = std::make_shared<Consultation>(patientPtr, docPtr, doctorAppointment, "Paludisme");
    consultation1->AddSymptom("fever");
    consultation1->AddSymptom("cough");
    consultation1->AddSymptom("fever");

    auto consultation2 = std::make_shared<Consultation>(patientPtr, docPtr, doctorAppointment, "Headache");
    consultation2->AddSymptom("headache");
    consultation2->AddSymptom("cough");
    consultation2->AddSymptom("fever");

    auto consultation3 = std::make_shared<Consultation>(patientPtr, docPtr, doctorAppointment, "Nausea");
    consultation3->AddSymptom("headache");
    consultation3->AddSymptom("cough");
    consultation3->AddSymptom("nausea");

    
    auto consultation4 = std::make_shared<Consultation>(patientPtr, docPtr, doctorAppointment, "Paludisme");
    consultation1->AddSymptom("fever");
    consultation1->AddSymptom("diarrhea");
    consultation1->AddSymptom("fever");

    // Putting consultations in a vector
    std::vector<std::shared_ptr<Consultation>> consultations = {consultation1, consultation2, consultation3, consultation4};
    Consultation consul;
    // Finding the most frequent symptom across all consultations
    std::string mostFrequentSymptom = consul.getMostFrequentSymptomsFromConsultation(consultations);
    std::cout << "The most frequent symptom across all consultations is: " << mostFrequentSymptom << std::endl;
    
    std::string mostFrequentDiagnosis = consul.getMostFrequentDiagnosisFromConsultation(consultations);

    // Print out the most frequent diagnosis
    std::cout << "The most frequent diagnosis is: " << mostFrequentDiagnosis << std::endl;
    return 0;
}

// int main()
// {
// Patient patient1("Jean", "Dupont", "12 rue de la paix", "066950431");
// //patient1.DisplayPatient();

// Doctor doctor("Jean-luc", "Moretti", "12 rue de la paix", "066950431");
// //doctor.DisplayDoctor();

// Date date(12, 12, 2023);
// std::string reason = "J'ai un mal de tete";
// Appointment appointment(date, patient1, reason);

// Times timeslot(12, 30);

// appointment.setAppointmentTime(timeslot);

// appointment.DisplayAppointment();
// std::cout << "\n\n";


//     // Creating a new appointment

//     std::shared_ptr<Appointment> _appointment = std::make_shared<Appointment>(date, patient1, "check-up");
//     _appointment->setAppointmentTime(timeslot);
//     // Creating a new doctor appointment
//     std::shared_ptr<Doctor> docPtr = std::make_shared<Doctor>(doctor);
//     std::shared_ptr<DoctorAppointment> doctorAppointment = std::make_shared<DoctorAppointment>(_appointment, docPtr);

//     // Creating a new doctor schedule and adding appointments
//     DoctorSchedule doctorSchedule(docPtr);

//     doctorSchedule.AddAppointment(_appointment);

//     // Displaying the doctor's schedule
//     doctorSchedule.DisplaySchedule();

//     std::shared_ptr<Patient> patientPtr = std::make_shared<Patient>(patient1);
//     // Creating a new consultation
//     Consultation consultation(patientPtr,docPtr, doctorAppointment,"Paludisme");
//     consultation.DisplayConsultationWithDiagnosis();
//  consultation.AddSymptom("Fievre");
//     consultation.AddSymptom("Maux de tete");
//     consultation.AddSymptom("Maux de ventre");
//     consultation.AddSymptom("Maux de dos");
//     consultation.AddSymptom("Maux de gorge");
//     consultation.AddSymptom("Maux de gorge");
//     consultation.DisplayConsultationWithDiagnosisAndSymptoms();
//     consultation.AddNote("Le patient a de la fievre");
//     consultation.AddNote ("Le patient a mal a la tete");
//     consultation.AddNote ("Le patient a mal au ventre");
//     consultation.DisplayConsultationWithDiagnosisAndSymptomsAndNotes();

//     std::cout << consultation.getDiagnosis();
// return 0;
// }