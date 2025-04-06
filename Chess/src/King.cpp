#include "King.h"
#include <cstdlib>

#include <iostream> //debug

King::King(const Position& pos, bool white) : Piece(pos, white){}

char King::getSymbol()const{
    return isWhite() ? 'K' : 'k';
}

StatusCode King::isValidMove(const Position& dest, const BoardManager& board)const{

    //check distance is less than 1
    int dX = abs(dest._x - _pos._x);
    int dY = abs(dest._y - _pos._y);

    std::cout<< dX << " " <<dY<<std::endl;
    if (dX > 1 || dY > 1) {
        return StatusCode::IllegalMovement;
    }

    //------no need to check if path is clear

    //move is valid
    return StatusCode::LegalMovement;
}