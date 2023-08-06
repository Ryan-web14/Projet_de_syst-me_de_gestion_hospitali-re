#include "prescription.hpp"

NumberGenerator Prescription::_numberGenerator(10000,99999);

Prescription::Prescription(std::shared_ptr<Patient> patient, std::shared_ptr<Doctor> doctor) : _patient(patient), _doctor(doctor)
{
    _prescriptionId = _numberGenerator.generateNumber();
  _prescriptionDate = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}

//methods
void Prescription::AddMedecine(std::string name, std::string dosage, std::string frequency, std::string duration, std::string precision)
{
    std::transform(std::begin(name), std::end(name), std::begin(name), ::toupper); //transform the name to uppercase
    std::transform(std::begin(dosage), std::end(dosage), std::begin(dosage), ::toupper); //transform the dosage to uppercase
    std::transform(std::begin(frequency), std::end(frequency), std::begin(frequency), ::toupper); //transform the frequency to uppercase
    std::transform(std::begin(duration), std::end(duration), std::begin(duration), ::toupper); //transform the duration to uppercase
    std::transform(std::begin(precision), std::end(precision), std::begin(precision), ::toupper); //transform the precision to uppercase

    Medecine medecine;
    medecine.name = name;
    medecine.dosage = dosage;
    medecine.frequency = frequency;
    medecine.duration = duration;
    medecine.precision = precision;
    _medecines.push_back(medecine);
}

void Prescription::RemoveMedecine(std::string name)
{
    if(name.empty()) //throw an exception if the name is empty
    {
        throw std::invalid_argument("Invalid name");
    }

    std::transform(std::begin(name),std::end(name),std::begin(name), ::toupper); //transform the name to uppercase

  auto it = std::remove_if(std::begin(_medecines), std::end(_medecines),[&name](const Medecine& medecine){return medecine.name == name;});
  if(it != std::end(_medecines))
  {
    _medecines.erase(it);
    std::cout << "Suppression effectue" << std::endl;
  }
  else 
  {
    throw std::runtime_error("Medicament non trouve"); //throw an exception if the medecine is not found
  }
}

void Prescription::DisplayPrescription() const
{
 Birth birth =_patient->getBirthday();
 std::cout << "Numero de prescription: " << _prescriptionId << std::endl;
 std::cout << "Practicien: " << _doctor->getName() << " " <<_doctor->getSurname() <<" phone number "<<_doctor->getPhoneNumber()<< std::endl;
 std::cout << "Patient: " << _patient->getName() << _patient->getSurname() << std::endl;
 std::cout<<" Numero patient " <<_patient->getPermanentNumber() <<std::endl;
 std::cout <<"Date de naissance:" << birth.day << "/" << birth.month << "/" << birth.year << std::endl;
 std::cout << "Date de la prescription: " << std::put_time(std::localtime(&_prescriptionDate), "%d/%m/%Y %H:%M") << std::endl;
 std::cout <<"Medicaments: " << std::endl;
    for(const auto& medecine : _medecines)
    {
        std::cout << "Nom: " << medecine.name << std::endl;
        std::cout << "Dosage: " << medecine.dosage << " Unite(s) * " << medecine.frequency <<" / Jour"<< std::endl;
        std::cout << "Duree: " << medecine.duration << " J "<<std::endl;
        std::cout << "Precision: " << medecine.precision << std::endl;
    }
 
}
/*void Prescription::DisplayPrescription() const
{
    std::string separator = "+--------------------------------------------------------------------------------------------------+";
    std::string title = "|                                         PRESCRIPTION                                             |";

    std::cout << "\n\033[1;36m" << separator << "\033[0m\n";
    std::cout << "\033[1;36m" << title << "\033[0m\n";
    std::cout << "\033[1;36m" << separator << "\033[0m\n";

    std::cout << "\033[1;33m|Prescription ID:\033[0m \033[1;33m" << std::left <<std::setw(78) << std::setfill(' ') << _prescriptionId << "|\033[0m\n";

    std::string practitioner_info = " Practitioner: " + _doctor->getName() + " " + _doctor->getSurname() + " (Phone number: " + _doctor->getPhoneNumber() + ")";
    std::cout << "\033[1;33m|" << std::left << std::setw(95) << std::setfill(' ')<< practitioner_info << "|\033[0m\n";

    std::string patient_info = " Patient: " + _patient->getName() + " " + _patient->getSurname() + " (Patient Number: " + _patient->getPermanentNumber() + ")";
    std::cout << "\033[1;33m|" << std::left << std::setw(95) << std::setfill(' ') << patient_info << "|\033[0m\n";

    std::time_t t = std::time(nullptr);
    char mbstr[100];
    if (std::strftime(mbstr, sizeof(mbstr), "%d/%m/%Y %H:%M", std::localtime(&t))) {
        std::string date_info = " Prescription Date: " + std::string(mbstr);
        std::cout << "\033[1;33m|" << std::left << std::setw(95) << std::setfill(' ') << date_info << "|\033[0m\n";
    }

    std::cout << "\033[1;36m" << separator << "\033[0m\n";

    std::cout << "\033[1;33m|Medicines: \033[0m\n";
    for(const auto& medecine : _medecines)
    {
        std::cout << "\033[1;33m| - Name:\033[0m " << medecine.name << "\n";
        std::cout << "\033[1;33m|   Dosage:\033[0m " << medecine.dosage << " (" << medecine.frequency << " times a day for " << medecine.duration << " days)\n";
        std::cout << "\033[1;33m|   Instructions:\033[0m " << medecine.precision << "\n";
        std::cout << "\033[1;36m" << separator << "\033[0m\n";
    }
}*/


//getter and setter
//setter
void Prescription::setPatient(std::shared_ptr<Patient> patient)
{
    _patient = patient;
}

void Prescription::setDoctor(std::shared_ptr<Doctor> doctor)
{
    _doctor = doctor;
}

//getter
std::shared_ptr<Patient> Prescription::getPatient() const
{
    return _patient;
}

std::shared_ptr<Doctor> Prescription::getDoctor() const
{
    return _doctor;
}

std::vector<Medecine> Prescription::getMedecines() const
{
    return _medecines;
}

std::string Prescription::getPrescriptionId() const
{
    return _prescriptionId;
}