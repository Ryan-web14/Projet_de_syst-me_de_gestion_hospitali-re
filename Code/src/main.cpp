
// #include <iostream>
// #include <conio.h>

// int main() {
//     int choice = 0;
//     const int NUMBER_OF_CHOICES = 3;
//     const char* choices[] = {
//         "Option 1",
//         "Option 2",
//         "Exit"
//     };

//     while (true) {
//         // Display menu
//         system("cls");
//         for (int i = 0; i < NUMBER_OF_CHOICES; ++i) {
//             if (i == choice) {
//                 std::cout << " > "; // Highlight the selected choice
//             } else {
//                 std::cout << "   ";
//             }
//             std::cout << choices[i] << '\n';
//         }

//         // Get user input
//         char ch = _getch();

//         // Handle input
//         switch (ch) {
//             case 72: // Up arrow key
//                 if (choice > 0) --choice;
//                 break;
//             case 80: // Down arrow key
//                 if (choice < NUMBER_OF_CHOICES - 1) ++choice;
//                 break;
//             case 13: // Enter key
//                 if (choice == NUMBER_OF_CHOICES - 1) // Exit option
//                     return 0;
//                 else
//                     std::cout << "You chose: " << choices[choice] << "\n";
//                     system("pause");
//                 break;
//         }
//     }
//     return 0;
// }

#include "hospital.hpp"
#include <memory>

int main()
{
  Hospital hopital("Hopital de la Tour");

  Birth birth;
  birth.day = 1;
  birth.month = 1;
  birth.year = 2000;
  std::shared_ptr<Patient> patient = std::make_shared<Patient>("Jean", "Dupont", birth, "Rue de la gare 1", "064568525");

  patient->DisplayPatient();
}