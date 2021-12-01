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

int pos[DIRECTIONS];
int counters[DIRECTIONS];

int destination_reached()
{
    int found = 0, i = 0;
    while (!found && i < DIRECTIONS)
    {
        found = map[pos[i]] == 'x';
        i++;
    }
    return found;
}

int best_dir()
{
    int found = -1, i;
    for (i = 0; i < DIRECTIONS; i++)
    {
        if (map[pos[i]] == 'x' && (found == -1 || counters[found] > counters[i] || dirs[found] > dirs[i]))
            found = i;
    }
    return found;
}
int stale()
{
    int stale = 1, i = 0;
    while (stale && i < DIRECTIONS)
    {
        stale = map[pos[i]] == '.' || map[pos[i]] == 'o';
        i++;
    }
    return stale;
}

int main()
{
    int r, s, i;
    int o = -1;
    scanf("%d %d", &r, &s);
    i = 0;
    while (i < r * s)
    {
        scanf(" %c", &map[i]);
        if (map[i] == 'o')
            o = i;
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
            switch (map[pos[cell]])
            {
            case '>':
                counters[cell]++;
                pos[cell]++;
                break;
            case '<':
                counters[cell]++;
                pos[cell]--;
                break;

            case '^':
                counters[cell]++;
                pos[cell] -= s;
                break;

            case 'v':
                counters[cell]++;
                pos[cell] += s;
                break;
            default:
                break;
            }
        }
    }
    if (stale())
        printf(":(\n");
    else
        printf(":)\n%c\n", dirs[best_dir()]);
    return 0;
}