#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <algorithm>
#include <fstream>

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

void binaryNumConversion();
void search(const int list[], int listSize, int &foundPos, int searchItem);
void selectionSort(int list[], int listSize);
void twoDArray(double table[][10], int numRows, int numColumns);

int main()
{
    binaryNumConversion();
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
    int foundPos;
    search(list, LIST_SIZE, foundPos, 48);
    if (foundPos < 0)
    {
        std::cout << "Not found!" << std::endl;
    }

    selectionSort(list, LIST_SIZE);
    outputArray(list, LIST_SIZE);

    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;
    std::string filenameCpy = filename;
    std::transform(filenameCpy.begin(), filenameCpy.end(), filenameCpy.begin(), ::tolower);
    std::ifstream myFile;
    myFile.open(filenameCpy + ".txt");
    if (myFile.is_open())
    {
        std::cout << "I was able to open the file" << std::endl;
    }
    else
    {
        std::cout << "The file was not able to be opened" << std::endl;
    }
    double myTable[10][10];
    myTable[0][0] = -99.8;
    int row = 6;
    int col;
    for (col = 0; col < 10; col++)
    {
        myTable[row][col] = 100;
    }
    col = 4;
    for (row = 0; row < 10; row++)
    {
        myTable[row][col] = 200;
    }
    for (row = 0; row < 10; row++)
    {
        for (col = 0; col < 10; col++)
        {
            myTable[row][col] = -999;
        }
    }
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

void binaryNumConversion()
{

    int digits[1000];
    int numDigits = 0;
    std::string binaryNumber;
    std::cout << "Enter a binary number: ";
    std::cin >> binaryNumber;
    std::cout << std::endl;

    for (int i = 0; i < binaryNumber.length(); i++)
    {
        digits[i] = binaryNumber[i] - '0';
        if (digits[i] != 0 && digits[i] != 1)
        {
            std::cout << "There are non-binary digits in the input." << std::endl;
            return;
        }
        numDigits++;
    }
    int exponent = 0;
    int decimalNum = 0;
    for (int i = numDigits - 1; i >= 0; i--)
    {
        decimalNum += digits[i] * pow(2, exponent);
        exponent++;
    }
    std::cout << binaryNumber << " converted to decimal is " << decimalNum << std::endl;
}

void search(const int list[], int listSize, int &foundPos, int searchItem)
{
    foundPos = -1;
    for (int i = 0; i < listSize; i++)
    {
        if (list[i] == searchItem)
        {
            foundPos = i;
            break;
        }
    }
}

void selectionSort(int list[], int listSize)
{
    for (int unsorted = listSize - 1; unsorted > 0; unsorted--)
    {
        int largest;
        findLargest(list, unsorted + 1, largest);
        int temp = list[unsorted];
        list[unsorted] = list[largest];
        list[largest] = temp;
    }
}