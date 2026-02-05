#include<stdio.h>
#include<math.h>

#define GRID_SIZE 30

int main(){
	
	// Initialize 16x16 grid with 'x'
	char grid[GRID_SIZE][GRID_SIZE];
	int i, j;
	
	for(i = 0; i < GRID_SIZE; i++){
		for(j = 0; j < GRID_SIZE; j++){
			grid[i][j] = '.';
		}
	}
	
	int px_Start = 1;
	int py_Start = 2;
	int px_End = 13;
	int py_End = 23;
	
	int dx = abs(px_Start - px_End);
	int dy = abs(py_Start - py_End);
	
	int max;
	if (dx > dy){
		max = dx;
		max = dx;
	} else{
		max = dy;
	}
	
	float X = px_Start;
	float Y = py_Start;
	
	// Calculate increments for smooth line drawing
	float X_Inc = (dx == 0) ? 0 : (float)(px_End - px_Start) / max;
	float Y_Inc = (dy == 0) ? 0 : (float)(py_End - py_Start) / max;
	
	for(i = 0; i < max; i++){
		// Plot points on grid by changing '.' to 'o'
		// Y coordinate is inverted for bottom-left origin (screen coordinate)
		int gridY = GRID_SIZE - 1 - (int)round(Y);
		int gridX = (int)round(X);
		
		if(gridX >= 0 && gridX < GRID_SIZE && gridY >= 0 && gridY < GRID_SIZE){
			grid[gridY][gridX] = 'o';
		}
		X = X + X_Inc;
		Y = Y + Y_Inc;
	}
	
	// Display the grid (bottom-left origin)
	printf("\n16x16 Grid (Bottom-Left Origin):\n");
	for(i = GRID_SIZE - 1; i >= 0; i--){
		for(j = 0; j < GRID_SIZE; j++){
			printf("%c ", grid[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
