#include "doctorSchedule.hpp"


DoctorSchedule::DoctorSchedule(std::shared_ptr<Doctor> doctor) : _doctor(doctor) 
{
  
}

void DoctorSchedule::AddAppointment(std::shared_ptr<Appointment> appointment)
{
    std::shared_ptr<DoctorAppointment> doctorAppointment = std::make_shared<DoctorAppointment>(appointment, _doctor);
    _appointmentList.push_back(doctorAppointment);
    
}

void DoctorSchedule::DeleteAppointment(std::shared_ptr<Appointment> appointment)
{
  _appointmentList.erase(std::remove(std::begin(_appointmentList), std::end(_appointmentList),appointment));
  return;
}

bool DoctorSchedule::IsAvalaible(const Date& date) const
{
   for(const auto appointment: _appointmentList)
   {
    if(appointment->getAppointmentDate() == date)
    {
        return false;
    }
   }
   return true;
}
void DoctorSchedule::DisplaySchedule() const
{
    std::cout << "\n\033[1;35m========================================\033[0m\n";
    std::cout << "\033[1;36m            EMPLOI DU TEMPS DOCTEUR\033[0m\n";
    std::cout << "\033[1;35m========================================\033[0m\n";

    if (_appointmentList.empty())
    {
        std::cout << "\033[1;31mThe schedule is currently empty.\033[0m\n";
    }
    else
    {
        for(const auto& appointment: _appointmentList)
        {
            appointment->DisplayDoctorAppointment();
        }
    }

    std::cout << "\033[1;35m========================================\033[0m\n";
}


