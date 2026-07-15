#ifndef UNTITLED5_SPLITTER_H
#define UNTITLED5_SPLITTER_H

#include <string>
#include <vector>
#include "Piece.h"

class Splitter {
    public:
        std::vector<Piece> split(const std::string& line);
    private:
    Piece readNumber(const std::string& line, size_t& pos);
    Piece readName(const std::string& line, size_t& pos);
};

#endif //UNTITLED5_SPLITTER_H
