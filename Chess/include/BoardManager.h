#pragma once

#include <vector>
#include <memory>
#include <string>

#include "Position.h"
#include "Piece.h"

const size_t BOARDSIZE = 8;

class BoardManager{
    std::vector<std::vector<std::unique_ptr<Piece>>> _gameBoard; //used as the board matrix as access is o(1)
    bool _whiteTurn;

    public:
        // BoardManager(); // not necessary only for start of development
        BoardManager(const std::string& start = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr"); // will be implemented once we have a factory
        BoardManager(const BoardManager &) = delete;
        BoardManager& operator=(const BoardManager&) = delete;
        StatusCode playMove(const std::string & res);
        const Piece * getPieceAt(const Position&)const;
        std::unique_ptr<Piece> extractPieceAt(const Position&);
        bool isOccupied(const Position&)const;
        std::pair<Position, Position> resToPos(const std::string &);
        bool isInCheck(bool white)const;
        Position findKingPosition(bool white)const;
        void insertPiece(const Position& , std::unique_ptr<Piece>&& );
        StatusCode tryChecks(const Position&, const Position&);
};