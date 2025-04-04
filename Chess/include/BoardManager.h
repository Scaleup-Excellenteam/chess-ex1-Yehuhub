#include <vector>
#include <memory>
#include <string>

#include "Piece.h"
#include "Position.h"

class BoardManager{
    std::vector<std::vector<std::unique_ptr<Piece>>> _gameBoard;

    public:
        BoardManager(const std::string& start = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr");
        BoardManager(const BoardManager &) = delete;
        BoardManager& operator=(const BoardManager&) = delete;
        int playMove(const std::string & res);
        const Piece * getPieceAt(const Position&)const;

};