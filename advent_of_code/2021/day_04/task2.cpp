#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>
#include <stdio.h>
#define BOARD_SIZE 25
#define ROWS 5
#define COLS 5

using namespace std;

typedef array<int, BOARD_SIZE> board_t;
typedef array<bool, BOARD_SIZE> visited_t;

vector<board_t> boardsValues = vector<board_t>();
vector<visited_t> boardsVisited = vector<visited_t>();
vector<int> nums = vector<int>();

/* 
  print the board for debug
*/
void printBoard(board_t &b, visited_t &v)
{
    for (int i = 0; i < b.size(); i++)
        if (v[i])
            cout << b[i] << " ";
        else
            cout << ". ";
    cout << endl;
}

/*
  mark number in the provided board and return true if the board won
*/
bool markNum(board_t &b, visited_t &v, int num)
{
    int i = 0;
    bool found = false;
    while (i < BOARD_SIZE && !found)
    {
        found = b[i] == num;
        i++;
    }
    if (!found)
        return false;
    i--;

    v[i] = true;
    /* check row */
    bool win = true;
    for (int j = 0; j < COLS && win; j++)
        win = v[i / COLS * COLS + j];
    if (win)
        return true;
    /* check col */
    win = true;
    for (int j = 0; j < ROWS && win; j++)
        win = v[j * COLS + i % COLS];
    if (win)
        return true;
    return false;
}

/*
  retrieve the sum of all the non-visited cells in the board
*/
int boardSum(board_t &b, visited_t &v)
{
    int sum = 0;
    for (int i = 0; i < b.size(); i++)
        if (!v[i])
            sum += b[i];
    return sum;
}

int main()
{
    /* save nums */
    string buf;
    cin >> buf;

    /* save boards */
    while (!cin.eof())
    {
        array<int, BOARD_SIZE> tempBoardValues = array<int, BOARD_SIZE>();
        array<bool, BOARD_SIZE> tempBoardVisited = array<bool, BOARD_SIZE>();
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            cin >> tempBoardValues[i];
            tempBoardVisited[i] = false;
        }
        boardsValues.push_back(tempBoardValues);
        boardsVisited.push_back(tempBoardVisited);
    }

    /* process numbers */
    string delim = ",";
    int winner = -1;
    int end = buf.find(delim);
    int num = 0;
    int i = 0;
    while (winner == -1 && end != -1 && boardsValues.size() > 0)
    {
        /* get next number */
        num = stoi(buf.substr(0, end));
        buf = buf.substr(end + 1, buf.length());
        end = buf.find(delim);
        /* mark all cells and check for winner */
        for (int j = boardsValues.size() - 1; j >= 0 && winner == -1; j--)
        {
            if (markNum(boardsValues[j], boardsVisited[j], num))
            {
                winner = j;
                /* if not the last one, it means there are still not winning boards */
                if (boardsValues.size() > 1)
                {
                    /* remove the current winning board */
                    /* safe since we're processing boards from the end of the array */
                    boardsValues.erase(boardsValues.begin() + j);
                    boardsVisited.erase(boardsVisited.begin() + j);
                    /* still have to find the last winner, keep searching */
                    winner = -1;
                }
            }
        }
        i++;
    }
    cout << num * boardSum(boardsValues[winner], boardsVisited[winner]) << endl;
    return 0;
}