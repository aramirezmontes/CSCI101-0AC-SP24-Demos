#include <iostream>
#include <iomanip>

int main()
{
    std::cout << std::setprecision(3) << std::fixed << std::showpoint;
    double cal;
    double sum = 0;
    int count = 0;
    while (count < 7)
    {
        std::cout << "Enter the calories for day #" << count + 1 << ": ";
        std::cin >> cal;
        sum += cal; // sum = sum + cal;

        count++; // count = count + 1;
    }
    std::cout << "The average calories burned per day is " << sum / count << std::endl;
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