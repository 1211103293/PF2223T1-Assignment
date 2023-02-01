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
using namespace std;

void oddNumbers(int &num) // to only get odd numbers
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
}

// DEFAULT SETTINGS
void displayMainMenu(int row, int col, int zombie)
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
        cout << "Proceed to Game Board";
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
    char icon=' ';
    char trail=' ';
};


void setupMap (vector<vector<char>>& map, const int row, const int col){
    map.resize(row);
    for (int i=0; i<row; i++) {
        map[i].resize(col);
        for (int j=0; j<col; j++) {
                map[i][j] = '_';
        }
    }
}

void displayMap (vector<vector<char>>& map){
    for (int i=0; i<map.size(); i++) {
        for (int j=0; j<map[0].size(); j++) {
            cout << map[i][j];
        }
        cout<<endl;
    }
}

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

    int newrow= character.row;
    int newcol=character.col;

    if(movement==0)
        newrow--;
    else if(movement==1)
        newcol++;
    else if(movement==2)
        newrow++;
    else if(movement==3)
        newcol--;
   
    //  later if you want to check movement such as rock, do it here
    // if(isInside(map,newrow,newcol) || getElement(map, newRow, newCol) != ROCK) {
    if(isInside(map,newrow,newcol)) {
        setElement(map, character.row, character.col, character.trail);
        character.row=newrow;
        character.col=newcol;
        setElement(map, character.row, character.col, character.icon);
    }
}

void setUpZombie(vector<gamechar>& zombieArray, int numOfZombie, vector<vector<char>>& map) {
    zombieArray.clear();
    for (int i=0; i<numOfZombie; i++) {
        gamechar zombie;
        zombie.icon=ZOMBIE;
        zombie.trail= ZOMBIE_TRAIL;
        randomiseLife(zombie,10,100);
        randomiseAttack(zombie,10,20);
        randomiseRange(zombie, 1,4);
        randomisePosition(zombie,map);
        setElement(map,zombie.row, zombie.col, zombie.icon);
        zombieArray.push_back(zombie);
    }
}

void Help(string command)
{
    system("cls");
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


int main()
{
    cout << "Assignment (Part 1)" << endl;
    cout << "Let's Get Started!" << endl;
    cout << "~~~~~~~~~~~~~~~~~~" << endl;
    pf::Pause();

    int row = 5; // board rows
    int col = 9; // board column
    int zombie = 1; // num. of zombies
    displayMainMenu(row, col, zombie);

    string command;
    cout << "command > ";
    cin >> command;
  
     if (command == "help"){
        Help(command);
            cout << endl;
    }

    else{
        cout << "Please input a valid command" << endl;
    }


    // srand (time(NULL));
    vector<vector<char>> map;
    vector<gamechar> zombieArray;

    bool isPlay = true;

    // whole game loop start from menu
    while (isPlay){
        bool isInGame= true;
        // int row, col;
        // cout<<"please enter num of row";
        // cin>>row;
        // cout<<"please enter num of col";
        // cin>>col;

        // FOR TESTING PURpose
        // int row=5, col=5;

        setupMap (map, row, col);
   

        // makesure to randomise game object before adding the alien and zombie

        gamechar alien;
        alien.icon=ALIEN;
        alien.trail=ALIEN_TRAIL;
        randomiseLife(alien,10,100);
        alien.row=map.size()/2;
        alien.col=map[0].size()/2;
        setElement(map,alien.row, alien.col, alien.icon);
       
        // %3+1 mean within 1-3
        // setUpZombie(zombieArray, rand()%3+1, map);
        setUpZombie(zombieArray, 2, map);

        // moveChar(alien,map,1);
        // moveChar(alien,map,1);

        // single game loop / game logic
        while (isInGame){
            //system("cls");
            // system("clear");
            displayMap (map);
            system("pause");

            // FOR TESTING PURPOSE
            cout<<"Enter q to move the zombies. ";
            char temp;
            cin>>temp;
            if(temp=='q')
                isInGame=false;
        }
    }
   
    return 0;

}