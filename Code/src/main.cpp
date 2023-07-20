#include "patient.hpp"
#include "time.hpp"




int main()
{
Patient patient1("Jean", "Dupont", "12 rue de la paix", "066950431");
patient1.DisplayPatient();

Times time(3,5);

time += 60;
return 0;
}