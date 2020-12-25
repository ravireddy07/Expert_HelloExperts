// https://www.helloexperts.com/question-view?q_id=24418875675

#include <bits/stdc++.h>
using namespace std;

void setZero(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = 0;
    return;
}

void inputArray(int ar[], int n)
{
    cout << "Enter 20 numbers to Alpha: ";
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    return;
}

void doubleArray(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
        b[i] = a[i] * 2;
    return;
}

void copyGamma(int stock[10][4], int g[])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (!i)
                stock[i][j] = g[j];
            else
            {
                //stock[i][j] = g[j] * 3;                // 3 times of gamma
                stock[i][j] = stock[i - 1][j - 1] * 3; // 3 times of previous row
            }
        }
    }
    return;
}

void copyAlphaBeta(int stock[10][4], int a[], int b[])
{
    int itr = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            stock[i][j] = a[itr];
            itr++;
        }
    }
    itr = 0;
    for (int i = 5; i < 10; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            stock[i][j] = b[itr];
            itr++;
        }
    }
    return;
}

void printArray(int ar[], int n)
{
    int itr = 0;
    for (int i = 0; i < n; i++, itr++)
    {
        if (itr % 15 == 0)
            cout << endl
                 << ar[i] << " ";
        else
            cout << ar[i] << " ";
    }
}

void setInStock(int stock[10][4], int d[])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (!j)
                cin >> stock[i][j];
            else
                stock[i][j] = (stock[i][j - 1] * 2) - d[j];
        }
    }
    return;
}

int main()
{
    int inStock[10][4];
    int alpha[20];
    int beta[20];
    int gamma[4] = {11, 13, 15, 17};
    int delta[10] = {3, 5, 2, 6, 10, 9, 7, 11, 1, 8};

    setZero(alpha, sizeof(alpha) / sizeof(alpha[0]));

    inputArray(alpha, sizeof(alpha) / sizeof(alpha[0]));

    doubleArray(alpha, beta, sizeof(beta) / sizeof(beta[0]));

    copyGamma(inStock, gamma);

    copyAlphaBeta(inStock, alpha, beta);

    printArray(alpha, sizeof(alpha) / sizeof(alpha[0]));

    setInStock(inStock, delta);

    return 0;
}
