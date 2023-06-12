# So_Long
***Game Screenshot***

## Description
So_Long is a simple 2D game implemented using the minilibx library. The goal of the game is for the player to collect every collectible present on the map and then escape by choosing the shortest possible route. The game provides a top-down view and the player can move in four directions: up, down, left, and right using the W, A, S, and D keys. The player's movements are displayed in the shell, and collisions with walls are prevented.

## Installation
To compile and run the So_Long project, please follow these steps:

Clone the repository to your local machine:

```bash
git clone https://github.com/your-username/so_long.git
```
Change to the project directory:

```bash
cd so_long
```
Compile the project using the Makefile:

```bash
make
```
This will generate an executable named so_long.

## Run the game:

```bash
./so_long maps/map.ber
```
>Replace maps/map.ber with the path to your desired map file. Example map files can be found in the maps/ directory.

## Controls

- ***Use the W*** key or the Up arrow key to move the player character up.
- ***Use the S*** key or the Down arrow key to move the player character down.
- ***Use the A*** key or the Left arrow key to move the player character left.
- ***Use the D*** key or the Right arrow key to move the player character right.
- ***Press the ESC*** key to exit the game.

## Rules

- The player must collect every collectible present on the map before escaping.
- The player can only escape after collecting all collectibles.
- The player must choose the shortest possible route to escape.
- The player cannot move into walls.
- The number of movements is displayed in the shell.

## Dependencies
So_Long has the following dependencies:

- minilibx - A simple library for graphical programming, used to create the game's visual interface.
Please make sure to have the necessary dependencies installed before compiling and running the project.

## Resources
- [minilibx documentation](https://harm-smits.github.io/42docs/libs/minilibx)

## Contributing
Contributions to the So_Long project are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.

## License
This project is written by me, feel free to use it as a guide for your proyect!!

## Acknowledgements
The So_Long project is inspired by the 42 School curriculum.
The minilibx library was created by Olivier Crouzet and provided by the 42 School.
This project was developed by me.
