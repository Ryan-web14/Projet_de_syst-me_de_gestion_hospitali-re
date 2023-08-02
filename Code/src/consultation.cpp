#include "consultation.hpp"

// initialization of the static variable
//std::map<std::string, int> Consultation::_symptomFrequency;
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
        //_symptomFrequency[symptom]--;
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
    std::string title = "|                     CONSULTATION                   |";

    std::cout << "\n\033[1;36m" << separator << "\033[0m\n";
    std::cout << "\033[1;36m" << title << "\033[0m\n";
    std::cout << "\033[1;36m" << separator << "\033[0m\n";

    std::cout << "\033[1;33m|ID Consultation:\033[0m \033[1;33m" << std::left <<std::setw(38) << std::setfill(' ') << _consultationId << "|\033[0m\n";

    std::string patient_info = " Patient: " + _patient->getSurname() + " " + _patient->getName();
    std::cout << "\033[1;33m|" << std::left << std::setw(55) << std::setfill(' ')<< patient_info << "|\033[0m\n";

    std::string doctor_info = " Docteur: " + _doctor->getSurname() + " " + _doctor->getName();
    std::cout << "\033[1;33m|" << std::left << std::setw(55) << std::setfill(' ') << doctor_info << "|\033[0m\n";

    std::cout << "\033[1;36m|" << separator << "\033[0m\n\n";
}

void Consultation::DisplayConsultationWithDiagnosis() const
{
    std::string separator = "+-------------------------------------------------------+";
    std::string title = "|             CONSULTATION AVEC DIAGNOSTIQUE            |";

    std::cout << "\n\033[1;36m" << separator << "\033[0m\n";
    std::cout << "\033[1;36m" << title << "\033[0m\n";
    std::cout << "\033[1;36m" << separator << "\033[0m\n";

    std::cout << "\033[1;33m|ID Consultation:\033[0m \033[1;33m" << std::left <<std::setw(38) << std::setfill(' ') << _consultationId << "|\033[0m\n";

    std::string patient_info = " Patient: " + _patient->getSurname() + " " + _patient->getName();
    std::cout << "\033[1;33m|" << std::left << std::setw(55) << std::setfill(' ')<< patient_info << "|\033[0m\n";

    std::string doctor_info = " Docteur: " + _doctor->getSurname() + " " + _doctor->getName();
    std::cout << "\033[1;33m|" << std::left << std::setw(55) << std::setfill(' ') << doctor_info << "|\033[0m\n";

    std::string diagnosis_info = " Diagnostique: " + _diagnosis;
    std::cout << "\033[1;33m|" << std::left << std::setw(55) << std::setfill(' ') << diagnosis_info << "|\033[0m\n";

    std::cout << "\033[1;36m|" << separator << "\033[0m\n\n";
}

void Consultation::DisplayConsultationWithDiagnosisAndSymptoms() const
{
    std::string separator = "+-------------------------------------------------------+";
    std::string title = "|  CONSULTATION AVEC DIAGNOSTIQUE ET SYMPTOMES          |";

    std::cout << "\n\033[1;36m" << separator << "\033[0m\n";
    std::cout << "\033[1;36m" << title << "\033[0m\n";
    std::cout << "\033[1;36m" << separator << "\033[0m\n";

    std::cout << "\033[1;33m|ID Consultation:\033[0m \033[1;33m" << std::left <<std::setw(38) << std::setfill(' ') << _consultationId << "|\033[0m\n";

    std::string patient_info = " Patient: " + _patient->getSurname() + " " + _patient->getName();
    std::cout << "\033[1;33m|" << std::left << std::setw(55) << std::setfill(' ')<< patient_info << "|\033[0m\n";

    std::string doctor_info = " Docteur: " + _doctor->getSurname() + " " + _doctor->getName();
    std::cout << "\033[1;33m|" << std::left << std::setw(55) << std::setfill(' ') << doctor_info << "|\033[0m\n";

    std::string diagnosis_info = " Diagnostique: " + _diagnosis;
    std::cout << "\033[1;33m|" << std::left << std::setw(55) << std::setfill(' ') << diagnosis_info << "|\033[0m\n";

    std::cout << "\033[1;33m|Symptomes: \033[0m" <<"\n";
    for (auto symptom : _symptoms)
    {
        std::cout << "\033[1;33m\033[0m" << std::left << std::setw(56) << std::setfill(' ')<<symptom << "\033[1;33m|\033[0m\n";
    }

    std::cout << "\033[1;36m" << separator << "\033[0m\n\n";
}



