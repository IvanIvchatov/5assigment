#ifndef UNTITLED5_MEMORY_H
#define UNTITLED5_MEMORY_H

#include <string>
#include <map>
#include <iostream>

class Memory {
public:
    std::map<std::string, double> values;

    double get(const std::string& name) {
        return values[name];
    }

    void add(const std::string& name, double value) {
        auto result = values.emplace(name, value);
        if (!result.second) {
            std::cout << "Error: variable '" << name << "' already defined" << std::endl;
        }
    }
};

#endif //UNTITLED5_MEMORY_H
