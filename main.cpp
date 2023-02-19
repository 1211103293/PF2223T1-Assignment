// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: T12L 
// Names: FARAH KAMILA BINTI YAHYA | SHERENE JUANITA A/P JOHN BENEDICT | HASYA MAISARAH BINTI HAZIZI 
// IDs: 1211103293 | 1211101119 | 1221303619 
// Emails: 12111103293@student.mmu.edu.my | 1211101119@student.mmu.edu.my | 1221303619@student.mmu.edu.my 
// Phones: 011-23883345 | 010-4481086 | 016-5375951 
// ********************************************************* 

#include "pf/helper.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <bits/stdc++.h> // TO TRANSFORM INPUT
using namespace std;

// GET ODD NUMBERS ONLY
void oddNumbers(int &num)
{
    do
    {
        cin >> num;
        if (num % 2 != 0){
            break;
        }

        else{
            cout << "Please enter ODD numbers only! =>  ";
        }
    } while (num % 2 == 0);
    return;
}

// CHANGE SETTINGS
void changeSettings(int &row, int &col, int &zombie)
{
    cout << "    Board Settings    " << endl;
    cout << "----------------------" << endl;
    cout << "Please enter odd numbers only. " << endl;

    cout << "Enter number of board rows     =>  ";
    oddNumbers(row);
    cout << "Enter number of board columns  =>  ";
    oddNumbers(col);
    cout << endl;

    cout << "    Zombies Settings    " << endl;
    cout << "------------------------" << endl;
    cout << "Enter number of zombies        =>  ";
    cin >> zombie;
    cout << endl;
    cout << "Settings Updated." << endl;
    system("pause");
    system("cls");
}

// DISPLAY GAME SETTINGS
void displayMainMenu(int &row, int &col, int &zombie)
{
    char answer;
    cout << endl;
    cout << "    Game Settings    " << endl;
    cout << "---------------------" << endl;
    cout << "Number of Board Rows     =>  " << row << "        " << endl;
    cout << "Number of Board Columns  =>  " << col << "        " << endl;
    cout << "Number of Zombies        =>  " << zombie << "        " << endl;
    cout << endl;
    cout << "Do you want to change the settings? (y/n) => ";
    cin >> answer;
    cout << endl;
    answer = toupper(answer);
    if (answer == 'Y')
    {
        changeSettings(row, col, zombie);
        displayMainMenu(row, col, zombie);
    }
    else if (answer == 'N')
    {
        cout << "Proceed to Game Board" << endl;
        system("pause");
    }
    else
    {
        cout << "Input Error! Please choose either y (yes) or n (no)." << endl;
        cout << endl;
        displayMainMenu(row, col, zombie);
    }
    cout << endl;
}

/*
    {1,2,3,4,5,...}

    {
        {1,2,3,4,5,...}
        {1,2,3,4,5,...}
        {1,2,3,4,5,...}
        {1,2,3,4,5,...}
        {1,2,3,4,5,...}
    }

*/

char ALIEN= 'A';
char ZOMBIE= 'Z';
char ALIEN_TRAIL= '.';
char ZOMBIE_TRAIL= ' ';


struct gamechar {
    int life =0;
    int attack=0;
    int range=0;
    int row=-1;
    int col=-1;
    int newRow=-1;
    int newCol=-1;
    char icon=' ';
    char trail='.';
};


void setupMap (vector<vector<char>>& map, const int row, const int col){
    map.resize(row);
    for (int i=0; i<row; i++) {
        map[i].resize(col);
        for (int j=0; j<col; j++) {
                map[i][j] = '_';
        }
    }
    /*cout << " ";
    for (int j = 0; j < row; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
        cout << digit;
    }

    cout << endl;
    cout << " ";
    for (int j = 0; j < row; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl << endl;*/
}

// void displayMap (vector<vector<char>>& map){
//     for (int i=0; i<map.size(); i++) {
//         for (int j=0; j<map[0].size(); j++) {
//             cout << map[i][j];
//         }
//         cout<<endl;
//     }
// }


bool isInside (vector<vector<char>>& map, int row, int col){
    bool checkRow = row>=0 && row<map.size();
    bool checkCol = col>=0 && col<map[0].size();
    return checkRow && checkCol;
}

char getElement (vector<vector<char>>& map, int row, int col) {
    return map[row][col];
}

void setElement (vector<vector<char>>& map, int row, int col, char icon){
    map[row][col]=icon;
}

