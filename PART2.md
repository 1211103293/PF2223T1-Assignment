# Part 2

## Video Demo

YouTube link to your [Video Demo](https://youtu.be/6YP9L1vuIPg).

## Minimum Requirements

### Completed

List all the features completed.

1. Default game settings
2. Customizable game settings
3. Dynamic game board
4. 2D array map with (x, y) coordinates
5. Alien and zombie character attributes
6. Alien movement on the board (map)
7. Zombie movement and attacks by range
8. Interactable game objects on the map (rock, health kit, pod)
9. Help menu display
10. Commands for game controls (alien movement)
11. Executable game commands (alien will move according to user input)
12. Save and load game file

## To Do

1. Making random objects appear under the rock
2. Changing the zombies symbol on the board from 'Z' to digit values

## Additional Features

> There are no additional features

## Contributions

List down the contribution of each group members.

For example:

### FARAH KAMILA

1. Display default game settings
2. Customizable game settings
3. Correspond the game board with the settings
4. Zombie's movement on the map
5. Zombie range attack
6. Find zombie location on the board and zombie condition
7. Save and load file

### SHERENE JUANITA

1. Generate game board
2. Set up global variables, 2D array map, and basic character movement & attributes
3. Initialise alien's position at centre of the game board
4. Game logic (if game is still in play or not and game loop)
5. Alien movement condition on the board
6. Game objects effect on alien and zombie

### HASYA MAISARAH

1. Help menu display
2. Get user command
3. Implement commands for game controls
4. Randomise items on the game board
5. Randomise objects after alien trail
6. Initial alien and zombie status display (life point, attack point and range)

## Problems Encountered & Solutions

1. Settings: The customizable settings would accept even numbers for the board rows and columns.
Solution: Created a function to call back and check on the input to ensure the remainder of the number when divided by 2 does not equal to zero.

2. Settings and game board: The game board did not change according to the customised settings.
Solution: Pass by refrence the parameters in displayMainMenu so that the parameters correspond with what had been input.

3. Game board: Borders would not align with the lines and coordinates did not show on the game board.
Solution: Included code in the displayMap function to output borders using setw() function to align the rows and lines and added an ouput that would correctly show the game board coordinates.

4. Update alien trail: The trail would not change to random objects.
Solution: Added a function to randomise the objects according to the trail left behind using rand()% function and object array.

5. Alien attack zombie: Alien would not attack nearest zombie only.
Solution: Added the distanceFormula function to calculate the zombie with the closest distance to the alien on the board and attack the zombie as in the zombie array.

6. Zombie condition: The zombie condition would not update after alien attack.
Solution: According to the zombieArray in the zombieIndex (to know each zombie on the board), added the update in the function. Still a bit buggy.

7. Alien and zombie movement: Couldn't figure out how to get the zombie and alien to move.
Solution: Added boolean functions with the movemet conditions.

8. Alien and zombie stats: The stats would not update according to the damage inflicted.
Solution: Added new variable to replace the old variables and values, but still buggy.

9. Zombie attack range: Didn't know how to check if alien was in the zombie range.
Solution: Added a zombieRangeAttack function that checks if the alien's position on the board is within the range of the zombie's randomly allocated range attack value.

10. Game logic: Was not sure how to check if the game was still in play or not.
Solution: Added a boolean variable and a while loop in the main function.

11. Save and load file: Didn't know how to use pointers to store the game file's data.
Solution: No solution. Used a different function to store the data of the game file, which requires us to include <bits/stdc++.h>, in order to use ofstream file() and ifstream file().

12. Game over condition: Didn't know how/when to end the game.
Solution: Added a function to check if the alien has died (checkAlienDied) which would see if the alien life is at zero, which makes the boolean value for isInGame false, thus the game would be over.