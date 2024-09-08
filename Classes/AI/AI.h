#ifndef AI_H
#define AI_H

#include "../../Globals/Aggregator.h"

class Map;
class AI
{
private:
    const int Vin_condition = 3;
    const int arrayOffset = 1;
    int Map_size = LX_axis * LY_axis;
    int AIS_factor = 10;
    int PLS_factor = -10;
    int draw_score = 0;
    char AI_symbol = 'O';
    char Player_symbol = 'X';

public:
    move User_to_2d(int input);
    void set_C_symbol(char symbol_param);
    
    bool Victory(char symbol, Map& map);
    move find_best_move(char symbol, Map& map);
    void C_move(bool Hard, Map& map);
    char Get_Player_symbol();
    char Get_AI_symbol();
    AI();
    ~AI();
};
#endif