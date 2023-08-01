#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Patient.hpp"
#include "doctorAppointment.hpp"

class Consultation
{
public:
//constructor and destructor
//default constructor
Consultation() = default;
Consultation(Patient& patient,std::shared_ptr<Doctor> doctor,std::shared_ptr<DoctorAppointment> doctorAppointment);
private:
}

