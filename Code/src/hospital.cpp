#include "hospital.hpp"

Hospital::Hospital(std::string name)
{
    _name = name;
}

// methods
void Hospital::AddPatient(std::shared_ptr<Patient> patient)
{
    _patientList.push_back(patient);
    PatientRecord patientRecord(patient);
    _patientRecordList.push_back(std::make_shared<PatientRecord>(patientRecord));
}

void Hospital::DeletePatient(const std::string &patientId)
{
    auto it = std::remove_if(std::begin(_patientList), std::end(_patientList), [&patientId](std::shared_ptr<Patient> patient)
                             { return patient->getPermanentNumber() == patientId; });
    if (it != std::end(_patientList))
    {
        _patientList.erase(it);
    }
    else
    {
        throw std::runtime_error("Patient non trouve");
    }
}

void Hospital::AddPatientRecord(std::shared_ptr<PatientRecord> patientRecord)
{
    _patientRecordList.push_back(patientRecord);
}

void Hospital::AddDoctor(std::shared_ptr<Doctor> doctor)
{
    _doctorList.push_back(doctor);
}

void Hospital::DeleteDoctor(const std::string doctorId)
{
    auto it = std::remove_if(std::begin(_doctorList), std::end(_doctorList), [&doctorId](std::shared_ptr<Doctor> doctor)
                             { return doctor->getPhoneNumber() == doctorId; });
    if (it != std::end(_doctorList))
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
    auto it = std::remove_if(std::begin(_prescriptionList), std::end(_prescriptionList), [&prescriptionId](std::shared_ptr<Prescription> prescription)
                             { return prescription->getPrescriptionId() == prescriptionId; });
    if (it != std::end(_prescriptionList))
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
    auto it = std::remove_if(std::begin(_consultationList), std::end(_consultationList), [&consultationId](std::shared_ptr<Consultation> consultation)
                             { return consultation->getConsultationId() == consultationId; });
    if (it != std::end(_consultationList))
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
    auto it = std::remove_if(std::begin(_appointmentList), std::end(_appointmentList), [&appointmentId](std::shared_ptr<Appointment> appointment)
                             { return appointment->getAppointmentId() == appointmentId; });
    if (it != std::end(_appointmentList))
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
    auto it = std::remove_if(std::begin(_doctorAppointmentList), std::end(_doctorAppointmentList),
                             [&appointment, &doctor](std::shared_ptr<DoctorAppointment> doctorAppointment)
                             { return doctorAppointment->getAppointment() == appointment && doctorAppointment->getDoctor() == doctor; });

    if (it != std::end(_doctorAppointmentList))
    {
        _doctorAppointmentList.erase(it);
    }
    else
    {
        throw std::runtime_error("Pas de rendez-vous de docteur");
    }
}

void Hospital::AddToDoctorSchedule(std::shared_ptr<Doctor> doctor, std::shared_ptr<Appointment> appointment)
{
    auto doctorFound = std::find_if(std::begin(_doctorList), std::end(_doctorList), [&doctor](std::shared_ptr<Doctor> doc)
                                    { return doc->getDoctorNumber() == doctor->getDoctorNumber(); });

    auto appointmentFound = std::find_if(std::begin(_appointmentList), std::end(_appointmentList), [&appointment](std::shared_ptr<Appointment> app)
                                         { return app->getAppointmentId() == appointment->getAppointmentId(); });

    if (doctorFound != std::end(_doctorList) && appointmentFound != std::end(_appointmentList))
    {
        DoctorSchedule doctorSchedule(doctor);
        doctorSchedule.AddAppointment(appointment);
        _doctorScheduleList.push_back(doctorSchedule);
    }
    else
    {
        throw std::runtime_error("Docteur ou rendez-vous non trouve");
    }
}

void Hospital::AddTreatment(std::shared_ptr<Treatment> treatment, std::shared_ptr<Patient> patient)
{
    auto patientFound = std::find_if(std::begin(_patientList), std::end(_patientList), [&patient](std::shared_ptr<Patient> pat)
                                     { return pat->getPermanentNumber() == patient->getPermanentNumber(); });

    if (patientFound != std::end(_patientList))
    {
        _treatmentList.push_back(treatment);
    }
    else
    {
        throw std::runtime_error("Patient non trouve");
    }
    for (const auto &record : _patientRecordList)
    {
        if (patient == record->getPatient())
        {
            record->AddTreatement(treatment);
            return;
        }
    }
}

