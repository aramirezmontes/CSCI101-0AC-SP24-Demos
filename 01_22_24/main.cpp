#include <iostream>
#include <string>
#include <cmath>

int main()
{
    std::string input;
    int exp;

    std::cout << "Enter the exponent: ";
    std::cin >> exp;
    std::cout << std::endl;

    std::cout << "Enter something: ";
    // std::cin >> input; only gets one word up to a space
    std::getline(std::cin, input);
    std::cout << std::endl;

    std::cout << "You entered " << input << std::endl;

    double answer = std::pow(2, exp);

    char ch;
    // std::cin.get(ch);

    return 0;
}