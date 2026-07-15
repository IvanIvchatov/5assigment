
#ifndef UNTITLED5_TREEBUILDER_H
#define UNTITLED5_TREEBUILDER_H

#include <vector>
#include "Piece.h"
#include "Node.h"

class TreeBuilder {
public:
    TreeBuilder(std::vector<Piece> pieces) : pieces(std::move(pieces)), pos(0) {}

    NodePtr buildExpression();

private:
    std::vector<Piece> pieces;
    size_t pos;

    Piece& current() { return pieces[pos]; }
    void advance() { pos++; }

    NodePtr buildTerm();
    NodePtr buildFactor();
};

#endif //UNTITLED5_TREEBUILDER_H
