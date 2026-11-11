#include <iomanip>
#include <iostream>

bool readMatrix(int** a, int rows, int cols);
void printMatrix(int** a, int rows, int cols);
int countRowsWithoutZero(int** a, int rows, int cols);
int occurrences(int** a, int rows, int cols, int value);
void findMaxRepeated(int** a, int rows, int cols,
    bool& found, int& maximum);

#ifndef UNIT_TEST
int main()
{
    int rows, cols;

    std::cout << "Enter rows and columns: ";

    if (!(std::cin >> rows >> cols) || rows <= 0 || cols <= 0)
    {
        std::cout << "Invalid matrix size.\n";
        return 1;
    }

    int** a = new int* [rows];

    for (int i = 0; i < rows; ++i)
        a[i] = new int[cols] {};

    std::cout << "Enter matrix elements:\n";

    if (!readMatrix(a, rows, cols))
    {
        std::cout << "Invalid matrix element.\n";

        for (int i = 0; i < rows; ++i)
            delete[] a[i];

        delete[] a;
        return 1;
    }

    std::cout << "Matrix:\n";
    printMatrix(a, rows, cols);

    int count = countRowsWithoutZero(a, rows, cols);

    std::cout << "Rows without zero elements: "
        << count << '\n';

    bool found = false;
    int maximum = 0;

    findMaxRepeated(a, rows, cols, found, maximum);

    if (found)
        std::cout << "Maximum repeated value: "
        << maximum << '\n';
    else
        std::cout << "No repeated values.\n";

    for (int i = 0; i < rows; ++i)
        delete[] a[i];

    delete[] a;

    return 0;
}
#endif

bool readMatrix(int** a, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (!(std::cin >> a[i][j]))
                return false;

    return true;
}

void printMatrix(int** a, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
            std::cout << std::setw(6) << a[i][j];

        std::cout << '\n';
    }
}

int countRowsWithoutZero(int** a, int rows, int cols)
{
    int count = 0;

    for (int i = 0; i < rows; ++i)
    {
        bool hasZero = false;

        for (int j = 0; j < cols; ++j)
        {
            if (a[i][j] == 0)
            {
                hasZero = true;
                break;
            }
        }

        if (!hasZero)
            ++count;
    }

    return count;
}

int occurrences(int** a, int rows, int cols, int value)
{
    int count = 0;

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (a[i][j] == value)
                ++count;

    return count;
}

void findMaxRepeated(int** a, int rows, int cols,
    bool& found, int& maximum)
{
    found = false;
    maximum = 0;

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
        {
            if (occurrences(a, rows, cols, a[i][j]) > 1)
            {
                if (!found || a[i][j] > maximum)
                {
                    maximum = a[i][j];
                    found = true;
                }
            }
        }
}