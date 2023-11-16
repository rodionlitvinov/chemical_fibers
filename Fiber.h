#ifndef FIBER_H
#define FIBER_H

#include <string>
#include <vector>
#include <map>

class Fiber {
public:
    Fiber(bool burns_quickly, bool dissolves_in_acetone, bool threads_extractable, bool shrinks_when_burned, const std::string& name);

    static std::string identify_fiber(const std::vector<Fiber>& fibers, const std::map<std::string, bool>& properties);

    bool getBurnsQuickly() const;
    bool getDissolvesInAcetone() const;
    bool getThreadsExtractable() const;
    bool getShrinksWhenBurned() const;
    std::string getName() const;

private:
    bool burns_quickly;
    bool dissolves_in_acetone;
    bool threads_extractable;
    bool shrinks_when_burned;
    std::string name;
};

#endif // FIBER_H
