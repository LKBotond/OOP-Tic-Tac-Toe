#include "AI.h"
#include "../Map/Map.h"

AI::AI() {}
move AI::User_to_2d(int input)
{
    move movement;
    movement.Row = (input - arrayOffset) / LX_axis;
    movement.Col = (input - arrayOffset) % LY_axis;
    return movement;
}

void AI::set_C_symbol(char symbol_param)
{
    AI_symbol = symbol_param;
}

bool AI::Victory(char symbol, Map &map)
{
    int count = 0;
    // serarch horizontally
    for (int i = 0; i < LY_axis; i++)
    {
        for (int j = 0; j < LX_axis; j++)
        {
            if (symbol == map.Get_position(i, j))
            {
                count++;
                if (count == Vin_condition)
                {
                    return true;
                }
            }
        }
        count = 0;
    }

    // search vertically
    for (int i = 0; i < LX_axis; i++)
    {
        for (int j = 0; j < LY_axis; j++)
        {
            if (symbol == map.Get_position(j, i))
            {
                count++;
                if (count == Vin_condition)
                {
                    return true;
                }
            }
        }
        count = 0;
    }

    // search diagonally
    for (int i = 0; i < LY_axis; i++)
    {
        if (symbol == map.Get_position(i, i))
        {
            count++;
            if (count == Vin_condition)
            {
                return true;
            }
        }
    }
    count = 0;

    // search contra diagonally
    for (int i = 0; i < LY_axis; i++)
    {
        if (symbol == map.Get_position(i, LX_axis - i - 1))
        {
            count++;
            if (count == Vin_condition)
            {
                return true;
            }
        }
    }
    return false;
}

move AI::find_best_move(char symbol, Map &map)
{

    // base case
    if (Victory(AI_symbol, map))
        return move(AIS_factor);

    else if (Victory(Player_symbol, map))
        return move(PLS_factor);

    else if (!map.Are_moves_left())
        return move(draw_score);

    std::vector<move> moves;
    for (int i = 0; i < LX_axis; i++)
    {
        for (int j = 0; j < LY_axis; j++)
        {

            move Current_move;
            Current_move.Row = i;
            Current_move.Col = j;
            if (map.Check_position(Current_move))
            {
                map.set_position(Current_move, symbol);

                // evaluation
                if (symbol == AI_symbol)
                {
                    Current_move.Score = find_best_move(Player_symbol, map).Score;
                }
                else
                {
                    Current_move.Score = find_best_move(AI_symbol, map).Score;
                }
                moves.push_back(Current_move);
                map.set_position(Current_move, map.Get_blank());
            }
        }
    }
    int Best_move = 0;
    if (symbol == AI_symbol)
    {
        int bestScore = PLS_factor;
        for (int i = 0; i < moves.size(); i++)
        {
            if (moves[i].Score > bestScore)
            {
                Best_move = i;
                bestScore = moves[i].Score;
            }
        }
    }
    else if (symbol == Player_symbol)
    {
        int bestScore = AIS_factor;
        for (int i = 0; i < moves.size(); i++)
        {
            if (moves[i].Score < bestScore)
            {
                Best_move = i;
                bestScore = moves[i].Score;
            }
        }
    }
    return moves[Best_move];
}

void AI::C_move(bool Hard, Map &map)
{
    if (Hard)
    {
        move movement;
        movement.Score = 0;
        movement = find_best_move(AI_symbol, map);
        map.set_position(movement, AI_symbol);
    }
    else
    {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        while (true)
        {
            move movement = User_to_2d(std::rand() % Map_size);
            if (map.Check_position(movement))
            {
                map.set_position(movement, AI_symbol);
                break;
            }
        }
    }
}
char AI::Get_Player_symbol()
{
    return Player_symbol;
}

char AI::Get_AI_symbol()
{
    return AI_symbol;
}

AI::~AI()
{
}
