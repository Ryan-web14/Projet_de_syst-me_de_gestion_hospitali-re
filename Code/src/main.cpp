#include "patient.hpp"

#include "doctor.hpp"




int main()
{
Patient patient1("Jean", "Dupont", "12 rue de la paix", "066950431");
patient1.DisplayPatient();

Doctor doctor("Jean", "Dupont", "12 rue de la paix", "066950431");
doctor.DisplayDoctor();

return 0;
}