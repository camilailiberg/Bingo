#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define  ROWS   5
#define  COL    5
#define  FREE   2
#define  SCALE  15
#define  SHIFT  1
#define  MAXVAL 75
#define  FALSE 0
#define  TRUE 1

#define MINVAL 1
#define VALUES 25
#define B 0
#define I 1
#define N 2
#define G 3
#define O 4
#define DOB 'X'

#define BINGO 5


void welcomeScreen(); //THIS IS A FUNCTION DECLARATION. //THIS IS BEST PRACTICE.
void displayExplicitCard();
void clearScreen();
void displayCard();
void displayRandomCard();
void fillCardRand(int arr[ROWS][COL], int used[MAXVAL]);
void setValue(int arr[ROWS][COL], int row, int col, int arrUsed[MAXVAL]);
void displayBingoCard(int arr[ROWS][COL]);
void initializeArrays(int used[MAXVAL], int called[MAXVAL], char result[ROWS][COL]);

void play(int card[ROWS][COL], int called[MAXVAL], char result[ROWS][COL]);
int callNumber();
void checkNumber(char letter, int number, int card[ROWS][COL], char result[ROWS][COL]);
void displayNumber(char letter, int number);
void displayBingoCardPlay(int card[ROWS][COL], char result[ROWS][COL]);

bool horizontalLine(char result[ROWS][COL]);


int main()
{

    int called[MAXVAL];
    char result[ROWS][COL];

    int card[ROWS][COL];
    int used[MAXVAL];
    srand((int)time(0));
    welcomeScreen();
    clearScreen();
    //displayExplicitCard();
    //clearScreen();
    //displayCard();
    //clearScreen();
    //displayRandomCard();
    //clearScreen();
    initializeArrays(used, called, result);
    fillCardRand(card, used);
    displayBingoCard(card);
    play(card, called, result);

    return 0;

}

void welcomeScreen()
{

    //Prints BINGO in big words.
    printf("\t\tBBBBB   II  NN     NN    GGGGG    OOOO\n\t\tBB  BB  II  NN N   NN  GG        OO  OO\n\t\tBBBBB   II  NN  N  NN  GG        OO  OO\n\t\tBB  BB  II  NN   N NN  GG  GGGG  OO  OO\n\t\tBBBBB   II  NN     NN   GGGGGG    OOOO");
    //print all the rules.
    printf("\nRULES OF THE GAME\n");
    printf("1. A player receives a Bingo Card\n");
    printf("2. Each card has a random placement of numbers for each column, B, I, N, G, O\n");
    printf("\tColumn B contains values 1 - 15\n");
    printf("\tColumn I contains values 16 -  30\n");
    printf("\tColumn N contains values 31 - 45 in addition to a Free Space\n");
    printf("\tColumn G contains values 46 - 60\n");
    printf("\tColumn O contains values 61 - 75\n");
    printf("3. Variuos patterns are identified to accomplish a BINGO \n");
    printf("4. Each round of game will identify which pattern should be accomplish to win a BINGO\n");
    printf("5. Winning numbers randomly selected during play\n");
    printf("6. Good Luck!\n");


    return;
}

//clears the screen
void clearScreen()
{

    printf("\n\t\t\tHIT <ENTER> TO CONTINIUE.\n");
    //use so that the user clears the screen instead of it clearing automaticaly. (Basicaly acting as a pause for the program).
    char clr;
    scanf("%c", &clr);

    system("clear"); //UNIX. //this clears the screen in the command line.
    //system ("cls"); //Windows

    return;
}


void displayExplicitCard()
{

    printf("Function displayExplicitCard\n");
    //Prints the user card.
    printf("|---------------------------------------|\n");
    printf("|   B   |   I   |   N   |   G   |   O   |\n");
    printf("|---------------------------------------|\n");
    printf("|   15  |   16  |   31  |   46  |   61  |\n");
    printf("|---------------------------------------|\n");
    printf("|   2   |   23  |   45  |   60  |   75  |\n");
    printf("|---------------------------------------|\n");
    printf("|   5   |   20  |  FREE |   51  |   68  |\n");
    printf("|---------------------------------------|\n");
    printf("|   12  |   27  |   40  |   55  |   70  |\n");
    printf("|---------------------------------------|\n");
    printf("|   9   |   30  |   37  |   49  |   64  |\n");
    printf("|---------------------------------------|\n");

    return;
}


