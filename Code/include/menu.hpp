#pragma once

#include "hospital.hpp"

namespace menu
{
 extern Hospital hospital;
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