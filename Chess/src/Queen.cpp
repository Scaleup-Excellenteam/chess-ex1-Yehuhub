#include "Queen.h"

Queen::Queen(const Position& pos, bool white) : Piece(pos, white){}

bool Queen::isKing()const{
    return false;
}

StatusCode Queen::isValidMove(const Position& dest, const BoardManager& board)const{
    
    int dX = dest._x - _pos._x;
    int dY = dest._y - _pos._y;
    Position dir;

    //-------check if movement was valid and get the correct direction vector normalized
    if(dest._x == _pos._x){
        dir = {0, (dest._y > _pos._y ? 1 : -1)};
    }else if(dest._y == _pos._y){
        dir = {(dest._x > _pos._x ? 1 : -1), 0};
    }else if(abs(dX) == abs(dY)){
        dir = {(dX > 0) ? 1 : -1,
               (dY > 0) ? 1 : -1}; 
    }else{
        return StatusCode::IllegalMovement;
    }

    if(!board.isPathClear(_pos, dest, dir)){
        return StatusCode::IllegalMovement;
    }

    return StatusCode::LegalMovement;
}
