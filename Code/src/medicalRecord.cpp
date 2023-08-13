#include "medicalRecord.hpp"

NumberGenerator MedicalRecord::_numberGenerator(20000, 29999);

//constructor
MedicalRecord::MedicalRecord()
{
  _medicalRecordId = _numberGenerator.generateNumber();
}

// methods
void MedicalRecord::AddAppointment(std::shared_ptr<Appointment> appointment)
{
  _appointmentList.push_back(appointment);
}

void MedicalRecord::AddConsultation(std::shared_ptr<Consultation> consultation)
{
  _consultationList.push_back(consultation);
}

void MedicalRecord::AddPrescription(std::shared_ptr<Prescription> prescription)
{
  _prescriptionList.push_back(prescription);
}

void MedicalRecord::AddDoctorAppointment(std::shared_ptr<DoctorAppointment> doctorAppointment)
{
  _doctorAppointmentList.push_back(doctorAppointment);
}

void MedicalRecord::RemoveAppointment(std::shared_ptr<Appointment> appointment)
{
  _appointmentList.erase(std::remove(_appointmentList.begin(), _appointmentList.end(), appointment), _appointmentList.end());
}

void MedicalRecord::RemoveConsultation(std::shared_ptr<Consultation> consultation)
{
  _consultationList.erase(std::remove(_consultationList.begin(), _consultationList.end(), consultation), _consultationList.end());
}

void MedicalRecord::RemovePrescription(std::shared_ptr<Prescription> prescription)
{
  _prescriptionList.erase(std::remove(_prescriptionList.begin(), _prescriptionList.end(), prescription), _prescriptionList.end());
}
void MedicalRecord::AddAllergy(std::string Allergy)
{
  _allergies.push_back(Allergy);
}

void MedicalRecord::AddChronicDisease(std::string ChronicDisease)
{
  _chronicDiseases.push_back(ChronicDisease);
}

void MedicalRecord::AddChronicMedication(std::string ChronicMedication)
{
  _chronicMedications.push_back(ChronicMedication);
}

void MedicalRecord::RemoveAllergy(std::string Allergy)
{
  _allergies.erase(std::remove(_allergies.begin(), _allergies.end(), Allergy), _allergies.end());
}

void MedicalRecord::RemoveChronicDisease(std::string ChronicDisease)
{
  _chronicDiseases.erase(std::remove(_chronicDiseases.begin(), _chronicDiseases.end(), ChronicDisease), _chronicDiseases.end());
}

void MedicalRecord::RemoveChronicMedication(std::string ChronicMedication)
{
  _chronicMedications.erase(std::remove(_chronicMedications.begin(), _chronicMedications.end(), ChronicMedication), _chronicMedications.end());
}

void MedicalRecord::RemoveDoctorAppointment(std::shared_ptr<Appointment> appointment, std::shared_ptr<Doctor> doctor)
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

void MedicalRecord::DisplayAppointmentList() const
{
  std::cout << "\n\033[1;35m========================================\033[0m\n";
  std::cout << "\033[1;36m            LISTE DES RENDEZ-VOUS\033[0m\n";
  std::cout << "\033[1;35m========================================\033[0m\n";

  if (_appointmentList.empty())
  {
    std::cout << "Pas de rendez-vous." << std::endl;
  }
  else
  {
    for (const auto &appointment : _appointmentList)
    {
      appointment->DisplayAppointment();
    }
  }
  std::cout << "\033[1;35m========================================\033[0m\n";
}

void MedicalRecord::DisplayConsultationList() const
{
  std::cout << "\n\033[1;35m========================================\033[0m\n";
  std::cout << "\033[1;36m            LISTE DES CONSULTATIONS\033[0m\n";
  std::cout << "\033[1;35m========================================\033[0m\n";

  if (_consultationList.empty())
  {
    std::cout << "Pas de consultations." << std::endl;
  }
  else
  {
    for (const auto &consultation : _consultationList)
    {
      consultation->DisplayConsultation();
    }
  }
  std::cout << "\033[1;35m========================================\033[0m\n";
}

void MedicalRecord::DisplayPrescriptionList() const
{
  std::cout << "\n\033[1;35m========================================\033[0m\n";
  std::cout << "\033[1;36m            LISTE DES PRESCRIPTIONS\033[0m\n";
  std::cout << "\033[1;35m========================================\033[0m\n";

  if (_prescriptionList.empty())
  {
    std::cout << "Pas de prescriptions." << std::endl;
  }
  else
  {
    for (const auto &prescription : _prescriptionList)
    {
      prescription->DisplayPrescription();
    }
  }
  std::cout << "\033[1;35m========================================\033[0m\n";
}

