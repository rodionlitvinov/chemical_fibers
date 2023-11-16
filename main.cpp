#include "Fiber.h"
#include "Utils.h"
#include "CSVHandler.h"
#include "MenuFunctions.h"
#include <iostream>
#include <vector>

void print_menu() {
    std::cout << "\nMain Menu:\n";
    std::cout << "1. Identify fiber by its physical properties\n";
    std::cout << "2. Select and view information about a fiber\n";
    std::cout << "3. How to use the application\n";
    std::cout << "4. Information about the program\n";
    std::cout << "5. View properties of all fibers\n";
    std::cout << "6. Add a new fiber\n";
    std::cout << "7. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    std::vector<Fiber> fibers = load_fibers_from_csv("fibers.csv");
    int choice;
    std::cout << " " << std::endl;
    std::cout << "\n=====================\n";
    std::cout << "\n   Fiber Buddy 1.0   \n";
    std::cout << "\n=====================\n";
    std::cout << " " << std::endl;

    while (true) {
        print_menu();
        std::cin >> choice;
        std::cin.ignore(); // To handle the newline character after integer input

        switch (choice) {
            case 1:
                identify_fiber(fibers);
                break;
            case 2:
                select_and_view_fiber(fibers);
                break;
            case 3:
                how_to_use();
                break;
            case 4:
                program_info();
                break;
            case 5:
                view_all_fibers(fibers);
                break;
            case 6:
                add_new_fiber(fibers);
                break;
            case 7:
                std::cout << "Exiting the program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid selection, please try again." << std::endl;
        }
    }

    return 0;
}
