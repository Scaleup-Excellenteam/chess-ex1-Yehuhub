#pragma once

//need to think if needs to be a class
//will need to implement:(maybe arithmetics for direction vector applications)
//  operators: !=, +/+=
//  copy ctor
struct Position
{
    int _x;
    int _y;

    bool operator==(const Position& other) const{
        return(_x == other._x && _y == other._y);
    }
    bool operator!=(const Position& other)const{
        return !(*this == other);
    }
    Position& operator+=(const Position& other){
        _x += other._x;
        _y += other._y;
        return *this;
    }

    Position& operator=(const Position& other){
        if(this != &other){
            _x = other._x;
            _y = other._y;
        }
        return *this;
    }
};
