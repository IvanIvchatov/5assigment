#ifndef UNTITLED5_NODE_H
#define UNTITLED5_NODE_H

#include <string>
#include <vector>
#include <memory>
#include <cmath>
#include <algorithm>
#include "Memory.h"

class Node {
public:
    virtual double calculate(Memory& memory) = 0;
    virtual ~Node() = default;
};

using NodePtr = std::shared_ptr<Node>;

class NumberNode : public Node {
public:
    double value;
    NumberNode(double value) : value(value) {}
    double calculate(Memory& memory) override {
        return value;
    }
};

class VariableNode : public Node {
public:
    std::string name;
    VariableNode(std::string name) : name(name) {}
    double calculate(Memory& memory) override {
        return memory.get(name);
    }
};

class OperationNode : public Node {
public:
    char op;
    NodePtr left, right;
    OperationNode(char op, NodePtr left, NodePtr right)
        : op(op), left(left), right(right) {}

    double calculate(Memory& memory) override {
        double l = left->calculate(memory);
        double r = right->calculate(memory);
        switch (op) {
            case '+': return l + r;
            case '-': return l - r;
            case '*': return l * r;
            case '/': return l / r;
        }
        return 0;
    }
};

class FunctionCallNode : public Node {
public:
    std::string name;
    std::vector<NodePtr> arguments;
    FunctionCallNode(std::string name, std::vector<NodePtr> arguments)
        : name(name), arguments(arguments) {}

    double calculate(Memory& memory) override {
        std::vector<double> values;
        for (auto& argument : arguments) {
            values.push_back(argument->calculate(memory));
        }

        if (name == "pow")  return std::pow(values[0], values[1]);
        if (name == "abs")  return std::fabs(values[0]);
        if (name == "max")  return std::max(values[0], values[1]);
        if (name == "min")  return std::min(values[0], values[1]);

        return 0;
    }
};

#endif //UNTITLED5_NODE_H
