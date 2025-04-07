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
    virtual ~Piece() = default;

    bool isWhite()const; 
    void changePosition(const Position&);
    
    virtual bool isKing()const = 0;
    virtual StatusCode isValidMove(const Position&, const BoardManager&)const = 0;

};