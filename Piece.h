#ifndef UNTITLED5_PIECE_H
#define UNTITLED5_PIECE_H

#include <string>

enum class PieceType {
    NUMBER,
    IDENTIFIER,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    OPEN_PAREN,
    CLOSE_PAREN,
    OPEN_BRACKET,
    CLOSE_BRACKET,
    COMA,
    ASSIGN,
    END
};

struct Piece {
    PieceType type;
    std::string text;

    Piece(PieceType type, std::string text)
        : type(type), text(std::move(text)) {}
};

#endif //UNTITLED5_PIECE_H
