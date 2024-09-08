#include "Map.h"

Map::Map(bool Base)
{
    if (Base)
    {
        // game map
        for (int i = 0; i < Y_axis; i++)
        {
            for (int j = 0; j < X_axis; j++)
            {
                bool isBorderRow = (i == R_position_A || i == R_position_B);
                bool isBorderCol = (j == C_position_A || j == C_position_B);
                bool isEndOfLine = (j == X_axis - 1);
                Gmap[i][j] = isEndOfLine ? '\n' : (isBorderRow ? (isBorderCol ? '|' : '_') : (isBorderCol ? '|' : ' '));
            }
        }
        // Logic Map
        int Y_position = 1;
        for (int i = 0; i < LY_axis; i++)
        {
            int X_position = 1;
            for (int j = 0; j < LX_axis; j++)
            {
                Lmap[i][j] = &Gmap[Y_position][X_position];
                X_position = X_position + 4;
            }
            Y_position = Y_position + 3;
        }
    }
}
void Map::Show_Map()
{
    for (int i = 0; i < Y_axis; i++)
    {
        for (int j = 0; j < X_axis; j++)
        {
            std::cout << Gmap[i][j];
        }
    }
    std::cout << std::endl;
}
void Map::Reset_Map()
{
    for (int i = 0; i < LY_axis; i++)
    {
        for (int j = 0; j < LX_axis; j++)
        {
            *Lmap[i][j] = Blank;
        }
    }
}
void Map::Tutorial()
{
    int counter = 1;
    for (int i = 0; i < LX_axis; i++)
    {
        for (int j = 0; j < LY_axis; j++)
        {
            *Lmap[i][j] = '0' + counter;
            counter++;
        }
    }
}
void Map::set_position(move Movement, char symbol)
{
    *Lmap[Movement.Row][Movement.Col] = symbol;
}

bool Map::Check_position(move Movement)
{

    if (*Lmap[Movement.Row][Movement.Col] == Blank)
    {
        return true;
    }
    return false;
}
char Map::Get_position(int Col, int Row)
{
    return *Lmap[Row][Col];
}

bool Map::Are_moves_left()
{
    for (int i = 0; i < LY_axis; i++)
    {
        for (int j = 0; j < LX_axis; j++)
        {
            if (*Lmap[i][j] == Blank)
            {
                return true;
            }
        }
    }
    return false;
}
char Map::Get_blank()
{
    return Blank;
}
Map::~Map()
{
    for (int i = 0; i < LX_axis; i++)
    {
        for (int j = 0; j < LX_axis; j++)
        {
            Lmap[i][j] = nullptr;
        }
    }
}
