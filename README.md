# Alien vs. Zombie

Alien vs Zombie is a text based game which requires strategic thinking skills to win. The player will play as the alien, and they will have to plan a path on the game's board in order to defeat the zombie(s) and win the game.

YouTube link to the [Video Demo](https://youtu.be/6YP9L1vuIPg).

## Compilation Instructions

From the repository, click on the main.cpp source code and copy the raw content. Then, paste it into your VS Code and download the pf file into the same folder. Once everything has been transferred accordingly, open the folder containing the code on your command prompt and type in the following command:

```
g++ pf\*.cpp main.cpp -o main
```

Then, an .exe file will appear in the folder. To open the game on your command prompt, you can either click on the .exe file or put in the following command in your cmd.

```
.\main.exe
```

Once you've opened the main.exe file, you can start playing the Alien vs. Zombie game.

## User Manual

The goal of this game is to lead the Alien to defeat the Zombies by using the objects which are arrows, health kits and magical pods, randomly placed on the board.

Settings
1. The game will ask the player if they want to change the dimensions of the board and the number of zombies.
2. If the player chooses to type in 'y', the player can input the desire dimensions. The number of rows being the y-axis while the number of columns, the x-axis. The number must be odd to ensure the Alien character can spawn right in the middle of the board.
3. The player then must input the number of zombies.
3. Once the player is happy with the settings, type 'n' to keep the settings.
4. The program will proceed to the game board.
5. In the middle of the game, the player may save their progress by using the save command and typing in the desired file name along with the file type '.txt'
6. Player can load saved games by using the load command and typing in the saved file's name.

Game characters:
1. Alien 'A' - controlled by the player.
2. Zombie 'Z' - will move on its own during its turn.

Game objects:
1. Health pack 'h' - increases the Alien's life points by 20 HP.
2. Magical pod 'p' - inflicts damage towards the nearest zombie.
3. Arrow '<', '>', '^', 'v' - changes the Alien's direction and increases the Alien's attack points by 20.
4. Rock 'r' - blocks the Alien's path.

How to play:
1. Move the Alien on the center of the board by typing in 'left', 'right', 'up' or 'down' at the command space.
2. The Alien will keep moving in the direction input by the player and leave a trail behind its path.
3. If the Alien encounters a health pack, the Alien's health points will increase by 20 HP.
4. When a magical pod 'p' is found, the zombie nearest to the Alien will take damage by 20 HP.
5. To increase the Alien's life points, the player must direct the Alien towards the health pack 'h'. The health pack will provide 20 HP to the Alien.
6. If an arrow on the board is found, the Alien's attack points will increase by 20. The attack points will be accumulated throughout the game. Then, the Alien's direction will change to the direction of the arrow collected. For example, an arrow point left, '<', will force the Alien to turn left.
7. An arrow's direction can be changed according to the player. The command 'arrow' can be used to do this. The row and column of the desired arrow has to be inputted as well as the new direction.
8. If and after the player decides to change the direction of an arrow, it will still be the Alien's turn to move. So, changing an arrow's direction should be done before moving the Alien.
9. If the Alien hits a rock object symbolised by the letter 'r', or the board's border, the Alien's path will be blocked and its turn will end.
10. Once the Alien's turn ends, each zombie will take a turn and decide wether to move or to stay stationary.
11. If the Alien is in the attack range of a zombie, the zombie will attack the Alien.
12. After all zombies on the board have acted, it is once again the Alien's turn.
13. Move the alien towards a zombie, the alien will attack the zombie with its accumulated attack points.
14. If enough attack points is collected to defeat the zombie, the zombie will die.
14. The game ends if all zombies are killed or the Alien is killed.

## Progress Log

- [Part 1](PART1.md)
- [Part 2](PART2.md)

## Contributors

- Farah Kamila binti Yahya
- Sherene Juanita A/P John Benedict
- Hasya Maisarah binti Hazizi


