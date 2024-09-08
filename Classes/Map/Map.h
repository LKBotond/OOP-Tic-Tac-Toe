#ifndef MAP_H
#define MAP_H

#include "../../Globals/Aggregator.h"

class Map
{
private:
    char Gmap[Y_axis][X_axis];
    char *Lmap[LY_axis][LX_axis];
    const int R_position_A = 2;
    const int R_position_B = 5;
    const int C_position_A = 3;
    const int C_position_B = 7;
    char Blank = ' ';

public:
    void Show_Map();
    void Reset_Map();
    void Tutorial();
    void set_position(move Movement, char symbol);

    bool Check_position(move Movement);
    bool Are_moves_left();
    char Get_position(int Col, int Row);
    char Get_blank();

    Map(bool Base);
    ~Map();
};
#endif