void randomiseLife(gamechar& character, int min, int max){
    character.life = rand()% max + min;
}

void randomiseAttack(gamechar& character, int min, int max){
    character.attack = rand()% max + min;
}

void randomiseRange(gamechar& character, int min, int max){
    character.range = rand()% max + min;
}

void randomisePosition(gamechar& character, vector<vector<char>>& map){
    int row= rand()% map.size();
    int col= rand()% map[0].size();
   
    while (getElement(map,row,col)== ALIEN || getElement(map,row,col) == ZOMBIE) {
        row= rand()% map.size();
        col= rand()% map[0].size();
    }

    character.row=row;
    character.col=col;
}

void moveChar(gamechar& character,  vector<vector<char>>& map,int movement){
    //0 -> up
    //1 -> right
    //2 -> down
    //3 -> left

    character.newRow=character.row;
    character.newCol=character.col;

    if(movement==0)
        character.newRow--;
    else if(movement==1)
        character.newCol++;
    else if(movement==2)
        character.newRow++;
    else if(movement==3)
        character.newCol--;
}

void setUpZombie(vector<gamechar>& zombieArray, int numOfZombie, vector<vector<char>>& map) {
    zombieArray.clear();
    for (int i=0; i<numOfZombie; i++) {
        gamechar zombie;
        zombie.icon = ZOMBIE;
        zombie.trail = ZOMBIE_TRAIL;
        randomiseLife(zombie, 10, 100);
        randomiseAttack(zombie, 10, 20);
        randomiseRange(zombie, 1, 4);
        randomisePosition(zombie, map);
        setElement(map,zombie.row, zombie.col, zombie.icon);
        zombieArray.push_back(zombie);
    }
}

void Help()
{
    //system("cls");
    cout <<"\nCommands" << endl;
    cout << "1. up    - Move up." << endl;
    cout << "2. down  - Move down." << endl;
    cout << "3. left  - Move left." << endl;
    cout << "4. right - Move right." << endl;
    cout << "5. arrow - Change the direction of an arrow." << endl;
    cout << "6. help  - Display these user commands." << endl;
    cout << "7. save  - Save the game." << endl;
    cout << "8. load  - Load a game." << endl;
    cout << "9. quit  - Quit the game." << endl;
}

/*void objectMovement(char arrow){
    
}

class objects {
    private:
    char rock;
    char pod;
    char health;
    char trail;

    public:
    void objectMovement();
};*/

// GLOBAL VARIABLE TO BE USED IN FUNCTION
const static int UP     = 0;
const static int RIGHT  = 1;
const static int DOWN   = 2;
const static int LEFT   = 3;
const static char LIFE  = 'h';
const static char POD   = 'p';
const static char ROCK  = 'r';
const static char A_UP      = '^';
const static char A_DOWN    = 'v';
const static char A_LEFT    = '<';
const static char A_RIGHT   = '>';
const static char EMPTY     = ' ';
const static char SEPARATOR     = ',';

// DISPLAY GAME BOARD
void displayMap (vector<vector<char>>& map){  // PARAMETER map FOR 2D ARRAY MAP
    cout <<"     .: Alien vs Zombie :.     " << endl;
    for (int i = 0; i < map.size(); i++)
    {
        // LINES
        cout << "  ";
        for (int j = 0; j < map[0].size(); j++)
        {
            cout << "+---";
        }
        cout << "+" << endl;

        // ROWS
        cout << setw(2) << i + 1;

        for (int j = 0; j < map[0].size(); j++)
        {
            cout << "| " << map[i][j] << " ";
        }
        cout << "|" << endl;
    }

    // INCREASE GAME BOARD LINES
    cout << "  ";
    for (int j = 0; j < map[0].size(); j++)
    {
        cout << "+---";
    }
    cout << "+" << endl;

    cout << " ";
    for (int j = 1; j < map[0].size() + 1; j++)
    {
        cout << setw(4) << j;
    }
    cout << " " << endl;
}

// GET USER COMMAND
void getCommand(string& command) {
        cout << "command > ";
        cin >> command;
}

// RANDOMISE ITEMS IN BOARD
void randomizeObject(vector<vector<char>>& map) {

    // PROBABILITY ITEM DROP IS numItemInArray/totalArraySize
    char object[] = {
        ' ', ' ', ' ', ' ', ' ',
        '^', '>', 'v', '^', 
        'h', 'p', 'r'
    };
    // REFER ABOVE ARRAY
    int numObject = 12;

    for (int i=0; i<map.size(); i++) {
        for (int j=0; j<map[0].size(); j++) {
            map[i][j] = object[rand()%numObject];
        }
    }
}

