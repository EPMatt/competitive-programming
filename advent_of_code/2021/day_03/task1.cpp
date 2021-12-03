#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>

#define DIAG_LEN 12
using namespace std;

int main()
{
    int gamma = 0, epsilon = 0, count = 0;
    int diagSums[DIAG_LEN];
    char t;
    for (int i = 0; i < DIAG_LEN; i++)
        diagSums[i] = 0;
    while (!cin.eof())
    {
        for (int i = 0; i < DIAG_LEN; i++)
        {
            cin >> t;
            diagSums[i] += t - '0';
        }
        count++;
    }
    for (int i = 0; i < DIAG_LEN; i++)
    {
        if (diagSums[i] > count / 2)
            /* 1 is most common bit */
            gamma |= 1 << (DIAG_LEN - 1 - i);
        else
            /* 0 is most common bit */
            epsilon |= 1 << (DIAG_LEN - 1 - i);
    }
    cout << gamma * epsilon << endl;
    return 0;
}