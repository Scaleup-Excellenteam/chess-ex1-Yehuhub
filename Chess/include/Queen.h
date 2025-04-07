#pragma once

#include "BoardManager.h"
#include "Piece.h"

class Queen : public Piece{

    public:
    Queen(const Position&, bool white);

    virtual bool isKing()const override;
    virtual StatusCode isValidMove(const Position& , const BoardManager&)const override;
};