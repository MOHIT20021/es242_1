#include <stdio.h>
#include <stdint.h>
#include <assert.h>


typedef int player_t; // 1 or 2
typedef int board_t[4][5]; // 

void init_board(board_t board)
{
    for (int row = 0; row <4; ++row) {
        for (int col = 0; col < 5; ++col) {
            board[row][col] = 0;
        }
    }
}

void print_board(board_t board)
{
    for (int row = 3; row >=0 ; row--) {
        for (int col = 0; col < 5; col++) {
            printf("%d",board[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

int has_won(board_t board, player_t player){
    int flag=0;
    // for checking row;
    for (int i=0;i<4;i++){
        for (int j=0;j<5;j++){
            if (board[i][j]==player){
                flag+=1;}
            else if (flag==4){
                return 1;
            }
            else if (flag>0){
                break;
            }
            else if (j>=2 && flag ==0){
                break;
            }
            }
    }
        
    flag=0;
    // for checking columns/;
    for (int j=0;j<5;j++){
        for (int i=0;i<4;i++){
            if (board[i][j]!=player){
                break;}
            if(i==3){
              return 1; }
        }
    }

    // #for diagnals
    int diag1[4][2]={{3,0},{2,1},{1,2},{0,3}};
    int d1[4][2]={{3,1},{2,2},{1,3},{0,4}};


    int diag2[4][2]={{3,4},{2,3},{1,2},{0,1}};
    int d2[4][2]={{3,3},{2,2},{1,1},{0,0}};

    // checking d1 and diag1
    for (int i=0;i<4;i++){
        int j=0;
        if (board[diag1[i][j]][diag1[i][j+1]]!=player){
            break;
        }
        return 1;
    } 
    
    for (int i=0;i<4;i++){
        int j=0;
        if (board[d1[i][j]][d1[i][j+1]]!=player){
            break;
        }
        return 1;
    } 

    // checking d2 and diag2
    for (int i=0;i<4;i++){
        int j=0;
        if (board[diag2[i][j]][diag2[i][j+1]]!=player){
            break;
        }
        return 1;
    } 
    
    for (int i=0;i<4;i++){
        int j=0;
        if (board[d2[i][j]][d2[i][j+1]]!=player){
            break;
        }
        return 1;
    }   
return 0;
}


typedef struct {
    int row;
    int column;
    int player;// 1 or 2
    /* -1 for a loss, 0 for a draw, 1 for a win. */
    int score;
} move_t;

int is_full(board_t board){
    for (int i =0; i<4; i++){
        for(int j=0; j<5; j++){
            if (board[i][j] ==0){
                return 0;
            }
        }
    }
    return 1;
}

move_t best_move(board_t board, player_t player)
{
    move_t response;
    move_t candidate;
    candidate.row = -1;
    candidate.column =-1;
    candidate.score =-1;
    candidate.player = player;


    // assert(!is_full(board));
    // assert(!has_won(board, player));
    // assert(!has_won(board, 3-player));
    for(int j=0; j<5;j++ ){
        for(int i=0; i<4; i++){
            if (board[i][j]==0 && ((i-1>0) || board[i-1][j]!=0)){
                candidate.row = i;candidate.column =j;
                board[i][j] = 3-player;
                if (has_won(board,3-player)){
                    candidate.score= player;
                    board[candidate.row][candidate.column]=0;
                    return candidate;
                }

                else if(is_full(board)){
                    candidate.score = 0;
                    board[candidate.row][candidate.column]=0;
                    return candidate;
                }
                response = best_move(board, 3-player);
                board[response.row][response.column]= 0; 
                if(response.player!= response.score){
                    candidate.score = player;
                    board[candidate.row][candidate.column]=0;
                    return candidate;
                }
                else if(response.score ==0){
                    board[candidate.row][candidate.column]=0;
                    candidate.score = 0;
                    return candidate;

                }
                else{
                    board[candidate.row][candidate.column]=0;
                    continue;
                }

            }
        }
    }
    candidate.score = 3-player;
    board[candidate.row][candidate.column]=0;
    return candidate;
}

int main(){
    board_t b;
    init_board(b);
    print_board(b);
    int player=1;
    b[0][0]=player;
    printf("\n");
    print_board(b);
    move_t a=best_move(b,3-player);
    b[a.row][a.column]=2;
    printf("\n");
    print_board(b);

    printf("############\n");
    
    b[0][1]=player;
    printf("\n");
    print_board(b);
    a=best_move(b,3-player);
    b[a.row][a.column]=2;
    printf("\n");
    print_board(b);

    printf("############\n");
    
    b[0][2]=player;
    printf("\n");
    print_board(b);
    a=best_move(b,3-player);
    b[a.row][a.column]=2;
    printf("\n");
    print_board(b);
        printf("############\n");
    
    b[0][3]=player;
    printf("\n");
    print_board(b);
    a=best_move(b,3-player);
    b[a.row][a.column]=2;
    printf("\n");
    print_board(b);




}