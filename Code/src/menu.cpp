#include "menu.hpp"
#include <iomanip>
#include <sstream>
#include <iostream>
#include <string>
#include <limits>
#include <memory>
#include <algorithm>
using namespace menu;



void menu::DisplayMainMenu()
{
    int choice;
    // do
    // {
        
       
        std::cout << std::string(40, '=') << "\n";
std::cout << "Welcome to " << hospital.getName() << "\n";
std::cout << std::string(40, '-') << "\n";
std::cout << std::left << std::setw(5) << "1." << "Patient\n";
std::cout << std::left << std::setw(5) << "2." << "Doctor\n";
std::cout << std::left << std::setw(5) << "3." << "Consultation\n";
std::cout << std::left << std::setw(5) << "4." << "Appointment\n";
std::cout << std::left << std::setw(5) << "5." << "Treatment\n";
std::cout << std::left << std::setw(5) << "6." << "Prescription\n";
std::cout << std::left << std::setw(5) << "7." << "Exam\n";
std::cout << std::left << std::setw(5) << "8." << "Hospitalisation\n";
std::cout << std::left << std::setw(5) << "9." << "Exit\n";
std::cout << std::string(40, '=') << "\n";
std::cout << "Enter your choice: ";
std::cin >> choice;

    //     switch (choice)
    //     {
    //         case 1:
    //             PatientMenu();
    //             break;
    //         case 2:
    //             DoctorMenu();
    //             break;
    //         case 3:
    //             ConsultationMenu();
    //             break;
    //         case 4:
    //             AppointmentMenu();
    //             break;
    //         case 5:
    //             TreatmentMenu();
    //             break;
    //         case 6:
    //             PrescriptionMenu();
    //             break;
    //         case 7:
    //             ExamMenu();
    //             break;
    //         case 8:
    //             HospitalisationMenu();
    //             break;
    //         case 9:
    //             std::cout << "Thank you for using our application" << std::endl;
    //             break;
    //         default:
    //             std::cout << "Invalid choice" << std::endl;
    //             break;
    //     }
    // } while (choice != 9);
}

