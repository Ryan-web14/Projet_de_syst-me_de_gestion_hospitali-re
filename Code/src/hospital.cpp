#include "hospital.hpp"	

Hospital::Hospital(std::string name)
{
    _name = name;
}

//methods
void Hospital::AddPatient(std::shared_ptr<Patient> patient)
{
    _patientList.push_back(patient);
}

void Hospital::DeletePatient(const std::string patientId)
{
    auto it = std::remove_if(std::begin(_patientList),std::end(_patientList),[&patientId](std::shared_ptr<Patient> patient)
    {return patient->getPermanentNumber() == patientId;});
    if(it != std::end(_patientList))
    {
        _patientList.erase(it);
    }
    else
    {
        throw std::runtime_error("Patient not found");
    }
}

void Hospital::AddDoctor(std::shared_ptr<Doctor> doctor)
{
    _doctorList.push_back(doctor);
}

void Hospital::DeleteDoctor(const std::string doctorId)
{
    auto it = std::remove_if(std::begin(_doctorList),std::end(_doctorList),[&doctorId](std::shared_ptr<Doctor> doctor)
    {return doctor->getPhoneNumber() == doctorId;});
    if(it != std::end(_doctorList))
    {
        _doctorList.erase(it);
    }
    else
    {
        throw std::runtime_error("Doctor not found");
    }
}

void Hospital::AddPrescription(std::shared_ptr<Prescription> prescription)
{
    _prescriptionList.push_back(prescription);
}

void Hospital::DeletePrescription(const std::string prescriptionId)
{
    auto it = std::remove_if(std::begin(_prescriptionList),std::end(_prescriptionList),[&prescriptionId](std::shared_ptr<Prescription> prescription)
    {return prescription->getPrescriptionId() == prescriptionId;});
    if(it != std::end(_prescriptionList))
    {
        _prescriptionList.erase(it);
    }
    else
    {
        throw std::runtime_error("Prescription not found");
    }
}

void Hospital::AddConsultation(std::shared_ptr<Consultation> consultation)
{
    _consultationList.push_back(consultation);
}

void Hospital::DeleteConsultation(const std::string consultationId)
{
    auto it = std::remove_if(std::begin(_consultationList),std::end(_consultationList),[&consultationId](std::shared_ptr<Consultation> consultation)
    {return consultation->getConsultationId() == consultationId;});
    if(it != std::end(_consultationList))
    {
        _consultationList.erase(it);
    }
    else
    {
        throw std::runtime_error("Consultation not found");
    }
}

void Hospital::AddAppointment(std::shared_ptr<Appointment> appointment)
{
    _appointmentList.push_back(appointment);
}

void Hospital::DeleteAppointment(const std::string appointmentId)
{
    auto it = std::remove_if(std::begin(_appointmentList),std::end(_appointmentList),[&appointmentId](std::shared_ptr<Appointment> appointment)
    {return appointment->getAppointmentId() == appointmentId;});
    if(it != std::end(_appointmentList))
    {
        _appointmentList.erase(it);
    }
    else
    {
        throw std::runtime_error("Appointment not found");
    }
}

void Hospital::AddDoctorAppointment(std::shared_ptr<DoctorAppointment> doctorAppointment)
{
    _doctorAppointmentList.push_back(doctorAppointment);
}