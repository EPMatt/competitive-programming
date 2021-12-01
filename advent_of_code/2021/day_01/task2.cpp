#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>

#define BUF 4

using namespace std;

int main()
{
    /* 
    solution: compare only the first number of the first triad and the last number of the second triad 
    no need to perform sums :)
    */
    int depths[BUF], depth, count = 0;

    /* preload */
    int j = 0;
    while (!cin.eof() && j < 3)
        cin >> depths[j++];
    /* solve */
    int i = 3;
    while (!cin.eof())
    {
        cin >> depths[i];
        if (depths[i] > depths[(i + (BUF-3)) % BUF])
            count++;
        i = (i + 1) % BUF;
    }
    cout << count << endl;
    return 0;
}