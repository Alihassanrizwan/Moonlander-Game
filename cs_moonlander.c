// cs_moonlander.c
// Written by YOUR-NAME (YOUR-ZID),
// on TODAYS-DATE
// TODO: Program Description

#include <stdio.h>
#include <stdbool.h>
#include <math.h>  
// Provided Constant Definitions
#define BOARD_LEN 10
#define BOARD_MAX_LEVELS 32
#define BASE_OXY_RATE 1.0
#define MAX_PORTALS 16
#define TITLE_STR_LEN 25
#define INVALID_INDEX -1
#define COMMAND_QUIT 'q'

// TODO: Your #defines go here

// Provided Enum Definitions
enum entity {
    EMPTY,
    CHEESE,
    ROCK,
    LANDER,
    HOLE_DOWN,
    HOLE_UP,
    PORTAL
};

// TODO: Your enums go here

// Provided Struct Definitions
struct tile {
    enum entity entity;
};

// TODO: Your structs go here

// Provided Function Prototypes
void init_board(
    struct tile board[BOARD_LEN][BOARD_LEN]
);
void print_board(
    struct tile board[BOARD_LEN][BOARD_LEN],
    int player_row,
    int player_col,
    int cheese_held,
    int cheese_lander,
    double oxy_capacity,
    double oxy_level,
    double oxy_rate
);
void print_board_header(void);
void print_player_stats(
    int cheese_held,
    int cheese_lander,
    double oxy_capacity,
    double oxy_level,
    double oxy_rate
);

// TODO: Your function prototypes go here
bool input_valid(
    struct tile board[BOARD_LEN][BOARD_LEN],
    int rows, int cols);
bool size_valid(int rows,int cols);



void input_lander(int *rows, int *cols);
void insert_lander(
    struct tile board[BOARD_LEN][BOARD_LEN],
    int rows, int cols);


void input_ches_rock(char *che_rock, int *rows, int *cols);
void insert_ches_rock(
    struct tile board[BOARD_LEN][BOARD_LEN], 
    char che_rock,int rows,int cols);


void input_more_rock(char *che_rock, int* rows, int *cols, int *col1, int *col2);
void insert_more_rock(
    struct tile board[BOARD_LEN][BOARD_LEN], 
    char che_rock,int rows,int cols, int col1, int col2);

void Quantity(int *quantity);
void Capacity( float *capacity);
void player_position(int *rows , int *cols);


void player_movements(
    struct tile board[BOARD_LEN][BOARD_LEN], 
    int *rows, int *cols, int*cheese, float* temp ,float *b_o_r, int *count, int *p_cheese);
bool win_game(
    struct tile board[BOARD_LEN][BOARD_LEN]
    );
 void whole_move(struct tile board[BOARD_LEN][BOARD_LEN],
        char move, char side,int * rows, int *cols,  float *temp, float* b_o_r);
void two_portal(struct tile board[BOARD_LEN][BOARD_LEN],
            int * rows, int * cols,float* temp,float * b_o_r);







