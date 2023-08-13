#pragma once

#include <vector>
#include <chrono>
#include <algorithm>
#include "prescription.hpp"
#include "Date.hpp"

class Treatment
{
public:
    // constructor and destructor
    // default constructor
    Treatment() = default;
    // constructor with parameters
    Treatment(std::shared_ptr<Patient> patient, std::shared_ptr<Doctor> doctor, std::string treatmentName, std::string treatmentType, std::string treatmentDescription, Date &start, Date &end);
    // destructor
    ~Treatment() = default;

    // methods
    void DisplayTreatment() const;
    void AddPrescription(std::shared_ptr<Prescription> prescription);
    void RemovePrescription(std::string IdPrescription);
    void AddBiologicalExam(std::shared_ptr<BiologicalExam> bioExam);
    void RemoveBiologicalExam(std::string IdbioExam);
    void AddXrayExam(std::shared_ptr<XrayExam> xrayExam);
    void RemoveXrayExam(std::string IdXrayExam);

    // getter and setter
    // getter
    std::string getTreatmentId() const;
    std::shared_ptr<Patient> getPatient() const;
    std::shared_ptr<Doctor> getDoctor() const;
    std::string getTreatmentType() const;
    std::string getTreatmentName() const;
    std::string getTreatmentDescription() const;
    Date getTreatmentStartDate() const;
    Date getTreatmentEndDate() const;
    std::string getTreatmentResult() const;
    std::vector<std::shared_ptr<Prescription>> getPrescriptionList() const;
    std::vector<std::shared_ptr<BiologicalExam>> getBiologicalExamList() const;
    std::vector<std::shared_ptr<XrayExam>> getXrayExamList() const;
    // setter
    void setPatient(std::shared_ptr<Patient> patient);
    void setDoctor(std::shared_ptr<Doctor> doctor);
    void setTreatmentType(std::string treatmentType);
    void setTreatmentDate(Date &date);
    void setTreatmentResult(std::string result);
    void setTreatmentDescription(std::string description);

private:
    static NumberGenerator _numberGenerator;
    std::string _treatmentId;
    std::shared_ptr<Patient> _patient;
    std::shared_ptr<Doctor> _doctor;
    std::string _treatmentType;
    std::string _treatmentName;
    std::string _treatmentDescription;
    Date _treatmentStarDate;
    Date _treatmentEndDate;
    std::string _treatmentResult;
    std::time_t _treatmentTime;
    std::vector<std::shared_ptr<Prescription>> _prescriptionList;
    std::vector<std::shared_ptr<BiologicalExam>> _biologicalExamList;
    std::vector<std::shared_ptr<XrayExam>> _xrayExamList;
};