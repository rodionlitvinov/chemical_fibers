#include "MenuFunctions.h"
#include "Utils.h"
#include "CSVHandler.h"
#include <iostream>
#include <map>

void identify_fiber(std::vector<Fiber>& fibers) {
    std::map<std::string, bool> properties;
    properties["burns_quickly"] = get_user_input("Does the fiber burn quickly?");
    properties["dissolves_in_acetone"] = get_user_input("Does the fiber dissolve in acetone?");
    properties["threads_extractable"] = get_user_input("Can threads be extracted from the resin?");
    properties["shrinks_when_burned"] = get_user_input("Does the fiber shrink when burned?");

    std::string identified_fiber = Fiber::identify_fiber(fibers, properties);
    std::cout << "Identified Fiber: " << identified_fiber << std::endl;
}

void add_new_fiber(std::vector<Fiber>& fibers) {
    std::string name;
    std::cout << "Enter the name of the new fiber: ";
    std::getline(std::cin, name);

    bool burns_quickly = get_user_input("Does the fiber burn quickly?");
    bool dissolves_in_acetone = get_user_input("Does the fiber dissolve in acetone?");
    bool threads_extractable = get_user_input("Can threads be extracted from the resin?");
    bool shrinks_when_burned = get_user_input("Does the fiber shrink when burned?");

    Fiber new_fiber(burns_quickly, dissolves_in_acetone, threads_extractable, shrinks_when_burned, name);
    fibers.push_back(new_fiber);

    save_fibers_to_csv(fibers, "fibers.csv");
}

void select_and_view_fiber(const std::vector<Fiber>& fibers) {
    int index = 1;
    for (const auto& fiber : fibers) {
        std::cout << index++ << ". " << fiber.getName() << std::endl;
    }

    std::cout << "Enter the number of the fiber: ";
    int choice;
    std::cin >> choice;
    std::cin.ignore(); // To handle the newline character after integer input

    if (choice >= 1 && choice <= static_cast<int>(fibers.size())) {
        const Fiber& fiber = fibers[choice - 1];
        std::cout << "----------------------------------------\n";
        std::cout << "Name: " << fiber.getName() << std::endl;
        std::cout << "  - Burns Quickly: " << (fiber.getBurnsQuickly() ? "Yes" : "No") << "\n";
        std::cout << "  - Dissolves in Acetone: " << (fiber.getDissolvesInAcetone() ? "Yes" : "No") << "\n";
        std::cout << "  - Threads Extractable: " << (fiber.getThreadsExtractable() ? "Yes" : "No") << "\n";
        std::cout << "  - Shrinks When Burned: " << (fiber.getShrinksWhenBurned() ? "Yes" : "No") << "\n";
        std::cout << "----------------------------------------\n";
    } else {
        std::cout << "Invalid selection." << std::endl;
    }
}

void view_all_fibers(const std::vector<Fiber>& fibers) {
    std::cout << "\nProperties of All Fibers:\n";
    std::cout << "----------------------------------------\n";

    for (const auto& fiber : fibers) {
        std::cout << " " << std::endl;
        std::cout << "Name: " << fiber.getName() << "\n";
        std::cout << "  - Burns Quickly: " << (fiber.getBurnsQuickly() ? "Yes" : "No") << "\n";
        std::cout << "  - Dissolves in Acetone: " << (fiber.getDissolvesInAcetone() ? "Yes" : "No") << "\n";
        std::cout << "  - Threads Extractable: " << (fiber.getThreadsExtractable() ? "Yes" : "No") << "\n";
        std::cout << "  - Shrinks When Burned: " << (fiber.getShrinksWhenBurned() ? "Yes" : "No") << "\n";
        std::cout << "----------------------------------------\n";
    }
}


void how_to_use() {
    std::cout << " " << std::endl;
    std::cout << "To use the application:" << std::endl;
    std::cout << "- Choose an option from the main menu by entering the number next to the option. " << std::endl;
    std::cout << "- Follow the prompts provided by the application. " << std::endl;
    std::cout << "- Enter 'yes' or 'no' when asked about fiber properties. " << std::endl;
    std::cout << "- To exit, choose the 'Exit' option from the main menu. " << std::endl;
    std::cout << " " << std::endl;
}

void program_info() {
    std::cout << "Fiber Buddy\nVersion: 1.0\nAuthor: Radion Litvinov\nLicense: Freeware" << std::endl;
}
