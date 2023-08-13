#pragma once 

#include <string>
#include <chrono>
#include <memory>
#include "patient.hpp"
#include "consultation.hpp"
#include "xrayExam.hpp"
#include "biologicalExam.hpp"


class Billing
{
    public:
    //constructor and destructor
    //default constructor
    Billing() = default;
    //constructor with parameters which are the patient
    Billing(std::shared_ptr<Patient> patient);
    //destructor
    ~Billing() = default;

    //method
    void AddConsultation(std::shared_ptr<Consultation> consultation);
    void AddxrayExam(std::shared_ptr<XrayExam> xrayExam);
    void AddbiologicalExam(std::shared_ptr<BiologicalExam> biologicalExam);
    void DisplayBilling() const; //display the billing
    void AddCharge();


    private:
    std::vector<std::shared_ptr<Consultation>> _consultation;
    std::vector<std::shared_ptr<XrayExam>> _xrayExam;
    std::vector<std::shared_ptr<BiologicalExam>> _biologicalExam;
    std::shared_ptr<Patient> _patient;
    double _totalCharge;
    std::string assurance;
    std::string _billingId;
    static NumberGenerator _numberGenerator;

};