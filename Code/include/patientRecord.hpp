#pragma once

#include <memory>
#include <string>
#include "medicalRecord.hpp"

class PatientRecord
{
public:
    // constructor and destructor
    // constructor with parameters which are the smart_ptr of patient
    PatientRecord(std::shared_ptr<Patient> patient);
    // default constructor
    PatientRecord() = default;
    // destructor
    ~PatientRecord() = default;

    //getter
    std::shared_ptr<Patient> getPatient();
    std::shared_ptr<MedicalRecord> getMedicalRecord() const;

    // methods
    void AddAppointment(std::shared_ptr<Appointment> appointment);
    void RemoveAppointment(std::shared_ptr<Appointment> appointment);
    void AddDoctorAppointment(std::shared_ptr<DoctorAppointment> doctorAppointment);
    void RemoveDoctorAppointment(std::shared_ptr<Appointment> appointment, std::shared_ptr<Doctor> doctor);
    void AddPrescription(std::shared_ptr<Prescription> prescription);
    void RemovePrescription(std::shared_ptr<Prescription> prescription);
    void AddConsultation(std::shared_ptr<Consultation> consultation);
    void RemoveConsultation(std::shared_ptr<Consultation> consultation);
    void AddChronicDisease(std::string chronicDisease);
    void RemoveChronicDisease(std::string chronicDisease);
    void AddChronicMedication(std::string chronicMedication);
    void RemoveChronicMedication(std::string chronicMedication);
    void AddAllergy(std::string allergy);
    void RemoveAllergy(std::string allergy);
    void AddTreatement(std::shared_ptr<Treatment> treatment);
    void RemoveTreatment(std::string treatmentId);
    void AddXrayExam(std::shared_ptr<XrayExam> xray);
    void RemoveXrayExam(std::string xrayId);
    void AddBiologicalExam(std::shared_ptr<BiologicalExam> biologicalExam);
    void RemoveBiologicalExam(std::string bioExamId);
    void DisplayMedicalRecord() const;

private:
    std::shared_ptr<Patient> _patient;
    std::shared_ptr<MedicalRecord> _medicalRecord;
};