void Hospital::DeleteTreatment(std::string treatmentId)
{
    auto it = std::remove_if(std::begin(_treatmentList), std::end(_treatmentList), [&treatmentId](std::shared_ptr<Treatment> treat)
                             { return treat->getTreatmentId() == treatmentId; });

    if (it != std::end(_treatmentList))
    {
        _treatmentList.erase(it);
    }
    else
    {
        throw std::runtime_error("Traitement non trouve");
    }
}

void Hospital::AddXrayExam(std::shared_ptr<XrayExam> xrayExam, std::shared_ptr<Patient> patient)
{
    auto patientFound = std::find_if(std::begin(_patientList), std::end(_patientList), [&patient](std::shared_ptr<Patient> pat)
                                     { return pat->getPermanentNumber() == patient->getPermanentNumber(); });

    if(patientFound != std::end(_patientList))
        _xrayExamList.push_back(xrayExam);
    
     for (const auto &record : _patientRecordList)
    {
        if (patient == record->getPatient())
        {
            record->AddXrayExam(xrayExam);
            return;
        }
    }
}

void Hospital::DeleteXrayExam(std::string xrayExamId)
{
    auto it = std::remove_if(std::begin(_xrayExamList), std::end(_xrayExamList), [&xrayExamId](std::shared_ptr<XrayExam> xray)
                             { return xray->getExamId() == xrayExamId; });

    if (it != std::end(_xrayExamList))
    {
        _xrayExamList.erase(it);
    }
    else
    {
        throw std::runtime_error("Examen radiologique non trouve");
    }
}

void Hospital::AddBiologicalExam(std::shared_ptr<BiologicalExam> biologicalExam, std::shared_ptr<Patient> patient)
{
    auto patientFound = std::find_if(std::begin(_patientList), std::end(_patientList), [&patient](std::shared_ptr<Patient> pat)
                                     { return pat->getPermanentNumber() == patient->getPermanentNumber(); });

    if(patientFound != std::end(_patientList))
        _biologicalExamList.push_back(biologicalExam);
    
     for (const auto &record : _patientRecordList)
    {
        if (patient == record->getPatient())
        {
            record->AddBiologicalExam(biologicalExam);
            return;
        }
    }
}


void Hospital::DeleteBiologicalExam(std::string biologicalExamId)
{
    auto it = std::remove_if(std::begin(_biologicalExamList), std::end(_biologicalExamList), [&biologicalExamId](std::shared_ptr<BiologicalExam> bio)
                             { return bio->getExamId() == biologicalExamId; });

    if (it != std::end(_biologicalExamList))
    {
        _biologicalExamList.erase(it);
    }
    else
    {
        throw std::runtime_error("Examen biologique non trouve");
    }
}

void Hospital::AddHospitalisation(std::shared_ptr<Hospitalisation> hospitalisation)
{
 _hospitalisationList.push_back(hospitalisation);
}

void Hospital::DeleteHospitalisation(std::string& hospitalisationId)
{
    auto it = std::remove_if(std::begin(_hospitalisationList), std::end(_hospitalisationList), [&hospitalisationId](std::shared_ptr<Hospitalisation> hosp)
                             { return hosp->getHospitalisationId() == hospitalisationId; });

    if (it != std::end(_hospitalisationList))
    {
        _hospitalisationList.erase(it);
    }
    else
    {
        throw std::runtime_error("Examen biologique non trouve");
   }
}

// methods for displaying
void Hospital::DisplayPatientList() const
{
    std::cout << "Liste des patient " << std::endl;
    for (auto patient : _patientList)
    {
        patient->DisplayPatient();
    }
}

void Hospital::DisplayDoctorList() const
{
    std::cout << "Liste des docteurs " << std::endl;
    for (auto doctor : _doctorList)
    {
        doctor->DisplayDoctor();
    }
}

void Hospital::DisplayAppointmentList() const
{
    std::cout << "Liste des rendez-vous" << std::endl;
    for (auto appointment : _appointmentList)
    {
        appointment->DisplayAppointment();
    }
}

