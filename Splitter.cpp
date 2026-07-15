#include "Splitter.h"
#include <cctype>

Piece Splitter::readNumber(const std::string& line, size_t& pos) {
    size_t start = pos;
    while (pos < line.size() && (std::isdigit((unsigned char)line[pos]) || line[pos] == '.')) {
        pos++;
    }
    std::string text = line.substr(start, pos - start);
    return Piece(PieceType::NUMBER, text);
}
Piece Splitter::readName(const std::string& line, size_t& pos) {
    size_t start = pos;
    while (pos < line.size() && (std::isalnum((unsigned char)line[pos]) || line[pos] == '_')) {
        pos++;
    }
    std::string text = line.substr(start, pos - start);
    return Piece(PieceType::IDENTIFIER, text);
}

std::vector<Piece> Splitter::split(const std::string& line) {
    std::vector<Piece> pieces;
    size_t pos = 0;
    while (pos < line.size()) {
        char c = line[pos];
        if (std::isspace((unsigned char)c)) {
            pos++;
            continue;
        }
        if (std::isdigit((unsigned char)c)) {
            pieces.push_back(readNumber(line, pos));
            continue;
        }
        if (std::isalpha((unsigned char)c)) {
            pieces.push_back(readName(line, pos));
            continue;
        }
        switch (c) {
            case '+': pieces.push_back(Piece(PieceType::PLUS, "+")); break;
            case '-': pieces.push_back(Piece(PieceType::MINUS, "-")); break;
            case '*': pieces.push_back(Piece(PieceType::MULTIPLY, "*")); break;
            case '/': pieces.push_back(Piece(PieceType::DIVIDE, "/")); break;
            case '(': pieces.push_back(Piece(PieceType::OPEN_PAREN, "(")); break;
            case ')': pieces.push_back(Piece(PieceType::CLOSE_PAREN, ")")); break;
            case '{': pieces.push_back(Piece(PieceType::OPEN_BRACKET, "{")); break;
            case '}': pieces.push_back(Piece(PieceType::CLOSE_BRACKET, "}")); break;
            case ',': pieces.push_back(Piece(PieceType::COMA, ",")); break;
            case '=': pieces.push_back(Piece(PieceType::ASSIGN, "=")); break;
            default: break;
        }
        pos++;
    }
    pieces.push_back(Piece(PieceType::END, ""));
    return pieces;
}