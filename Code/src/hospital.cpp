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
        throw std::runtime_error("Patient non trouve");
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
        throw std::runtime_error("Docteur non trouve");
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
        throw std::runtime_error("Prescription non trouvee");
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
        throw std::runtime_error("Consultation non trouve");
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
        throw std::runtime_error("rendez-vous non trouve");
    }
}

void Hospital::AddDoctorAppointment(std::shared_ptr<DoctorAppointment> doctorAppointment)
{
    _doctorAppointmentList.push_back(doctorAppointment);
}

void Hospital::DeleteDoctorAppointment(std::shared_ptr<Appointment> appointment, std::shared_ptr<Doctor> doctor)
{
    auto it = std::remove_if(std::begin(_doctorAppointmentList),std::end(_doctorAppointmentList),
    [&appointment,&doctor](std::shared_ptr<DoctorAppointment> doctorAppointment){return doctorAppointment->getAppointment() == appointment && doctorAppointment->getDoctor() == doctor;});

    if(it != std::end(_doctorAppointmentList))
    {
        _doctorAppointmentList.erase(it);
    }
    else
    {
        throw std::runtime_error("Pas de rendez-vous de docteur");
    }
}


// void Hospital::AddToDoctorSchedule(std::shared_ptr<Doctor> doctor, std::shared_ptr<Appointment> appointment)
// {
//     auto it = std::find_if(std::begin(_doctorList), std::end(_doctorList),[&doctor](std::shared_ptr<Doctor> doc)
//     {return doc->getDoctorNumber() == doctor->getDoctorNumber();});
// }

//methods for displaying
void Hospital::DisplayPatientList() const
{
    std::cout << "Liste des patient " << std::endl;
    for(auto patient : _patientList)
    {
       patient->DisplayPatient();
    }
}

void Hospital::DisplayDoctorList() const
{
    std::cout << "Liste des docteurs " << std::endl;
    for(auto doctor : _doctorList)
    {
       doctor->DisplayDoctor();
    }
}

void Hospital::DisplayAppointmentList() const
{
    std::cout << "Liste des rendez-vous" << std::endl;
    for(auto appointment : _appointmentList)
    {
       appointment->DisplayAppointment();
    }
}

void Hospital::DisplayConsultationList() const
{
    std::cout << "Liste de consultation" << std::endl;
    for(auto consultation : _consultationList)
    {
       consultation->DisplayConsultationWithDiagnosis();
    }
}

void Hospital::DisplayPrescriptionList(std::shared_ptr<Patient> patient) const
{
    std::cout << "Prescription list: " << std::endl;
    for(auto prescription : _prescriptionList)
    {
        if(prescription->getPatient() == patient)
       prescription->DisplayPrescription();
    }
}

void Hospital::DisplayDoctorAppointmentList(std::shared_ptr<Doctor> doctor) const
{
    auto it = find_if(std::begin(_doctorList),std::end(_doctorList), [&doctor](std::shared_ptr<Doctor> doc)
    {return doc->getDoctorNumber() == doctor->getDoctorNumber();});

    if(it != std::end(_doctorList))
    {
        std::cout << "Liste de rendez-vous des docteurs" << std::endl;
        for(auto doctorAppointment : _doctorAppointmentList)
        {
            if(doctorAppointment->getDoctor() == doctor)
            {
                doctorAppointment->DisplayDoctorAppointment();
            }
        }
    }
    else if(it !=std::end(_doctorList) && _doctorAppointmentList.empty())
    {
        std::cout << "Liste de rendez-vous des docteurs vide" << std::endl;
    }
    else 
    {
        throw std::runtime_error("Docteur non trouve");
    }
}

void Hospital::DisplayConsultationForDoctor(std::shared_ptr<Doctor> doctor) const
{
    auto it = find_if(std::begin(_doctorList),std::end(_doctorList), [&doctor](std::shared_ptr<Doctor> doc)
    {return doc->getDoctorNumber() == doctor->getDoctorNumber();});

    if(it != std::end(_doctorList))
    {
        std::cout << "Consultation list: " << std::endl;
        for(auto consultation : _consultationList)
        {
            if(consultation->getDoctor() == doctor)
            {
                consultation->DisplayConsultationWithDiagnosis();
            }
        }
    }
    else if(it !=std::end(_doctorList) && _consultationList.empty())
    {
        std::cout << " Liste de consultation vide " << std::endl;
    }
    else 
    {
        throw std::runtime_error("Docteur non trouve");
    }
}

void Hospital::DisplayAppointmentListForPatient(std::shared_ptr<Patient> patient) const
{
    auto it = find_if(std::begin(_patientList),std::end(_patientList), [&patient](std::shared_ptr<Patient> pat)
    {return pat->getPermanentNumber() == patient->getPermanentNumber();});

    if(it != std::end(_patientList))
    {
        std::cout << "Liste des rendez-vous: " << std::endl;
        for(auto appointment : _appointmentList)
        {
            if(appointment->getPatient() == patient)
            {
                appointment->DisplayAppointment();
            }
        }
    }
    else if(it !=std::end(_patientList) && _appointmentList.empty())
    {
        std::cout << "Liste de rendez-vous vide" << std::endl;
    }
    else 
    {
        throw std::runtime_error("Patient non trouve");
    }
}

//more specific methods

void Hospital::FindPatient(const std::string patientId) 
{
    auto it = std::find_if(std::begin(_patientList), std::end(_patientList),
    [&patientId](std::shared_ptr<Patient> patient){return patient->getPermanentNumber() == patientId;});

    if(it != std::end(_patientList))
    {
        (*it)->DisplayPatient();
    }
    else
    {
        throw std::runtime_error("Patient non trouve");
    }
}

void Hospital::FindDoctor(const std::string doctorId)
{
    auto it = std::find_if(std::begin(_doctorList),std::end(_doctorList),[&doctorId](std::shared_ptr<Doctor> doctor)
    {return doctor->getDoctorNumber() == doctorId;});

    if(it != std::end(_doctorList))
    {
        (*it)->DisplayDoctor();
    }
    else
    {
        throw std::runtime_error("Docteur non trouve");
    }
    
}