void Hospital::DisplayConsultationList() const
{
    std::cout << "Liste de consultation" << std::endl;
    for (auto consultation : _consultationList)
    {
        consultation->DisplayConsultationWithDiagnosis();
    }
}

void Hospital::DisplayPrescriptionList(std::shared_ptr<Patient> patient) const
{
    std::cout << "Prescription list: " << std::endl;
    for (auto prescription : _prescriptionList)
    {
        if (prescription->getPatient() == patient)
            prescription->DisplayPrescription();
    }
}

void Hospital::DisplayDoctorAppointmentList(std::shared_ptr<Doctor> doctor) const
{
    auto it = find_if(std::begin(_doctorList), std::end(_doctorList), [&doctor](std::shared_ptr<Doctor> doc)
                      { return doc->getDoctorNumber() == doctor->getDoctorNumber(); });

    if (it != std::end(_doctorList))
    {
        std::cout << "Liste de rendez-vous des docteurs" << std::endl;
        for (auto doctorAppointment : _doctorAppointmentList)
        {
            if (doctorAppointment->getDoctor() == doctor)
            {
                doctorAppointment->DisplayDoctorAppointment();
            }
        }
    }
    else if (it != std::end(_doctorList) && _doctorAppointmentList.empty())
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
    auto it = find_if(std::begin(_doctorList), std::end(_doctorList), [&doctor](std::shared_ptr<Doctor> doc)
                      { return doc->getDoctorNumber() == doctor->getDoctorNumber(); });

    if (it != std::end(_doctorList))
    {
        std::cout << "Consultation list: " << std::endl;
        for (auto consultation : _consultationList)
        {
            if (consultation->getDoctor() == doctor)
            {
                consultation->DisplayConsultationWithDiagnosis();
            }
        }
    }
    else if (it != std::end(_doctorList) && _consultationList.empty())
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
    auto it = find_if(std::begin(_patientList), std::end(_patientList), [&patient](std::shared_ptr<Patient> pat)
                      { return pat->getPermanentNumber() == patient->getPermanentNumber(); });

    if (it != std::end(_patientList))
    {
        std::cout << "Liste des rendez-vous: " << std::endl;
        for (auto appointment : _appointmentList)
        {
            if (appointment->getPatient() == patient)
            {
                appointment->DisplayAppointment();
            }
        }
    }
    else if (it != std::end(_patientList) && _appointmentList.empty())
    {
        std::cout << "Liste de rendez-vous vide" << std::endl;
    }
    else
    {
        throw std::runtime_error("Patient non trouve");
    }
}

// more specific methods
void Hospital::FindPatient(const std::string &patientId)
{
    auto it = std::find_if(std::begin(_patientList), std::end(_patientList),
                           [&patientId](std::shared_ptr<Patient> patient)
                           { return patient->getPermanentNumber() == patientId; });

    if (it != std::end(_patientList))
    {
        (*it)->DisplayPatient();
    }
    else
    {
        throw std::runtime_error("Patient non trouve");
    }
}

std::shared_ptr<Patient> Hospital::FindPatientById(const std::string &patientId)
{
    auto it = std::find_if(std::begin(_patientList), std::end(_patientList),
                           [&patientId](std::shared_ptr<Patient> patient)
                           { return patient->getPermanentNumber() == patientId; });

    if (it != std::end(_patientList))
    {
        return *it;
    }

    return nullptr;
}

void Hospital::FindDoctor(const std::string doctorId)
{
    auto it = std::find_if(std::begin(_doctorList), std::end(_doctorList), [&doctorId](std::shared_ptr<Doctor> doctor)
                           { return doctor->getDoctorNumber() == doctorId; });

    if (it != std::end(_doctorList))
    {
        (*it)->DisplayDoctor();
    }
    else
    {
        throw std::runtime_error("Docteur non trouve");
    }
}

void Hospital::FindPrescription(const std::string &prescriptionId)
{
    auto it = std::find_if(std::begin(_prescriptionList), std::end(_prescriptionList), [&prescriptionId](std::shared_ptr<Prescription> prescription)
                           { return prescription->getPrescriptionId() == prescriptionId; });

    if (it != std::end(_prescriptionList))
    {
        (*it)->DisplayPrescription();
    }
    else
    {
        throw std::runtime_error("Prescription non trouve");
    }
}

