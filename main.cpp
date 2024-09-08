#include "./Globals/Aggregator.h"
#include "./Classes/Map/Map.h"
#include "./Classes/AI/AI.h"
#include "./Functions/Helpers.h"

int main(int argc, char **argv)
{
    bool Base = true;
    bool Hardmode;
    std::cout << "Do you like a challange? Y or N\n";
    char Uin = GetChar('Y', 'N');

    if (Uin == 'Y')
    {
        Hardmode = true;
        std::cout << "Hardmode activated" << std::endl;
    }
    else if (Uin = 'N')
        Hardmode = false;


    Map map(Base);
    AI Logic;
    Trivium();
    map.Tutorial();
    map.Show_Map();
    map.Reset_Map();
    int PVictory = 0;
    int AIVictory = 0;
    int Draw_count = 0;
    while (true)
    {
        int Pmove;
        while (true)
        {
            std::cout << "Make your move stranger: ";
            std::cin >> Pmove;
            move LPmove = Logic.User_to_2d(Pmove);
            if (map.Check_position(LPmove))
            {
                map.set_position(LPmove, Logic.Get_Player_symbol());
                break;
            }
        }
        if (Logic.Victory(Logic.Get_Player_symbol(), map))
        {
            map.Show_Map();
            PVictory++;
            std::cout << Logic.Get_Player_symbol() << " Won\n";
            std::cout << PVictory << " times" << std::endl;
            if (Replay('Y', 'N'))
                map.Reset_Map();
            else
                break;
        }
        else if (!map.Are_moves_left())
        {
            map.Show_Map();
            Draw_count++;
            std::cout << "Congratulations it's a Tie\n";
            std::cout << "Yee Drew the game " << Draw_count << " times" << std::endl;
            if (Replay('Y', 'N'))
                map.Reset_Map();
            else
                break;
        }
        Logic.C_move(Hardmode, map);
        map.Show_Map();
        if (Logic.Victory(Logic.Get_AI_symbol(), map))
        {
            map.Show_Map();
            AIVictory++;
            std::cout << Logic.Get_AI_symbol() << " Won\n";
            std::cout << "EW you've been beaten " << AIVictory << " times" << std::endl;
            if (Replay('Y', 'N'))
                map.Reset_Map();
            else
                break;
        }
        else if (!map.Are_moves_left())
        {
            Draw_count++;
            std::cout << "Congratulations it's a Tie\n";
            std::cout << "Yee Drew the game " << Draw_count << " times" << std::endl;
        }
    }
}