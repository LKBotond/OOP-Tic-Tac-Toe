#ifndef AGGREGATOR_H
#define AGGREGATOR_H
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <limits>
#include <vector>

constexpr int X_axis = 12;
constexpr int Y_axis = 9;
constexpr int LX_axis = 3;
constexpr int LY_axis = 3;

struct move
{

    int Score;
    int Row;
    int Col;
    move() {};
    move(int score)
    {
        Score = score;
    };
};
#endif
