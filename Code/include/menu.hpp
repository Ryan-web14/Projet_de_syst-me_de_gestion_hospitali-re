#pragma once

#include "hospital.hpp"

namespace menu
{
  Hospital hospital("Hopital General de Ngoyo");
    void DisplayMainMenu();
    void PatientMenu();
    void DoctorMenu();
    void ConsultationMenu();
    void AppointmentMenu();
    void TreatmentMenu();
    void PrescriptionMenu();
    void ExamMenu();
    void HospitalisationMenu();
};