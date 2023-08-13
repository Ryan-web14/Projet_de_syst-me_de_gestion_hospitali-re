#include "hospitalisation.hpp"

NumberGenerator Hospitalisation::_numberGenerator(100000, 999999);

Hospitalisation::Hospitalisation(std::shared_ptr<Patient> patient, std::shared_ptr<Doctor> doctor, std::string hospitalisationReason, int hospitalisationDuration,std::string hospitalisationLocation)
    : _patient(patient), _doctor(doctor), _hospitalisationLocation(hospitalisationLocation)
    
{
    std::transform(std::begin(hospitalisationReason), std::end(hospitalisationReason), std::begin(hospitalisationReason), ::tolower);
    _hospitalisationStartDate = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    _hospitalisationDuration = hospitalisationDuration;


    //to define the end date we are going to do some operation on the time
    //we are going to add the duration to the start date
    std::chrono::duration<int, std::ratio<24*60*60>> duration(_hospitalisationDuration);
    std::chrono::system_clock::time_point endDate = std::chrono::system_clock::from_time_t(_hospitalisationStartDate) + duration;
    
    //convert the endDate so it's printable
    hospitalisationEndDate = std::chrono::system_clock::to_time_t(endDate);
    
     if(hospitalisationReason.empty())
    {
        throw std::invalid_argument("La raison de l'hospitalisation  ne peut pas etre vide!");
        return;
    }
    
    for(auto& c :hospitalisationReason)
    {
        if(!std::isalpha(c) && !std::isspace(c))
        {
            throw std::runtime_error("La raison de l'hospitalisation ne peut pas contenir des chiffres!");
            return;
        }
    }
    _hospitalisationReason = hospitalisationReason;
}

//methods
void Hospitalisation::AddTreatment(std::shared_ptr<Treatment> treatment)
{
    _treatments.push_back(treatment);
}

void Hospitalisation::RemoveTreatment(std::string IdTreatment)
{
    auto it = std::remove_if(std::begin(_treatments), std::end(_treatments), [&IdTreatment](const std::shared_ptr<Treatment>treatment)
    {return treatment->getTreatmentId() == IdTreatment;});

    if(it != std::end(_treatments))
    {
        _treatments.erase(it, std::end(_treatments));
        std::cout << "Suppression effectue" << std::endl;
    }
    else 
    {
        throw std::runtime_error("Traitement non trouve"); 
    }
}

void Hospitalisation::AddPrescription(std::shared_ptr<Prescription> prescription)
{
    _prescriptions.push_back(prescription);
}

void Hospitalisation::RemovePrescription(std::string IdPrescription)
{
    auto it = std::remove_if(std::begin(_prescriptions), std::end(_prescriptions), [&IdPrescription](const std::shared_ptr<Prescription>prescription)
    {return prescription->getPrescriptionId() == IdPrescription;});

    if(it != std::end(_prescriptions))
    {
        _prescriptions.erase(it, std::end(_prescriptions));
        std::cout << "Suppression effectue" << std::endl;
    }
    else 
    {
        throw std::runtime_error("Prescription non trouve"); 
    }
}

void Hospitalisation::AddBiologicalExam(std::shared_ptr<BiologicalExam> bioExam)
{
    _biologicalExams.push_back(bioExam);
}

void Hospitalisation::RemoveBiologicalExam(std::string IdbioExam)
{
    auto it = std::remove_if(std::begin(_biologicalExams), std::end(_biologicalExams), [&IdbioExam](const std::shared_ptr<BiologicalExam>bioexam)
    {return bioexam->getExamId() == IdbioExam;});

    if(it != std::end(_biologicalExams))
    {
        _biologicalExams.erase(it, std::end(_biologicalExams));
        std::cout << "Suppression effectue" << std::endl;
    }
    else 
    {
        throw std::runtime_error("Examen biologique non trouve"); 
    }
}

void Hospitalisation::AddXrayExam(std::shared_ptr<XrayExam> xrayExam)
{
    _xrayExams.push_back(xrayExam);
}

void Hospitalisation::RemoveXrayExam(std::string IdXrayExam)
{
    auto it = std::remove_if(std::begin(_xrayExams), std::end(_xrayExams), [&IdXrayExam](const std::shared_ptr<XrayExam>xrayexam)
    {return xrayexam->getExamId() == IdXrayExam;});

    if(it != std::end(_xrayExams))
    {
        _xrayExams.erase(it, std::end(_xrayExams));
        std::cout << "Suppression effectue" << std::endl;
    }
    else 
    {
        throw std::runtime_error("Examen non trouve"); 
    }
}


