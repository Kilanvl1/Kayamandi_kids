#include <iostream>

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
int row;
int column; 
char token = 'x';
bool tie = false; 
std::string player1Name; 
std::string player2Name;

void printBoard() {
    std::cout << "    |     |  \n";
    std::cout << "  "<<space[0][0]<<" |  "<<space[0][1]<<"  | "<<space[0][2]<<"  \n";
    std::cout << "----|-----|----\n";
    std::cout << "    |     |   \n";
    std::cout << "  "<<space[1][0]<<" |  "<<space[1][1]<<"  | "<<space[1][2]<<"  \n";
    std::cout << "----|-----|----\n";
    std::cout << "    |     |   \n";
    std::cout << "  "<<space[2][0]<<" |  "<<space[2][1]<<"  | "<<space[2][2]<<"  \n";
    std::cout << "    |     |   \n";
    std::cout<< "\n\n";
}

void findPlaceOnBoard() {
    int digit; 

    if(token=='x') {
        std::cout<<player1Name<<" Please enter the number where you would like to play ";
        std::cin>>digit; 
    }
    if(token=='0') {
        std::cout<<player2Name<<" Please enter the number where you would like to play ";
        std::cin>>digit; 
    }

    switch(digit) {
        case 1:
            row = 0; 
            column = 0;
            break; 
        case 2:
            row = 0;
            column = 1; 
            break;  
        case 3:
            row = 0;
            column = 2; 
            break;
        case 4:
            row = 1;
            column = 0; 
            break;
        case 5:
            row = 1;
            column = 1; 
            break;
        case 6:
            row = 1;
            column = 2; 
            break;
        case 7:
            row = 2;
            column = 0; 
            break;
        case 8:
            row = 2;
            column = 1; 
            break;
        case 9:
            row = 2;
            column = 2; 
            break;
        default: 
            std::cout<<"Invalid !!!\n";
    }

    if(token=='x' && space[row][column] != 'x' && space[row][column] != '0') {
        space[row][column]='x';
        token='0'; 
    } else if(token=='0' && space[row][column] != 'x' && space[row][column] != '0') {
        space[row][column]='0';
        token='x'; 
    } else {
        std::cout<<"There is no empty space\n";
        findPlaceOnBoard();
    }
    printBoard(); 

}

bool checkGameStatus() {
    for(int i = 0; i < 3; i++) {
        if(space[i][0] == space[i][1] && space[i][0] == space[i][2] || space[0][i] == space[1][i] && space[0][i] == space[2][i]) {
            return true; 
        }
        if(space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[1][1] == space[2][0]) {
            return true; 
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(space[i][j] != 'x' && space[i][j] != '0') {
                return false;
            }
        }
        
    }
    tie = true; 
    return false; 
}

int main() {
    std::cout <<"Enter the name of the first player : \n";
    getline(std::cin, player1Name);
    std::cout<<"Enter the name of the second player : \n";
    getline(std::cin, player2Name); 
    std::cout<<player1Name<< " is player 1 so they will play first \n";
    std::cout<<player2Name<< " is player 2 so they will play second \n";

    while(!checkGameStatus()) {
        printBoard();
        findPlaceOnBoard();
        checkGameStatus();
    }
    
}