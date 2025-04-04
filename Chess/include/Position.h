#pragma once

struct Position
{
    int _x;
    int _y;

    bool operator==(const Position& other) const{
        return(_x == other._x && _y == other._y);
    }

    // Position& operator=(const Position& other){
    //     if(this != &other){
    //         _x = other._x;
    //         _y = other._y;
    //     }
    //     return *this;
    // }
};