void Consultation::DisplayConsultationWithDiagnosisAndSymptomsAndNotes() const
{
    std::string separator = "+-------------------------------------------------------+";
    std::string title = "| CONSULTATION AVEC DIAGNOSTIQUE,SYMPTOMES ET NOTE      |";

    std::cout << "\n\033[1;36m" << separator << "\033[0m\n";
    std::cout << "\033[1;36m" << title << "\033[0m\n";
    std::cout << "\033[1;36m" << separator << "\033[0m\n";

    std::cout << "\033[1;33m|ID Consultation:\033[0m \033[1;33m" << std::left <<std::setw(38) << std::setfill(' ') << _consultationId << "|\033[0m\n";

    std::string patient_info = " Patient: " + _patient->getSurname() + " " + _patient->getName();
    std::cout << "\033[1;33m|" << std::left << std::setw(55) << std::setfill(' ')<< patient_info << "|\033[0m\n";

    std::string doctor_info = " Docteur: " + _doctor->getSurname() + " " + _doctor->getName();
    std::cout << "\033[1;33m|" << std::left << std::setw(55) << std::setfill(' ') << doctor_info << "|\033[0m\n";

    std::string diagnosis_info = " Diagnostique: " + _diagnosis;
    std::cout << "\033[1;33m|" << std::left << std::setw(55) << std::setfill(' ') << diagnosis_info << "|\033[0m\n";

    std::cout << "\033[1;33m|Symptomes: \033[0m" <<"\n";
    for (auto symptom : _symptoms)
    {
        std::cout << "\033[1;33m|\033[0m" << std::left << std::setw(55) << std::setfill(' ') << symptom << "\033[1;33m|\033[0m\n";
    }

    std::cout << "\033[1;33m|Notes: \033[0m" <<"\n";
    for (auto note : _notes)
    {
        std::cout << "\033[1;33m|\033[0m" << std::left << std::setw(55) << std::setfill(' ') << note << "\033[1;33m|\033[0m\n";
    }

    std::cout << "\033[1;36m" << separator << "\033[0m\n\n";
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

//getter and setter
//getter
std::string Consultation::getConsultationId() const
{
    return _consultationId;
}

std::string Consultation::getDiagnosis() const
{
    return _diagnosis;
}

std::vector<std::string> Consultation::getSymptoms() const
{
    return _symptoms;
}

std::vector<std::string> Consultation::getNotes() const
{
    return _notes;
}

std::shared_ptr<Patient> Consultation::getPatient() const
{
    return _patient;
}

std::shared_ptr<Doctor> Consultation::getDoctor() const
{
    return _doctor;
}

double Consultation::getCost() const
{
    return _cost;
}



//setter
void Consultation::setDiagnosis(std::string diagnosis)
{
    if(diagnosis.empty())
    {
        throw std::invalid_argument("Diagnosis cannot be empty");
    }
    _diagnosis = diagnosis;
}
//Chercher comment modifier un string particulier dans un tableau 
// void Consultation::setSymptoms(std::vector<std::string> symptoms)
// {
//     if(symptoms.empty())
//     {
//         throw std::invalid_argument("Symptoms cannot be empty");
//     }
//     _symptoms = symptoms;
// }

// void Consultation::setNotes(std::vector<std::string> notes)
// {
    
// }

void Consultation::setPatient(std::shared_ptr<Patient> patient)
{
    if(patient == nullptr)
    {
        throw std::invalid_argument("Patient cannot be null");
    }
    _patient = patient;
}

void Consultation::setDoctor(std::shared_ptr<Doctor> doctor)
{
    if(doctor == nullptr)
    {
        throw std::invalid_argument("Doctor cannot be null");
    }
    _doctor = doctor;
}

void Consultation::setCost(double cost)
{
    if(cost < 0)
    {
        throw std::invalid_argument("Cost cannot be negative");
    }
    _cost = cost;
}

void Consultation::setFollowUps(std::shared_ptr<DoctorAppointment> followUps)
{

}
//other methods

std::string Consultation::getMostFrequentSymptoms() const
{
    if(_symptoms.empty())
    {
        throw std::runtime_error("Symptoms is empty");
    }

    std::map<std::string, int> symptomsMap;
    for(auto& symptom : _symptoms)
    {
        symptomsMap[symptom]++;
    }

    std::string mostFrequentSymptom = _symptoms[0];
    int max = symptomsMap[mostFrequentSymptom];

    for(const auto& symptom : symptomsMap)
    {
        if(symptom.second > max)
        {
            mostFrequentSymptom = symptom.first;
            max = symptom.second;
        }
    }

    return mostFrequentSymptom;
}

std::string Consultation::getMostFrequentSymptomsFromConsultation(std::vector<std::shared_ptr<Consultation>> consultationList) const 
{
    std::vector<std::string> symptomsList;
    for(auto& consultList : consultationList)
    {
     std::vector<std::string> symptoms;
     symptoms = consultList->getSymptoms();
     symptomsList.insert(symptomsList.end(), symptoms.begin(), symptoms.end());
    }

    std::map<std::string, int> symptomsMap;
    for(auto& symptom : symptomsList)
    {
        symptomsMap[symptom]++;
    }
    std::string mostFrequentSymptom = symptomsList[0];
    int max = symptomsMap[mostFrequentSymptom];

    for(const auto& symptom : symptomsMap)
    {
        if(symptom.second > max)
        {
            mostFrequentSymptom = symptom.first;
            max = symptom.second;
        }
    }

    return mostFrequentSymptom;
}

std::string Consultation::getMostFrequentDiagnosisFromConsultation(std::vector<std::shared_ptr<Consultation>> consultationList) const
{
    std::vector<std::string> diagnosisList;
    for(auto& consult : consultationList)
    {
        diagnosisList.push_back(consult->getDiagnosis());
    }
    std::map<std::string, int> diagnosisMap;
    for(auto& diagnosis : diagnosisList)
    {
        diagnosisMap[diagnosis]++;
    }
    std::string mostFrequentDiagnosis = diagnosisList[0];
    int max = diagnosisMap[mostFrequentDiagnosis];

    for(const auto& diagnosis : diagnosisMap)
    {
        if(diagnosis.second > max)
        {
            mostFrequentDiagnosis = diagnosis.first;
            max = diagnosis.second;
        }
    }

    return mostFrequentDiagnosis;
}
