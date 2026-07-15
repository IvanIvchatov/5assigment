#include <iostream>
#include <string>
#include "Splitter.h"
#include "TreeBuilder.h"
#include "Node.h"
#include "Memory.h"

int main() {
    Memory memory;
    std::string line;

    while (std::getline(std::cin, line)) {
        if (line == "exit" || line == "quit") break;
        if (line.empty()) continue;

        Splitter splitter;
        std::vector<Piece> pieces = splitter.split(line);

        if (pieces[0].type == PieceType::IDENTIFIER && pieces[0].text == "var") {
            std::string name = pieces[1].text;
            std::vector<Piece> rest(pieces.begin() + 3, pieces.end());
            TreeBuilder builder(rest);
            NodePtr node = builder.buildExpression();
            memory.add(name, node->calculate(memory));
            continue;
        }

        TreeBuilder builder(pieces);
        NodePtr node = builder.buildExpression();
        std::cout << node->calculate(memory) << std::endl;
    }

    return 0;
}