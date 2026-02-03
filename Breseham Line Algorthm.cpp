#include <stdio.h>
#include <stdlib.h>   // abs
#include <math.h>     // round

#define GRID_SIZE 30

// 1) Initialize grid with '.'
void initGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '.';
        }
    }
}

// 2) Plot function: plots a single point on grid using bottom-left origin idea
void plotPoint(char grid[GRID_SIZE][GRID_SIZE], int x, int y, char mark) {
    int gridY = GRID_SIZE - 1 - y;  // convert Cartesian y (bottom-left) to array row index
    int gridX = x;

    if (gridX >= 0 && gridX < GRID_SIZE && gridY >= 0 && gridY < GRID_SIZE) {
        grid[gridY][gridX] = mark;
    }
}

// 3) Display grid
void printGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    printf("\nGrid (Bottom-Left Origin):\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

// 4) DDA Line Drawing Function
void drawLineDDA(char grid[GRID_SIZE][GRID_SIZE], int x1, int y1, int x2, int y2, char mark) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xInc = (float)dx / steps;
    float yInc = (float)dy / steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        plotPoint(grid, (int)round(x), (int)round(y), mark);
        x += xInc;
        y += yInc;
    }
}

// 5) Bresenham Line Drawing Function (works for ALL slopes)
void drawLineBresenham(char grid[GRID_SIZE][GRID_SIZE], int x1, int y1, int x2, int y2, char mark) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;  // decision parameter

    while (1) {
        plotPoint(grid, x1, y1, mark);

        if (x1 == x2 && y1 == y2) break;

        int e2 = 2 * err;

        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

int main() {
    char grid[GRID_SIZE][GRID_SIZE];
    initGrid(grid);

    int px_Start = 6, py_Start = 6;
    int px_End   = 8, py_End   = 18;

    // Example usage:
    // DDA line plotted with 'D'
    drawLineDDA(grid, px_Start, py_Start, px_End, py_End, 'D');
    printGrid(grid);

    // Bresenham line plotted with 'B'
    drawLineBresenham(grid, px_Start, py_Start, px_End, py_End, 'B');

    // Print result
    printGrid(grid);

    return 0;
}

