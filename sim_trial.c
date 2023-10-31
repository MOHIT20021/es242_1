#include <stdio.h>

typedef char board_t[15];
typedef struct {
    int line; /* 0 for 12, 1 for 13, ..., 14 for 56. */
    int score;
    int player;
} move_t;
             


void print_board(board_t board) {
    for (int i = 0; i < 15; i++) {
        printf("%d ", board[i]);
    }
    printf("\n"); // Print a final newline for formatting
}

int sum_board(board_t board){
  int sum=0;
  for(int i=0;i<15;i++){
    sum+=board[i];
  }
  return sum;
}

int has_lost(board_t board, int player) {
    int lost[20][3] = {{0, 4, 8}, {7, 3, 0}, {9, 11, 13}, {4, 11, 1}, {12, 6, 7}, {0, 5, 1}, {5, 9, 6}, {12, 10, 9}, {12, 14, 3}, {14, 4, 3}, {2, 6, 0}, {2, 13, 4}, {10, 5, 7}, {10, 1, 3}, {10, 14, 11}, {8, 5, 11}, {8, 7, 14}, {8, 6, 13}, {2, 12, 3}, {2, 9, 1}};
    
   
    for (int i = 0; i < 20; i++) {
        int j;
        for (j = 0; j < 3; j++) {
            if ( board[lost[i][j]] != player) {
              break;

            }

        }
        if (j == 3) {
          return 1; // You may want to return 1 to indicate a win
        }
    }
 
    return 0;
}

move_t best_move(board_t board, int player) {
   move_t candidate;
   move_t response;
   printf(" entered player %d", player);
   printf("\n");
   printf(" initial board  ");
   print_board(board);
   candidate.player= player;
   for (int i=0; i<15; i++){
    if(sum_board(board)==21){
      printf("################\n");
      printf(" if ==14 \n");
      candidate.score=3-player;
      printf(" candidate.score %d", candidate.score);
      printf("\n#################\n");
      return candidate;

    }
    if (board[i] ==0){
      printf(" Eneterend Board\n");
      candidate.line= i;
      printf("i= %d",i);
      board[i] = player;
      if(has_lost(board, player)){
        printf("\n");

        printf("has lost \n");
        board[i]=0;
        continue;
      }    
    printf(" Entered response \n");
  
    response = best_move(board, 3 - player);
    if(response.player!=response.score){
      printf("response.player!=response.score\n");
      candidate.score = player;
      break;
    }
   }
   }
   board[candidate.line]=0;
   board[response.line]=0;
   printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
   return candidate;}

    


// int print_board(int board)

int main() { 
  printf("hi hello anura\n");
            // 1  2  3  4  5  6  7  8   9  10  11  12  13  14  15
  board_t b = {1, 0, 0, 0, 0, 0, 0, 0 , 0, 1,  0,  0,  2,  0,  2};
  int player =2 ;
    printf("player = %d", player );
    printf("%d", best_move(b, player).line+1);
    return 0;
 

}