void displayCard()
{

    printf("Function displayCard\n");

    int row;
    int col;
    int num;


    printf("|---------------------------------------|\n");
    printf("|   B   |   I   |   N   |   G   |   O   |\n");
    printf("|---------------------------------------|\n");


    int count = 0; //counts in which colum the program currently is.

    int rand1 = 1;
    int rand2 = 16;
    int rand3 = 31;
    int rand4 = 46;
    int rand5 = 61;


    for ( col = 0; col < COL; col++ )
    {

        //this checks for when to print FREE + makes that all the lines are align if the number in the first colum is 10 or greater.
        if( count == 2 && rand1 > 9 )
        {
            printf("|   %d  |   %d  |  FREE |   %d  |   %d  |\n", rand1, rand2, rand4, rand5);
            printf("|---------------------------------------|\n");
        }

        //this checks for when to print FREE + makes that all the lines are align if the number in the first colum is 9 or less.
        else if ( count == 2 && rand1 < 10){
            printf("|    %d  |   %d  |  FREE |   %d  |   %d  |\n", rand1, rand2, rand4, rand5);
            printf("|---------------------------------------|\n");
        }

        //this makes that all the lines are align if the number in the first colum is 10 or greater.
        else if( rand1 > 9 )
        {
            printf("|   %d  |   %d  |   %d  |   %d  |   %d  |\n", rand1, rand2, rand3, rand4, rand5);
            printf("|---------------------------------------|\n");
        }

        //this makes that all the lines are align if the number in the first colum is 9 or less.
        else
        {
            printf("|    %d  |   %d  |   %d  |   %d  |   %d  |\n", rand1, rand2, rand3, rand4, rand5);
            printf("|---------------------------------------|\n");
        }

        //increases the numbres in the bingo card so that they don't repeat.
        rand1++;
        rand2++;
        rand3++;
        rand4++;
        rand5++;
        count++;

    }

    return;

}


void displayRandomCard()
{


    printf("Function displayRandomCard\n");

    int row;
    int col;
    int num;

    printf("|---------------------------------------|\n");
    printf("|   B   |   I   |   N   |   G   |   O   |\n");
    printf("|---------------------------------------|\n");

    int count = 0;

    for ( col = 0; col < COL; col++ )
    {

        int rand1 = rand() % 15 + 1;
        int rand2 = rand() % 15 + 16;
        int rand3 = rand() % 15 + 31;
        int rand4 = rand() % 15 + 46;
        int rand5 = rand() % 15 + 61;


        if( count == 2 && rand1 > 9 )
        {
            printf("|   %d  |   %d  |  FREE |   %d  |   %d  |\n", rand1, rand2, rand4, rand5);
            printf("|---------------------------------------|\n");
        }

        else if ( count == 2 && rand1 < 10){
            printf("|    %d  |   %d  |  FREE |   %d  |   %d  |\n", rand1, rand2, rand4, rand5);
            printf("|---------------------------------------|\n");
        }

        //this makes that all the lines are aligns if the number in the first colum is 10 or greater.
        else if( rand1 > 9 )
        {
            printf("|   %d  |   %d  |   %d  |   %d  |   %d  |\n", rand1, rand2, rand3, rand4, rand5);
            printf("|---------------------------------------|\n");
        }

        else
        {
            printf("|    %d  |   %d  |   %d  |   %d  |   %d  |\n", rand1, rand2, rand3, rand4, rand5);
            printf("|---------------------------------------|\n");
        }

         count++; //counts in which colum the program currently is.

    }

    return;

}

void fillCardRand(int arr[ROWS][COL], int arrUsed[MAXVAL])
{
    int row;
    int col;

    for(row = 0 ; row < ROWS ; row++){
        for (col = 0; col < COL; col++)
        {
            if(row == 2 && col == 2){

                arr[row][col] = 0;

            }//closes if.
            else{

                setValue(arr, row, col, arrUsed);

            } //closes else.
        } //closes inner for loop.
    } //closes outer for lop.


    return;
}


void setValue(int arr[ROWS][COL], int row, int col, int arrUsed[MAXVAL])
{

    int num;
    int base;
    int idx;

    base = SCALE * col;
    num = (rand() % SCALE) + SHIFT + base;
    idx = num - SHIFT;

    if(arrUsed[idx] == FALSE)
    {
        arrUsed[idx] = TRUE;
        arr[row][col] = num;
    }
    else
    {
        setValue(arr, row, col, arrUsed);
    }

}

