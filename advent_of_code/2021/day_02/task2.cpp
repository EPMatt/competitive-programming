#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    int depth = 0, pos = 0, aim = 0, t;
    string cmd;
    while (!cin.eof())
    {
        cin >> cmd >> t;
        if (cmd.compare("forward") == 0)
        {
            pos += t;
            depth -= aim * t;
        }
        else if (cmd.compare("up") == 0)
            aim += t;
        else if (cmd.compare("down") == 0)
            aim -= t;
    }
    cout << depth * pos << endl;
    return 0;
}