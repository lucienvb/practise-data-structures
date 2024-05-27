#include <stdio.h>
#include <stdlib.h>

// Flood fill functie om het eiland uit te breiden en de grootte te tellen
void floodFill(int** grid, int row, int col, int rows, int cols, int* currentSize) {
    // Basisvoorwaarden voor terugkeer
    if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] == 0) {
        return;
    }

    // Markeer de huidige cel als bezocht
    grid[row][col] = 0;
    (*currentSize)++;

    // Recursief roep flood fill aan voor de vier omliggende cellen (boven, onder, links, rechts)
    floodFill(grid, row - 1, col, rows, cols, currentSize);
    floodFill(grid, row + 1, col, rows, cols, currentSize);
    floodFill(grid, row, col - 1, rows, cols, currentSize);
    floodFill(grid, row, col + 1, rows, cols, currentSize);
}

// Functie om het grootste eiland te vinden
int findLargestIsland(int** grid, int rows, int cols) {
    int maxSize = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                int currentSize = 0;
                floodFill(grid, i, j, rows, cols, &currentSize);
                if (currentSize > maxSize) {
                    maxSize = currentSize;
                }
            }
        }
    }

    return maxSize;
}

// Hulpfunctie om een 2D-array te printen
void printGrid(int** grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Hulpfunctie om een 2D-array dynamisch toe te wijzen
int** createGrid(int rows, int cols) {
    int** grid = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        grid[i] = (int*)malloc(cols * sizeof(int));
    }
    return grid;
}

// Hulpfunctie om het grid vrij te geven
void freeGrid(int** grid, int rows) {
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
}

// Voorbeeldgebruik
int main() {
    int rows = 5;
    int cols = 5;
    int** grid = createGrid(rows, cols);

    int sampleGrid[5][5] = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 1, 1},
        {0, 1, 0, 0, 0},
        {1, 1, 1, 1, 0}
    };

    // Kopieer het voorbeeldgrid naar de dynamisch toegewezen grid
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = sampleGrid[i][j];
        }
    }

    printf("Input Grid:\n");
    printGrid(grid, rows, cols);

    int largestIslandSize = findLargestIsland(grid, rows, cols);
    printf("\nSize of the largest island: %d\n", largestIslandSize);

    freeGrid(grid, rows);
    return 0;
}