void Hospitalisation::ProlongHospitalisationDuration(int daysToAdd)
{
    _hospitalisationDuration += daysToAdd;
    std::chrono::duration<int, std::ratio<24*60*60>> totalDuration(_hospitalisationDuration);
    std::chrono::system_clock::time_point endDate = std::chrono::system_clock::from_time_t(_hospitalisationStartDate) + totalDuration;
    
    // Convert the endDate so it's printable
    hospitalisationEndDate = std::chrono::system_clock::to_time_t(endDate);
}




void Hospitalisation::DisplayHospitalisation() const
{
    std::cout << "Id hospitalisation: " << _hospitalisationId << std::endl;
    std::cout << "Patient: " << _patient->getSurname() << " " << _patient->getName() << std::endl;
    std::cout << "Medecin: " << _doctor->getSurname() << " " << _doctor->getName() << std::endl;
    std::cout << "Date de debut: " << std::ctime(&_hospitalisationStartDate) << std::endl;
    std::cout << "Date de fin: " << std::ctime(&hospitalisationEndDate) << std::endl;
    std::cout << "Raison: " << _hospitalisationReason << std::endl;
    std::cout << "Duree: " << _hospitalisationDuration << std::endl;
    std::cout << "Localisation: " << _hospitalisationLocation << std::endl;
    std::cout << "Traitement: " << std::endl;
    for(auto treatment : _treatments)
    {
        treatment->DisplayTreatment();
    }
    std::cout << "Prescription: " << std::endl;
    for(auto prescription : _prescriptions)
    {
        prescription->DisplayPrescription();
    }
    std::cout << "Examen biologique: " << std::endl;
    for(auto bioExam : _biologicalExams)
    {
        bioExam->DisplayExam();
    }
    std::cout << "Examen radiologique: " << std::endl;
    for(auto xrayExam : _xrayExams)
    {
        xrayExam->DisplayExam();
    }
}

//getter and setter
//getter
std::string Hospitalisation::getHospitalisationId() const
{
    return _hospitalisationId;
}

std::shared_ptr<Patient> Hospitalisation::getPatient() const
{
    return _patient;
}

std::shared_ptr<Doctor> Hospitalisation::getDoctor() const
{
    return _doctor;
}

std::string Hospitalisation::getHospitalisationReason() const
{
    return _hospitalisationReason;
}

std::string Hospitalisation::getHospitalisationLocation() const
{
    return _hospitalisationLocation;
}

int Hospitalisation::getHospitalisationDuration() const
{
    return _hospitalisationDuration;
}

time_t Hospitalisation::getHospitalisationStartDate() const
{
    return _hospitalisationStartDate;
}

time_t Hospitalisation::getHospitalisationEndDate() const
{
    return hospitalisationEndDate;
}

std::vector<std::shared_ptr<Treatment>> Hospitalisation::getTreatmentList() const
{
    return _treatments;
}

std::vector<std::shared_ptr<Prescription>> Hospitalisation::getPrescriptionList() const
{
    return _prescriptions;
}

std::vector<std::shared_ptr<BiologicalExam>> Hospitalisation::getBiologicalExamList() const
{
    return _biologicalExams;
}

std::vector<std::shared_ptr<XrayExam>> Hospitalisation::getXrayExamList() const
{
    return _xrayExams;
}

//setter
void Hospitalisation::setPatient(std::shared_ptr<Patient> patient)
{
    _patient = patient;
}

void Hospitalisation::setDoctor(std::shared_ptr<Doctor> doctor)
{
    _doctor = doctor;
}

void Hospitalisation::setHospitalisationReason(std::string& reason)
{
     if(reason.empty())
    {
        throw std::invalid_argument("La raison de l'hospitalisation  ne peut pas etre vide!");
        return;
    }
    
    for(auto& c :reason)
    {
        if(!std::isalpha(c) && !std::isspace(c))
        {
            throw std::runtime_error("La raison de l'hospitalisation ne peut pas contenir des chiffres!");
            return;
        }
    }

    _hospitalisationReason = reason;
}

void Hospitalisation::setHospitalisationDuration(int duration)
{
    
    _hospitalisationDuration = duration;
}

void Hospitalisation::setEmergencyContact(EmergencyContact& contact)
{
    _contact = contact;
}