void menu::PatientMenu()
{
std::string choice;
do
{
        
std::cout << "================= Menu Patient =================" << std::endl;
std::cout << "1) Ajouter patient"                             << std::endl;
std::cout << "2) Modifier patient"                            << std::endl;
std::cout << "3) Supprimer patient"                           << std::endl;
std::cout << "4) Afficher patient"                            << std::endl;
std::cout << "5) Afficher tous les patients"                   << std::endl;
std::cout << "6) Rechercher patient par NIP"                   << std::endl;
std::cout << "7) Rechercher patient par nom"                   << std::endl;
std::cout << "8) Retour"                                      << std::endl;
std::cout << "===============================================" << std::endl;
std::cout << "Votre choix: ";
std::getline(std::cin, choice);

std::stringstream ss(choice);
int choice_int;
if (ss >> choice_int && ss.eof())
{
    switch (choice_int)
    {
    case 1:
        // AddPatient
        {
            bool isValidPatient = false;
            while (!isValidPatient)
            {
                try
                {
                    std::cout << "==================== Création de Patient ====================" << std::endl;
                    std::string name, surname, adress, phone_number;
                    Birth birth;

                    std::cout << std::setw(20) << std::left << "Nom: ";
                    std::getline(std::cin, name);

                    std::cout << std::setw(20) << std::left << "Prenom: ";
                    std::getline(std::cin, surname);

                    std::cout << "Date de naissance:" << std::endl;
                    std::cout << std::setw(20) << std::left << "Jour: ";
                    std::cin >> birth.day;

                    std::cout << std::setw(20) << std::left << "Mois: ";
                    std::cin >> birth.month;

                    std::cout << std::setw(20) << std::left << "Annee: ";
                    std::cin >> birth.year;
                    std::cin.ignore();

                    std::cout << std::setw(20) << std::left << "Adresse: ";
                    std::getline(std::cin, adress);

                    std::cout << std::setw(20) << std::left << "Numero de telephone: ";
                    std::getline(std::cin, phone_number);

                    Patient patient(name, surname, birth, adress, phone_number);
                    std::shared_ptr<Patient> patientPtr = std::make_shared<Patient>(patient);
                    hospital.AddPatient(patientPtr);
                    isValidPatient = true;

                    std::cout << "================= Création du patient réussie ================" << std::endl;
                    std::cout << "Appuyez sur Entrée pour continuer...";
                    std::cin.get();
                }
                catch (const std::exception &e)
                {
                    std::cerr << "Erreur : " << e.what() << '\n';
                    std::cout << "Veuillez réessayer.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore rest of the line
                }
            }
        }
        break;
    case 2:
        // ModifyPatient
        {
            do
            {
                std::cout << "Que voulez-vous modifier ?" << std::endl;
                std::cout << "1) Nom" << std::endl;
                std::cout << "2) Prenom" << std::endl;
                std::cout << "3) Date de naissance" << std::endl;
                std::cout << "4) Numero de telephone" << std::endl;
                std::cout << "5) Retour" << std::endl;
                std::cout << "Votre choix: ";

                std::getline(std::cin, choice);
                std::stringstream ss(choice);
                int choice_int;

                if (ss >> choice_int && ss.eof())
                {
                    switch (choice_int)
                    {
                    case 1:
                    {
                        // ModifyPatientName
                        std::string patientId;
                        std::cout << "======================== Modification du nom du patient ========================" << std::endl;
                        std::cout << "Entrez le NIP du patient: ";
                        std::getline(std::cin, patientId);
                        std::transform(patientId.begin(), patientId.end(), patientId.begin(), ::toupper);
                        std::shared_ptr<Patient> patientPtr = hospital.FindPatientById(patientId);

                        if (patientPtr != nullptr)
                        {
                            bool isValidName = false;
                            while (!isValidName)
                            {
                                std::cout << "--------------------------------------------------------------------------------" << std::endl;
                                std::cout << "Entrez le nouveau nom: ";
                                std::getline(std::cin, choice);

                                // Vérifie si le nom contient des chiffres
                                if (std::any_of(choice.begin(), choice.end(), ::isdigit))
                                {
                                    std::cout << "Erreur: Le nom ne doit pas contenir de chiffres. Veuillez réessayer." << std::endl;
                                }
                                else
                                {
                                    patientPtr->setSurname(choice);
                                    std::cout << "Modification réussie" << std::endl;
                                    isValidName = true; // Sort de la boucle
                                }
                            }
                        }
                        else
                        {
                            std::cout << "--------------------------------------------------------------------------------" << std::endl;
                            std::cout << "Erreur: Patient introuvable" << std::endl;
                        }
                        std::cout << "================================================================================" << std::endl;
                        std::cout << "Appuyez sur Entrée pour continuer...";
                        std::cin.get();
                    }
                         break;

                    case 2:
                    {
                         std::string patientId;
                         std::cout << "======================== Modification du prénom du patient ========================" << std::endl;
                         std::cout << "Entrez le NIP du patient: ";
                         std::getline(std::cin, patientId);
                         std::transform(patientId.begin(), patientId.end(), patientId.begin(), ::toupper);
                         std::shared_ptr<Patient> patientPtr = hospital.FindPatientById(patientId);

                         if (patientPtr != nullptr)
                         {
                            bool isValidName = false;
                            while (!isValidName)
                            {
                                std::cout << "--------------------------------------------------------------------------------" << std::endl;
                                std::cout << "Entrez le nouveau prénom: ";
                                std::getline(std::cin, choice);

                                if (std::any_of(choice.begin(), choice.end(), ::isdigit))
                                {
                                    std::cout << "Erreur: Le prénom ne doit pas contenir de chiffres. Veuillez réessayer." << std::endl;
                                }
                                else
                                {
                                    patientPtr->setName(choice);
                                    std::cout << "Modification réussie" << std::endl;
                                    isValidName = true; // Sort de la boucle
                                }
                            }
                         }
                         else
                         {
                            std::cout << "--------------------------------------------------------------------------------" << std::endl;
                            std::cout << "Erreur: Patient introuvable" << std::endl;
                         }
                         std::cout << "================================================================================" << std::endl;
                         std::cout << "Appuyez sur Entrée pour continuer...";
                         std::cin.get();
                    }
                    case 3:
                    {
                         bool isValidDate = false;
                         std::string input;
                         Birth newBirth;

                         std::string patientId;
                         std::cout << "=================== Modification de la date de naissance du patient ===================" << std::endl;
                         std::cout << "Entrez le NIP du patient: ";
                         std::getline(std::cin, patientId);
                         std::transform(patientId.begin(), patientId.end(), patientId.begin(), ::toupper);
                         std::shared_ptr<Patient> patientPtr = hospital.FindPatientById(patientId);

                         if (patientPtr != nullptr)
                         {
                            Birth newBirth;
                            bool isValidDate = false;

                            while (!isValidDate)
                            {

                                std::cout << "Entrez le nouveau jour de naissance: ";
                                std::getline(std::cin, input);
                                std::stringstream ssDay(input);
                                if (!(ssDay >> newBirth.day) || !ssDay.eof())
                                {
                                    std::cout << "Erreur: Vous devez entrer un entier pour le jour. Veuillez réessayer.\n";
                                    continue;
                                }

                                std::cout << "Entrez le nouveau mois de naissance: ";
                                std::getline(std::cin, input);
                                std::stringstream ssMonth(input);
                                if (!(ssMonth >> newBirth.month) || !ssMonth.eof())
                                {
                                    std::cout << "Erreur: Vous devez entrer un entier pour le mois. Veuillez réessayer.\n";
                                    continue;
                                }

                                std::cout << "Entrez la nouvelle année de naissance: ";
                                std::getline(std::cin, input);
                                std::stringstream ssYear(input);
                                if (!(ssYear >> newBirth.year) || !ssYear.eof())
                                {
                                    std::cout << "Erreur: Vous devez entrer un entier pour l'année. Veuillez réessayer.\n";
                                    continue;
                                }
                                patientPtr->setBirthday(newBirth);
                                std::cout << "Modification réussie" << std::endl;
                                isValidDate = true;
                            }
                         }
                         else
                         {
                            std::cout << "--------------------------------------------------------------------------------" << std::endl;
                            std::cout << "Erreur: Patient introuvable" << std::endl;
                         }

                         std::cout << "================================================================================" << std::endl;
                         std::cout << "Appuyez sur Entrée pour continuer...";
                         std::cin.get();
                    }
                    break;

                    case 4:
                    {
                         std::string phoneNumber;
                         bool isValidPhoneNumber = false;
                        
                         std::string patientId;
                         std::cout << "=================== Modification de la date de naissance du patient ===================" << std::endl;
                         std::cout << "Entrez le NIP du patient: ";
                         std::getline(std::cin, patientId);
                         std::transform(patientId.begin(), patientId.end(), patientId.begin(), ::toupper);
                         std::shared_ptr<Patient> patientPtr = hospital.FindPatientById(patientId);

                         while (!isValidPhoneNumber)
                         {
                            std::cout << std::setw(40) << std::setfill('=') << "" << '\n';
                            std::cout << std::setw(20) << std::setfill(' ') << "Nouveau numéro de téléphone: ";
                            std::getline(std::cin, phoneNumber);

                            if (patientPtr->IsValidPhoneNumber(phoneNumber))
                            { 
                                patientPtr->setPhoneNumber(phoneNumber);
                                std::cout << std::setw(40) << std::setfill('-') << "" << '\n';
                                std::cout << "Modification réussie" << std::endl;
                                isValidPhoneNumber = true; 
                            }
                            else
                            {
                                std::cout << std::setw(40) << std::setfill('-') << "" << '\n';
                                std::cout << "Erreur: Numéro de téléphone invalide. Veuillez réessayer." << std::endl;
                            }
                            std::cout << std::setw(40) << std::setfill('=') << "" << '\n';
                         }
                    }

                          default:
                        break;
                    }
                       break;
                    }
                
                else
                {
                    while(true)
                    {
                        std::cout << "Choix invalide " << std::endl;
                        std::cout << "Votre choix: ";
                        std::getline(std::cin, choice);
                        std::stringstream ss(choice);
                        if(ss >> choice_int && ss.eof())
                        {
                            break;
                        }
                    }
                }
            } while (choice != "5");
        }
        break;
    case 3:
        // DeletePatient
        bool success = false;
        while (!success)
        {
            std::cout << std::setw(40) << std::setfill('=') << "" << '\n';
            std::cout << "Suppression de malade" << std::endl;
            std::cout << std::setw(40) << std::setfill('-') << "" << '\n';
            std::cout << "Entrez le NIP du patient: ";

            try
            {
                std::string patientId;
                std::getline(std::cin, patientId);
                std::transform(patientId.begin(), patientId.end(), patientId.begin(), ::toupper);
                hospital.DeletePatient(patientId);
                std::cout << "Suppression réussie" << std::endl;
                success = true;
            }
            catch (const std::exception &e)
            {
                std::cout << e.what() << std::endl;
                std::cout << "Veuillez réessayer.\n";
            }

            std::cout << std::setw(40) << std::setfill('=') << "" << '\n';
            std::cin.clear();
        }

        break;
    case 4:
        // DisplayPatient
        
        break;
    case 5:
        // DisplayAllPatients();
        break;
    case 6:
        // SearchPatientByNIP();
        break;
    case 7:
        // SearchPatientByName();
        break;
    default:
        std::cout << "Invalid choice" << std::endl;
        break;
    }
}
else
{
    while(true)
    {
        std::cout << "Choix invalide " << std::endl;
        std::cout << "Votre choix: ";
        std::getline(std::cin, choice);
        std::stringstream ss(choice);
        if(ss >> choice_int && ss.eof())
        {
            break;
        }
    }
}

} while (choice != "8");

}