void Hospital::FindConsultation(const std::string &consultationId)
{
    auto it = std::find_if(std::begin(_consultationList), std::end(_consultationList), [&consultationId](std::shared_ptr<Consultation> consultation)
                           { return consultation->getConsultationId() == consultationId; });

    if (it != std::end(_consultationList))
    {
        (*it)->DisplayConsultationWithDiagnosis();
    }
    else
    {
        throw std::runtime_error("Consultation non trouve");
    }
}

void Hospital::FindAppointment(const std::string &appointmentId)
{
    auto it = std::find_if(std::begin(_appointmentList), std::end(_appointmentList), [&appointmentId](std::shared_ptr<Appointment> appointment)
                           { return appointment->getAppointmentId() == appointmentId; });

    if (it != std::end(_appointmentList))
    {
        (*it)->DisplayAppointment();
    }
    else
    {
        throw std::runtime_error("Rendez-vous non trouve");
    }
}

void Hospital::SortAppointmentByDate(std::vector<std::shared_ptr<Appointment>> &appointments)
{
    std::sort(appointments.begin(), appointments.end(), [](const std::shared_ptr<Appointment> &a1, const std::shared_ptr<Appointment> &a2)
              { return a1->getAppointmentDate() < a2->getAppointmentDate(); });
}

void Hospital::FindDoctorAppointment(std::shared_ptr<Appointment> appointment, std::shared_ptr<Doctor> doctor)
{
    auto it = std::find_if(std::begin(_doctorAppointmentList), std::end(_doctorAppointmentList), [&appointment, &doctor](std::shared_ptr<DoctorAppointment> doctorAppointment)
                           { return doctorAppointment->getAppointment() == appointment && doctorAppointment->getDoctor() == doctor; });

    if (it != std::end(_doctorAppointmentList))
    {
        (*it)->DisplayDoctorAppointment();
    }
    else
    {
        throw std::runtime_error("Rendez-vous docteur non trouve");
    }
}

void Hospital::FindPatientByName(std::string &name)
{
    if (name.empty())
    {
        throw std::length_error("Nom vide");
    }
    else
    {
        name[0] = std::toupper(name[0]);

        for (std::size_t i = 1; i < name.size(); ++i)
        {
            name[i] = std::tolower(name[i]);
        }
    }
    std::vector<std::shared_ptr<Patient>> patientList;

    auto it = std::copy_if(std::begin(_patientList), std::end(_patientList), std::back_inserter(patientList),
                           [&name](std::shared_ptr<Patient> patient)
                           { return patient->getName() == name; });

    std::cout << "Resultat de la recherche: " << std::endl;

    if (patientList.empty())
    {
        throw std::runtime_error("Patient non trouve");
        return;
    }

    for (const auto patient : patientList)
    {
        patient->DisplayPatient();
    }
}

void Hospital::FindDoctorByName(std::string &name)
{
    if (name.empty())
    {
        throw std::length_error("Nom vide");
    }
    else
    {
        name[0] = std::toupper(name[0]);

        for (std::size_t i = 1; i < name.size(); ++i)
        {
            name[i] = std::tolower(name[i]);
        }
    }

    std::vector<std::shared_ptr<Doctor>> doctorList;
    auto it = std::copy_if(std::begin(_doctorList), std::end(_doctorList), std::back_inserter(_doctorList),
                           [&name](std::shared_ptr<Doctor> doctor)
                           { return doctor->getName() == name; });

    if (doctorList.empty())
    {
        throw std::runtime_error("Docteur non trouve");
        return;
    }

    for (const auto doctor : doctorList)
    {
        doctor->DisplayDoctor();
    }
}

// methods link to the medicalRecord
void Hospital::AddAppointmentToPatientRecord(std::string &patientId, std::shared_ptr<Appointment> appointment)
{
    auto patient = FindPatientById(patientId);
    for (const auto record : _patientRecordList)
    {
        if (patient == record->getPatient())
        {
            record->AddAppointment(appointment);
            return;
        }
    }
    throw std::runtime_error("Patient non trouve");
}

