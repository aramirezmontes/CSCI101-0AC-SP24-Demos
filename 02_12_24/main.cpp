#include <iostream>
#include <string>
#include <limits>
#include <cmath>

int getIntGreaterThan0(std::string prompt);

int main()
{
    int memSize;
    memSize = getIntGreaterThan0("Enter the memory size: ");

    std::cout << "The minimum MAR size is " << ceil(log2(memSize)) << std::endl;

    return 0;
}

int getIntGreaterThan0(std::string prompt)
{
    int number;
    std::cout << prompt;
    std::cin >> number;
    std::cout << std::endl;
    while (!std::cin || number <= 0)
    {
        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "You entered something that is not a number." << std::endl;
        }
        else
        {
            std::cout << "The number must be greater than 0." << std::endl;
        }
        std::cout << prompt;
        std::cin >> number;
        std::cout << std::endl;
    }
    return number;
}