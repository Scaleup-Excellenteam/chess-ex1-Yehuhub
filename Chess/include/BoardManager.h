#include <vector>
#include <memory>
#include <string>

#include "Piece.h"
#include "Position.h"

const size_t BOARDSIZE = 8;

class BoardManager{
    std::vector<std::vector<std::unique_ptr<Piece>>> _gameBoard;
    bool _whiteTurn;

    public:
        BoardManager(); // not necessary only for start of development
        BoardManager(const std::string& start = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr"); // will be implemented once we have a factory
        BoardManager(const BoardManager &) = delete;
        BoardManager& operator=(const BoardManager&) = delete;
        int playMove(const std::string & res);
        const Piece * getPieceAt(const Position&)const;
        bool isOccupied(const Position&)const;

};