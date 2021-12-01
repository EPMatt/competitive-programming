#include <stdio.h>
#define MAX_C 100
#define MAX_R 200
#define OFFSET 100
char m[MAX_R][MAX_C];

int main()
{
    int n, i, v = 0, max = v, min = v, r, c;
    char t;
    for (r = 0; r < MAX_R; r++)
    {
        for (c = 0; c < MAX_C; c++)
        {
            m[r][c] = '.';
        }
    }
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf(" %c", &t);
        if (t == '+')
        {
            m[v + OFFSET][i] = '/';
            if (v > max)
                max = v;
            v++;
        }
        else if (t == '-')
        {
            v--;
            m[v + OFFSET][i] = '\\';
            if (v < min)
                min = v;
            if (i == 0)
                max = v;
        }
        else
        {
            m[v + OFFSET][i] = '_';
        }
    }

    if (n > 0)
    {
        for (r = max; r >= min; r--)
        {
            for (c = 0; c < n; c++)
            {
                printf("%c", m[r + OFFSET][c]);
            }
            if(max!= min) printf("\n");
        }
    }
    return 0;
}