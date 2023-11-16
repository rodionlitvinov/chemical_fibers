#include "Fiber.h"
#include <algorithm>
#include <stdexcept>

Fiber::Fiber(bool burns_quickly, bool dissolves_in_acetone, bool threads_extractable, bool shrinks_when_burned, const std::string& name)
    : burns_quickly(burns_quickly), dissolves_in_acetone(dissolves_in_acetone), threads_extractable(threads_extractable), shrinks_when_burned(shrinks_when_burned), name(name) {}

std::string Fiber::identify_fiber(const std::vector<Fiber>& fibers, const std::map<std::string, bool>& properties) {
    std::vector<Fiber> potential_fibers = fibers;

    for (const auto& prop : properties) {
        potential_fibers.erase(
            std::remove_if(potential_fibers.begin(), potential_fibers.end(),
                           [&prop](const Fiber& fiber) {
                               if (prop.first == "burns_quickly") return fiber.getBurnsQuickly() != prop.second;
                               if (prop.first == "dissolves_in_acetone") return fiber.getDissolvesInAcetone() != prop.second;
                               if (prop.first == "threads_extractable") return fiber.getThreadsExtractable() != prop.second;
                               if (prop.first == "shrinks_when_burned") return fiber.getShrinksWhenBurned() != prop.second;
                               throw std::invalid_argument("Unknown property");
                           }),
            potential_fibers.end()
        );
    }

    if (potential_fibers.size() == 1) {
        return potential_fibers.front().getName();
    } else if (potential_fibers.empty()) {
        return "Unknown";
    } else {
        std::string result = "Multiple fibers match the criteria:\n";
        for (const auto& fiber : potential_fibers) {
            result += fiber.getName() + "\n";
        }
        return result;
    }
}

bool Fiber::getBurnsQuickly() const { return burns_quickly; }
bool Fiber::getDissolvesInAcetone() const { return dissolves_in_acetone; }
bool Fiber::getThreadsExtractable() const { return threads_extractable; }
bool Fiber::getShrinksWhenBurned() const { return shrinks_when_burned; }
std::string Fiber::getName() const { return name; }
