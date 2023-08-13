#pragma once

#include <string>

class EmergencyContact
{
public:
    //default constructor
    EmergencyContact() = default;
    // constructor with parameters
    EmergencyContact(const std::string &name, const std::string &relationship, const std::string &phoneNumber);
    
    // Getters
    const std::string &getName() const;
    const std::string &getRelationship() const;
    const std::string &getPhoneNumber() const;

    // Setters
    void setName(const std::string &name);
    void setRelationship(const std::string &relationship);
    void setPhoneNumber(const std::string &phoneNumber);

private:
    std::string _name;
    std::string _relationship;
    std::string _phoneNumber;
    std::string _email;
};