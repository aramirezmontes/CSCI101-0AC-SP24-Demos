#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>

const double PROD_PRICE = 3.5;

int main()
{
    std::ifstream order;
    order.open("order.txt");
    std::cout << std::left;
    std::cout << "+-" << std::setw(33) << std::setfill('-') << "-"
              << "+" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << "| " << std::setw(15) << "Product"
              << " | " << std::setw(15) << "Quantity"
              << "|" << std::endl;
    std::cout << "+-" << std::setw(33) << std::setfill('-') << "-"
              << "+" << std::endl;
    char product;
    int quantity;
    int totalQuantity = 0;
    order >> product;
    order >> quantity;
    totalQuantity += quantity; // totalQuantity = totalQuantity + quantity;
    std::cout << std::setfill(' ');
    std::cout << "| " << std::setw(15) << product
              << " | " << std::setw(15) << quantity
              << "|" << std::endl;
    std::cout << "+-" << std::setw(33) << std::setfill('-') << "-"
              << "+" << std::endl;

    order >> product;
    order >> quantity;
    totalQuantity += quantity;

    std::cout << std::setfill(' ');
    std::cout << "| " << std::setw(15) << product
              << " | " << std::setw(15) << quantity
              << "|" << std::endl;
    std::cout << "+-" << std::setw(33) << std::setfill('-') << "-"
              << "+" << std::endl;

    order >> product;
    order >> quantity;
    totalQuantity += quantity;

    std::cout << std::setfill(' ');
    std::cout << "| " << std::setw(15) << product
              << " | " << std::setw(15) << quantity
              << "|" << std::endl;
    std::cout << "+-" << std::setw(33) << std::setfill('-') << "-"
              << "+" << std::endl;

    order >> product;
    order >> quantity;
    totalQuantity += quantity;

    std::cout << std::setfill(' ');
    std::cout << "| " << std::setw(15) << product
              << " | " << std::setw(15) << quantity
              << "|" << std::endl;
    std::cout << "+-" << std::setw(33) << std::setfill('-') << "-"
              << "+" << std::endl;

    std::ofstream outputFile;
    outputFile.open("orderOutput.txt");

    outputFile << std::setprecision(2) << std::fixed << std::showpoint;
    outputFile << "Total quantity = " << totalQuantity << std::endl;
    outputFile << "Average quantity = " << totalQuantity / 4.0 << std::endl;

    order.close();
    outputFile.close();

    /* std::string input;
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
    std::cout << std::endl; */

    return 0;
}