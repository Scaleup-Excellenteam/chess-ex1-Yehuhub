
#include "BoardManager.h"
#include "PieceFactory.h"
#include <iostream>

// BoardManager::BoardManager() :_whiteTurn(true) {
//     _gameBoard.resize(BOARDSIZE, std::vector<std::unique_ptr<Piece>>(BOARDSIZE));
// }
BoardManager::BoardManager(const std::string& start) : _whiteTurn(true){
    if(start.size() != BOARDSIZE * BOARDSIZE){
        throw std::invalid_argument("String size must be 64 characters long!");
    }

    _gameBoard.reserve(BOARDSIZE);
    for(size_t i = 0; i < BOARDSIZE ; i++){
        std::vector<std::unique_ptr<Piece>> row;
        row.reserve(BOARDSIZE);  //better performance - saves allocations

        for(size_t j = 0; j < BOARDSIZE ; j++){
            std::cout<<j<<std::endl;
            char symbol = start[i * BOARDSIZE + j];
            row.emplace_back(pieceFactory(symbol ,Position(j + 1, i + 1)));
        }
        _gameBoard.emplace_back(std::move(row));
    }
}

const Piece * BoardManager::getPieceAt(const Position& pos)const{
    return _gameBoard[pos._y - 1][pos._x - 1].get();
}
bool BoardManager::isOccupied(const Position& pos)const{
    return _gameBoard[pos._y - 1][pos._x - 1].get();
}

int BoardManager::playMove(const std::string & res){
    auto [src, dest] = resToPos(res);

    auto srcPiece = getPieceAt(src);
    auto destPiece = getPieceAt(dest);

    if(!srcPiece){
        return 11;
    }

    if(_whiteTurn != srcPiece->isWhite()){
        return 12;
    }

    std::cout<< src._x << " "<< src._y <<std::endl;
    std::cout<< dest._x << " "<< dest._y <<std::endl;

    if(destPiece && srcPiece->isWhite() == destPiece->isWhite()){
        return 13;
    }

    if(getPieceAt(src)->isValidMove(dest, *this) != StatusCode::LegalMovement){
        return 21;
    }

    return 40;
}

//function assumes that res is in the valid format - (AHah 1-8 AHah 1-8)
std::pair<Position, Position> BoardManager::resToPos(const std::string & res){
    Position dest;
    Position src;

    src._y = std::toupper(res[0]) - 'A' + 1;
    src._x = res[1] - 48;

    dest._y = std::toupper(res[2]) - 'A' + 1;
    dest._x = res[3] - 48;

    return std::pair(src, dest);
}