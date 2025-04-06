#pragma once

#include "Piece.h"
#include "StatusCode.h"

class King : public Piece{

    public:
    King(const Position&, bool white);
    virtual char getSymbol()const override;
    virtual StatusCode isValidMove(const Position& , const BoardManager&)const override;

};