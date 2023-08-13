#include "patientRecord.hpp"

PatientRecord::PatientRecord(std::shared_ptr<Patient> patient) : _patient(patient)
{
}

void PatientRecord::AddAppointment(std::shared_ptr<Appointment> appointment)
{
    _medicalRecord->AddAppointment(appointment);
}

void PatientRecord::RemoveAppointment(std::shared_ptr<Appointment> appointment)
{
    _medicalRecord->RemoveAppointment(appointment);
}

void PatientRecord::AddPrescription(std::shared_ptr<Prescription> prescription)
{
    _medicalRecord->AddPrescription(prescription);
}

void PatientRecord::RemovePrescription(std::shared_ptr<Prescription> prescription)
{
    _medicalRecord->RemovePrescription(prescription);
}

void PatientRecord::AddConsultation(std::shared_ptr<Consultation> consultation)
{
    _medicalRecord->AddConsultation(consultation);
}

void PatientRecord::RemoveConsultation(std::shared_ptr<Consultation> consultation)
{
    _medicalRecord->RemoveConsultation(consultation);
}

void PatientRecord::AddChronicDisease(std::string chronicDisease)
{
    _medicalRecord->AddChronicDisease(chronicDisease);
}

void PatientRecord::RemoveChronicDisease(std::string chronicDisease)
{
    _medicalRecord->RemoveChronicDisease(chronicDisease);
}

void PatientRecord::AddAllergy(std::string allergy)
{
    _medicalRecord->AddAllergy(allergy);
}

void PatientRecord::RemoveAllergy(std::string allergy)
{
    _medicalRecord->RemoveAllergy(allergy);
}

void PatientRecord::DisplayMedicalRecord() const
{
    _patient->DisplayPatient();
    _medicalRecord->DisplayMedicalRecord();
}

void PatientRecord::AddDoctorAppointment(std::shared_ptr<DoctorAppointment> doctorAppointment)
{
    _medicalRecord->AddDoctorAppointment(doctorAppointment);
}

void PatientRecord::RemoveDoctorAppointment(std::shared_ptr<Appointment> appointment, std::shared_ptr<Doctor> doctor)
{
    _medicalRecord->RemoveDoctorAppointment(appointment, doctor);
}

void PatientRecord::AddChronicMedication(std::string chronicMedication)
{
    _medicalRecord->AddChronicMedication(chronicMedication);
}

void PatientRecord::RemoveChronicMedication(std::string chronicMedication)
{
    _medicalRecord->RemoveChronicMedication(chronicMedication);
}

void PatientRecord::AddTreatement(std::shared_ptr<Treatment> treatment)
{
    _medicalRecord->AddTreatement(treatment);
}

void PatientRecord::RemoveTreatment(std::string treatmentId)
{
    _medicalRecord->RemoveTreatment(treatmentId);
}

void PatientRecord::AddXrayExam(std::shared_ptr<XrayExam> xray)
{
    _medicalRecord->
}

void PatientRecord::RemoveXrayExam(std::string xrayId)
{
    _medicalRecord->RemoveXrayExam(xrayId);
}

void PatientRecord::AddBiologicalExam(std::shared_ptr<BiologicalExam> biologicalExam)
{
    _medicalRecord->AddBiologicalExam(biologicalExam);
}

void PatientRecord::RemoveBiologicalExam(std::string bioExamId)
{
    _medicalRecord->RemoveBiologicalExam(bioExamId);
}


//getter
std::shared_ptr<Patient> PatientRecord::getPatient()
{
    return _patient;
}

std::shared_ptr<MedicalRecord> PatientRecord::getMedicalRecord() const
{
    return _medicalRecord;
}