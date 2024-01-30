#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

int main()
{
    int magicNum = 87;
    int userNum;
    std::string day;

    std::cout << "Enter a number: ";
    std::cin >> userNum;
    std::cout << std::endl;
    std::cout << "Enter a day: ";
    std::cin >> day;
    std::cout << std::endl;

    std::transform(day.begin(), day.end(), day.begin(), ::tolower); // to transform to upper case replace ::tolower with ::toupper

    if (userNum <= magicNum /* || day != "monday" */)
    {
        if (day == "monday")
            std::cout << "It is Monday" << std::endl;
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