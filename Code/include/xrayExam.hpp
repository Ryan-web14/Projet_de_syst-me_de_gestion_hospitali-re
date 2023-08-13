#pragma once 

#include "exam.hpp"


class XrayExam : public Exam
{
    public:
    //constructor and destructor
    //default constructor
    XrayExam() = default;
    //constructor with parameters
    XrayExam(std::shared_ptr<Patient> patient, std::shared_ptr<Doctor> doctor, std::string examType, Date& examDate, std::string bodyPart,
    std::string xrayTechnique, std::string equipment);
    //destructor
    ~XrayExam() = default;

    //method
    void DisplayExam() const override; //display the exam
    
    //getter and setter
    //getter
    std::string getBodyPart() const;
    std::string getXrayTechnique() const;
    std::string getEquipment() const;
    //setter
    void setBodyPart(std::string bodyPart);
    void setXrayTechnique(std::string xrayTechnique);
    void setEquipment(std::string equipment);

    private:
    std::string _bodyPart;
    std::string _xrayTechnique;
    std::string _equipment;


};
