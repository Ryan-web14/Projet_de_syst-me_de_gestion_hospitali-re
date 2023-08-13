#pragma once

#include "exam.hpp"

class BiologicalExam :public Exam
{
    public:
    //constructor and destructor
    //default constructor
    BiologicalExam() = default;
    //constructor with parameters
    BiologicalExam(std::shared_ptr<Patient> patient, std::shared_ptr<Doctor> doctor, std::string examType, Date& examDate, double cost,
     std::string biologicalSample, std::string biologicalExamTechnique,std::string typeOfAnalysis,std::string methodOfAnalysis,int duration);
    //destructor
    ~BiologicalExam() = default;

    //method
    void DisplayExam() const override; //display the exam
    
    //getter and setter 
    //getter
    std::string getBiologicalSample() const;
    std::string getBiologicalExamTechnique() const;
    std::string getTypeOfAnalysis() const;
    std::string getMethodOfAnalysis() const;
    int getDuration() const;
    //setter
    void setBiologicalSample(std::string biologicalSample);
    void setBiologicalExamTechnique(std::string biologicalExamTechnique);
    void setTypeOfAnalysis(std::string typeOfAnalysis);
    void setMethodOfAnalysis(std::string methodOfAnalysis);
    void setDuration(int duration);

    private:
    std::string _biologicalSample;
    std::string _biologicalExamTechnique;
    std::string _typeOfAnalysis;
    std::string _methodOfAnalysis;
    int _duration;
    
};