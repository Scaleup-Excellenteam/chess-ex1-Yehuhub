#pragma once

#include "BoardManager.h"
#include "Piece.h"

class Rook : public Piece{

    public:
    Rook(const Position&, bool white);

    virtual bool isKing()const override;
    virtual StatusCode isValidMove(const Position& , const BoardManager&)const override;
};