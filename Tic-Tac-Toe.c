#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#define COMPUTER 'O'
#define PLAYER2 'O'

int finalMove=1;
int freespaces=9;
const char PLAYER1 ='X';
char arr[3][3];

void frontBody();
void resetElement();
void updatedBoard();
int player1Move();
int player2Move();
int computerMove();
int checkWinner();

int main()
{
    
    int choice;
    frontBody();
    do{
    char winner = ' ';
    printf("\n1.ENTER 1 IF YOU WANT TO PLAY WITH COMPUTER\n");
    printf("2.ENTER 2 IF YOU WANT TO PLAY WIHT ANOTHER PLAYER\n");
    printf("ENTER YOUR CHOICE:");
    scanf("%d",&choice);

    //choice 1 is between player 1 vs computer    
    if(choice==1)
    {
        resetElement();
        updatedBoard();

         while (1)
    {
        player1Move();
        updatedBoard();
        winner=checkWinner();
        if(winner!=' ')
        {
            printf("\nPLAYER 1 IS THE WINNER !!!\n");
            break;
        }
        else if(freespaces==0)
        {
            printf("\nIT'S A TIE MATCH !!!\n\n");
            break;
        }
        computerMove();
        updatedBoard();
        winner=checkWinner();
        if(winner!=' ')
        {
            printf("\nCOMPUTER IS THE WINNER !!!\n");
            break;
        }

    }
    }
    //choice 2 is between player 1 vs player 2
    else if(choice==2)
    {
         resetElement();
        updatedBoard();

         while (1)
    {
        player1Move();
        updatedBoard();
        winner=checkWinner();
        if(winner!=' ')
        {
            printf("\nPLAYER 1 IS THE WINNER !!!\n\n");
            break;
        }
        else if(freespaces==0)
        {
            printf("\nIT'S A TIE MATCH !!!\n\n");
            break;
        }
    
        player2Move();
        updatedBoard();
        winner=checkWinner();
        if(winner!=' ')
        {
            printf("\nPLAYER 2 IS THE WINNER !!!\n\n");
            break;
        }
}
    }
    printf("\n-----------------X------------------\n\n");
    printf("\n1.ENTER 1 IF YOU WANT TO PLAY AGAIN\n");
    printf("2.ENTER 2 TO EXIT THE GAME\n\n");
    printf("ENTER YOUR CHOICE:");
    scanf("%d",&choice);

        
    } while (choice==1);
    printf("\n---THANKS FOR PLAYING!---\n\n");
}
    
    

void frontBody()
{
    printf("      **********************      \n");
    printf("***** WELCOME TO TIC-TAC-TOE *****\n");
    printf("      **********************      \n\n");

    printf("        RULES OF THE GAME:        \n\n");
    printf("1. The game is played on a grid that's 3 squares by 3 squares.\n");
    printf("2. You are X , your friend (or the computer in this case) is O ,\n   Players take turns putting their marks in empty squares.\n");
    printf("3. The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner.\n");
    printf("4. When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie.\n\n");


}
void resetElement()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            arr[i][j]=' ';
        }
    }
}
void updatedBoard()
{
    printf("           %c | %c | %c \n",arr[0][0],arr[0][1],arr[0][2]);
    printf("          ---|---|---\n");
    printf("           %c | %c | %c \n",arr[1][0],arr[1][1],arr[1][2]);
    printf("          ---|---|---\n");
    printf("           %c | %c | %c \n",arr[2][0],arr[2][1],arr[2][2]);
}

int player1Move()
{
    printf("\nIT'S PLAYER 1 TURN!\n\n");
    int x,y;
    do{
    printf("enter row from (1-3):");
    scanf("%d",&x);
    x--;
    printf("enter column from (1-3):");
    scanf("%d",&y);
    y--;
    if(arr[x][y]!=' ' )
    {
        printf("\nINVALID MOVE!!!\n\n");
    }
    else if((x<0 || x>2) || (y<0 || y>2))
    {
        printf("\nINVALID MOVE!!!\n\n");
    }
    else{
        arr[x][y] = PLAYER1 ;
        freespaces--;
        break;
    }

    }while((arr[x][y]!=' ') || (x<0 || x>2) || (y<0 || y>2));

}
int player2Move()
{
    printf("\nIT'S PLAYER 2 TURN!\n\n");
    int x,y;
    do{
    printf("enter row from (1-3):");
    scanf("%d",&x);
    x--;
    printf("enter column from (1-3):");
    scanf("%d",&y);
    y--;
    if(arr[x][y]!=' ' )
    {
        printf("\nINVALID MOVE!!!\n\n");
    }
    else if((x<0 || x>2) || (y<0 || y>2))
    {
        printf("\nINVALID MOVE!!!\n\n");
    }
    else{
        arr[x][y] = PLAYER2 ;
        freespaces--;
        break;
    }

    }while((arr[x][y]!=' ') || (x<0 || x>2) || (y<0 || y>2));

}

int computerMove()
{
    printf("\nIT'S COMPUTER TURN! \n\n");
    //creats a seed based on current time
    srand(time(0));
    int x,y;
    if(freespaces>0)
    {
        do{
            x=rand()%3;
            y=rand()%3;
        }while(arr[x][y]!=' ');
        arr[x][y]=COMPUTER;
        freespaces--;
    }



}

int checkWinner()
{
    //check rows
    for(int i=0;i<3;i++)
    {
        if(arr[i][0]==arr[i][1] && arr[i][1]==arr[i][2]){
            return arr[i][0];
        }
    }
    //check columns
     for(int j=0;j<3;j++)
    {
        if(arr[0][j]==arr[1][j] && arr[1][j]==arr[2][j]){
            return arr[0][j];
        }
    }
    //check diagonal1
    if(arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2]){
        return arr[0][0];
    }
    //check diagonal2
    if(arr[0][2]==arr[1][1] && arr[1][1]==arr[2][0]){
        return arr[0][2];
    }
    return ' ';



}