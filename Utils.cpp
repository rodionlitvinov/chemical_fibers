#include "Utils.h"
#include <iostream>
#include <algorithm>

bool get_user_input(const std::string& question) {
    std::string input;
    while (true) {
        std::cout << question << " (Yes/No): ";
        std::getline(std::cin, input);
        std::transform(input.begin(), input.end(), input.begin(),
                       [](unsigned char c){ return std::tolower(c); });

        if (input == "yes" || input == "y") {
            return true;
        } else if (input == "no" || input == "n") {
            return false;
        } else {
            std::cout << "Invalid input. Please answer with 'yes' or 'no'.\n";
        }
    }
}

bool string_to_bool(const std::string& str) {
    std::string lower_str = str;
    std::transform(lower_str.begin(), lower_str.end(), lower_str.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return lower_str == "yes";
}
