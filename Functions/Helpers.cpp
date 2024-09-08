#include "Helpers.h"

char GetChar(char condition_1, char condition_2)
{
    char input;
    while (true)
    {

        std::cin >> input;
        input = toupper(input);
        if (input != toupper(condition_1) && input != toupper(condition_2))
        {
            std::cout << "Invalid input Type either " << condition_1 << " or " << condition_2 << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    return input;
}

void Trivium()
{
    std::cout << "You can move by typing in the number you want to occupy\n";
    std::cout << "You play with the standard ruleset, First to take 3 in line wins\n";
    std::cout << "here be the Map\n";
}

bool Replay(char condition_1, char condition_2)
{
    std::cout << "Would you like to play again? " << condition_1 << " or " << condition_2 << std::endl;
    char answer = GetChar(condition_1, condition_2);
    if (answer == condition_1)
        return true;

    return false;
}
