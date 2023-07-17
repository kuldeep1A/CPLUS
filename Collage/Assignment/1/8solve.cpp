#include <iostream>
using namespace std;

// Write a program to multiply two matrix A and B.

const int MAX_SIZE = 100;

void Multiplication(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], int rowsA, int colsB, int rowsB)
{
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < rowsB; k++)
            {
                C[i][j] += A[i][k] + B[k][j];
            }
        }
    }
}

void displayMatrix(int matrix[][MAX_SIZE], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int A[MAX_SIZE][MAX_SIZE];
    int B[MAX_SIZE][MAX_SIZE];
    int C[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;

    /*
    rowsA, colsA = 2, 2
    rowsB, colsB = 2, 2

    A: 1 1
       1 1

    B: 2 2
       2 2
    */

    cout << "Enter the number of rows and columns for matrix A: ";
    cin >> rowsA >> colsA;

    cout << "Enter the number of rows and columns for matrix B: ";
    cin >> rowsB >> colsB;

    if (colsA != rowsB)
    {
        cout << "Error: The number of columns in matrix A must be equal to  the number of rows in matrix B." << endl;
        return 0;
    }

    cout << "Enter the elements of matrix A: " << endl;
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsA; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter the elements of matrix B: " << endl;
    for (int i = 0; i < rowsB; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            cin >> B[i][j];
        }
    }

    Multiplication(A, B, C, rowsA, colsB, rowsB);

    cout << "Matrix C = A * B: " << endl;
    displayMatrix(C, rowsA, colsB);

    return 0;
}