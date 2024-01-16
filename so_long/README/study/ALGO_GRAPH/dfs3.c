#include <stdio.h>

#define ROWS 7
#define COLS 7

// Function to perform Depth-First Search (DFS)
int dfs(char map[][COLS], int x, int y, int visited[][COLS]) {
    // Mark the current position as visited
    visited[x][y] = 1;

    // Check if the current position is the endpoint
    if (map[x][y] == 'E') {
        return 1; // Endpoint found, map is valid
    }

    // Define the possible moves (up, down, left, right)
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // Explore all possible moves
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        // Check if the new position is within bounds and not a blocked tile (1)
        if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS && map[newX][newY] != '1' && !visited[newX][newY]) {
            // Recursively call DFS on the new position
            if (dfs(map, newX, newY, visited)) {
                return 1; // Endpoint found, map is valid
            }
        }
    }
    return 0; // Endpoint not found
}

// Function to check if the map is valid
int isMapValid(char map[][COLS]) {
    int startX = -1, startY = -1;

    // Find the starting point (P)
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (map[i][j] == 'P') {
                startX = i;
                startY = j;
                break;
            }
        }
    }

    // Check if the starting point is valid
    if (startX == -1 || startY == -1) {
        return 0; // Invalid map
    }

    // Create a visited matrix to keep track of visited positions during DFS
    int visited[ROWS][COLS] = {0};

    // Perform DFS from the starting point
    if (dfs(map, startX, startY, visited)) {
        return 1; // Map is valid
    } else {
        return 0; // Map is invalid
    }
}

int main() {
    // Define the map
    char map[][COLS] = {
        "1111111",
        "1C00001",
        "11P0001",
        "101C1C1",
        "1101101",
        "10000E1",
        "1111111"
    };

    // Check if the map is valid
    if (isMapValid(map)) {
        printf("The map is valid.\n");
    } else {
        printf("The map is invalid.\n");
    }

    return 0;
}