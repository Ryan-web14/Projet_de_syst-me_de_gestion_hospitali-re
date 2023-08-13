
#include "EmergencyContact.hpp"

EmergencyContact::EmergencyContact(const std::string &name, const std::string &relationship, const std::string &phoneNumber)
    : _name(name), _relationship(relationship), _phoneNumber(phoneNumber)
{
}

// Getters
const std::string &EmergencyContact::getName() const
{
    return _name;
}

const std::string &EmergencyContact::getRelationship() const
{
    return _relationship;
}

const std::string &EmergencyContact::getPhoneNumber() const
{
    return _phoneNumber;
}


// Setters
void EmergencyContact::setName(const std::string &name)
{
    _name = name;
}

void EmergencyContact::setRelationship(const std::string &relationship)
{
    _relationship = relationship;
}

void EmergencyContact::setPhoneNumber(const std::string &phoneNumber)
{
    _phoneNumber = phoneNumber;
}