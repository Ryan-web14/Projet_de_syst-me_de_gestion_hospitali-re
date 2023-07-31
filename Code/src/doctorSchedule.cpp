#include "doctorSchedule.hpp"



void DoctorSchedule::AddAppointment(std::shared_ptr<Appointment> appointment)
{
    std::shared_ptr<DoctorAppointment> doctorAppointment = std::make_shared<DoctorAppointment>(appointment, _doctor);
    _appointmentList.push_back(doctorAppointment);
    
}

// void DoctorSchedule::DeleteAppointment(std::shared_ptr<Appointment> appointment)
// {
//   _appointmentList.erase(std::remove(std::begin(_appointmentList), std::end(_appointmentList),appointment));
//   return;
// }

// bool DoctorSchedule::IsAvalaible(const Date& date) const
// {
//    for(const auto appointment: _appointmentList)
//    {
//     if(appointment->getAppointmentDate() == date)
//     {
//         return false;
//     }
//    }
//    return true;
// }

void DoctorSchedule::DisplaySchedule() const
{
    for(const auto appointment: _appointmentList)
    {
        appointment->DisplayDoctorAppointment();
    }
    return;
}