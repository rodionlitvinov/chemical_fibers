#ifndef UTILS_H
#define UTILS_H

#include <string>

// Function to get validated user input (returns true for 'yes', false for 'no')
bool get_user_input(const std::string& question);

// Function to convert a string to a boolean ('yes' to true, 'no' to false)
bool string_to_bool(const std::string& str);

#endif // UTILS_H
