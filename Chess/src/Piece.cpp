#include "Piece.h"

Piece::Piece(const Position& pos, bool white) : _pos(pos), _white(white){}; 

bool Piece::isWhite()const{ 
    return _white; 
}

void Piece::changePosition(const Position& newPos){
    _pos = newPos;
}