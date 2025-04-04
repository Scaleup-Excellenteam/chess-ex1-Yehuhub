#pragma once

enum class StatusCode {
    NoPieceAtSource = 11,
    WrongPieceAtSource,
    OwnPieceAtDest,
    IllegalMovement = 21,
    MoveCauseOwnCheck = 31,

    LegalMovement = 40,
    ValidMoveCheckEnemy,
    ValidMoveNextTurn
};