#include "biologicalExam.hpp"

// constructor with parameters

BiologicalExam::BiologicalExam(std::shared_ptr<Patient> patient, std::shared_ptr<Doctor> doctor, std::string examType, Date &examDate, double cost,
                               std::string biologicalSample, std::string biologicalExamTechnique, std::string typeOfAnalysis, std::string methodOfAnalysis,
                               int duration) : Exam(patient, doctor, examType, examDate,cost), _biologicalSample(biologicalSample), _biologicalExamTechnique(biologicalExamTechnique), _typeOfAnalysis(typeOfAnalysis),
                                                  _methodOfAnalysis(methodOfAnalysis), _duration(duration)

{
}

//method
void BiologicalExam::DisplayExam() const
{
    std::cout << "ID Examen: " << _examId << std::endl;
    std::cout << "Patient: " << _patient->getSurname() << " " << _patient->getName() << std::endl;
    std::cout << "Practicien: " << _doctor->getSurname() << " " << _doctor->getName() << std::endl;
    std::cout << "Type Examen: " << _examType << std::endl;
    std::cout << "Date Examen: " << _examDate << std::endl;
    std::cout << "Heure de realisation Examen: " << std::put_time(std::localtime(&_examTime), "%d/%m/%Y %H:%M") << std::endl;
    std::cout << "Echantillon biologique: " << _biologicalSample << std::endl;
    std::cout << "Technique utilise: " << _biologicalExamTechnique << std::endl;
    std::cout << "Type d'analyse: " << _typeOfAnalysis << std::endl;
    std::cout << "Methode d'analyse: " << _methodOfAnalysis << std::endl;
    std::cout << "Duree de l'analyse: " << _duration << std::endl;
}

//getter and setter
//getter
std::string BiologicalExam::getBiologicalSample() const
{
    return _biologicalSample;
}

std::string BiologicalExam::getBiologicalExamTechnique() const
{
    return _biologicalExamTechnique;
}

std::string BiologicalExam::getTypeOfAnalysis() const
{
    return _typeOfAnalysis;
}

std::string BiologicalExam::getMethodOfAnalysis() const
{
    return _methodOfAnalysis;
}

int BiologicalExam::getDuration() const
{
    return _duration;
}

//setter
void BiologicalExam::setBiologicalSample(std::string biologicalSample)
{
    _biologicalSample = biologicalSample;
}

void BiologicalExam::setBiologicalExamTechnique(std::string biologicalExamTechnique)
{
    _biologicalExamTechnique = biologicalExamTechnique;
}

void BiologicalExam::setTypeOfAnalysis(std::string typeOfAnalysis)
{
    _typeOfAnalysis = typeOfAnalysis;
}

void BiologicalExam::setMethodOfAnalysis(std::string methodOfAnalysis)
{
    _methodOfAnalysis = methodOfAnalysis;
}

void BiologicalExam::setDuration(int duration)
{
    _duration = duration;
}


