#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int** map;

typedef struct _RobotInfo
{
    unsigned int cleanCount;
    unsigned int r;
    unsigned int c;
    unsigned int d;
    bool isActive;

} RobotInfo;
RobotInfo r1 = { .cleanCount = 0, .r = 0, .c = 0, .d = 0, .isActive = true };

int check_state();
int check_back();

int main()
{
       int n, m;

    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &r1.r, &r1.c, &r1.d);


    map = malloc(sizeof(int*) * n);


    for (int i = 0; i < n; i++)
    {
        map[i] = malloc(sizeof(int) * m);

    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }


    int command = 1;

    while (r1.isActive != false)
    {
        switch (command)
        {
        case 1:
            r1.cleanCount++;
            map[r1.r][r1.c] = 2;
            command = 2;
            break;
        case 2:

            for (int i = 0; i < 4; i++)
            {
                if (check_state())
                {
                    command = 1;
                    break;
                }

                if (i == 3)
                {
                    if (check_back())
                    {
                        command = 2;
                        break;
                    }
                    else
                    {
                        r1.isActive = false;
                    }
                }

            }
            break;
        }
    }

    printf("%d\n", r1.cleanCount);

    return 0;
}

int check_back() {
    int r = r1.r, c = r1.c;

    switch (r1.d)
    {
    case 0:
        r++; break;
    case 1:
        c--; break;
    case 2:
        r--; break;
    case 3:
        c++; break;
    }

    if (map[r][c] != 1)
    {
        r1.r = r;
        r1.c = c;
        return 1;
    }
    return 0;

}


int check_state()
{
    int r = r1.r,c = r1.c;

    switch (r1.d)
    {
    case 0:
        c--; break;
    case 1:
        r--; break;
    case 2:
        c++; break;
    case 3:
        r++; break;
    }
    if (r1.d == 0)
        r1.d = 3;
    else
        r1.d -= 1;

    if (map[r][c] == 0)
    {
        r1.r = r;
        r1.c = c;
        return 1;
    }
    return 0;

}