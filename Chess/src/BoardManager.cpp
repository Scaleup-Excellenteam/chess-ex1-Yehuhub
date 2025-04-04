
#include "BoardManager.h"

BoardManager::BoardManager() {
    _gameBoard.resize(BOARDSIZE, std::vector<std::unique_ptr<Piece>>(BOARDSIZE));
}

const Piece * BoardManager::getPieceAt(const Position& pos)const{
    return _gameBoard[pos._x][pos._y].get();
}
bool BoardManager::isOccupied(const Position& pos)const{
    return _gameBoard[pos._x][pos._y].get();
}