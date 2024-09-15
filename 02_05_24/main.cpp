#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <fstream>

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
                // clear and ignore are only used when we have input failure
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
    for (double i = 0; i < 7; i = i + 0.001)
        ; // warning this is a semantic error
    {
        std::cout << "*" << std::endl;
    }
    count--;
    std::cout << "The average calories burned per day is " << sum / count << std::endl;

    int magicNum = rand() % 100 + 1;
    int userNum;

    bool isGuessed = false;
    do
    {
        std::cout << "Guess a number between 1 and 100: ";
        std::cin >> userNum;
        std::cout << std::endl;
        // this is wrong you have to do the right validation for the lecture activity
        while (!std::cin)
        {
            std::cin.clear(); // removes error condition from input stream
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "You entered something that is not a number! Please try again." << std::endl;
            std::cout << "Guess a number between 1 and 100: ";
            std::cin >> userNum;
            std::cout << std::endl;
        }
        while (userNum < 1 || userNum > 100)
        {

            std::cout << "The number entered is invalid. Please try again." << std::endl;
            std::cout << "Guess a number between 1 and 100: ";
            std::cin >> userNum;
            std::cout << std::endl;
        }
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
    } while (!isGuessed);

    // read until the end of the file
    std::ifstream order;
    order.open("order.txt");
    char product;
    int quantity;
    std::cout << std::left;
    std::cout << "+-" << std::setw(33) << std::setfill('-') << "-"
              << "+" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << "| " << std::setw(15) << "Product"
              << " | " << std::setw(15) << "Quantity"
              << "|" << std::endl;
    std::cout << "+-" << std::setw(33) << std::setfill('-') << "-"
              << "+" << std::endl;
    while (!order.eof())
    {
        order >> product >> quantity;

        if (!order)
        {
            continue;
        }
        // order processing
        std::cout << std::setfill(' ');
        std::cout << "| " << std::setw(15) << product
                  << " | " << std::setw(15) << quantity
                  << "|" << std::endl;
        std::cout << "+-" << std::setw(33) << std::setfill('-') << "-"
                  << "+" << std::endl;
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