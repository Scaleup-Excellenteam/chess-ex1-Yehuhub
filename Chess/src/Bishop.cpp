#include "Bishop.h"

Bishop::Bishop(const Position& pos, bool white) : Piece(pos, white){}

bool Bishop::isKing()const{
    return false;
}

StatusCode Bishop::isValidMove(const Position& dest, const BoardManager& board)const{
    
    int dX = dest._x - _pos._x;
    int dY = dest._y - _pos._y;

    //-------check if movement was valid
    if(abs(dX) != abs(dY)){
        return StatusCode::IllegalMovement;
    }

    //-------check if the path is clear
    //find the direction vector and normalize to 1(specific for rook)
    Position dir((dX > 0) ? 1 : -1,
                 (dY > 0) ? 1 : -1); 

    if(!board.isPathClear(_pos, dest, dir)){
        return StatusCode::IllegalMovement;
    }

    return StatusCode::LegalMovement;
}
