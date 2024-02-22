#include <iostream>
#include <string>
#include <limits>

const int LIST_SIZE = 10;
const int NUM_COLORS = 6;

enum colorType
{
    RED,
    BLUE,
    GREEN,
    PURPLE,
    ORANGE,
    YELLOW
};
const std::string colorNames[NUM_COLORS] = {"Red", "Blue", "Green", "Purple", "Orange", "Yellow"};
const colorType colors[NUM_COLORS] = {
    RED,
    BLUE,
    GREEN,
    PURPLE,
    ORANGE,
    YELLOW};

void resetStream();
void initialize(int list[], int listSize, int initialValue = 0);
void inputArray(int list[], int listSize, std::string prompt);
void outputArray(const int list[], int listSize);
void calculateSum(const int list[], int listSize, double &sum);
void findLargest(const int list[], int listSize, int &largestPos);
void printColorMenu();
// lecture activity rewrite the function below (from Monday) to reference the constant arrays
colorType inputColor();

int main()
{
    int list[LIST_SIZE] = {5};

    initialize(list, LIST_SIZE);
    inputArray(list, LIST_SIZE, "Enter a number: ");
    outputArray(list, LIST_SIZE);

    double sum = 0;
    calculateSum(list, LIST_SIZE, sum);

    std::cout << "The sum is " << sum << " and the average is " << sum / LIST_SIZE << std::endl;

    int largestPos = 0;
    findLargest(list, LIST_SIZE, largestPos);

    std::cout << "The largest element is " << list[largestPos] << " at position " << largestPos << std::endl;

    return 0;
}

void resetStream()
{
    std::cout << "You entered something that is not a number!" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void initialize(int list[], int listSize, int initialValue)
{
    for (int i = 0; i < listSize; i++)
    {
        list[i] = initialValue;
    }
}

void inputArray(int list[], int listSize, std::string prompt)
{
    for (int i = 0; i < listSize; i++)
    {
        std::cout << prompt;
        std::cin >> list[i];
        std::cout << std::endl;
        while (!std::cin)
        {
            resetStream();
            std::cout << prompt;
            std::cin >> list[i];
            std::cout << std::endl;
        }
    }
}

void outputArray(const int list[], int listSize)
{
    for (int i = 0; i < listSize; i++)
    {
        std::cout << list[i] << std::endl;
    }
}

void calculateSum(const int list[], int listSize, double &sum)
{
    sum = 0;
    for (int i = 0; i < listSize; i++)
    {
        sum += list[i]; // sum = sum + list[i];
    }
}

void findLargest(const int list[], int listSize, int &largestPos)
{
    largestPos = 0;
    for (int i = 1; i < listSize; i++)
    {
        if (list[largestPos] < list[i])
        {
            largestPos = i;
        }
    }
}

void printColorMenu()
{
    std::cout << "Please choose a color:" << std::endl;
    for (int i = 0; i < NUM_COLORS; i++)
    {
        std::cout << i + 1 << ". " << colorNames[i] << std::endl;
    }
}
