#include "TreeBuilder.h"
#include <cstdlib>

NodePtr TreeBuilder::buildExpression() {
    NodePtr left = buildTerm();

    while (current().type == PieceType::PLUS || current().type == PieceType::MINUS) {
        char op = current().text[0];
        advance();
        NodePtr right = buildTerm();
        left = std::make_shared<OperationNode>(op, left, right);
    }

    return left;
}

NodePtr TreeBuilder::buildTerm() {
    NodePtr left = buildFactor();

    while (current().type == PieceType::MULTIPLY || current().type == PieceType::DIVIDE) {
        char op = current().text[0];
        advance();
        NodePtr right = buildFactor();
        left = std::make_shared<OperationNode>(op, left, right);
    }

    return left;
}
NodePtr TreeBuilder::buildFactor() {
    Piece piece = current();

    if (piece.type == PieceType::NUMBER) {
        advance();
        return std::make_shared<NumberNode>(std::atof(piece.text.c_str()));
    }

    if (piece.type == PieceType::OPEN_PAREN) {
        advance();
        NodePtr node = buildExpression();
        advance();
        return node;
    }
    if (piece.type == PieceType::IDENTIFIER) {
        advance();
        if (current().type == PieceType::OPEN_PAREN) {

            advance();
            std::vector<NodePtr> arguments;
            if (current().type != PieceType::CLOSE_PAREN) {
                arguments.push_back(buildExpression());
                while (current().type == PieceType::COMA) {
                    advance();
                    arguments.push_back(buildExpression());
                }
            }
            advance();
            return std::make_shared<FunctionCallNode>(piece.text, arguments);
        }
        return std::make_shared<VariableNode>(piece.text);
    }

    return std::make_shared<NumberNode>(0);
}