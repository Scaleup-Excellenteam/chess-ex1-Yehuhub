#pragma once

#include "Position.h"
#include "StatusCode.h"
//need to define Position√ (need to check if _pos(pos) works)
//need to define enum or namespace for status codes

class Piece{
    
    Position _pos;
    bool _white;

    public:
    Piece(const Position& pos, bool white) : _pos(pos), _white(white){}; 

    bool isWhite()const{ return _white; }; //for readability
    void changePosition(const Position&);
    
    virtual char getSymbol()const = 0;
    // virtual bool isPathClear(const Position&, const BoardManager&)const = 0;
    virtual StatusCode isValidMove(const Position&, const BoardManager&)const = 0;

};