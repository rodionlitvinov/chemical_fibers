#include "CSVHandler.h"
#include "Utils.h"
#include <fstream>
#include <sstream>

std::vector<Fiber> load_fibers_from_csv(const std::string& filepath) {
    std::vector<Fiber> fibers;
    std::ifstream file(filepath);
    std::string line, word;
    std::vector<std::string> row;

    // Skip the header line
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        row.clear();

        while (std::getline(ss, word, ',')) {
            row.push_back(word);
        }

        if (row.size() == 5) {
            Fiber fiber(string_to_bool(row[0]), string_to_bool(row[1]), string_to_bool(row[2]), string_to_bool(row[3]), row[4]);
            fibers.push_back(fiber);
        }
    }

    return fibers;
}

void save_fibers_to_csv(const std::vector<Fiber>& fibers, const std::string& filepath) {
    std::ofstream file(filepath);
    file << "burns_quickly,dissolves_in_acetone,threads_extractable,shrinks_when_burned,name\n";

    for (const auto& fiber : fibers) {
        file << (fiber.getBurnsQuickly() ? "Yes" : "No") << ","
             << (fiber.getDissolvesInAcetone() ? "Yes" : "No") << ","
             << (fiber.getThreadsExtractable() ? "Yes" : "No") << ","
             << (fiber.getShrinksWhenBurned() ? "Yes" : "No") << ","
             << fiber.getName() << "\n";
    }
}
