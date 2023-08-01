#include "consultation.hpp"

// initialization of the static variable
std::map<std::string, int> Consultation::_symptomFrequency;
NumberGenerator Consultation::_numberGenerator(100000, 999999);

// constructors
Consultation::Consultation(std::shared_ptr<Patient> patient, std::shared_ptr<Doctor> doctor, std::shared_ptr<DoctorAppointment> doctorAppointment, std::string diagnosis)
{
    _consultationId = _numberGenerator.generateNumber();
    _patient = patient;
    _doctor = doctor;
    _doctorAppointment = doctorAppointment;
    _diagnosis = diagnosis;
    _cost = 0;
    _isPaid = false;
}

// methods
void Consultation::AddSymptom(std::string symptom)
{
    _symptoms.push_back(symptom);
    return;
}

bool Consultation::DeleteSymptom(std::string symptom)
{
    auto it = std::find(std::begin(_symptoms), std::end(_symptoms), symptom);
    if (it != std::end(_symptoms))
    {
        _symptoms.erase(it);
        _symptomFrequency[symptom]--;
        return true; //return true if the symptom has been deleted
    }
    return false; //return false if the symptom has not been deleted
}

void Consultation::AddNote (std::string note)
{
    _notes.push_back(note);
    return;
}

void Consultation::DisplayConsultation() const
{
    std::string separator = "+-------------------------------------------------------+";
    std::string title = "|                     CONSULTATION                      |";

    std::cout << "\n\033[1;36m" << separator << "\033[0m\n";
    std::cout << "\033[1;36m" << title << "\033[0m\n";
    std::cout << "\033[1;36m" << separator << "\033[0m\n";

    std::cout << "\033[1;33m|Consultation ID:\033[0m \033[1;33m" << std::left <<std::setw(38) << std::setfill(' ') << _consultationId << "|\033[0m\n";

    std::string patient_info = " Patient: " + _patient->getSurname() + " " + _patient->getName();
    std::cout << "\033[1;33m|" << std::left << std::setw(55) << std::setfill(' ')<< patient_info << "|\033[0m\n";

    std::string doctor_info = " Doctor: " + _doctor->getSurname() + " " + _doctor->getName();
    std::cout << "\033[1;33m|" << std::left << std::setw(55) << std::setfill(' ') << doctor_info << "|\033[0m\n";

    std::cout << "\033[1;36m|" << separator << "\033[0m\n\n";
}

void Consultation::DisplayConsultationWithDiagnosis() const
{
    std::string separator = "+-------------------------------------------------------+";
    std::string title = "|             CONSULTATION WITH DIAGNOSIS               |";

    std::cout << "\n\033[1;36m" << separator << "\033[0m\n";
    std::cout << "\033[1;36m" << title << "\033[0m\n";
    std::cout << "\033[1;36m" << separator << "\033[0m\n";

    std::cout << "\033[1;33m|Consultation ID:\033[0m \033[1;33m" << std::left <<std::setw(38) << std::setfill(' ') << _consultationId << "|\033[0m\n";

    std::string patient_info = " Patient: " + _patient->getSurname() + " " + _patient->getName();
    std::cout << "\033[1;33m|" << std::left << std::setw(55) << std::setfill(' ')<< patient_info << "|\033[0m\n";

    std::string doctor_info = " Doctor: " + _doctor->getSurname() + " " + _doctor->getName();
    std::cout << "\033[1;33m|" << std::left << std::setw(55) << std::setfill(' ') << doctor_info << "|\033[0m\n";

    std::string diagnosis_info = " Diagnosis: " + _diagnosis;
    std::cout << "\033[1;33m|" << std::left << std::setw(55) << std::setfill(' ') << diagnosis_info << "|\033[0m\n";

    std::cout << "\033[1;36m|" << separator << "\033[0m\n\n";
}

void Consultation::DisplayConsultationWithDiagnosisAndSymptoms() const
{
    std::string separator = "+-------------------------------------------------------+";
    std::string title = "|  CONSULTATION WITH DIAGNOSIS AND SYMPTOMS             |";

    std::cout << "\n\033[1;36m" << separator << "\033[0m\n";
    std::cout << "\033[1;36m" << title << "\033[0m\n";
    std::cout << "\033[1;36m" << separator << "\033[0m\n";

    std::cout << "\033[1;33m|Consultation ID:\033[0m \033[1;33m" << std::left <<std::setw(38) << std::setfill(' ') << _consultationId << "|\033[0m\n";

    std::string patient_info = " Patient: " + _patient->getSurname() + " " + _patient->getName();
    std::cout << "\033[1;33m|" << std::left << std::setw(55) << std::setfill(' ')<< patient_info << "|\033[0m\n";

    std::string doctor_info = " Doctor: " + _doctor->getSurname() + " " + _doctor->getName();
    std::cout << "\033[1;33m|" << std::left << std::setw(55) << std::setfill(' ') << doctor_info << "|\033[0m\n";

    std::string diagnosis_info = " Diagnosis: " + _diagnosis;
    std::cout << "\033[1;33m|" << std::left << std::setw(55) << std::setfill(' ') << diagnosis_info << "|\033[0m\n";

    std::cout << "\033[1;33m|Symptoms: \033[0m" <<"\n";
    for (auto symptom : _symptoms)
    {
        std::cout << "\033[1;33m\033[0m" << std::left << std::setw(56) << std::setfill(' ')<<symptom << "\033[1;33m|\033[0m\n";
    }

    std::cout << "\033[1;36m" << separator << "\033[0m\n\n";
}



void Consultation::DisplayConsultationWithDiagnosisAndSymptomsAndNotes() const
{
    std::cout << "Id de consultation : " << _consultationId << std::endl;
    std::cout <<"Patient: " << _patient->getSurname() << " " << _patient->getName() << std::endl;
    std::cout <<"Docteur: " << _doctor->getSurname() << " " << _doctor->getName() << std::endl;
    std::cout <<"Diagnostique: " << _diagnosis << std::endl;
    std::cout <<"Symptomes: ";
    for (auto symptom : _symptoms)
    {
        std::cout << symptom << " ";
    }
    std::cout << std::endl;
    std::cout <<"Notes: ";
    for (auto note : _notes)
    {
        std::cout << note << " ";
    }
    std::cout << std::endl;
}

void Consultation::DisplayConsultationWithDiagnosisAndSymptomsAndNotesAndCost() const
{
    std::cout << "Id de consultation : " << _consultationId << std::endl;
    std::cout <<"Patient: " << _patient->getSurname() << " " << _patient->getName() << std::endl;
    std::cout <<"Docteur: " << _doctor->getSurname() << " " << _doctor->getName() << std::endl;
    std::cout <<"Diagnostique: " << _diagnosis << std::endl;
    std::cout <<"Symptomes: ";
    for (auto symptom : _symptoms)
    {
        std::cout << symptom << " ";
    }
    std::cout << std::endl;
    std::cout <<"Notes: ";
    for (auto note : _notes)
    {
        std::cout << note << " ";
    }
    std::cout << std::endl;
    std::cout <<"Coût: " << _cost << std::endl;
}


