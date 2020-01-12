#include <bits/stdc++.h>
using namespace std;
int sum = 0;

int withoutLoop(int n, int i)
{
    if (i <= n)
    {
        sum += i;
        withoutLoop(n, i + 1);
    }
    else
    {
        return sum;
    }
}

void method2()
{
    int n, i = 1, sum = 0;
    cout << endl
         << "Enter a number: ";
    cin >> n;

repeating:
    if (i <= n)
    {
        sum += i;
        i++;
        goto repeating;
    }
    else
    {
        cout << endl
             << "The sum of the numbers between 1 and " << n << " is: " << sum;
    }
    return;
}

int main()
{
    int n, i = 1, sum = 0;
    cout << "Enter a number: ";
    cin >> n;
    //method-1
    cout << endl
         << "The sum of the numbers between 1 and " << n << " is: " << withoutLoop(n, i);
    //method-2
    method2();
}