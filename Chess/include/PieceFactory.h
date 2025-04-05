#pragma once

#include <memory>
#include "Piece.h"
#include "Position.h"


std::unique_ptr<Piece> pieceFactory(char type, const Position&);