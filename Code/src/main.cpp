
// #include <iostream>
// #include <conio.h>

// int main() {
//     int choice = 0;
//     const int NUMBER_OF_CHOICES = 3;
//     const char* choices[] = {
//         "Option 1",
//         "Option 2",
//         "Exit"
//     };

//     while (true) {
//         // Display menu
//         system("cls");
//         for (int i = 0; i < NUMBER_OF_CHOICES; ++i) {
//             if (i == choice) {
//                 std::cout << " > "; // Highlight the selected choice
//             } else {
//                 std::cout << "   ";
//             }
//             std::cout << choices[i] << '\n';
//         }

//         // Get user input
//         char ch = _getch();

//         // Handle input
//         switch (ch) {
//             case 72: // Up arrow key
//                 if (choice > 0) --choice;
//                 break;
//             case 80: // Down arrow key
//                 if (choice < NUMBER_OF_CHOICES - 1) ++choice;
//                 break;
//             case 13: // Enter key
//                 if (choice == NUMBER_OF_CHOICES - 1) // Exit option
//                     return 0;
//                 else
//                     std::cout << "You chose: " << choices[choice] << "\n";
//                     system("pause");
//                 break;
//         }
//     }
//     return 0;
// }

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
    Patient patient2("kean", "coco",birth, "12 rue de la paix", "066770431");
    Doctor doctor("Jean-luc", "Moretti",birth, "12 rue mboula", "066950431");
    Doctor doctor2("Joel", "Yollei",birth, "12 rue de la danse", "066957851");
   
//     Doctor doctor("Jean-luc", "Moretti", "12 rue de la paix", "066950431");
    Date date(12, 12, 2023);
    Times time(12,12);
    date.setTime(time);

    std::shared_ptr<Appointment> _appointment = std::make_shared<Appointment>(date, patient1, "checkup");
    std::shared_ptr<Doctor> docPtr = std::make_shared<Doctor>(doctor);

  
    std::shared_ptr<DoctorAppointment> doctorAppointment = std::make_shared<DoctorAppointment>(_appointment, docPtr);
  std::shared_ptr<Doctor> docPtr2 = std::make_shared<Doctor>(doctor2);
      Date date1(12, 12, 2023);
    Times time1(13,15);
    date1.setTime(time1);
    std::shared_ptr<Appointment> _appointment2 = std::make_shared<Appointment>(date1, patient2, "critical wound");
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
    hospital.AddDoctorAppointment(doctorAppointment2);
    hospital.AddDoctorAppointment(doctorAppointment2);
    //try{
    //     hospital.DisplayAppointmentList();
    // hospital.DisplayDoctorList();
    // hospital.DisplayPatientList();
    // hospital.DisplayConsultationList();
     hospital.DisplayPrescriptionList(patientPtr);
    //hospital.DisplayDoctorAppointmentList(docPtr2);
    std::cout << "-------------------" << std::endl;
    // std::cout <<"Entrer le numero du rendez vous a supprimer" << std::endl;
    // std::string num;
    // std::cin >> num;
    std::cout << "entrer le nom du patient à rechercher ";
    std::string name;
    std::cin >> name;
    hospital.FindPatientByName(name);
    //hospital.DeleteAppointment(num);
    //hospital.DisplayAppointmentList();
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
   
    // prescription.DisplayPrescription();

    // try
    // {
    //     prescription.RemoveMedecine("Doliprane");
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
    // prescription.DisplayPrescription();
//  Birth birth;
// birth.day = 12;
// birth.month = 12;
// birth.year = 2000;
//     Patient patient1 ("Jean", "Dupont", birth, "12 rue de la paix", "066950431");
//     patient1.DisplayPatient();

    return 0;
}

// // int main()
// // {
// // Patient patient1("Jean", "Dupont", "12 rue de la paix", "066950431");
// // //patient1.DisplayPatient();

// // Doctor doctor("Jean-luc", "Moretti", "12 rue de la paix", "066950431");
// // //doctor.DisplayDoctor();

// // Date date(12, 12, 2023);
// // std::string reason = "J'ai un mal de tete";
// // Appointment appointment(date, patient1, reason);

// // Times timeslot(12, 30);

// // appointment.setAppointmentTime(timeslot);

// // appointment.DisplayAppointment();
// // std::cout << "\n\n";


// //     // Creating a new appointment

// //     std::shared_ptr<Appointment> _appointment = std::make_shared<Appointment>(date, patient1, "check-up");
// //     _appointment->setAppointmentTime(timeslot);
// //     // Creating a new doctor appointment
// //     std::shared_ptr<Doctor> docPtr = std::make_shared<Doctor>(doctor);
// //     std::shared_ptr<DoctorAppointment> doctorAppointment = std::make_shared<DoctorAppointment>(_appointment, docPtr);

// //     // Creating a new doctor schedule and adding appointments
// //     DoctorSchedule doctorSchedule(docPtr);

// //     doctorSchedule.AddAppointment(_appointment);

// //     // Displaying the doctor's schedule
// //     doctorSchedule.DisplaySchedule();

// //     std::shared_ptr<Patient> patientPtr = std::make_shared<Patient>(patient1);
// //     // Creating a new consultation
// //     Consultation consultation(patientPtr,docPtr, doctorAppointment,"Paludisme");
// //     consultation.DisplayConsultationWithDiagnosis();
// //  consultation.AddSymptom("Fievre");
// //     consultation.AddSymptom("Maux de tete");
// //     consultation.AddSymptom("Maux de ventre");
// //     consultation.AddSymptom("Maux de dos");
// //     consultation.AddSymptom("Maux de gorge");
// //     consultation.AddSymptom("Maux de gorge");
// //     consultation.DisplayConsultationWithDiagnosisAndSymptoms();
// //     consultation.AddNote("Le patient a de la fievre");
// //     consultation.AddNote ("Le patient a mal a la tete");
// //     consultation.AddNote ("Le patient a mal au ventre");
// //     consultation.DisplayConsultationWithDiagnosisAndSymptomsAndNotes();

// //     std::cout << consultation.getDiagnosis();
// // return 0;
//  }