// RANDOMISE TRAIL INTO ITEM ON THE BOARD
void updateTrail(vector<vector<char>>& map) {

    // PROBABILITY ITEM DROP IS numItemInArray/totalArraySize
    char object[] = {
        ' ', ' ', ' ', ' ', ' ',
        '^', '>', 'v', '^', 
        'h', 'p', 'r'
    };
    // REFER ABOVE ARRAY
    int numObject = 12;

    for (int i=0; i<map.size(); i++) {
        for (int j=0; j<map[0].size(); j++) {
            if (map[i][j] == ALIEN_TRAIL)
                map[i][j] = object[rand()%numObject];
        }
    }
}

// FIND ZOMBIE IN THE SPECIFIED ROW & COL
int findZombie(vector<gamechar> zombieArray, int row, int col) {
    for (int i=0; i<zombieArray.size(); i++) {
        if (zombieArray.at(i).row == row && zombieArray.at(i).col == col)
            return i;
    }
    return 0;
}

// CALCULATE DISTANSE BETWEEN 2 POINTS
int distanceFormula(int row1, int col1, int row2, int col2) {
    return abs(row1 - row2) + abs(col1 - col2) + (row1 == row2) + (col1 == col2);
}

// GET THE NEAREST ZOMBIE
int findNearestZombie(vector<gamechar> zombieArray, int row, int col) {
    int currentZombie = 0;
    int currentDistance = distanceFormula(zombieArray.at(0).row, zombieArray.at(0).col, row, col);

    for (int i=1; i<zombieArray.size(); i++) {
        int newDistance = distanceFormula(zombieArray.at(i).row, zombieArray.at(i).col, row, col);
        if (newDistance < currentDistance) {
            currentZombie = i;
            currentDistance = newDistance;
        }
    }
    return currentZombie;
}

// DISPLAY IF ZOMBIE IS DEAD OR HURT
void checkZombieDied(vector<vector<char>>& map, vector<gamechar> zombieArray, int zombieIndex) {
    if (zombieArray.at(zombieIndex).life <= 0) {
        cout << "ZOMBIE " << zombieIndex << " DIED!" << endl;
        setElement(map, zombieArray.at(zombieIndex).row, zombieArray.at(zombieIndex).col, ZOMBIE_TRAIL);
    }
    else {
        cout << "Zombie Hurt! Zombie " << zombieIndex << ", Life Left: " << zombieArray.at(zombieIndex).life - 20 << endl;
    }
}

// CONDITION FOR GAME OVER
void checkAlienDied(vector<vector<char>>& map, gamechar& character, bool& isInGame) {
    if (character.life <= 0) {
        cout << "ALIEN DIED!" << endl;
        isInGame = false;
    }
    else {
        cout << "Alien Hurt! Life Left: " << character.life << endl;
    }
}

