#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

int main()
{
    std::string input;
    double exp;
    std::cout << std::setprecision(2) << std::fixed << std::showpoint;

    std::cout << "Enter the exponent: ";
    std::cin >> exp;
    std::cout << std::endl;
    // std::cin.clear();
    // std::cin >> exp;
    // int x;
    // std::cin >> x;
    char ch;
    // std::cin.get(ch);
    //  remove leading whitespace from input stream

    std::cout << "Enter something: ";
    std::cin >> std::ws;
    // std::cin >> input; only gets one word up to a space
    std::getline(std::cin, input);
    std::cout << std::endl;

    std::cout << "You entered " << input << std::endl;

    std::cout << "Enter something else ";
    // std::cin.get(ch);
    std::cin >> std::ws;
    std::getline(std::cin, input);
    std::cout << std::endl;
    std::cout << "You entered " << input << std::endl;

    double answer = std::pow(5, exp);
    std::cout << std::setprecision(3) << answer << " ";
    std::cout << std::setprecision(4) << answer << " ";
    std::cout << std::endl;

    return 0;
}