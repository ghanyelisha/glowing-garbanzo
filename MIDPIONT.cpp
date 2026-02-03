#include <stdio.h>

// Plot the 8 symmetric points of the circle
void plotCirclePoints(int xc, int yc, int x, int y)
{
    printf("(%d, %d)\n", xc + x, yc + y);
    printf("(%d, %d)\n", xc - x, yc + y);
    printf("(%d, %d)\n", xc + x, yc - y);
    printf("(%d, %d)\n", xc - x, yc - y);

    printf("(%d, %d)\n", xc + y, yc + x);
    printf("(%d, %d)\n", xc - y, yc + x);
    printf("(%d, %d)\n", xc + y, yc - x);
    printf("(%d, %d)\n", xc - y, yc - x);
}

// Midpoint Circle Drawing Algorithm
void midpointCircle(int xc, int yc, int r)
{
    int x = 0;
    int y = r;
    int p = 1 - r;   // initial decision parameter

    // Plot initial points
    plotCirclePoints(xc, yc, x, y);

    while (x < y)
    {
        x++;

        if (p < 0)
        {
            p = p + 2 * x + 1;
        }
        else
        {
            y--;
            p = p + 2 * x + 1 - 2 * y;
        }

        plotCirclePoints(xc, yc, x, y);
    }
}

int main()
{
    int xc, yc, r;

    printf("Enter center (xc yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter radius r: ");
    scanf("%d", &r);

    printf("\nCircle points using Midpoint Circle Algorithm:\n");
    midpointCircle(xc, yc, r);

    return 0;
}

