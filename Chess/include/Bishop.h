#pragma once

#include "BoardManager.h"
#include "Piece.h"

class Bishop : public Piece{

    public:
    Bishop(const Position&, bool white);

    virtual bool isKing()const override;
    virtual StatusCode isValidMove(const Position& , const BoardManager&)const override;
};