int main(void) {
    // TODO: add your code (and remove this todo)
    int rows, cols;
    char che_rock;
    int col1, col2;
     int choice;
     int quantity;
     float capacity;
     int cheese = 0;
     int p_cheese=0;
     float b_o_r = BASE_OXY_RATE;
     printf("2sdsahkd  hdkjsa dh");
     printf("value %f", b_o_r);
    // prints the board with no player
    // you may decide to delete or move this later...
    struct tile board[BOARD_LEN][BOARD_LEN];
    init_board(board);
    print_board(board, INVALID_INDEX, INVALID_INDEX, 0, 0, 0.0, 0.0,
            BASE_OXY_RATE);



    input_lander(&rows, &cols);
     while(!size_valid(rows, cols)){
       printf("this position of insertion Not existing!");
       printf("insert Again1\n");
       input_lander(&rows, &cols);
     }


    insert_lander(board, rows, cols);
    print_board(board, INVALID_INDEX, INVALID_INDEX, 0, 0, 0.0, 0.0,
            BASE_OXY_RATE);

    
   
    printf("\n                       ******************Menu:\n");
        printf("Press 0. For Input Cheese and rock\n");
        printf("Press ANy key(1 -- 9). For exit\n");
        printf("Enter your choice (0 to move forward, 1 to 9 to move exit): ");
        scanf("%d", &choice);
    while(choice == 0){
        input_ches_rock(&che_rock, &rows, &cols);

        while(!input_valid(board, rows, cols) || !size_valid(rows, cols)){
                          
                printf("Invalid Input kindly Enter Again\n");
                input_ches_rock(&che_rock, &rows, &cols);
               }
        
        insert_ches_rock(board, che_rock, rows, cols);
        print_board(board, INVALID_INDEX, INVALID_INDEX, 0, 0, 0.0, 0.0,
            BASE_OXY_RATE);
        printf("Press 0. For Input Cheese and rock\n");
        printf("Press Any Key (1 -- 9). For exit\n");
        printf("Enter your choice (0 to move forward, 1 to 9 to move exit): ");
        scanf("%d", &choice);
    }
    
     

      printf("\n                        ********************* Menu:\n");
        printf("Press 0. For input Three Rocks Location in One Time\n");
        printf("Press Any key)(1 -- 9) For exit\n");
        printf("Enter your choice (0 to move forward, 1 to 9 to move exit: ");
        scanf("%d", &choice);
        while(choice == 0){
             input_more_rock(&che_rock, &rows, &cols, &col1, &col2);
            while(che_rock != 'R' || !input_valid(board, rows , cols)|| !input_valid(board, rows , col1)|| !input_valid(board, rows , col2) || !size_valid(rows, cols) || !size_valid(rows, col1) || !size_valid(rows, col2)){
            printf("Invalid Input Please Enter Capital R and four integer inputs on the NULL space And Select existing Tiles: ");
            input_more_rock(&che_rock, &rows, &cols, &col1, &col2);
            }
            insert_more_rock(board ,che_rock, rows, cols, col1, col2);
            print_board(board, INVALID_INDEX, INVALID_INDEX, 0, 0, 0.0, 0.0,
            BASE_OXY_RATE);

            insert_more_rock(board ,che_rock, rows, cols, col1, col2);
            print_board(board, INVALID_INDEX, INVALID_INDEX, 0, 0, 0.0, 0.0,
            BASE_OXY_RATE);
            printf("Press 1. For input Three Rocks Location in One Time\n");
            printf("Press Any key( 1 -- 9) For exit\n");
            printf("Enter your choice (0 to move forward, 1 to 9 to move exit): ");
            scanf("%d", &choice);
    }
        



    printf("\n                        ********************* Menu:\n");
        printf("Press 0. For input q: \n");
        printf("Press Any key)(1 -- 9) For exit\n");
        printf("Enter your choice (0 to move forward, 1 to 9 to move exit: ");
        scanf("%d", &choice);
       
        if(choice == 0){
        Quantity(&quantity);
        while(quantity<=0){
             printf("invalid Input: ");
             Quantity(&quantity);
        }
        Capacity( &capacity);
        while(capacity<=0){
              printf("Invalid Input ");
              Capacity( &capacity);
        }
        player_position(&rows , &cols);
        
        while(!input_valid(board, rows, cols)|| !size_valid(rows, cols)){
            player_position(&rows , &cols);
        }
        print_board(board, rows, cols, 0, 0, capacity, capacity,
            BASE_OXY_RATE);
        }
        



    float temp = capacity;
    int count=0;
    int i=0;

    while(temp>0){
            player_movements(board, &rows, &cols, &cheese, &temp, &b_o_r, &count, &p_cheese);
      
            if( win_game(board)){
                print_board(board, rows, cols, p_cheese, cheese, capacity,capacity,
                b_o_r);
                printf("You WIN THE GAme\n");
                break;
            } 
           
            print_board(board, rows, cols, p_cheese, cheese, capacity,temp,
            b_o_r);
             
       i++;
    }
      if(temp<=0 ){
                printf("Yo LOSE the GAme\n");
            }









//printf("%d, %d, %d", rows, cols, cheese);




    
 
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////// YOUR FUNCTIONS //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// TODO: Your function implementations go here
bool input_valid(
    struct tile board[BOARD_LEN][BOARD_LEN],int rows, int cols){
   if (board[rows][cols].entity == EMPTY) {
        return true;
    }
    else{
       return false;
    }

}

bool size_valid(int rows,int cols){
   if(rows<0 || rows>=10  || cols<0 || cols>=10 )
      return false;
    else return true;       

}



void input_lander(int *rows, int *cols){
    printf("Please enter the [row] [col] of the lander: ");
    scanf("%d %d", rows, cols);

}
void insert_lander(
    struct tile board[BOARD_LEN][BOARD_LEN],
    int rows, int cols){
        board[rows][cols].entity= LANDER;
    }
void input_ches_rock(char *che_rock, int *rows, int *cols) {
    printf("\nPlease enter cheese and rock locations: ");
    scanf(" %c %d %d", che_rock, rows, cols); // Read input
}
void insert_ches_rock(
    struct tile board[BOARD_LEN][BOARD_LEN], 
    char che_rock,int rows,int cols){
      if(che_rock == 'r'){
       board[rows][cols].entity= ROCK;
      }
      else if(che_rock == 'c'){
        board[rows][cols].entity= CHEESE;
      }
    }

void input_more_rock(char *che_rock, int* rows, int *cols, int *col1, int *col2){
     printf("\nPlease enter cheese and rock locations: ");
     scanf(" %c %d %d %d %d", che_rock, rows,cols, col1, col2); // Read input
}
void insert_more_rock(
    struct tile board[BOARD_LEN][BOARD_LEN], 
    char che_rock,int rows,int cols, int col1, int col2){
                board[rows][cols].entity= ROCK;
                board[rows][col1].entity= ROCK;
                board[rows][col2].entity= ROCK;
    }



void Quantity(int *quantity){
    printf("Please enter the target qty of cheese: ");
    scanf("%d", quantity);
    printf("You entered: %d\n", *quantity);
}
 
 void Capacity( float *capacity){
 printf("Please enter the player's oxygen tank capacity: ");
    scanf("%f", capacity);
    printf("You entered: %f\n", *capacity);

 }

void player_position(int *rows , int *cols){
     printf("Please enter the [row] [col] of the player: ");
    scanf("%d %d", rows, cols);

}

void whole_move(struct tile board[BOARD_LEN][BOARD_LEN],
        char move,char side, int * rows, int *cols, float *temp, float* b_o_r){
      int r = *rows, c = *cols ;
      float t= *temp;
    if(side == 'd'){
          if(c+1 <=9){
            t= t- *(b_o_r);
                 board[r][c+1].entity = HOLE_DOWN;
          }
          else{
            printf("Invalid Move Try Again\n");
          }
     }
    else if(side == 's'){
        if(r+1 <=9){
            t= t- *(b_o_r);
                 board[r+1][c].entity = HOLE_DOWN;
          }
          else{
            printf("Invalid Move Try Again\n");
          }
    }
    else if(side == 'a'){
        
            printf("%d A gya\n", c);
        if(c-1 >=0){
            
            printf("value before of t %f", t);
            t = t- *(b_o_r);
            printf("value of t %f", t);
           board[r][c-1].entity = HOLE_DOWN;
            
          }
          else{
            printf("Invalid Move Try Again\n");
          }

    }
    else if(side == 'w'){
            if(r-1 >=0){
                t= t- *(b_o_r);
          
                 board[r][c+1].entity = HOLE_DOWN;
            
          }
          else{
            printf("Invalid Move Try Again\n");
          }

    }
    else{
        printf("invalid move\n");
    }
  printf("all values after updation\n ,%d,%d, %f", r, c, t);

    *rows = r;
    *cols= c;
    *temp = t;
       printf("\n pointer values after updation, %d,%d, %f\n", *rows, *cols, *temp);

        }
void two_portal(struct tile board[BOARD_LEN][BOARD_LEN],
            int * rows, int * cols,float* temp,float * b_o_r){
                printf("in two portal function\n");
           char move;
           int r1=-1, r2=-1, c1=-1;
           int r = *rows, c=* cols;
           float t = *temp;    
            printf("Enter move and coordinates (e.g., a 1 2 3): ");
            scanf(" %c %d %d %d", &move, &r1, &r2, &c1);
            printf("Values in function: %c, %d, %d, %d\n", move, r1, r2, c1);
          while(r1<0 || r1>9|| c1<0 || c1>9 ||r2<0 || r2>9){
             printf("Your input is invalid!\n");
             printf("Kindly enter again (e.g., a 1 2 3): ");
            scanf(" %c %d %d %d", &move, &r1, &r2, &c1);
             printf("Values in function: %c, %d, %d, %d\n", move, r1, r2, c1);
          }
          
         if(move == 'a'){
                 if(c-1>=0){
                    t = t- (*b_o_r);
                   board[r][c-1].entity=PORTAL;
                   board[r1][c1].entity=PORTAL;
                    board[r2][c1].entity=PORTAL;
                 }
                 else{
                    printf("invalid move\n");
                 }
         }
         else if(move == 'w'){
                if(r-1>=0){
                             t = t- (*b_o_r);
                   board[r-1][c].entity=PORTAL;
                   board[r1][c1].entity=PORTAL;
                    board[r2][c1].entity=PORTAL;
                 }
                 else{
                    printf("invalid move\n");
                 }
         }
         else if(move == 's'){
                 if(r+1<=9){
                             t = t- (*b_o_r);
                   board[r+1][c].entity=PORTAL;
                   board[r1][c1].entity=PORTAL;
                    board[r2][c1].entity=PORTAL;
                 }
                 else{
                    printf("invalid move\n");
                 }
         }
         else if(move == 'd'){
                if(c+1<=9){
                             t = t- (*b_o_r);
                   board[r][c+1].entity=PORTAL;
                   board[r1][c1].entity=PORTAL;
                    board[r2][c1].entity=PORTAL;
                 }
                 else{
                    printf("invalid move\n");
                 }
         }
         else{
            printf("Invalid Input\n");
         }


    *rows = r;
    *cols = c;
    *temp = t;

            }


void player_movements(
    struct tile board[BOARD_LEN][BOARD_LEN], 
        int *rows, int *cols, int* cheese, float*temp, float* b_o_r, int* count, int* p_cheese){

    int r = *rows, c = *cols ;
    float t= *temp;
    char move;
    printf("*********************Movements Menu************************************\n");
    printf("press d for right move\n");
    printf("Press s for downd move\n");
    printf("press a for left move\n");
    printf("press w for up move\n");
    printf("Press m for Transpose\n");
    printf("Press q for quiet\n");
    printf("Press t for two portals\n");
    printf("Press h a , h s , h d , h w for whole movement\n");
 
     printf("Enter your Move: ");
      scanf(" %c", &move);

    if(move == 'd'){
          if(c+1 <=9){
             if(board[r][c+1].entity != HOLE_DOWN){
                    board[r][c].entity=EMPTY;
                    c++;
                    t= t-*(b_o_r);
                    if(input_valid(board, r, c) == false){
                        (*cheese)++;
                    }
                }
             else{
                    //board[r][c].entity=HOLE_DOWN;
                    c++;
                    t= t-*(b_o_r);
                    if(input_valid(board, r, c) == false){
                        (*p_cheese)++;
                    }
                }
          }
          else{
            printf("invalid Move Try Again\n");
          }
     }
    else if(move == 's'){
           
        if(r+1 <=9){
                if(board[r+1][c].entity!= HOLE_DOWN){
                    board[r][c].entity=EMPTY;
                    r++;
                    t= t- *(b_o_r);
                    if(input_valid(board, r , c) == false){
                    
                    (*cheese)++;
                }
            
                else{
                    //board[r][c].entity=HOLE_DOWN;
                    r++;
                    t= t- *(b_o_r);
                    if(input_valid(board, r , c) == false){
                    (*p_cheese)++;
                    }
                }

            }
          }
          else{
            printf("invalid Move Try Again\n");
          }
    }
    else if(move == 'a'){
        if(c-1 >=0){
            if(board[r][c-1].entity!= HOLE_DOWN){
                board[r][c].entity=EMPTY;
                t= t- *(b_o_r);
                 c--;
                if(input_valid(board , r ,c) == false){
                    (*cheese)++;
                        }
            }
            
            else{
                //board[r][c].entity=HOLE_DOWN;
                     t= t- *(b_o_r);
                    c--;
                    (*p_cheese)++;
                    
            }
        }
    
          else{
            printf("invalid Move Try Again\n");
          }

    }
    else if(move == 'w'){
            if(r-1 >=0){
                if(board[r-1][c].entity!= HOLE_DOWN){
                    board[r][c].entity=EMPTY;
                    t= t- *(b_o_r);
                    r--;
                    if(input_valid(board , r , c) == false){
                    (*cheese)++;
                    }
                }
                else{
                   // board[r][c].entity=HOLE_DOWN;
                        t= t- *(b_o_r);
                    r--;
                    if(input_valid(board , r , c) == false){
                    (*p_cheese)++;
                    }

                }
            }
          else{
            printf("invalid Move Try Again\n");
          }

    }
    else if(move == 'm'){
       int coun = ++ (*count );
        float a2= BASE_OXY_RATE+ 0.2;;
           int trans=r;
           r = c;
           c = trans;
           t= t- 20;
            float power = 1;
            for(int i=1; i<=coun; i++)
            {
                power *=a2;
            }
             (*b_o_r) = BASE_OXY_RATE * power;
          
    }
    else if(move == 'h'){
        char side;
        printf("Enter turn a, w, s, d: ");
        scanf(" %c", &side);
        printf ("\n\n\n\\n ma to a gya\n\n ");
         printf("%d,%d, %f", r, c, t);
         printf("move side in function = %c, %c", move , side);
        whole_move(board, move, side, &r, &c, &t, b_o_r);


    }
    
     
    else if(move == 't'){
             printf("i am in t\n");
             
             two_portal(board, &r, &c, &t, b_o_r);

       }
    else if(move == 'q'){
        t=0;
    }


    else{
     printf("command Not found\n");
    }


    printf("Value of p cheese , cheese%d, %d\n", *p_cheese, *cheese);
  *temp = t;
  *rows = r;
  *cols = c;
 
}


bool win_game(
    struct tile board[BOARD_LEN][BOARD_LEN]){
        for(int row=0; row<BOARD_LEN; row++){
                for(int col=0; col<BOARD_LEN; col++){
                   if ((board[row][col].entity == ROCK) || (board[row][col].entity == CHEESE) ||(board[row][col].entity == HOLE_UP) || (board[row][col].entity == HOLE_DOWN) ||(board[row][col].entity == PORTAL) )
                    return false;
                
                }
        }
        return true;
    }













////////////////////////////////////////////////////////////////////////////////
////////////////////////////// PROVIDED FUNCTIONS //////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// Initialises the board to EMPTY for each tile
void init_board(struct tile board[BOARD_LEN][BOARD_LEN]) {
    for (int row = 0; row < BOARD_LEN; row++) {
        for (int col = 0; col < BOARD_LEN; col++) {
            board[row][col].entity = EMPTY;
        }
    }
    return;
}

// Prints a line commonly used when printing the board, line length scales with
// the BOARD_LEN constant
void print_board_line(void) {
    printf("+");
    for (int col = 0; col < BOARD_LEN; col++) {
        printf("---+");
    }
    printf("\n");
    return;
}

// Prints the header of the cs_moonlander board
void print_board_header(void) {
    char title_str[TITLE_STR_LEN + 1] = "C S   M O O N L A N D E R";

    printf("|");
    for (int i = (4 * BOARD_LEN - TITLE_STR_LEN) / 2; i > 0; i--) {
        printf(" ");
    }

    printf("%s", title_str);

    for (int i = (4 * BOARD_LEN - TITLE_STR_LEN) / 2; i > 0; i--) {
        printf(" ");
    }
    printf("|\n");

    return;
}

// Prints the player stats when requested by the user
void print_player_stats(
    int cheese_held,
    int cheese_lander,
    double oxy_capacity,
    double oxy_level,
    double oxy_rate
) {
    printf("Player Cheese: %d     Lander Cheese: %d\n",
            cheese_held, cheese_lander);
    printf("Oxy: %.2lf / %.2lf  @  %.6lf / move\n", oxy_level,
            oxy_capacity, oxy_rate);
    return;
}

// Prints the cs_moonlander board
void print_board(
    struct tile board[BOARD_LEN][BOARD_LEN],
    int player_row,
    int player_col,
    int cheese_held,
    int cheese_lander,
    double oxy_capacity,
    double oxy_level,
    double oxy_rate) {

    print_board_line();
    print_board_header();
    print_board_line();
    for (int row = 0; row < BOARD_LEN; row++) {
        for (int col = 0; col < BOARD_LEN; col++) {
            printf("|");
            if (row == player_row && col == player_col) {
                printf("0.0");
            } else if (board[row][col].entity == ROCK) {
                printf("^^^");
            } else if (board[row][col].entity == LANDER) {
                printf("/|\\");
            } else if (board[row][col].entity == CHEESE) {
                printf("<(]");
            } else if (board[row][col].entity == HOLE_UP) {
                printf("/O\\");
            } else if (board[row][col].entity == HOLE_DOWN) {
                printf("\\O/");
            } else if (board[row][col].entity == PORTAL) {
                printf("~~~");
            } else {
                printf("   ");
            }
        }
        printf("|\n");
        print_board_line();
    }
    print_player_stats(cheese_held, cheese_lander, oxy_capacity, oxy_level,
            oxy_rate);
    print_board_line();
    return;
}