// CONDITION FOR ALIEN MOVEMENT
void moveAlien(gamechar& character,  vector<vector<char>>& map, int movement, vector<gamechar>& zombieArray) {
    moveChar(character, map, movement);
    bool isMoving = true;

    cout << "MOVING FROM " << character.col+1 << ", " << character.row+1 << " TO "    
        << character.newCol+1 << ", " << character.newRow+1 << " " << endl;

    while (isMoving)
    {
        if (isInside(map,character.newRow,character.newCol) && getElement(map,character.newRow,character.newCol) == ZOMBIE) {
            int zombieIndex = findZombie(zombieArray, character.newRow, character.newCol);
            cout << "Alien found a Zombie! Alien inflict " << character.attack << " to Zombie " << zombieIndex << endl;
            zombieArray.at(zombieIndex).life -= character.attack;
            checkZombieDied(map, zombieArray, zombieIndex);
            isMoving = false;
        }
        else if (isInside(map,character.newRow,character.newCol) && getElement(map,character.newRow,character.newCol) == LIFE) {
            cout << "Alien found a Health Kit! Alien life increase by 20"  << endl;
            character.life += 20;
            isMoving = true;
        }
        else if (isInside(map,character.newRow,character.newCol) && getElement(map,character.newRow,character.newCol) == POD) {
            cout << "Alien found a magical pod! Nearest Zombie has been attacked!"  << endl;

            int zombieIndex = findNearestZombie(zombieArray, character.newRow, character.newCol);
            cout << "Zombie " << zombieIndex << " Loses 20 Hp. ";
            checkZombieDied(map, zombieArray, zombieIndex);
            isMoving = true;
        }
        else if (isInside(map,character.newRow,character.newCol) && getElement(map,character.newRow,character.newCol) == ROCK) {
            cout << "Uh Oh! Alien found a rock! Cannot move from here..."  << endl;
            isMoving = false;
        }
        else if (isInside(map,character.newRow,character.newCol) && getElement(map,character.newRow,character.newCol) == A_UP) {
            isMoving = true;
            character.attack += 20;
            movement = UP;
            cout << "Alien found an arrow! Changing the direction to UP!" << endl;
        }
        else if (isInside(map,character.newRow,character.newCol) && getElement(map,character.newRow,character.newCol) == A_DOWN) {
            isMoving = true;
            character.attack += 20;
            movement = DOWN;
            cout << "Alien found an arrow! Changing the direction to DOWN!" << endl;
        }
        else if (isInside(map,character.newRow,character.newCol) && getElement(map,character.newRow,character.newCol) == A_LEFT) {
            isMoving = true;
            character.attack += 20;
            movement = LEFT;
            cout << "Alien found an arrow! Changing the direction to LEFT!" << endl;
        }
        else if (isInside(map,character.newRow,character.newCol) && getElement(map,character.newRow,character.newCol) == A_RIGHT) {
            isMoving = true;
            character.attack += 20;
            movement = RIGHT;
            cout << "Alien found an arrow! Changing the direction to RIGHT!" << endl;
        }
        else if (isInside(map,character.newRow,character.newCol) && (getElement(map,character.newRow,character.newCol) == EMPTY || getElement(map,character.newRow,character.newCol) == ALIEN_TRAIL) ) {
            isMoving = true;
            cout << "Alien advances!" << endl;
        }
        else {
            cout << "Alien Hit a Border! Alien's turn ended!" << endl;
            isMoving = false;
        }

        // GRAPHICALLY MOVE THE CHARACTER
        if(isInside(map,character.newRow,character.newCol) && isMoving) {
            setElement(map, character.row, character.col, character.trail);
            character.row=character.newRow;
            character.col=character.newCol;
            setElement(map, character.row, character.col, character.icon);
        }

        system("pause");
        system("cls");
        displayMap(map);
        moveChar(character, map, movement);
    }
}

// CONDITION FOR ZOMBIE MOVEMENT
void moveZombie(gamechar& character,  vector<vector<char>>& map, int movement, gamechar& alien, bool& isInGame) {
    moveChar(character, map, movement);
    // if(isInside(map,character.newRow,character.newCol) && getElement(map,character.newRow,character.newCol) == ALIEN) {
    //     cout << "Zombie decide to move to melee attack Alien" << endl;
    //     alien.life -= 20;
    //     checkAlienDied(map, alien, isInGame);
    // }
    // else 
    if(
        isInside(map,character.newRow,character.newCol) 
        && getElement(map,character.newRow,character.newCol) != ROCK 
        && getElement(map,character.newRow,character.newCol) != ALIEN
        && getElement(map,character.newRow,character.newCol) != ZOMBIE
    ) {
        // BOARD START WITH 1
        cout << "Zombie decide to move to (" << character.newCol+1 << ", " << character.newRow+1 << ")" << endl;
        setElement(map, character.row, character.col, character.trail);
        character.row=character.newRow;
        character.col=character.newCol;
        setElement(map, character.row, character.col, character.icon);
    }
    else {
        cout << "Zombie decide to stay stationary" << endl;
    }
    system("pause");
    system("cls");
    displayMap(map);
}

// ZOMBIE ATTACK CONDITION BY CHECKING RANGE
void zombieRangeAttack(gamechar& character,  vector<vector<char>>& map, gamechar& alien, bool& isInGame) {
    if (
        character.row == alien.row && alien.row-character.row<character.range ||
        character.col == alien.col && alien.col-character.col<character.range
    ) {
        cout << "Zombie decide to range attack Alien" << endl;
        alien.life -= 20;
        checkAlienDied(map, alien, isInGame);
    }
}

// DISPLAY ALIEN STATS
void displayAlienStats(gamechar& character) {
    cout << "\t< Alien Status >" << endl
         << "\t  Life Point: " << character.life << endl
         << "\t  Attack Point: " << character.attack << endl;
    cout << endl;
}