void displayBingoCard(int arr[ROWS][COL])
{

    printf("Function displayBingoCard\n");

    int r;
    int c;

    printf("|---------------------------------------|\n");
    printf("|   B   |   I   |   N   |   G   |   O   |\n");
    printf("|---------------------------------------|\n");

    for( r = 0 ; r < ROWS ; r++ )
    {

        for ( c = 0; c < COL; c++)
        {
            if(arr[r][c] == 0)
            {
                printf("|  FREE ");
            }
            else if(arr[r][c] < 10)
            {
                printf("|    %d  ", arr[r][c]);
            }
            else
            {
                printf("|   %d  ", arr[r][c]);
            }

            if(c == 4){
                printf("|");
            }
        }
        printf("\n");
        printf("|---------------------------------------|\n");
    }

}

void initializeArrays(int used [MAXVAL], int called[MAXVAL], char result[ROWS][COL]){

    int row;
    int col;

    for(row = 0; row < ROWS; row++){
      for(col = 0; col < COL; col++){
        result[row][col] = ' ';
      }
    }

    for(col = 0 ; col < MAXVAL ; col++){
        used[col] = FALSE;
        called[col] = FALSE;
    }

}

void play(int card[ROWS][COL], int called[MAXVAL], char result[ROWS][COL]){

  int number;
  bool bingo = false;
  char letter;

  printf("\n\nLet's play BINGO!\n\n");

  while (!bingo){

    number = callNumber(called);

    if(number >= 1 && number <= 15){
      letter = 'B';
    }
    else if(number >= 16 && number <= 30){
      letter = 'I';
    }
    else if(number >= 31 && number <= 45){
      letter = 'N';
    }
    else if(number >= 46 && number <= 60){
      letter = 'G';
    }
      else if(number >= 61 && number <= 75){
      letter = 'O';
    }

    displayNumber(letter, number);
    checkNumber(letter, number, card, result);
    displayBingoCardPlay(card, result);

    bingo = horizontalLine(result);

  }

  if(bingo == true){
    printf("BINGO! You have BINGO! You won $1 MILLION DOLLARS!\n");
  }

  return;

}

void displayNumber(char letter, int number){

  printf("%c-%d... %c... %d\n",letter, number,letter, number );

  char clr;
  scanf("%c", &clr);

  system("clear"); //UNIX. //this clears the screen in the command line.
  //system ("cls"); //Windows

  return;

}

void checkNumber(char letter, int number, int card[ROWS][COL], char result[ROWS][COL]){

  int row;
  int col;

  switch (letter) {
    case 'B':
      col = 0;
      break;
    case 'I':
      col = 1;
      break;

    case 'N':
      col = 2;
      break;

    case 'G':
      col = 3;
      break;

    case 'O':
      col = 4;
      break;
  }

  for(row = 0 ; row < ROWS; row++){

    if( card[row][col] == number){
      result[row][col] = DOB;
    }

  }

}

int callNumber(int called[MAXVAL]){

  int num;
  int idx ;

  idx = (rand() % MAXVAL);
  num = idx + SHIFT;

  if(called[idx] == FALSE){
    called[idx] = TRUE;
    return num;

  }
  else{
  return callNumber(called);
  }

}

void displayBingoCardPlay(int arr[ROWS][COL], char result[ROWS][COL]){

  printf("Function displayBingoCard\n");

  int r;
  int c;

  printf("|---------------------------------------|\n");
  printf("|   B   |   I   |   N   |   G   |   O   |\n");
  printf("|---------------------------------------|\n");

  for( r = 0 ; r < ROWS ; r++ )
  {

      for ( c = 0; c < COL; c++)
      {
          if(arr[r][c] == 0)
          {
              printf("|  FREE ");
          }
          else if(result[r][c] == DOB){
            printf("|    %c  ", result[r][c]);
          }
          else if(arr[r][c] < 10)
          {
              printf("|    %d  ", arr[r][c]);
          }
          else
          {
              printf("|   %d  ", arr[r][c]);
          }

          if(c == 4){
              printf("|");
          }
      }
      printf("\n");
      printf("|---------------------------------------|\n");
  }

}

bool horizontalLine(char result [ ROWS ][ COL ]){

  bool retu = false;
  int count;

  for(int r = 0 ; r < ROWS ; r ++){
    count = 0;
    for(int c = 0 ; c < COL ; c++){

      if(result[r][c] == DOB || (r == FREE && c == FREE) ){
        count++;
        //printf("Found X at: row: %d  col: %d\n", r, c);
      }
      if(count == 5){
        retu = true;
        c = COL;
        r = ROWS;
      }

    }

  }
  printf("bingo: %d\n",retu );
  return retu;

}
