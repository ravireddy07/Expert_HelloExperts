#include <iostream>
#include <algorithm>
using namespace std;

void alMostSorted(int ar[], int n)
{
    int a, num1, num2;
    bool oneStep = true;
    string status;
    for (int i = 0; i < n - 1; i++)
    {
        if (ar[i] > ar[i + 1] && oneStep)
        {
            status = "swap";
            a = ar[i];
            ar[i] = ar[i + 1];
            ar[i + 1] = a;
            oneStep = false;
            num1 = ar[i];
            num2 = ar[i + 1];
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (ar[i] > ar[i + 1] && oneStep)
        {
            status = "reverse";
            //reverse(ar[i], ar[i + 1]);
            oneStep = false;
            num1 = ar[i];
            num2 = ar[i + 1];
        }
    }

    if (!oneStep)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    cout << status << " " << num1 << " " << num2;
}

int main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    alMostSorted(ar, n);
}