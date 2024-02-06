#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <limits>
// lecture activity add an input validation loop to the number guessing game part of the code.
int main()
{
    std::cout << std::setprecision(3) << std::fixed << std::showpoint;
    srand(time(0));
    double cal = 0;
    double sum = 0;
    int count = 0;
    while (cal != -1)
    {
        count++;    // count = count + 1;
        sum += cal; // sum = sum + cal;
        std::cout << "Enter the calories for day #" << count << " or enter -1 to quit: ";
        std::cin >> cal;
        std::cout << std::endl;



        while (!std::cin || cal < 0)
        {
            if (!std::cin)
            {
                std::cin.clear(); // removes error condition from input stream
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "You entered something that is not a number! Please try again." << std::endl;
            }
            else if (cal == -1)
            {
                break;
            }
            std::cout << "The calories entered are invalid. Please enter a positive number or -1 to exit." << std::endl;
            std::cout << "Enter the calories for day #" << count << " or enter -1 to quit: ";
            std::cin >> cal;
            std::cout << std::endl;
        }
    }
    count--;
    std::cout << "The average calories burned per day is " << sum / count << std::endl;

    int magicNum = rand() % 100 + 1;
    int userNum;

    bool isGuessed = false;
    while (!isGuessed)
    {
        std::cout << "Guess a number between 1 and 100: ";
        std::cin >> userNum;

        if (!std::cin)
            {
                std::cin.clear(); // removes error condition from input stream
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "You entered something that is not a number! Please try again." << std::endl;
            }
            else if (userNum <= 0)
            {
                std::cout << "You have entered a number less than 1. Please try again." << std::endl;
                continue;
            }
            
        std::cout << std::endl;
        if (userNum == magicNum)
        {
            std::cout << "You have chosen wisely." << std::endl;
            isGuessed = true;
        }
        else if (userNum > magicNum)
        {
            std::cout << "You have chosen poorly. Your number is too high." << std::endl;
        }
        else
        {
            std::cout << "You have chosen poorly. Your number is too low." << std::endl;
        }
    }
    /*  int x;
     std::cout << "Enter a number: ";
     std::cin >> x;
     std::cout << std::endl; */

    /*  int i = 20;
     while (i < 20)
     {
         std::cout << i << " ";
         i = i + 5;
     }
     std::cout << std::endl; */

    /* i = x;
    if (i <= 20)
    {
        std::cout << i << " ";
        i = i + 5;
    }
    if (i <= 20)
    {
        std::cout << i << " ";
        i = i + 5;
    }
    if (i <= 20)
    {
        std::cout << i << " ";
        i = i + 5;
    }
    if (i <= 20)
    {
        std::cout << i << " ";
        i = i + 5;
    }
    if (i <= 20)
    {
        std::cout << i << " ";
        i = i + 5;
    }
    if (i <= 20)
    {
        std::cout << i << " ";
        i = i + 5;
    }
    if (i <= 20)
    {
        std::cout << i << " ";
        i = i + 5;
    }
    std::cout << std::endl; */
    return 0;
}