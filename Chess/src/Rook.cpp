
#include "Rook.h"

Rook::Rook(const Position& pos, bool white) : Piece(pos, white){}

char Rook::getSymbol()const{
    return isWhite() ? 'R' : 'r';
}

StatusCode Rook::isValidMove(const Position& dest, const BoardManager& board)const{
    

    //-------check if movement was valid
    if(dest._x != _pos._x && dest._y != _pos._y){
        return StatusCode::IllegalMovement;
    }

    //-------check if the path is clear
    //find the direction vector and normalize to 1(specific for rook)
    Position dir((dest._x == _pos._x) ? 0 : (dest._x > _pos._x ? 1 : -1),
                 (dest._y == _pos._y) ? 0 : (dest._y > _pos._y ? 1 : -1)); 
    Position current(_pos);

    while(current != dest){
        current += dir;
        if(board.isOccupied(current)){
            return StatusCode::IllegalMovement; // the movement is actually legal but the path is not clear(no correct status code)
        }
    }

}