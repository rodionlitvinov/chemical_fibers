#ifndef MENUFUNCTIONS_H
#define MENUFUNCTIONS_H

#include "Fiber.h"
#include <vector>

// Function to handle the identification of a fiber based on user input
void identify_fiber(std::vector<Fiber>& fibers);

// Function to add a new fiber based on user input
void add_new_fiber(std::vector<Fiber>& fibers);

// Function to select and view information about a specific fiber
void select_and_view_fiber(const std::vector<Fiber>& fibers);

// Function to view properties of all fibers
void view_all_fibers(const std::vector<Fiber>& fibers);

// Function to display information on how to use the application
void how_to_use();

// Function to display information about the program
void program_info();

#endif // MENUFUNCTIONS_H
