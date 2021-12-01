#include <stdio.h>
#define MAX_W 100
#define MAX_H 100
#define DIRECTIONS 4
#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

char dirs[] = {'N', 'S', 'E', 'W'};
char map[MAX_W * MAX_H];

char *pos[DIRECTIONS];
int counters[DIRECTIONS];

int destination_reached()
{
    int found = 0, i = 0;
    while (!found && i < DIRECTIONS)
    {
        found = *pos[i] == 'x';
        i++;
    }
    return found;
}

int best_dir()
{
    int found = -1, i;
    for (i = 0; i < DIRECTIONS; i++)
    {
        if (*pos[i] == 'x' && (found == -1 || counters[found] > counters[i] || dirs[found] > dirs[i]))
            found = i;
    }
    return found;
}
int stale()
{
    int stale = 1, i = 0;
    while (stale && i < DIRECTIONS)
    {
        stale = *pos[i] == '.' || *pos[i] == 'o';
        i++;
    }
    return stale;
}

int main()
{
    int r, s, i;
    char *o = NULL;
    scanf("%d %d", &r, &s);
    i = 0;
    while (i < r * s)
    {
        scanf(" %c", &map[i]);
        if (map[i] == 'o')
            o = map + i;
        i++;
    }

    //init directions
    pos[NORTH] = o - s;
    pos[SOUTH] = o + s;
    pos[EAST] = o + 1;
    pos[WEST] = o - 1;
    while (!destination_reached() && !stale())
    {
        int cell;
        for (cell = 0; cell < DIRECTIONS; cell++)
        {
            if (*pos[cell] == '>')
            {
                counters[cell]++;
                pos[cell]++;
            }
            else if (*pos[cell] == '<')
            {
                counters[cell]++;
                pos[cell]--;
            }
            else if (*pos[cell] == '^')
            {
                counters[cell]++;
                pos[cell] -= s;
            }
            else if (*pos[cell] == 'v')
            {
                counters[cell]++;
                pos[cell] += s;
            }
        }
    }
    if (stale())
        printf(":(\n");
    else
        printf(":)\n%c\n", dirs[best_dir()]);
    return 0;
}