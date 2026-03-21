#include <iostream>
using namespace std;
void board(char board[][3]);
void board(char board[][3]){
    char value='1';
    for (int i=0;i <3;i++){
        for (int j=0;j<3;j++){
            board[i][j]=value;
            value++;
        }
    }
}
void display_board(char board[][3]);
void display_board(char board[][3]){
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            cout << board[i][j]<< " ";
        }
        cout<<endl;
    }
}
bool valid_move(char board[][3],int position);
bool valid_move(char board[][3],int position){
    if (position < 1 || position > 9){
        return false;
    }
    int row=(position-1)/3;
    int col=(position-1)%3;
    if (board[row][col]=='X'||board[row][col]=='O'){
        return false;
    }

    return true;
}
void place_move(char board[][3], int position, char player);
void place_move(char board[][3], int position, char player){
    int row = (position-1)/3;
    int col = (position-1)%3;
    board[row][col]=player;
}
bool check_winner(char board[][3], char player);
bool check_winner(char board[][3], char player){

    for(int i=0;i<3;i++){
        if (board[i][0]==player&&board[i][1]==player&&board[i][2]==player)
        {
            return true;
        }
    }
    for(int j = 0; j < 3; j++){
        if (board[0][j]==player&&board[1][j]==player&&board[2][j]==player){
            return true;
        }
    }
    if(board[0][0]==player&&board[1][1]==player&&board[2][2]==player){
        return true;
    }
    if(board[0][2]==player&&board[1][1]==player&&board[2][0]==player){
        return true;
    }
    return false;
}
bool board_full(char board[][3]);
bool board_full(char board[][3]){
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (board[i][j]!='X'&& board[i][j]!='O'){
                return false;
            }
        }
    }
    return true;
}
int main(){
    char board1[3][3];
    board(board1);
    char player = 'X';
    int position;
    while(true){
        display_board(board1);
        cout << "player "<< player << ", enter position: ";
        cin >> position;

        if(!valid_move(board1,position)){
            cout << "invalid,again" << endl;
            continue;
        }

        place_move(board1,position,player);
        display_board(board1);

        if(check_winner(board1,player)){
            cout <<"player" << player <<"wins!"<< endl;
            break;
        }

        if(board_full(board1)){
            cout <<"draw"<< endl;
            break;
        }
        if(player=='X'){
            player='O';
        }
        else{
            player='X';
        }
    }
    return 0;
}
