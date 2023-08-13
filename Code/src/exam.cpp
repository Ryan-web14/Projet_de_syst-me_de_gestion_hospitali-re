#include "exam.hpp"

NumberGenerator Exam::_numberGenerator(100000, 300000);

Exam::Exam(std::shared_ptr<Patient> patient, std::shared_ptr<Doctor> doctor, std::string examType, Date& examDate,double cost) :
 _patient(patient), _doctor(doctor), _examType(examType), _examDate(examDate), _cost(cost)
{
    _examId = _numberGenerator.generateNumber();
    _examTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}

//getter and setter
//getter
std::string Exam::getExamId() const
{
    return _examId;
}

std::shared_ptr<Patient> Exam::getPatient() const
{
    return _patient;
}

std::shared_ptr<Doctor> Exam::getDoctor() const
{
    return _doctor;
}

std::string Exam::getExamType() const
{
    return _examType;
}

Date Exam::getExamDate() const
{
    return _examDate;
}

std::string Exam::getResult() const
{
    return _result;
}

double Exam::getCost() const
{
    return _cost;
}

//setter
void Exam::setPatient(std::shared_ptr<Patient> patient)
{
    _patient = patient;
}

void Exam::setDoctor(std::shared_ptr<Doctor> doctor)
{
    _doctor = doctor;
}

void Exam::setExamType(std::string examType)
{
     if(examType.empty())
    {
        throw std::invalid_argument("ce champs ne peut pas etre vide!");
        return;
    }

    for(auto& c : examType)
    {
        if(!std::isalpha(c) && !std::isspace(c))
        {
            throw std::runtime_error("ce champs ne peut pas contenir de chiffre!");
            return;
        }
    }
    _examType = examType;
}

void Exam::setExamDate(Date& date)
{
    _examDate = date;
}

void Exam::setResult(std::string result)
{
      if(result.empty())
    {
        throw std::invalid_argument("ce champs ne peut pas etre vide!");
        return;
    }

    _result = result;
}



