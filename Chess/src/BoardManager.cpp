
#include "BoardManager.h"
#include "PieceFactory.h"
#include <iostream>

/**
 * @brief Construct a new Board Manager:: Board Manager object
 * 
 * @param start - board string
 */
BoardManager::BoardManager(const std::string& start) : _whiteTurn(true){
    if(start.size() != BOARDSIZE * BOARDSIZE){
        throw std::invalid_argument("String size must be 64 characters long!");
    }

    _gameBoard.reserve(BOARDSIZE);
    for(size_t i = 0; i < BOARDSIZE ; i++){
        std::vector<std::unique_ptr<Piece>> row;
        row.reserve(BOARDSIZE);  //better performance - saves allocations

        for(size_t j = 0; j < BOARDSIZE ; j++){
            char symbol = start[i * BOARDSIZE + j];
            row.emplace_back(pieceFactory(symbol ,Position(j + 1, i + 1)));
        }
        _gameBoard.emplace_back(std::move(row));
    }
}

/**
 * @brief checks if theres a piece at the selected position
 * 
 * @param pos - position to check
 * @return true - there is a piece at the position
 * @return false - no piece at the position
 */
bool BoardManager::isOccupied(const Position& pos)const{
    return _gameBoard[pos._y - 1][pos._x - 1].get();
}

/**
 * @brief returns a const raw pointer to the piece at the position
 * 
 * @param pos - position to return
 * @return const Piece* - const raw pointer to the piece
 */
const Piece * BoardManager::getPieceAt(const Position& pos)const{
    return _gameBoard[pos._y - 1][pos._x - 1].get();
}

/**
 * @brief pulls a piece out of the game board
 * 
 * @param pos - position of the piece we want to take out
 * @return std::unique_ptr<Piece> - returns the pulled piece
 */
std::unique_ptr<Piece> BoardManager::extractPieceAt(const Position& pos){
    return std::move(_gameBoard[pos._y - 1][pos._x - 1]);
}

/**
 * @brief insert a piece into the desired position
 * 
 * @param src - source position of piece
 * @param dest - destination position of piece
 */
void BoardManager::insertPiece(const Position& where, std::unique_ptr<Piece>&& piece){
    if(piece){
        piece->changePosition(where);
    }
    _gameBoard[where._y - 1][where._x - 1] = std::move(piece);
}


/**
 * @brief main function, performs all the necessary checks for a move and returns the status code for
 * the played move
 * 
 * @param res - formatted string 
 * @return StatusCode - the status code matching the played move
 */
StatusCode BoardManager::playMove(const std::string & res){
    auto [srcPos, destPos] = resToPos(res);

    auto srcPiece = getPieceAt(srcPos);
    auto destPiece = getPieceAt(destPos);

    if(!srcPiece){
        return StatusCode::NoPieceAtSource;
    }

    if(_whiteTurn != srcPiece->isWhite()){
        return StatusCode::WrongPieceAtSource;
    }


    if(destPiece && srcPiece->isWhite() == destPiece->isWhite()){
        return StatusCode::OwnPieceAtDest;
    }

    if(getPieceAt(srcPos)->isValidMove(destPos, *this) != StatusCode::LegalMovement){
        return StatusCode::IllegalMovement;
    }

    //Actually check for checks and move/return cannot move (needs to be delegated to another function for cleaner implementation)
    // auto extractedDest = extractPieceAt(destPos); //it is out of the vector and kept if needs to be returned to original pos
    // auto extractedSrc = extractPieceAt(srcPos);
    // insertPiece(destPos, std::move(extractedSrc));
    // if(isInCheck(_whiteTurn)){
    //     insertPiece(srcPos, std::move(extractPieceAt(destPos)));
    //     insertPiece(destPos, std::move(extractedDest));
    //     return StatusCode::MoveCauseOwnCheck;
    // }

    StatusCode checks = tryChecks(srcPos, destPos);
    if(checks != StatusCode::MoveCauseOwnCheck){
        _whiteTurn = !_whiteTurn;
    }
    return checks;
}

StatusCode BoardManager::tryChecks(const Position& src, const Position& dest){
    auto extractedSrc = extractPieceAt(src);
    auto extractedDest = extractPieceAt(dest); //it is out of the vector and kept if needs to be returned to original pos

    insertPiece(dest, std::move(extractedSrc));
    if(isInCheck(_whiteTurn)){
        insertPiece(src, std::move(extractPieceAt(dest)));
        insertPiece(dest, std::move(extractedDest));
        return StatusCode::MoveCauseOwnCheck;
    }else if(isInCheck(!_whiteTurn)){
        return StatusCode::ValidMoveCheckEnemy;
    }else{
        return StatusCode::ValidMoveNextTurn;
    }

}


/**
 * @brief function takes string in correct format (AHah1-8AHah1-8) and returns the src position 
 * and dest position
 * 
 * @param res - formatted string 
 * @return std::pair<Position, Position> - pair of positions(src, dest)
 */
std::pair<Position, Position> BoardManager::resToPos(const std::string & res){
    Position dest;
    Position src;

    src._y = std::toupper(res[0]) - 'A' + 1;
    src._x = res[1] - 48;

    dest._y = std::toupper(res[2]) - 'A' + 1;
    dest._x = res[3] - 48;

    return std::pair(src, dest);
}



//this should probably be changed to look for checks so it also looks for good checks(return value StatusCode)
/**
 * @brief function finds the wanted king's position and checks if in check
 * 
 * @param white - color we are looking for check on
 * @return true - if selected color is in check
 * @return false - if selected color is not in check
 */
bool BoardManager::isInCheck(bool white)const{
    Position myKingPos = findKingPosition(white);

    //in a weird case we dont have a king of that color(playing with no kings)
    if(myKingPos._x == -1 || myKingPos._y == -1){
        return false;
    }

    for (int y = 0 ; y < BOARDSIZE ; y++){
        for (int x = 0 ; x < BOARDSIZE ; x++){
            auto tempPiece = getPieceAt({x + 1, y + 1});
            if(tempPiece && tempPiece->isWhite() != white){
                if(tempPiece->isValidMove(myKingPos, *this) == StatusCode::LegalMovement){
                    return true;
                }
            }
        }
    }
    return false;
}

/**
 * @brief finds the wanted king in the vector
 * 
 * @param white - true if white, false if black
 * @return Position -- return the king's position
 */
Position BoardManager::findKingPosition(bool white)const{

    char kingSymbol = white ? 'K' : 'k';

    for (int y = 0 ; y < BOARDSIZE ; y++){
        for (int x = 0 ; x < BOARDSIZE ; x++){
            Position pos(x + 1, y + 1);
            auto tempPiece = getPieceAt(pos);
            if(tempPiece && tempPiece->getSymbol() == kingSymbol){
                return pos;
            }
        }
    }
    return {-1,-1}; //for game with no kings
}
