

#include <memory>


#include "hospital.hpp"

#include <iostream>
#include <memory>


int main() {





Birth birth;
birth.day = 12;
birth.month = 12;
birth.year = 2000;
    // Creating some mock consultations
    Patient patient1("kean", "Dupont",birth, "12 rue de la paix", "066950431");
    Patient patient2("auc", "coco",birth, "12 rue de la paix", "066770431");
    Doctor doctor("Jean-luc", "Moretti",birth, "12 rue mboula", "066950431");
    Doctor doctor2("Joel", "Yollei",birth, "12 rue de la danse", "066957851");
   
//     Doctor doctor("Jean-luc", "Moretti", "12 rue de la paix", "066950431");
    Date date(12, 12, 2023);

    std::shared_ptr<Appointment> _appointment = std::make_shared<Appointment>(date, patient1, "checkup");
    std::shared_ptr<Doctor> docPtr = std::make_shared<Doctor>(doctor);
    std::shared_ptr<DoctorAppointment> doctorAppointment = std::make_shared<DoctorAppointment>(_appointment, docPtr);
  std::shared_ptr<Doctor> docPtr2 = std::make_shared<Doctor>(doctor2);
    std::shared_ptr<Appointment> _appointment2 = std::make_shared<Appointment>(date, patient2, "critical wound");
    std::shared_ptr<DoctorAppointment> doctorAppointment2 = std::make_shared<DoctorAppointment>(_appointment2, docPtr2);
    auto patientPtr2 = std::make_shared<Patient>(patient2);
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



    Prescription prescription(patientPtr, docPtr);
    prescription.AddMedecine("Doliprane", "1", "3" , "5", "avant les repas");
    prescription.AddMedecine("Confantrine", "1", "3" , "5", "avant les repas");
  
  auto prescription1 = std::make_shared<Prescription>(prescription);

    Hospital hospital("JoJo Hospital");

    hospital.AddConsultation(consultation1);
    hospital.AddConsultation(consultation2);
    hospital.AddConsultation(consultation3);
    hospital.AddPrescription(prescription1);
    hospital.AddPatient(patientPtr2);
    hospital.AddDoctor(docPtr2);
    hospital.AddDoctor(docPtr);
    hospital.AddPatient(patientPtr);
    hospital.AddAppointment(_appointment);
    hospital.AddAppointment(_appointment2);
    
    try{
        hospital.DisplayAppointmentList();
    hospital.DisplayDoctorList();
    hospital.DisplayPatientList();
    hospital.DisplayConsultationList();
    hospital.DisplayPrescriptionList(patientPtr);
    std::cout << "-------------------" << std::endl;
    std::cout <<"Entrer le numero du rendez vous a supprimer" << std::endl;
    std::string num;
    std::cin >> num;
    hospital.DeleteAppointment(num);
    hospital.DisplayAppointmentList();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
   
    prescription.DisplayPrescription();

    try
    {
        prescription.RemoveMedecine("Doliprane");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    // prescription.DisplayPrescription();
//  Birth birth;
// birth.day = 12;
// birth.month = 12;
// birth.year = 2000;
//     Patient patient1 ("Jean", "Dupont", birth, "12 rue de la paix", "066950431");
//     patient1.DisplayPatient();

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