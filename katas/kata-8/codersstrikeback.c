#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{

    int boost = 0;

    // game loop
    while (1) {
        int x;
        int y;
        int nextCheckpointX;
        int nextCheckpointY;
        int nextCheckpointDist;
        int nextCheckpointAngle;
        scanf("%d%d%d%d%d%d", &x, &y, &nextCheckpointX, &nextCheckpointY, &nextCheckpointDist, &nextCheckpointAngle);
        int opponentX;
        int opponentY;
        scanf("%d%d", &opponentX, &opponentY);

        int opponentDistance = sqrt((x - opponentX) * (x - opponentX) + (y - opponentY) * (y - opponentY));

        if (nextCheckpointAngle > 90 || nextCheckpointAngle < -90)
            thrust = 0;
        else if (boost = 0 && nextCheckpointDist > 5000 && opponentDistance < 900)
        {
            boost = 1;
            printf("%d %d BOOST\n", nextCheckpointX, nextCheckpointY);
            continue;
        }
        else
            thrust = 100;

        printf("%d %d %d\n", nextCheckpointX, nextCheckpointY, thrust);
    }

    return 0;
}
