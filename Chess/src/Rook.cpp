#include "Rook.h"

Rook::Rook(const Position& pos, bool white) : Piece(pos, white){}

bool Rook::isKing()const{
    return false;
}

StatusCode Rook::isValidMove(const Position& dest, const BoardManager& board)const{
    

    //-------check if movement was valid
    if(dest._x != _pos._x && dest._y != _pos._y){
        return StatusCode::IllegalMovement;
    }

    //-------check if the path is clear
    //find the direction vector and normalize to 1
    Position dir((dest._x == _pos._x) ? 0 : (dest._x > _pos._x ? 1 : -1),
                 (dest._y == _pos._y) ? 0 : (dest._y > _pos._y ? 1 : -1)); 
                 
    if(!board.isPathClear(_pos, dest, dir)){
        return StatusCode::IllegalMovement;
    }

    return StatusCode::LegalMovement;
}
