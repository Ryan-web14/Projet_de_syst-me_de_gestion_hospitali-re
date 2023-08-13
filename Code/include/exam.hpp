#pragma 

#include <string>
#include <ctime>
#include <chrono>
#include <memory>
#include "patient.hpp"
#include "doctor.hpp"
#include "date.hpp"
#include "numberGenerator.hpp"


class Exam
{
    public:
    //constructor and destructor
    //default constructor
    Exam() = default;
    //constructor with parameters which are the patient, doctor,exam type)
    Exam(std::shared_ptr<Patient> patient, std::shared_ptr<Doctor> doctor, std::string examType, Date& examDate);
    //destructor
    virtual ~Exam() = default;	

    //method
    virtual void DisplayExam() const = 0; //Virtual method serving as interface for the derived classes

    //getter and setter
    //getter
    std::string getExamId() const;
    std::shared_ptr<Patient> getPatient() const;
    std::shared_ptr<Doctor> getDoctor() const;
    std::string getExamType() const;
    Date getExamDate() const;
    std::string getResult() const;
    //setter
    void setPatient(std::shared_ptr<Patient> patient);
    void setDoctor(std::shared_ptr<Doctor> doctor);
    void setExamType(std::string examType);
    void setExamDate(Date& date);
    void setResult(std::string result);

    protected:
    static NumberGenerator _numberGenerator;
    std::string _examId;
    std::shared_ptr<Patient> _patient;
    std::shared_ptr<Doctor> _doctor;
    std::string _examType;
    Date _examDate;
    std::string _result;
    std::time_t _examTime;


    

};