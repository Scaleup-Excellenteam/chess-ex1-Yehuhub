
#include "Rook.h"

Rook::Rook(const Position& pos, bool white) : Piece(pos, white){}

char Rook::getSymbol()const{
    return isWhite ? 'R' : 'r';
}

StatusCode Rook::isValidMove(const Position& dest, const BoardManager& board)const{
    
}