#include "xrayExam.hpp"

//constructor with parameters
XrayExam::XrayExam(std::shared_ptr<Patient> patient, std::shared_ptr<Doctor> doctor, std::string examType, Date& examDate,double cost, std::string bodyPart,
    std::string xrayTechnique, std::string equipment) : 
Exam(patient, doctor, examType, examDate,cost), _bodyPart(bodyPart), _xrayTechnique(xrayTechnique), _equipment(equipment)
{
}

//method
void XrayExam::DisplayExam() const 
{
    std::cout << "ID Examen: " << _examId << std::endl;
    std::cout << "Patient: " << _patient->getSurname() << " " << _patient->getName() << std::endl;
    std::cout << "Practicien: " << _doctor->getSurname() << " " << _doctor->getName() << std::endl;
    std::cout << "Type Examen: " << _examType << std::endl;
    std::cout << "Date Examen: " << _examDate << std::endl;
    std::cout << "Heure de realisation Examen: " << std::put_time(std::localtime(&_examTime), "%d/%m/%Y %H:%M")<< std::endl;
    std::cout << "Partie du corps: " << _bodyPart << std::endl;
    std::cout << "tecnique utilise: " << _xrayTechnique << std::endl;
    std::cout << "Equipement: " << _equipment << std::endl;
    std::cout << "Resultat: " << _result << std::endl;
}

//getter and setter
//getter
std::string XrayExam::getBodyPart() const
{
    return _bodyPart;
}

std::string XrayExam::getXrayTechnique() const
{
    return _xrayTechnique;
}

std::string XrayExam::getEquipment() const
{
    return _equipment;
}

//setter
void XrayExam::setBodyPart(std::string bodyPart)
{
    _bodyPart = bodyPart;
}

void XrayExam::setXrayTechnique(std::string xrayTechnique)
{
    _xrayTechnique = xrayTechnique;
}

void XrayExam::setEquipment(std::string equipment)
{
    _equipment = equipment;
}