void Hospital::AddConsultationToPatientRecord(std::string &patientId, std::shared_ptr<Consultation> consultation)
{
    auto patient = FindPatientById(patientId);
    for (const auto &record : _patientRecordList)
    {
        if (patient == record->getPatient())
        {
            record->AddConsultation(consultation);
            return;
        }
    }
    throw std::runtime_error("Patient non trouve");
}

void Hospital::AddPrescriptionToPatientRecord(std::string &patientId, std::shared_ptr<Prescription> prescription)
{
    auto patient = FindPatientById(patientId);
    for (const auto &record : _patientRecordList)
    {
        if (patient == record->getPatient())
        {
            record->AddPrescription(prescription);
            return;
        }
    }
    throw std::runtime_error("Patient non trouve");
}

void Hospital::AddChronicDiseaseToPatientRecord(std::string &patientId, std::string &chronicDisease)
{
    auto patient = FindPatientById(patientId);
    for (const auto &record : _patientRecordList)
    {
        if (patient == record->getPatient())
        {
            record->AddChronicDisease(chronicDisease);
            return;
        }
    }
    throw std::runtime_error("Patient non trouve");
}

void Hospital::AddChronicMedicationToPatientRecord(std::string &patientId, std::string &chronicMedication)
{
    auto patient = FindPatientById(patientId);
    for (const auto &record : _patientRecordList)
    {
        if (patient == record->getPatient())
        {
            record->AddChronicMedication(chronicMedication);
            return;
        }
    }
    throw std::runtime_error("Patient non trouve");
}

void Hospital::AddAllergyToPatientRecord(std::string &patientId, std::string &allergy)
{
    auto patient = FindPatientById(patientId);
    for (const auto &record : _patientRecordList)
    {
        if (patient == record->getPatient())
        {
            record->AddAllergy(allergy);
            return;
        }
    }
    throw std::runtime_error("Patient non trouve");
}

void Hospital::AddDoctorAppointmentToPatientRecord(std::string &patientId, std::shared_ptr<DoctorAppointment> DoctorAppointment)
{
    auto patient = FindPatientById(patientId);
    for (const auto &record : _patientRecordList)
    {
        if (patient == record->getPatient())
        {
            record->AddDoctorAppointment(DoctorAppointment);
            return;
        }
    }
    throw std::runtime_error("Patient non trouve");
}

void Hospital::DeleteAppointmentToPatientRecord(std::string &patientId, std::shared_ptr<Appointment> appointment)
{
    auto patient = FindPatientById(patientId);
    for (const auto &record : _patientRecordList)
    {
        if (patient == record->getPatient())
        {
            record->RemoveAppointment(appointment);
            return;
        }
    }
    throw std::runtime_error("Patient non trouve");
}

void Hospital::DeleteConsultationToPatientRecord(std::string &patientId, std::shared_ptr<Consultation> consultation)
{
    auto patient = FindPatientById(patientId);
    for (const auto &record : _patientRecordList)
    {
        if (patient == record->getPatient())
        {
            record->RemoveConsultation(consultation);
            return;
        }
    }
    throw std::runtime_error("Patient non trouve");
}

void Hospital::DeletePrescriptionToPatientRecord(std::string &patientId, std::shared_ptr<Prescription> prescription)
{
    auto patient = FindPatientById(patientId);
    for (const auto &record : _patientRecordList)
    {
        if (patient == record->getPatient())
        {
            record->RemovePrescription(prescription);
            return;
        }
    }
    throw std::runtime_error("Patient non trouve");
}

void Hospital::DeleteDoctorAppointmentToPatientRecord(std::string &patientId, std::shared_ptr<Appointment> Appointment, std::shared_ptr<Doctor> doctor)
{
    auto patient = FindPatientById(patientId);
    for (const auto &record : _patientRecordList)
    {
        if (patient == record->getPatient())
        {
            record->RemoveDoctorAppointment(Appointment, doctor);
            return;
        }
    }
    throw std::runtime_error("Patient non trouve");
}
void Hospital::DisplayPatientRecord(std::string &patientId)
{
    auto patient = FindPatientById(patientId);

    for (const auto &record : _patientRecordList)
    {
        if (patient == record->getPatient())
        {
            record->DisplayMedicalRecord();
            return;
        }
    }
    throw std::runtime_error("Patient non trouve");
}