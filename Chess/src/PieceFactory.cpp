
#include "PieceFactory.h"
#include "Rook.h"

std::unique_ptr<Piece> pieceFactory(char type, const Position& pos){
    bool white = std::isupper(type);
    char symbol = std::tolower(type);

    switch (symbol)
    {
    case 'r' : return std::make_unique<Rook>(pos, white);
    default: return nullptr;
    }
}