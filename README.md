
# So Long

## Overview
So Long is a 2D tile-based graphical project part of the 42 School curriculum. The project focuses on creating a small 2D game using the MiniLibX graphics library or a similar library. The objective is to develop a complete game, including player movements, collecting items, and encountering enemies or obstacles.

## Game Description
- The game is a simple 2D collectible game.
- The player can move up, down, left, and right on a grid-based map.
- The goal is to collect all the items on the map and reach the exit.
- The game ends when the player reaches the exit after collecting all items or if the player encounters an enemy or obstacle.

## Features
- Tile-based rendering of the game world.
- Player movements and interactions.
- Collection of items and tracking of game progress.
- Implementation of enemies or obstacles.
- Simple collision detection.
- End-game conditions based on player actions.

## Usage

### Compilation
To compile the game, use:
```bash
gcc -Wall -Wextra -Werror *.c -o so_long -lmlx -framework OpenGL -framework AppKit
```

### Running the Game
To start the game, run:
```bash
./so_long map_file.ber
```
Replace `map_file.ber` with the path to your map configuration file.

## Map Configuration
The map configuration file (`*.ber`) specifies the layout of the game world, including walls, items, player start position, and exit.

## Controls
- Arrow keys to move the player.
- `ESC` to exit the game.

## Notes
- Attention to detail in the game design and user experience is important.
- The game should handle different scenarios gracefully, including invalid maps or unexpected player actions.