// DISPLAY ZOMBIE STATS
void displayZombieStats(gamechar& character, int zombieIndex) {
    cout << "\t< Zombie "<< zombieIndex << " Status >" << endl
         << "\t  Life Point: " << character.life << endl
         << "\t  Attack Point: " << character.attack << endl
         << "\t  Range Point: " << character.range << endl;
    cout << endl;
}

// CHECK IF ZOMBIE IS WINNING OR NOT
bool checkWinCondition(vector<gamechar>& zombieArray) {
    for (int i=0; i<zombieArray.size(); i++) 
        if (zombieArray.at(i).life > 0)
            return false;
    return true;
}

// SAVE GAME STATE IN A FILE
void saveGame(string filename, vector<vector<char>>& map, vector<gamechar>& zombieArray, gamechar& alien) {
    ofstream file(filename);
    file << map.size() << SEPARATOR
         << map[0].size() << SEPARATOR;

    for(int i=0; i<map.size(); i++) {
        for (int j=0; j<map[0].size(); j++) {
            file << map[i][j] << SEPARATOR;
        }
    }

    file << alien.life << SEPARATOR
         << alien.attack << SEPARATOR
         << alien.row << SEPARATOR
         << alien.col << SEPARATOR;

    file << zombieArray.size() << SEPARATOR;
    for (int i=0; i<zombieArray.size(); i++) {
        file << zombieArray.at(i).life << SEPARATOR
            << zombieArray.at(i).attack << SEPARATOR
            << zombieArray.at(i).range << SEPARATOR
            << zombieArray.at(i).row << SEPARATOR
            << zombieArray.at(i).col << SEPARATOR;
    }
}

// LOAD GAME STATE IN A FILE
void loadGame(string filename, vector<vector<char>>& map, vector<gamechar>& zombieArray, gamechar& alien) {
    ifstream file(filename);
    string data;

    getline(file, data, SEPARATOR);
    int row = stoi(data);
    getline(file, data, SEPARATOR);
    int col = stoi(data);

    map.clear();
    setupMap(map, row, col);

    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            getline(file, data, SEPARATOR);
            setElement(map, i, j, data.c_str()[0]);
        }
    }

    getline(file, data, SEPARATOR);
    alien.life = stoi(data);

    getline(file, data, SEPARATOR);
    alien.attack = stoi(data);

    getline(file, data, SEPARATOR);
    alien.row = stoi(data);

    getline(file, data, SEPARATOR);
    alien.col = stoi(data);

    alien.icon = ALIEN;
    alien.trail = ALIEN_TRAIL;

    getline(file, data, SEPARATOR);
    int numZombie = stoi(data);
    zombieArray.clear();
    zombieArray.resize(numZombie);

    for (int i=0; i<numZombie; i++) {
        getline(file, data, SEPARATOR);
        zombieArray.at(i).life = stoi(data);

        getline(file, data, SEPARATOR);
        zombieArray.at(i).attack = stoi(data);

        getline(file, data, SEPARATOR);
        zombieArray.at(i).range = stoi(data);

        getline(file, data, SEPARATOR);
        zombieArray.at(i).row = stoi(data);

        getline(file, data, SEPARATOR);
        zombieArray.at(i).col = stoi(data);

        zombieArray.at(i).icon = ZOMBIE;
        zombieArray.at(i).trail = ZOMBIE_TRAIL;
    }

}

