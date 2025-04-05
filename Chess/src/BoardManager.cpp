
#include "BoardManager.h"
#include "PieceFactory.h"

BoardManager::BoardManager() :_whiteTurn(true) {
    _gameBoard.resize(BOARDSIZE, std::vector<std::unique_ptr<Piece>>(BOARDSIZE));
}
BoardManager::BoardManager(const std::string& start) : _whiteTurn(true){
    if(start.size() != BOARDSIZE * BOARDSIZE){
        throw std::invalid_argument("String size must be 64 characters long!");
    }

    for(size_t i = 0; i < BOARDSIZE ; i++){
        for(size_t j = 0; j < BOARDSIZE ; j++){
            char symbol = start[i * BOARDSIZE + j];
            _gameBoard[i].push_back(pieceFactory(symbol ,Position(i + 1, j + 1)));
        }
    }
}

const Piece * BoardManager::getPieceAt(const Position& pos)const{
    return _gameBoard[pos._x][pos._y].get();
}
bool BoardManager::isOccupied(const Position& pos)const{
    return _gameBoard[pos._x][pos._y].get();
}