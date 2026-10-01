# Hospital Management System

A console-based hospital management system written in C++17, built around an object model of 21 classes covering patients, doctors, appointments, consultations, prescriptions, exams, hospitalisation and billing.

The project was designed UML-first: class and use-case diagrams were produced before implementation, and the code follows them. Those diagrams are included in the repository.

## Domain model

The `Hospital` class is the aggregate root. It owns the collections of every other entity and exposes the operations that act on them.

```
Hospital
  ├── Patient ──────── PatientRecord ──── MedicalRecord
  │     └── EmergencyContact
  ├── Doctor ───────── Specialty
  │     └── DoctorSchedule
  ├── Appointment ──── DoctorAppointment
  ├── Consultation
  ├── Prescription ─── Treatment
  ├── Exam
  │     ├── BiologicalExam
  │     └── XrayExam
  ├── Hospitalisation
  └── Billing

Support types: Date, Times, NumberGenerator
```

`Exam` is the one polymorphic branch: `BiologicalExam` and `XrayExam` derive from it, so exams of different kinds are handled through the same interface.

Ownership is expressed with `std::shared_ptr` throughout, and entities are stored in `std::vector` and `std::map` collections held by `Hospital`. Record identifiers are produced by `NumberGenerator`, which draws from a uniform distribution and keeps a `std::set` of issued values so an identifier is never reused.

## Interface

Navigation is handled by the `menu` namespace, which holds a single `Hospital` instance and one function per area of the system:

- Main menu
- Patients
- Doctors
- Consultations
- Appointments
- Treatments
- Prescriptions
- Exams
- Hospitalisation

## Build

No build system is included. Compile the sources directly:

```bash
g++ -std=c++17 -I Code/include Code/src/*.cpp -o hospital
./hospital
```

Requires a C++17 compiler. No external dependencies.

## Project layout

```
Code/
  include/     class declarations (.hpp)
  src/         implementations (.cpp), entry point in main.cpp
```

Design documents at the repository root: class diagrams (`class.drawio`, `class.png`, `class16.svg`), use-case diagrams (`use_case.drawio.svg`, `useCaseV1.svg`), the system specification PDF, and a log of problems encountered during implementation.

## State of the project

This is an academic project, and some areas are unfinished:

- Persistence is partial. Data lives in memory for the duration of a session rather than in a database or file store.
- There is no test suite.
- The build is manual, with no CMake or Makefile.
- Input validation at the menu layer is minimal.

## What the project covers

- Class design from UML through to implementation
- Inheritance and polymorphism (`Exam` and its subclasses)
- Smart pointers and ownership semantics in modern C++
- Composition and aggregation across a 21-class domain model
- Separation of the domain layer from the interface layer

## License

MIT****
