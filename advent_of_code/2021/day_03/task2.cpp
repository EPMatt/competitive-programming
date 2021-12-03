#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <list>

#define DIAG_LEN 12
using namespace std;

list<long> o2Diags;
list<long> co2Diags;

/*
every diag item has the same length (i.e. 12 bits)
the following variables keep the sums of each "column" of the diag items
*/
int o2DiagSums[DIAG_LEN], co2DiagSums[DIAG_LEN];

/* remove the diag item from a diag sum, recomputing sums only for bits from the start index (0 = most significant bit) */
void removeItemFromDiag(int diagSums[], int start, int item)
{
    for (int j = start; j < DIAG_LEN; j++)
        diagSums[j] -= ((item >> (DIAG_LEN - j - 1)) & 1);
}

int main()
{
    char buf[DIAG_LEN];
    buf[DIAG_LEN] = 0;
    for (int i = 0; i < DIAG_LEN; i++)
    {
        o2DiagSums[i] = 0;
        co2DiagSums[i] = 0;
    }
    while (!cin.eof())
    {
        for (int i = 0; i < DIAG_LEN; i++)
        {
            cin >> buf[i];
            /* add the value for this bit to the respective column sum */
            o2DiagSums[i] += buf[i] - '0';
            co2DiagSums[i] = o2DiagSums[i];
        }
        /* store the diag item */
        o2Diags.push_back(strtol(buf, NULL, 2));
        co2Diags.push_back(strtol(buf, NULL, 2));
        cin.ignore(10, '\n');
    }
    int i = 0;

    /* process the list of diag items as described by bit criterias, iterating over each bit of diag items. */
    while (i < DIAG_LEN && (o2Diags.size() > 1 || co2Diags.size() > 1))
    {
        /* only if more candidates for the o2 generator rating are available */
        if (o2Diags.size() > 1)
        {
            if (o2DiagSums[i] >= o2Diags.size() / 2 + o2Diags.size() % 2)
            {
                /* 1 most common */
                o2Diags.remove_if([i](int val) -> bool
                                  {
                                      if (((val >> (DIAG_LEN - i - 1)) & 1) == 0)
                                      {
                                          /* update column sums for least significant bits */
                                          removeItemFromDiag(o2DiagSums, i + 1, val);
                                          return true;
                                      }
                                      return false;
                                  });
            }
            else
            {
                /* 0 most common */
                o2Diags.remove_if([i](int val) -> bool
                                  {
                                      if (((val >> (DIAG_LEN - i - 1)) & 1) == 1)
                                      {
                                          /* update column sums for least significant bits */
                                          removeItemFromDiag(o2DiagSums, i + 1, val);
                                          return true;
                                      }
                                      return false;
                                  });
            }
        }
        /* only if more candidates for the co2 scrubber rating are available */
        if (co2Diags.size() > 1)
        {
            if (co2DiagSums[i] <= co2Diags.size() / 2 - (1 - co2Diags.size() % 2))
            {
                /* 1 least common */
                co2Diags.remove_if([i](int val) -> bool
                                   {
                                       if (((val >> (DIAG_LEN - i - 1)) & 1) == 0)
                                       {
                                           /* update column sums for least significant bits */
                                           removeItemFromDiag(co2DiagSums, i + 1, val);
                                           return true;
                                       }
                                       return false;
                                   });
            }
            else
            {
                /* 0 least common */
                co2Diags.remove_if([i](int val) -> bool
                                   {
                                       if (((val >> (DIAG_LEN - i - 1)) & 1) == 1)
                                       {
                                           /* update column sums for least significant bits */
                                           removeItemFromDiag(co2DiagSums, i + 1, val);
                                           return true;
                                       }
                                       return false;
                                   });
            }
        }
        i++;
    }
    /* output the life support rating */
    cout << o2Diags.front() * co2Diags.front() << endl;
    return 0;
}