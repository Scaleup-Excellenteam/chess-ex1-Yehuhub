
#include "PieceFactory.h"
#include "Rook.h"
#include "King.h"

std::unique_ptr<Piece> pieceFactory(char type, const Position& pos){
    bool white = std::isupper(type);
    char symbol = std::tolower(type);

    switch (symbol)
    {
    case 'r' : return std::make_unique<Rook>(pos, white);
    case 'k' : return std::make_unique<King>(pos, white);
    default: return nullptr;
    }
}