void MedicalRecord::DisplayDoctorAppointmentList() const
{
  std::cout << "\n\033[1;35m========================================\033[0m\n";
  std::cout << "\033[1;36m            LISTE DES RENDEZ-VOUS MEDICAUX\033[0m\n";
  std::cout << "\033[1;35m========================================\033[0m\n";

  if (_doctorAppointmentList.empty())
  {
    std::cout << "Pas de rendez-vous medicaux." << std::endl;
  }
  else
  {
    for (const auto &doctorAppointment : _doctorAppointmentList)
    {
      doctorAppointment->DisplayDoctorAppointment();
    }
  }
  std::cout << "\033[1;35m========================================\033[0m\n";
}


void MedicalRecord::DisplayMedicalRecord() const
{
  std::cout << "\n\033[1;35m========================================\033[0m\n";
  std::cout << "\033[1;36m            DOSSIER MEDICAL\033[0m\n";
  std::cout << "\033[1;35m========================================\033[0m\n";

  std::cout << "Numero de dossier medical: " << _medicalRecordId << std::endl;
  std::cout << "Allergies: " << std::endl;
  if (_allergies.empty())
  {
    std::cout << " Pas d'allergie ";
  }
  else
  {
    for (const auto &allergy : _allergies)
    {
      std::cout << allergy << std::endl;
    }
  }
  std::cout << "Maladies chroniques: " << std::endl;
  if(_chronicDiseases.empty())
  {
    std::cout << " Pas de maladie chronique ";
  }
  else
  {
    for (const auto &chronicDisease : _chronicDiseases)
    {
      std::cout << chronicDisease << std::endl;
    }
  }
  std::cout << "Medicaments chroniques: " << std::endl;
  if(_chronicMedications.empty())
  {
    std::cout << " pas de medicament chronique ";
  }
  else 
  {
    for (const auto &chronicMedication : _chronicMedications)
    {
      std::cout << chronicMedication << std::endl;
    }
  }

 std::cout << "Liste des rendez-vous: " << std::endl;
if (_appointmentList.empty())
{
  std::cout << "Pas de rendez-vous." << std::endl;
}
else
{
  for (const auto &appointment : _appointmentList)
  {
    appointment->DisplayAppointment();
  }
}

std::cout << "Liste des consultations: " << std::endl;
if (_consultationList.empty())
{
  std::cout << "Pas de consultations." << std::endl;
}
else
{
  for (const auto &consultation : _consultationList)
  {
    consultation->DisplayConsultation();
  }
}

std::cout << "Liste des prescriptions: " << std::endl;
if (_prescriptionList.empty())
{
  std::cout << "Pas de prescriptions." << std::endl;
}
else
{
  for (const auto &prescription : _prescriptionList)
  {
    prescription->DisplayPrescription();
  }
}

std::cout << "Liste des rendez-vous medicaux: " << std::endl;
if (_doctorAppointmentList.empty())
{
  std::cout << "Pas de rendez-vous medicaux." << std::endl;
}
else
{
  for (const auto &doctorAppointment : _doctorAppointmentList)
  {
    doctorAppointment->DisplayDoctorAppointment();
  }
}

  std::cout << "\033[1;35m========================================\033[0m\n";
}

// getters and setters

std::string MedicalRecord::getMedicalRecordId() const
{
  return _medicalRecordId;
}

std::vector<std::string> MedicalRecord::getAllergies() const
{
  return _allergies;
}

std::vector<std::string> MedicalRecord::getChronicDiseases() const
{
  return _chronicDiseases;
}

std::vector<std::string> MedicalRecord::getChronicMedications() const
{
  return _chronicMedications;
}

std::vector<std::shared_ptr<Appointment>> MedicalRecord::getAppointmentList() const
{
  return _appointmentList;
}

std::vector<std::shared_ptr<Consultation>> MedicalRecord::getConsultationList() const
{
  return _consultationList;
}

std::vector<std::shared_ptr<Prescription>> MedicalRecord::getPrescriptionList() const
{
  return _prescriptionList;
}

std::vector<std::shared_ptr<DoctorAppointment>> MedicalRecord::getDoctorAppointmentList() const
{
  return _doctorAppointmentList;
}

