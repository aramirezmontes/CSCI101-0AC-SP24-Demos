#include <iostream>
#include <limits>
#include <string>

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
    ORANGE,
    YELLOW
};

void resetStream();

colorType inputColor();
void printColorMenu();
void printColor(colorType theColor);
std::string printColorName(colorType theColor);

int main()
{
    colorType color;
    color = inputColor();
    printColor(color);
    std::cout << printColorName(color) << std::endl;
    std::cout << "\033[0m";
    return 0;
}

colorType inputColor()
{

    colorType theColor;
    int colorInt;
    do
    {
        printColorMenu();
        std::cin >> colorInt;
        if (!std::cin)
        {
            resetStream();
        }
        else if (colorInt < 1 || colorInt > 6)
        {
            std::cout << "You must choose a number from the list." << std::endl;
        }
    } while (!std::cin || colorInt < 1 || colorInt > 6);
    switch (colorInt)
    {
    case 1:
        theColor = RED;
        break;
    case 2:
        theColor = BLUE;
        break;
    case 3:
        theColor = GREEN;
        break;
    case 4:
        theColor = PURPLE;
        break;
    case 5:
        theColor = ORANGE;
        break;
    case 6:
        theColor = YELLOW;
        break;
    }

    return theColor;
}

void printColorMenu()
{
    std::cout << "Please choose a color:" << std::endl;
    std::cout << "1. Red" << std::endl;
    std::cout << "2. Blue" << std::endl;
    std::cout << "3. Green" << std::endl;
    std::cout << "4. Purple" << std::endl;
    std::cout << "5. Orange" << std::endl;
    std::cout << "6. Yellow" << std::endl;
}

void printColor(colorType theColor)
{
    std::cout << "\033[1m";
    switch (theColor)
    {
    case RED:
        std::cout << "\033[38;5;196m\033[48;5;88m";
        break;
    case BLUE:
        std::cout << "\033[38;5;81m\033[48;5;4m";
        break;
    case GREEN:
        std::cout << "\033[38;5;118m\033[48;5;2m";
        break;
    case PURPLE:
        std::cout << "\033[38;5;135m\033[48;5;53m";
        break;
    case YELLOW:
        std::cout << "\033[38;5;226m\033[48;5;178m";
        break;
    case ORANGE:
        std::cout << "\033[38;5;214m\033[48;5;166m";
        break;
    default:
        std::cout << "\033[0m"
                  << "Unknown Color" << std::endl;
    }
    std::cout << "[ ]" << std::endl;
    std::cout << "\033[0m";
}

std::string printColorName(colorType theColor)
{
    switch (theColor)
    {
    case BLUE:
        return "Blue";
    case RED:
        return "Red";
    case YELLOW:
        return "Yellow";
    case ORANGE:
        return "Orange";
    case GREEN:
        return "Green";
    case PURPLE:
        return "Purple";
    default:
        return "Unknown Color";
    }
}

void resetStream()
{
    std::cout << "You entered something that is not a number!" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}