#include <iostream>
#include <string>
#include <limits>

const int LIST_SIZE = 10;

void resetStream();

int main()
{
    int list[LIST_SIZE] = {5};
    for (int i = 0; i < LIST_SIZE; i++)
    {
        list[i] = -99;
    }

    for (int i = 0; i < LIST_SIZE; i++)
    {
        std::cout << "Enter number #" << i + 1 << ": ";
        std::cin >> list[i];
        std::cout << std::endl;
        while (!std::cin)
        {
            resetStream();
            std::cout << "Enter number #" << i + 1 << ": ";
            std::cin >> list[i];
            std::cout << std::endl;
        }
    }

    for (int i = 0; i < LIST_SIZE; i++)
    {
        std::cout << list[i] << std::endl;
    }

    double sum = 0;
    for (int i = 0; i < LIST_SIZE; i++)
    {
        sum += list[i]; // sum = sum + list[i];
    }
    std::cout << "The sum is " << sum << " and the average is " << sum / LIST_SIZE << std::endl;

    int largestPos = 0;
    for (int i = 1; i < LIST_SIZE; i++)
    {
        if (list[largestPos] < list[i])
        {
            largestPos = i;
        }
    }

    std::cout << "The largest element is " << list[largestPos] << " at position " << largestPos << std::endl;

    return 0;
}

void resetStream()
{
    std::cout << "You entered something that is not a number!" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}