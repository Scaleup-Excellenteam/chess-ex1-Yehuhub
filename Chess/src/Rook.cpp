
#include "Rook.h"

Rook::Rook(const Position& pos, bool white) : Piece(pos, white){}

char Rook::getSymbol()const{
    return isWhite() ? 'R' : 'r';
}

StatusCode Rook::isValidMove(const Position& dest, const BoardManager& board)const{
    
    //check if movement was valid
    if(dest._x != _pos._x && dest._y != _pos._y){
        return StatusCode::IllegalMovement;
    }

    //check if the path is clear
    Position dir(dest._x - _pos._x, dest._y - _pos._y); //direction
    Position current(_pos);

    while(current != dest){
        current += dir;
        if(board.isOccupied(current)){
            return StatusCode::IllegalMovement; // the movement is actually legal the the path is wrong(no correct status code)
        }
    }

}