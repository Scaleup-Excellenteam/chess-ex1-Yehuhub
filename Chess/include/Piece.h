#pragma once


#include "Position.h"
#include "StatusCode.h"

class BoardManager;

class Piece{
    
    bool _white;

    protected:
    Position _pos;

    public:
    Piece(const Position& pos, bool white); 

    bool isWhite()const; 
    void changePosition(const Position&);
    
    virtual char getSymbol()const = 0;
    virtual StatusCode isValidMove(const Position&, const BoardManager&)const = 0;

};