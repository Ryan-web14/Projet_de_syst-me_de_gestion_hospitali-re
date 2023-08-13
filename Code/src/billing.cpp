#include "billing.hpp"

NumberGenerator Billing::_numberGenerator(1000, 9999);

Billing::Billing(std::shared_ptr<Patient> patient) : _patient(patient)
{
    _billingId = _numberGenerator.generateNumber();
    _totalCharge = 0;
}

void Billing::AddConsultation(std::shared_ptr<Consultation> consultation)
{
    _consultation.push_back(consultation);
}

void Billing::AddxrayExam(std::shared_ptr<XrayExam> xrayExam)
{
    _xrayExam.push_back(xrayExam);
}

void Billing::AddBiologicalExam(std::shared_ptr<BiologicalExam> biologicalExam)
{
    _biologicalExam.push_back(biologicalExam);
}

void Billing::AddCharge()
{
    for(auto& consultation : _consultation)
    {
        _totalCharge += consultation->getCost();
    }

    for(auto& xrayExam : _xrayExam)
    {
        _totalCharge += xrayExam->getCost();
    }

    for(auto& biologicalExam : _biologicalExam)
    {
        _totalCharge += biologicalExam->getCost();
    }
}

#include <iomanip> // for std::setw

void Billing::DisplayBilling() const
{
    std::cout << "================= Facture =================" << std::endl;
    std::cout << "Patient: " << _patient->getSurname() << " " << _patient->getName() << std::endl;
    std::cout << "Numero de facture: " << _billingId << std::endl;
    std::cout << "===========================================" << std::endl;

    std::cout << "Consultations:" << std::endl;
    for (auto& consultation : _consultation)
    {
        std::cout << "  ID: " << std::setw(5) << consultation->getConsultationId() << " | Cost: " << std::setw(10) << consultation->getCost() << std::endl;
    }
    std::cout << "-------------------------------------------" << std::endl;

    std::cout << "Examens radiologiques:" << std::endl;
    for (auto& xrayExam : _xrayExam)
    {
        std::cout << "  ID: " << std::setw(5) << xrayExam->getExamId() << " | Date: " << xrayExam->getExamDate() << " | Cost: " << std::setw(10) << xrayExam->getCost() << std::endl;
    }
    std::cout << "-------------------------------------------" << std::endl;

    std::cout << "Examens biologiques:" << std::endl;
    for (auto& biologicalExam : _biologicalExam)
    {
        std::cout << "  ID: " << std::setw(5) << biologicalExam->getExamId() << " | Date: " << biologicalExam->getExamDate() << " | Cost: " << std::setw(10) << biologicalExam->getCost() << std::endl;
    }
    std::cout << "===========================================" << std::endl;

    std::cout << "Total : " << std::setw(10) << _totalCharge << std::endl;
    std::cout << "===========================================" << std::endl;
}


// void Billing::DisplayBilling() const
// {
//     std::cout << "Facture du patient: " << _patient->getSurname() << " " << _patient->getName() << std::endl;
//     std::cout << "Numero de facture: " << _billingId << "\n\n";

//     std::cout << "Consultations:\n";
//     std::cout << std::left << std::setw(20) << "Consultation ID" << std::setw(10) << "Cost" << std::endl;
//     std::cout << std::string(30, '-') << std::endl;
//     for (auto& consultation : _consultation)
//     {
//         std::cout << std::setw(20) << consultation->getConsultationId() << std::setw(10) << consultation->getCost() << std::endl;
//     }

//     std::cout << "\nExamens radiologiques:\n";
//     std::cout << std::left << std::setw(20) << "Exam ID" << std::setw(20) << "Date" << std::setw(10) << "Cost" << std::endl;
//     std::cout << std::string(50, '-') << std::endl;
//     for (auto& xrayExam : _xrayExam)
//     {
//         std::cout << std::setw(20) << xrayExam->getExamId() << std::setw(20) << xrayExam->getExamDate() << std::setw(10) << xrayExam->getCost() << std::endl;
//     }

//     std::cout << "\nExamens biologiques:\n";
//     std::cout << std::left << std::setw(20) << "Exam ID" << std::setw(20) << "Date" << std::setw(10) << "Cost" << std::endl;
//     std::cout << std::string(50, '-') << std::endl;
//     for (auto& biologicalExam : _biologicalExam)
//     {
//         std::cout << std::setw(20) << biologicalExam->getExamId() << std::setw(20) << biologicalExam->getExamDate() << std::setw(10) << biologicalExam->getCost() << std::endl;
//     }

//     std::cout << "\nTotal: " << _totalCharge << std::endl;
// }
