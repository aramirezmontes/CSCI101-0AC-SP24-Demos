#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <cctype>

const std::string UNIT_PROMPT = "Enter the byte units (B for bytes, K for KB, M for MB, G for GB, T for TB, P for PB, or E for EB): ";

int getIntGreaterThan0(std::string prompt);
long calculateRawBytes(int memSize, char byteUnit);
int secret(int x);
char getCharacter(std::string prompt);
bool isValidByteUnit(char byteUnit);

int main()
{
    int memSize;
    memSize = getIntGreaterThan0("Enter the memory size: ");
    char unit = getCharacter(UNIT_PROMPT);
    while (!isValidByteUnit(unit))
    {
        std::cout << "The byte unit entered is invalid." << std::endl;
        unit = getCharacter(UNIT_PROMPT);
    }

    long rawmem = calculateRawBytes(memSize, unit);
    int y = secret(2);
    y = secret(7);

    std::cout << "The minimum MAR size is " << ceil(log2(rawmem)) << std::endl;

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

long calculateRawBytes(int memSize, char byteUnit)
{
    int exponent;

    switch (byteUnit)
    {
    case 'k':
    case 'K':
        exponent = 10;
        break;
    case 'm':
    case 'M':
        exponent = 20;
        break;
    case 'g':
    case 'G':
        exponent = 30;
        break;
    case 't':
    case 'T':
        exponent = 40;
        break;
    case 'p':
    case 'P':
        exponent = 50;
        break;
    case 'e':
    case 'E':
        exponent = 60;
        break;
    default:
        exponent = 0;
    }

    return memSize * pow(2, exponent);
}

int secret(int x)
{
    if (x > 5)
        return 2 * x;
    return x;
}

char getCharacter(std::string prompt)
{
    char x;
    std::cout << prompt;
    std::cin >> x;
    std::cout << std::endl;
    return x;
}

bool isValidByteUnit(char byteUnit)
{
    bool valid;
    byteUnit = toupper(byteUnit);
    valid = byteUnit == 'K' || byteUnit == 'M' || byteUnit == 'G' || byteUnit == 'T' ||
            byteUnit == 'P' || byteUnit == 'E' || byteUnit == 'B';
    return valid;
}