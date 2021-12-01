#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;

int main()
{
    int depth, prevDepth, count = 0;
    cin >> prevDepth;
    while (!cin.eof())
    {
        cin >> depth;
        if (depth > prevDepth)
            count++;
        prevDepth = depth;
    }
    cout << count << endl;
    return 0;
}