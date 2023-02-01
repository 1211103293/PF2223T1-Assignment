# Part 1

## Video Demo

Link for the [Video Demo](https://youtu.be/Wc5gueZNTnw).

## Minimum Requirements

### Completed

List all the features completed.

1. Default settings
2. Customizable settings
3. Help menu display
4. Game board
5. Game character attributes
6. Zombie and alien basic movements

### To Do

List all the features not yet done. Remove this section if there is no incomplete requirements.

1. Game characters movement and attack
2. Option for multiple zombies
3. Interactable game objects
4. Executable game commands
5. Save and load game file
6. Additional features

## Additional Features

Describe the additional features that has been implemented.

> No additional features have been implemented yet.

## Contributions

### Farah Kamila

1. Default settings display
2. Customizable game settings

### Sherene Juanita

1. Randomly generated game board
2. Initial position of alien on the board
3. Zombie basic movements

### Hasya Maisarah

1. Help menu display for game controls

## Problems Encountered & Solutions

1. Settings: Making the customizable settings accept only odd numbers for the board rows and columns.
Solution: Created a function to callback and check on the input to ensure the remainder of the number when divided by 2 does not equal to zero.

2. Board game: Input q is supposed to exit the game but instead it made the zombies move.
Solution: Changed the ouput command to "Enter q to move the zombies arund." 