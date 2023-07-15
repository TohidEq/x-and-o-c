#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>



const char PLAYER     = 'X';
const char COMPUTER   = 'O';

char board[3][3];

void resetBoard();
void printBoard();
int checkFreeSpace();

void playerMove();
void computerMove();

char checkWinner();
void printWinner(char);



int main(){

  char winner = ' ';
  char restart = 'Y';
  do {
    winner = ' ';
    restart = 'Y';
    resetBoard();
    printBoard();
    while (winner == ' ' && checkFreeSpace()>0) {
      playerMove();
      computerMove();
      printBoard();
      winner = checkWinner();
    }
    printWinner(winner);

    printf("Wanna play again? (Y/N): ");
    scanf("%c");
    scanf("%c",&restart);
    restart = toupper(restart);
  }while (restart == 'Y');
  printf("Have a good day :D\n");
  return 0;
}

void resetBoard(){
  for (int x=0; x<3; x++) {
    for (int y=0; y<3; y++) {
      board[x][y] = ' ';
    }
  }
}

void printBoard(){
  printf(" %c | %c | %c \n", 
          board[0][0],board[0][1],board[0][2]);
  printf("---|---|---\n");
  
  printf(" %c | %c | %c \n", 
          board[1][0],board[1][1],board[1][2]);
  printf("---|---|---\n");
  
    printf(" %c | %c | %c \n", 
          board[2][0],board[2][1],board[2][2]);
}

int checkFreeSpace(){
  int freeSpace = 9;
  for (int x=0; x<3; x++) {
    for (int y=0; y<3; y++) {
      if (board[x][y] != ' ') {
        freeSpace--;
      }
    }
  }
  return freeSpace;
}

void playerMove(){
  int x,y;

  do{
    printf("Enter X (1~3): ");
    scanf("%d",&x);
    x--;
    printf("Enter Y (1~3): ");
    scanf("%d",&y);
    y--;
    if(board[x][y] != ' '){
      printf("Invalid move!\n");
    }else {
      board[x][y] = PLAYER;
      break;
    }
  }while (board[x][y] != ' ') ;
}

void computerMove(){
  srand(time(0));

  int x,y;

  if(checkFreeSpace()>0){
    do {
      x = rand() % 3;
      y = rand() % 3;
    }while (board[x][y] != ' ');
    board[x][y] = COMPUTER;
  }
}

char checkWinner(){
  // rows
  if(board[0][0]==board[0][1] && board[0][1]==board[0][2] ) return board[0][0];
  if(board[1][0]==board[1][1] && board[1][1]==board[1][2] ) return board[1][1];
  if(board[2][0]==board[2][1] && board[2][1]==board[2][2] ) return board[2][2];
  
  // columns
  if(board[0][0]==board[1][0] && board[1][0]==board[2][0] ) return board[0][0];
  if(board[0][1]==board[1][1] && board[1][1]==board[2][1] ) return board[1][1];
  if(board[0][2]==board[1][2] && board[1][2]==board[2][2] ) return board[2][2];

  // diagonals
  if(board[0][0]==board[1][1] && board[1][1]==board[2][2] ) return board[1][1];
  if(board[0][2]==board[1][1] && board[1][1]==board[2][0] ) return board[1][1];

  return ' ';
}


void printWinner(char winner){
  if(winner == PLAYER){
    printf("YOU WON!\n");
  } 
  else if (winner == COMPUTER) {
    printf("YOU LOST!\n");
  }else { 
    printf("TIE!\n");
  }
}





