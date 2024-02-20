#include <iostream>

/* const int BLUE = 0;
const int RED = 1;
const int GREEN = 2;
const int YELLOW = 3;
const int PURPLE = 4;
const int ORANGE = 5; */
enum colorType
{
    RED,
    BLUE,
    GREEN,
    PURPLE,
    ORANGE
};

int main()
{
    colorType color;
    if (color == BLUE)
    {
        std::cout << "\033[1m"
                  << "\033[38;5;81m\033[48;5;4m"
                  << "[ ]" << std::endl;
    }
    else if (color == GREEN)
    {
        std::cout << "\033[1m"
                  << "\033[38;5;118m\033[48;5;2m"
                  << "[ ]" << std::endl;
    }

    std::cout << "\033[0m";
    return 0;
}