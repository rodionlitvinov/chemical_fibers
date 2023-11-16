#ifndef CSVHANDLER_H
#define CSVHANDLER_H

#include "Fiber.h"
#include <vector>
#include <string>

// Function to load fibers from a CSV file
std::vector<Fiber> load_fibers_from_csv(const std::string& filepath);

// Function to save fibers to a CSV file
void save_fibers_to_csv(const std::vector<Fiber>& fibers, const std::string& filepath);

#endif // CSVHANDLER_H
