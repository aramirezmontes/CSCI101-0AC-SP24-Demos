#include <iostream>

int main()
{
    int magicNum = 87;
    int userNum;

    std::cout << "Enter a number: ";
    std::cin >> userNum;
    std::cout << std::endl;

    if (userNum <= magicNum)
    {
        std::cout << "I won!!" << std::endl;
        std::cout << "I have the highest number because I'm the best!!!!" << std::endl;
    }
    else
    {
        std::cout << "Your number was higher." << std::endl;
    }
    std::cout << "Thanks for playing!" << std::endl;

    return 0;
}