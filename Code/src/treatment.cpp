#include "treatment.hpp"

NumberGenerator Treatment::_numberGenerator(100000, 999999);

//constructor with parameters
Treatment::Treatment(std::shared_ptr<Patient> patient, std::shared_ptr<Doctor> doctor,std::string treatmentName,
 std::string treatmentType,std::string treatmentDescription, Date& start , Date& end) : 
 _patient(patient), _doctor(doctor), _treatmentType(treatmentType), _treatmentStarDate(start), _treatmentEndDate(end)
 {
   std::transform(std::begin(treatmentType), std::end(treatmentType), std::begin(treatmentType), ::toupper);
   std::transform(std::begin(treatmentName), std::end(treatmentName), std::begin(treatmentName), ::toupper);
    _treatmentId = _numberGenerator.generateNumber();
    
    _treatmentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    _treatmentName = treatmentName;
    _treatmentDescription = treatmentDescription;
    _treatmentType = treatmentType;

 }

//methods
void Treatment::AddBiologicalExam(std::shared_ptr<BiologicalExam> bioExam)
{
    _biologicalExamList.push_back(bioExam);
}

void Treatment::RemoveBiologicalExam(std::string IdbioExam)
{
    auto it = std::remove_if(std::begin(_biologicalExamList), std::end(_biologicalExamList), [&IdbioExam](const std::shared_ptr<BiologicalExam>bioexam)
    {return bioexam->getExamId() == IdbioExam;});

    if(it != std::end(_biologicalExamList))
    {
        _biologicalExamList.erase(it, std::end(_biologicalExamList));
        std::cout << "Suppression effectue" << std::endl;
    }
    else 
    {
        throw std::runtime_error("Examen non trouve"); 
    }
}

void Treatment::AddXrayExam(std::shared_ptr<XrayExam> xrayExam)
{
    _xrayExamList.push_back(xrayExam);
}

void Treatment::RemoveXrayExam(std::string IdXrayExam)
{
    auto it = std::remove_if(std::begin(_xrayExamList), std::end(_xrayExamList), [&IdXrayExam](const std::shared_ptr<XrayExam>xrayexam)
    {return xrayexam->getExamId() == IdXrayExam;});

    if(it != std::end(_xrayExamList))
    {
        _xrayExamList.erase(it, std::end(_xrayExamList));
        std::cout << "Suppression effectue" << std::endl;
    }
    else 
    {
        throw std::runtime_error("Examen non trouve"); 
    }
}

void Treatment::AddPrescription(std::shared_ptr<Prescription> prescription)
{
    _prescriptionList.push_back(prescription);
}

void Treatment::RemovePrescription(std::string IdPrescription)
{
    auto it = std::remove_if(std::begin(_prescriptionList), std::end(_prescriptionList), [&IdPrescription](const std::shared_ptr<Prescription>prescription)
    {return prescription->getPrescriptionId() == IdPrescription;});

    if(it != std::end(_prescriptionList))
    {
        _prescriptionList.erase(it, std::end(_prescriptionList));
        std::cout << "Suppression effectue" << std::endl;
    }
    else 
    {
        throw std::runtime_error("Prescription non trouve"); 
    }
}

//getter and setter 
//getter
std::string Treatment::getTreatmentId() const
{
    return _treatmentId;
}

std::shared_ptr<Patient> Treatment::getPatient() const
{
    return _patient;
}

std::shared_ptr<Doctor> Treatment::getDoctor() const
{
    return _doctor;
}

std::string Treatment::getTreatmentType() const
{
    return _treatmentType;
}

Date Treatment::getTreatmentStartDate() const
{
    return _treatmentStarDate;
}

Date Treatment::getTreatmentEndDate() const
{
    return _treatmentEndDate;
}

std::string Treatment::getTreatmentResult() const
{
    return _treatmentResult;
}

std::vector<std::shared_ptr<Prescription>> Treatment::getPrescriptionList() const
{
    return _prescriptionList;
}

std::vector<std::shared_ptr<BiologicalExam>> Treatment::getBiologicalExamList() const
{
    return _biologicalExamList;
}

std::vector<std::shared_ptr<XrayExam>> Treatment::getXrayExamList() const
{
    return _xrayExamList;
}

std::string Treatment::getTreatmentName() const
{
    return _treatmentName;
}

std::string Treatment::getTreatmentDescription() const
{
    return _treatmentDescription;
}

//setter
void Treatment::setPatient(std::shared_ptr<Patient> patient)
{
    _patient = patient;
}

void Treatment::setDoctor(std::shared_ptr<Doctor> doctor)
{
    _doctor = doctor;
}

void Treatment::setTreatmentType(std::string treatmentType)
{
     if(treatmentType.empty())
    {
        throw std::invalid_argument("Ce champs ne peut pas etre vide!");
        return;
    }

    for(auto& c : treatmentType)
    {
        if(!std::isalpha(c) && !std::isspace(c))
        {
            throw std::runtime_error("Le type de traitement ne peut pas contenir des chiffres!");
            return;
        }
    }
    _treatmentType = treatmentType;
}

void Treatment::setTreatmentDate(Date& date)
{
    _treatmentStarDate = date;
}

void Treatment::setTreatmentResult(std::string result)
{
    _treatmentResult = result;
}

void Treatment::setTreatmentDescription(std::string description)
{
     if(description.empty())
    {
        throw std::invalid_argument("Ce champs ne peut pas etre vide!");
        return;
    }

    for(auto& c : description)
    {
        if(!std::isalpha(c) && !std::isspace(c))
        {
            throw std::runtime_error("La description du traitement ne peut pas contenir des chiffres!");
            return;
        }
    }

    _treatmentDescription = description;
}

//display the treatment
void Treatment::DisplayTreatment() const
{
    std::cout << "Traitement numero : " << _treatmentId << std::endl;
    std::cout << "Nom du traitement : " << _treatmentName << std::endl;
    std::cout << "Description du traitement : " << _treatmentDescription << std::endl;
    std::cout << "Type de traitement : " << _treatmentType << std::endl;
    std::cout << "Date de debut du traitement : " << _treatmentStarDate << std::endl;
    std::cout << "Date de fin du traitement : " << _treatmentEndDate << std::endl;
    std::cout << "Resultat du traitement : " << _treatmentResult << std::endl;
    std::cout << "Patient : " << _patient->getSurname() << " " << _patient->getName() << std::endl;
    std::cout << "Docteur : " << _doctor->getSurname() << " " << _doctor->getName() << std::endl;
    std::cout << "Prescriptions : " << std::endl;
    for(auto& prescription : _prescriptionList)
    {
        prescription->DisplayPrescription();
    }
    std::cout << "Examens biologiques : " << std::endl;
    for(auto& bioExam : _biologicalExamList)
    {
        bioExam->DisplayExam();
    }
    std::cout << "Examens radiologiques : " << std::endl;
    for(auto& xrayExam : _xrayExamList)
    {
        xrayExam->DisplayExam();
    }
}