int main()
{
    cout << "Assignment (Part 2)" << endl;
    cout << "Let's Get Started!" << endl;
    cout << "~~~~~~~~~~~~~~~~~~" << endl;
    // pf::Pause();
    system("pause");
    system("cls");

    int row = 5; // DEFAULT BOARD ROWS
    int col = 5; // DEFAULT BOARD COLUMNS
    int zombie = 1; // DEFAULT NUM. OF ZOMBIES

   // FOR USER INPUT
    string command;
    string filename;
    bool zombieMove = false;

    srand (time(NULL));
    vector<vector<char>> map;
    vector<gamechar> zombieArray;

    bool isPlay = true;

    // LOOP GAME FROM START MENU
    while (isPlay){
        bool isInGame= true;
        // SET UP SETTINGS FOR BOARD AND ZOMBIE
        displayMainMenu(row, col, zombie);

        Help();
        setupMap (map, row, col);
   

        // MAKE SURE ITEMS ARE RANDOMISED BEFORE ZOMBIES AND ALIENS ARE ADDED
        randomizeObject(map);

        gamechar alien;
        alien.icon=ALIEN;
        alien.trail=ALIEN_TRAIL;
        randomiseLife(alien,10,100);
        alien.row=map.size()/2;
        alien.col=map[0].size()/2;
        setElement(map,alien.row, alien.col, alien.icon);
       
       // PUT ZOMBIES ON THE BOARD
        setUpZombie(zombieArray, zombie, map);
        // setUpZombie(zombieArray, 2, map);

        // SINGLE GAME LOOP / GAME LOGIC
        while (isInGame){
            system("cls");
            // system("clear");
            displayMap (map);
            displayAlienStats(alien);
            for (int i=0; i<zombieArray.size(); i++)
                displayZombieStats(zombieArray.at(i), i);
            getCommand(command);

            if (command == "up") {
                moveAlien(alien,map,UP,zombieArray);
                zombieMove = true;
            }

            else if (command == "right") {
                moveAlien(alien,map,RIGHT,zombieArray);
                zombieMove = true;
            }

            else if (command == "down") {
                moveAlien(alien,map,DOWN,zombieArray);
                zombieMove = true;
            }

            else if (command == "left") {
                moveAlien(alien,map,LEFT,zombieArray);
                zombieMove = true;
            }

            else if (command == "arrow") {
                int arrowRow, arrowCol;
                string direction;
                cout << "Enter Arrow Row: ";
                cin >> arrowRow;
                cout << "Enter Arrow Column: ";
                cin >> arrowCol;
                cout << "Enter Arrow Direction: ";
                cin >> direction;

                // BOARD START WITH 1
                arrowRow--;
                arrowCol--;

                if (
                    (
                        direction == "up" || 
                        direction == "down" || 
                        direction == "left" || 
                        direction == "right"
                    ) &&
                    (
                        getElement(map, arrowRow, arrowCol) == A_UP ||
                        getElement(map, arrowRow, arrowCol) == A_DOWN ||
                        getElement(map, arrowRow, arrowCol) == A_LEFT ||
                        getElement(map, arrowRow, arrowCol) == A_RIGHT
                    )
                ) {
                    if (direction == "up")
                        setElement(map, arrowRow, arrowCol, '^');
                    else if (direction == "down")
                        setElement(map, arrowRow, arrowCol, 'v');
                    else if (direction == "left")
                        setElement(map, arrowRow, arrowCol, '<');
                    else if (direction == "right")
                        setElement(map, arrowRow, arrowCol, '>');
                }
                    else
                    cout << "You have put in the wrong input!" << endl;
                zombieMove = false;
            }

            else if (command == "help") {
                Help();
                zombieMove = false;
            }

            else if (command == "save") {
                cout << "Enter filename to save to > ";
                cin >> filename;
                saveGame(filename+".txt", map, zombieArray, alien);
                zombieMove = false;
            }

            else if (command == "load") {
                cout << "Enter filename to load from > ";
                cin >> filename;
                loadGame(filename+".txt", map, zombieArray, alien);
                zombieMove = false;
            }

            else if (command == "quit") {
                isInGame=false;
                isPlay=false;
                zombieMove = false;
            }
            else {
                cout << "There is no such command! You have loss a turn for poor command!" << endl;
                // zombieMove = false;
            }
            
            if (zombieMove) {
                for (int i=0; i<zombieArray.size(); i++) {
                    if (zombieArray.at(i).life > 0) {
                        cout << "Zombie " << i << "'s turn..." << endl;
                        moveZombie(zombieArray.at(i), map, rand()%4, alien, isInGame);
                        zombieRangeAttack(zombieArray.at(i), map, alien, isInGame);
                    }
                }
            }
            
            cout << "All turns Ended! Checking win condition and Updating new Trail!" << endl;
            bool isWinning = checkWinCondition(zombieArray);
            if (isWinning) {
                cout << "Congratulations, You Have Won The Game!" << endl;
                isInGame = false;
                system("pause");
                systen("cls");
            }
            else if (!isInGame) {
                // ALIEN DIED
                cout << "Too Bad, Try Again Next Time!" << endl;
                system("pause");
                system("cls");
            }
            else {
                system("pause");
                system("cls");
                updateTrail(map);
                displayMap(map);
                system("pause");
            }
        }
    }
   
    return 0;

}