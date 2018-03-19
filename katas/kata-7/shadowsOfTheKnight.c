#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int W; // width of the building.
    int H; // height of the building.
    scanf("%d%d", &W, &H);
    int N; // maximum number of turns before game over.
    scanf("%d", &N);
    int X0;
    int Y0;
    scanf("%d%d", &X0, &Y0);
    int X = X0;
    int Y = Y0;
    char *direction;
    int leftLimit = 0, rightLimit = W + 1, downLimit = H + 1, upLimit = 0;

    // game loop
    while (1) {
        char bombDir[4]; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        scanf("%s", bombDir);
        
        direction = bombDir;
        while (*direction != '\0') {
            if (*direction == 'D') {
                upLimit = Y + 1;
                Y += (downLimit - Y) / 2;
            }
            else if (*direction == 'U') {
                downLimit = Y;
                Y -= (Y - upLimit) / 2 + 1;
            }
            else if (*direction == 'R') {
                leftLimit = X + 1;
                X += (rightLimit - X) / 2;
            }
            else if (*direction == 'L') {
                rightLimit = X;
                X -= (X - leftLimit) / 2 + 1;
            }
            direction++;
        }

        // the location of the next window Batman should jump to.
        printf("%d %d\n", X, Y);
    }

    return 0;
}
